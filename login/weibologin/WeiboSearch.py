import re
import json

def sServerData(serverData):
	#get the server time and nonce from server data
	print "[+]parasing the serverData....."
	p = re.compile('\((.*)\)')
	jsonData = p.search(serverData).group(1)
	#print jsonData
	data = json.loads(jsonData)
	#print data
	serverTime = str(data['servertime'])
	nonce = data['nonce']
	pubkey = data['pubkey']
	rsakv = data['rsakv']
	print "[+]Server time is:", serverTime
	print "[+]Nonce is:", nonce
	return serverTime, nonce, pubkey, rsakv

def sRedirectData(text):
	p = re.compile('location\.replace\([\'"](.*?)[\'"]\)')
	loginUrl = p.search(text).group(1)
	print 'LoginUrl:',loginUrl
	return loginUrl

def sGetUserInfor(content):
	print "[+]I am getting the userInformation...."
	print content
	p = re.compile('\((.*)\)')
	j = p.search(content).group(1)
	data = json.loads(j)
	information = data['userinfo']
	print information
	userinfo = information['uniqueid']
	userdomain=information['userdomain']
	print "[+]user's uniqueid is:",userinfo
	print "[+]user's userdomain is:",userdomain
	return userinfo, userdomain