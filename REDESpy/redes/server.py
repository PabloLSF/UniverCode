import socket
import threading
import random
from Vivi import Vivi
from Jorjao import Jorjao
from Bob import Bob


class Servidor:
	def __init__(self, host='localhost', porta=2423):
		self.porta=porta						#porta pela qual a conexão acontece
		self.host= host							#ip host do servidor
		self.clientes={}						#dicionario de conexões de clientes por {nome :[personagem do cliente, come do cliente]}

	def clientHandler(self, con):
		con.send('Bem vindo a Apocalyptica!\n Qual seu nome?  '.encode('ascii'))
		nome=con.recv(1024).decode('ascii')
		con.send('Com qual personagem deseja jogar?(Vivi, Jorjão ou Bob'.encode('ascii'))
		persona=con.recv(1024).decode('ascii')
		if persona== 'Vivi':
			jogador=Vivi(nome)
		elif persona== 'Jorjão':
			jogador=Jorjao(nome)
		elif persona== 'Bob':
			jogador=Bob(nome)
		self.Clientes.update({con : [jogador, nome]})			#adiciona o cliente na lista de clientes


	def enviamsg(self,con, msg):			#função para enviar mensegens ao cliente
		con.send(msg.encode('ascii'))

	def recebemsg(self,con):				#função para receber os comandos do servidor
		msg=con.recv(1024).decode('ascii')
		self.acao(msg, con)					



	def acao(self, msg, con):				#função que toma uma ação dado o comando enviado pelo cliente
		self.comando=msg.strip()			#tira os espaços em branco do comando que o cliente enviou
		if comando== 'Sair' or 'sair':
			if self.Clientes.has_key(con)	
				del(self.Clientes[con])		#tira o cliente da lista de clientes
			con.close()						#encerra a conexão com ele

		elif comando == 'Atacar':
			#escrever forma de ataque
		elif comando == 'Defender':
			#escrever forma de defesa
		elif comando == 'Provocar':
			self.comando=msg.split()		#divide o comando em substrings
			for i in comando:
				mensagem= mensagem+' '+comando[i] #une as partes da provocação para enviar para o adversário   
			enviamsg(mensagem)
		else:
			self.con.send('comando inválido').encode('ascii')





	def main(self):
		self.server= socket.socket(socket.AF_INET, socket.SOCKSTREAM)		#abre o socket
		self.server.bind((host,porta))										#une o host a porta criando o servidor
		self.server.listen(2)												#escuta no máximo 2 clientes

		while True:
			con, adress= self.server.accept()								#servidor aceita conexão de um cliente
			thread= threading.Thread(target= self.ClientHandler, args= (con,)).start()		#thread do cliente inicia

if __name__="__main__":
	server=Servidor()
	server.main()