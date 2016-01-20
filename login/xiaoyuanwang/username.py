#generate username file
username = "sy15062"
for i in range(1,20):
    if i>9:
        username += str(i)
    else:
        username += '0'+str(i)

    fp = open('username.txt','a')
    fp.write(username+'\n')
    fp.close()
    username = "sy15062"
