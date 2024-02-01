import socket
import time
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
udp_host = socket.gethostname()
# For UDP
# Host IP
udp_port = 12345
# specified port to connect
sock.bind((udp_host, udp_port))
print("Enter ctrl+c to exit ")
while True:
	print("###### SERVER is LISTENING ###### ")
	data,addr = sock.recvfrom(1024)
	#receive data from client
	print("server received: ",data.decode())
	msg=input(str("Server says: "))
	sock.sendto(msg.encode(),addr)