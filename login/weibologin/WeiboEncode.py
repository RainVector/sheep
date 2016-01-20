import urllib
import base64
import rsa
import binascii

def PostEncode(userName, passWord, serverTime, nonce, pubkey, rsakv):
	#encode the post data
	encodedUserName = GetUserName(userName) #encray username with base64
	encodedPassWord = get_pwd(passWord,serverTime,nonce,pubkey) # encray with rsa
	postPara = {
		'entry': 'weibo',
		'gateway': '1',
		'from': '',
		'savestate': '0',
		'userticket': '1',
		'pagerefer': '',
		'vsnf': '1',
        'su': encodedUserName,
        'service': 'miniblog',
        'servertime': serverTime,
        'nonce': nonce,
        'rsakv': rsakv,
        'pwencode': 'rsa2',
        'sp': encodedPassWord,
        'sr':'960*1536',
        'encoding': 'UTF-8',
        'prelt': '56', 
        'url': 'http://weibo.com/ajaxlogin.php?framelogin=1&callback=parent.sinaSSOController.feedBackUrlCallBack',
        'returntype': 'META'
	}
	postData = urllib.urlencode(postPara)
	return postData

def GetUserName(userName):
	#it's used to encode the user name
	userNameTemp = urllib.quote(userName)
	userNameEncoded = base64.encodestring(userNameTemp)[:-1]
	return userNameEncoded

def get_pwd(password, servertime, nonce, pubkey):
	rsaPublickey = int(pubkey,16)
	key = rsa.PublicKey(rsaPublickey,65537) # generate public key
	message = str(servertime)+'\t'+str(nonce)+'\n'+str(password)

	passwd = rsa.encrypt(message,key) #encrypt
	passwd = binascii.b2a_hex(passwd) # translate the encrypted information to hex
	return passwd