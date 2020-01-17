import socket
import threading

class Cliente:


	def __init__(host='127.0.0.1', porta=2423):
		self.host=host
		self.porta=porta


	def main(self):
		self.conexaotcp()										#abre a conexão
		thread=threading.Thread(target=self.recebe).start()		#cria a thread
		self.envia()


	def conexaotcp(self):
		self.cliente=socket.socket(socket.AF_INET, socket.SOCK_STREAM)			#cria o socket
		self.cliente.connect((host, porta))

	def envia(self):					#função para enviar mensagens para o servidor
		while True:
			msg=input()
			self.Cliente.send(msg.encode('ascii'))
			if msg== 'sair' or 'Sair':
				self.Cliente.close()
				exit()

	def recebe(self):					#função para receber mensagens do servidor
		while True:
			msg=self.Cliente.recv(1024).decode('ascii')
			print(msg)


if __name__="__main__":
	Cliente=Cliente()
	Cliente.main()