import socket
import time 
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('192.168.43.90', 8585))
s.listen(0)                 
 
while True:
    client, addr = s.accept()
    print(client, addr)
    client.settimeout(5)
    while True:
        content = client.recv(1024)
        if len(content)==0:
           break
        if str(content,'utf-8') == '\r\n':
            continue
        else:
            print(str(content,'utf-8'))
            client.send(b'1')
    client.close()