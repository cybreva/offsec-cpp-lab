#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main() {
    string ip = "127.0.0.1"; // for Localhost testing
    int port = 80;           // HTTP Port testing

    // 1.Creating Socket (IPv4, TCP)
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "[-] Socket creation failed!" << endl;
        return 1;
    }

    // 2. Target Address Structure
    sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &target.sin_addr);

    // 3. Connect try karte hain
    int result = connect(sock, (struct sockaddr*)&target, sizeof(target));

    if (result == 0) {
        cout << "[+] Port " << port << " is OPEN on " << ip << endl;
    } else {
        cout << "[-] Port " << port << " is CLOSED/FILTERED" << endl;
    }

    close(sock);
    return 0;
}
