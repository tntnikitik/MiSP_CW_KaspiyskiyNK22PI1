#include "headers/server.hpp"
#include "headers/errorhandler.hpp"
#include "headers/getdata.hpp"
#include "headers/md5hash.hpp"
using namespace std;


server::server(string fpath, int port, string lpath)
{
    lp = lpath;
    char* ip="127.0.0.1";

    userdata = getdata(lp).get(fpath);

    sckt = start(port, ip);

}

int server::start(int port, char* address)
{
    sockaddr_in* selfAddr = new (sockaddr_in);
    selfAddr->sin_family = AF_INET;
    selfAddr->sin_port = htons(port);
    selfAddr->sin_addr.s_addr = inet_addr(address);
    int sckt = socket(AF_INET, SOCK_STREAM, 0);
    int rc = bind(sckt, (const sockaddr*)selfAddr, sizeof(sockaddr_in));
    if (rc == -1) {
        errorhandler(lp, "failed to bind socket", 1, true);
    }
    listen(sckt, 3);
    cout << "The server start" << endl;
    return sckt;
}

int  server::accepting_connection()
{
    sockaddr_in* remoteAddr = new (sockaddr_in);
    remoteAddr->sin_family = AF_INET;
    remoteAddr->sin_port = 0;
    remoteAddr->sin_addr.s_addr = 0;
    sockaddr_in * client_addr = new sockaddr_in;
    socklen_t len = sizeof(sockaddr_in);
    wrkr = accept(sckt, (sockaddr*)(client_addr), &len);
    cout << "The server accepted the connection" << endl;
    return wrkr;
}

bool server::authentication()
{
    md5h crypt;
    string err = "ERR";
    string ok = "OK";
    rc = recv(wrkr, buf, sizeof(buf), 0);
    buf[rc] = '\0';
    string ID(buf);
    if (userdata.count(ID) == 1) {
        strcpy(buf, crypt.salt.c_str());
        send(wrkr, buf, crypt.salt.length(), 0);
    } else {
        strcpy(buf, err.c_str());
        send(wrkr, buf, sizeof(buf), 0);
        close(wrkr);
        errorhandler(lp, "invalid client id", 2, false);
        return false;
    }
    cout << "The client has been identified" << endl;
    rc = recv(wrkr, buf, 4096, 0);
    buf[rc] = '\0';
    string message(buf);
    if (message != crypt.hash(userdata[ID])) {
        strcpy(buf, err.c_str());
        send(wrkr, buf, err.length(), 0);
        close(wrkr);
        errorhandler(lp, "invalid password", 3, false);
        return false;
    }
    strcpy(buf, ok.c_str());
    rc = send(wrkr, buf, ok.length(), 0);
    buf[rc] = '\0';
    cout << "The client has been authenticated" << endl;
    return true;
}
bool server::handling()
{
    uint32_t vectors_quantity;
    uint32_t vector_size;
    uint64_t vector;
    uint64_t maxVal = numeric_limits<uint64_t>::max();
    recv(wrkr, &vectors_quantity, sizeof(vectors_quantity), 0);
    for (uint32_t i = 0; i < vectors_quantity; i++) {
        us   int64_t sum = 1;
        recv(wrkr, &vector_size, sizeof(vector_size), 0);
        for (uint32_t j = 0; j < vector_size; j++) {
            recv(wrkr, &vector, sizeof(vector), 0);

            sum = sum*vector;
            if (sum >= maxVal) {
                sum = maxVal-1;
                break;
            }
        }
        uint64_t answer;


        answer = sum; //vector_size;
        send(wrkr, &answer, sizeof(answer), 0);
    }
    return true;
};
