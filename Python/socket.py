'''
    server
    listen
    socket
    thread
'''


from threading import Thread
import socket

rcvSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
rcvSocket.bind(("", 12345))
rcvSocket.listen(5)
rcvMsgThread = Thread(target=handleRcvMsg)
rcvMsgThread.start()


def handleRcvMsg():
    while True:
#            print 'listening...'
        clientSock, addr = rcvSocket.accept()
        data = ""
        while True:
            buf = clientSock.recv(1024)
            if not buf: break
            data += buf
#            print '[rcv]' + addr + ":" + data
        clientSock.close()
        
        try:
            cmdDict = json.loads(data)
            
            #
            # Pop-up message
            #
            if cmdDict['cmd'] == 'jump':
                data = cmdDict['data']
            else:
                continue
        except:
            pass
            
# ==============================================================================
''' 
    set socket default timeout
'''
socket.setdefaulttimeout(10.0)

# ==============================================================================
'''
    IP address to byte
    bytes 
    array
'''
socket.ntohl(struct.unpack("I",socket.inet_aton('225.1.2.255'))[0])
# 4278256383L

socket.inet_ntoa(struct.pack('I',socket.htonl(4278256383L)))
# '225.1.2.255'

