#pragma once
#include <cstdlib> // exit() - стандартные функции Си
#include <cstring> // strcpy(), strlen() - строки Си
#include <unistd.h> // close() - стандартные функции Unix
#include <netinet/in.h> //sockaddr_in and include <sys/socket.h>
#include <arpa/inet.h> // inet_addr()
#include <string>
#include <iostream>
//#include "getdata.hpp"
//#include "md5hash.hpp"
//#include "errorhandler.hpp"
#include <map>
#include <stdlib.h>
#include <bitset>
#include <cstdint>
#include <limits>
#include <cstdint>
#include <limits>
class server
{
private:
    std::string lp;
    int sckt;
    int wrkr;
    int rc;
    char *buf = new char[4096];
    std::map <std::string, std::string> userdata;
public:
    server(std::string fpath, int port, std::string lpath);
    int start(int port, char* address);
    int accepting_connection();
    bool authentication();
    bool handling();
};
