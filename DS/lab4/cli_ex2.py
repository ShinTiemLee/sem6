import socket
import time
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
udp_host = socket.gethostname()
udp_port = 12345
# For UDP
# Host IP
# specified port to connect
print("Enter ctrl+c to exit ")
while True:
	msg=input(str("Client says: "))
	sock.sendto(msg.encode(),(udp_host,udp_port))
	msg,addr=sock.recvfrom(1024)
	print("Client receives: ",msg.decode())