import urllib2
import cookielib

import urllib
import hashlib



def Encrypt(password):
		return hashlib.new('md5',password).hexdigest()[8:24]

def PostEncode(username,password):
	username = username
	encodedpwd = Encrypt(password)
	postPara={
		'username':username,
		'password':encodedpwd,
		'drop':'0',
		'type':'1',
		'n':'100'
	}
	postData = urllib.urlencode(postPara)
	return postData


'''

'''