month = ['01','02','03','04','05','06','07','08','09','10','11','12']
day = ['01','02','03','04','05','06','07','08','09','10','11','12','13',
       '14','15','16','17','18','19','20','21','22','23','24','25',
       '26','27','28','29','30','31']
fp = open('pwddatabase.txt','w')
password = ''
for i in range(12):
    #print i,month[i]
    tday = ''
    for j in range(31):
        #print j,day[j]
        tday = day[j]
        last = ''
        for k in range(9999):
            if len(str(k)) == 1:
                #print '000'+str(k)
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
            #print password
            fp = open('pwddatabase.txt','a')
            fp.writelines(password+'\n')
            fp.close()

