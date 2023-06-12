import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("localhost", 9999))

message = client.recv(1024).decode()
print("Received message:", message)
client.send(input(message).encode())

message = client.recv(1024).decode()
print("Received message:", message)
client.send(input(message).encode())

response = client.recv(1024).decode()
print("Received response:", response)
