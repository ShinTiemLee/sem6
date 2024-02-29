

PeerInfo=[[0,"peer0","active"],[1,"peer1","active"],[2,"peer2","active"],[3,"peer3","active"],[4,"peer4","active"],[5,"peer5","active"],[6,"peer6","active"],[7,"peer7","active"]]
elecmsg="Election"
okmsg="OK"
coodmsg="Coordinator"
reqmsg="request"
resmsg="response"
coordinator=7
timeinterval=datetime.timedelta(seconds=2)
highest=7
interruptflag=0

class peer:
	def __init__(self):
		for peer in PeerInfo:
			print(peer[1]," is active\n")
			if peer[0]==highest:
				print(peer[1]," is coordinator\n")


	def sendreq(self,id,msg):
			print(PeerInfo[id][1]," requested\n")
			if msg==reqmsg and PeerInfo[coordinator][2]=="active":
				print("Coordinator Responded\n")
			elif msg==reqmsg and PeerInfo[coordinator][2]!="active"
				flag=0
				for peer in PeerInfo:
					if peer[0]>peer[id]:
						print("Election message sent to ",peer[1])
						election()
						if peer[2]=="active":
							print("OK message received from ",peer[1])
							flag=1
				if flag==0:
					coordinator=id
					print("Peer",id,"is the coordinator now")


	def clienthandle(self):
		self.c=socket.socket()
		self.c.connect(PeerInfo[coordinator][1],PeerInfo[coordinator][2])
		print("Connected to peer: ",coordinator)
		while True:
			time.sleep(1)
			self.c.send("request".encode())
			interruptflag=0
			start=datetime.now()
			threading.thread(target=checktime,arg(start,)).start()
			msg=self.c.recv(1024).decode()
			interruptflag=1

	def checktime(self,start):
		failed_time= start+timeinterval
		while True:
			cur=datetime.now()
			if interruptflag==1:
				break
			if  cur>=failed_time:
				self.c.close()
				for peer in PeerInfo:
					if peer[0]>sys.arg[1]:
						try:
							self.c=socket.socket()
							self.c.connect(peer[1],peer[2])
							self.c.send(elecmsg.encode())

						except:
							continue

				threading.thread(target=serverhandle).start()




