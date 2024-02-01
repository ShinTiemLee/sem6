import socket
host=socket.gethostname()
port=12345
s=socket.socket()
s.connect((host,port))
s.sendall(b'Welcome User')
print('Client is connected to server and it has sent the message to server')
data=s.recv(1024)
s.close()
print('This is printing the message received back by the server')
print(repr(data))