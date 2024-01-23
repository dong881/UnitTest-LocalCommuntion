import socket
import time

server_ip = "255.255.255.255" 
server_port = 12345
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
client_socket.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
count = 1
while 1:
    try:
        count +=1
        
        message = "Hello, server!" + str(count)
        print(message)
        client_socket.sendto(message.encode('utf-8'), (server_ip, server_port))
        time.sleep(1)
    except Exception as e:
        print(f"Error: {e}")

