import urllib2
import cookielib

import WeiboEncode
import WeiboSearch

class WeiboLogin:
	def __init__(self,user,pwd,enableProxy=False):
		#init Weibologin,enableProxy is set to close
		print "Initializing WeiboLogin..."
		self.userName = user
		self.passWord = pwd
		self.enableProxy = enableProxy

		self.serverUrl = "http://login.sina.com.cn/sso/prelogin.php?entry=weibo&callback=sinaSSOController.preloginCallBack&su=&rsakt=mod&client=ssologin.js(v1.4.18)&_=1452778249698"
		self.loginUrl ="http://login.sina.com.cn/sso/login.php?client=ssologin.js(v1.4.18)"
		self.postHeader={'User-Agent':'Mozilla/5.0 (Windows NT 6.3; WOW64; rv:43.0) Gecko/20100101 Firefox/43.0'}

	def Login(self):
		#Login weibo programe
		#cookie or set the proxy server
		self.EnableCookie(self.enableProxy)

		serverTime, nonce, pubkey, rsakv = self.GetServerTime() #the first step
		postData = WeiboEncode.PostEncode(self.userName, self.passWord,serverTime, nonce,pubkey,rsakv) 
		print "Post data length:\n",len(postData)

		req  = urllib2.Request(self.loginUrl,postData,self.postHeader)	
		print "Post request..."
		result = urllib2.urlopen(req)
		text = result.read()
		#print "[+] The result:" + text


		
		try:
			loginUrl = WeiboSearch.sRedirectData(text) #parase the redirect result
			urllib2.urlopen(loginUrl)

			
			myurl = "http://weibo.com/hwrichardyu?from=feed&loc=nickname&is_all=1"
			htmlContent = urllib2.urlopen(myurl).read()
			fp = open('htmlContent.txt','w')
			fp.write(htmlContent)
			fp.close()
			
			'''
			response = urllib2.urlopen("http://weibo.com/ajaxlogin.php?framelogin=1&callback=parent.sinaSSOController.feedBackUrlCallBack&sudaref=weibo.com")
			content = response.read()
			fp = open('content.txt','w')
			fp.write(content)
			fp.close()
			uniqueid, userdomain = WeiboSearch.sGetUserInfor(content)
			url = "http://weibo.com/u/"+uniqueid+"/home"+userdomain
			print url
			myresponse = urllib2.urlopen("url")
			mycontent = myresponse.read()
			'''
		except:
			print "Login error"
			return False

		
		print "[+]Login success!"
		return True

	def EnableCookie(self, enableProxy):
		cookie = cookielib.LWPCookieJar()
		cookie_support = urllib2.HTTPCookieProcessor(cookie)

		if enableProxy:
			proxy_support = urllib2.ProxyHandler({'http':'http://xxx.pac'})#use proxy server
			opener = urllib2.build_opener(proxy_support,cookie_support,urllib2.HTTPHandler)
			print "Proxy enabled"
		else:
			opener=urllib2.build_opener(cookie_support,urllib2.HTTPHandler)

		urllib2.install_opener(opener) # construct opener respondent to cookie

	def GetServerTime(self):
    #"Get server time and nonce, which are used to encode the password"
	    print "[+]Getting server time and nonce..."
	    serverData = urllib2.urlopen(self.serverUrl).read()#get the content of the web page
	    print serverData

	    try:
	        serverTime, nonce, pubkey, rsakv = WeiboSearch.sServerData(serverData)#get servertime and nonce etc
	        return serverTime, nonce, pubkey, rsakv
	    except:
	        print '[-]Get server time & nonce error!'
	        return None


if __name__=='__main__':
	weiboLogin = WeiboLogin('username','passsword')
	if weiboLogin.Login() == True:
		print "Login success!"




