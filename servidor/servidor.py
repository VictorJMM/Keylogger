import socket

def processar_solicitacao(request):
    try:
        headers, body = request.split(b'\r\n\r\n', 1)
        body = body.decode().strip()

        if body:
            print(f"Tecla recebida: {body}")
    except ValueError:
        print("Erro ao separar cabeçalhos e corpo. Solicitação incompleta ou mal formatada.")
        print("Requisição recebida:")
        print(request)

def start_server():
    host = '0.0.0.0'
    port = 8080

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))  
    server_socket.listen(5)
    print(f"Servidor rodando em http://{host}:{port}")
    
    while True:
        client_socket, client_address = server_socket.accept()
        print(f"Conexão recebida de {client_address}")
        print("Requisição recebida:")

        while True:
            request = client_socket.recv(1024)  
            if not request:
                break 
            processar_solicitacao(request)

        client_socket.close()

if __name__ == '__main__':
    start_server()
