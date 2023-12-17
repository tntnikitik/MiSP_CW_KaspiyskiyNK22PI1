/** @file main.cpp
 * @author Каспийский Н. К.
 * @version 1.0
 * @brief Функция вывода справки и точка входа в программу
 * @date 17.12.2023
 * @copyright ИБСТ ПГУ
 */
#include <iostream>
#include <string>
#include "headers/server.hpp"
#include "headers/getdata.hpp"
#include <cryptopp/hex.h>
#include "headers/md5hash.hpp"
#include <string.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

void help()
{
    std::cout << "enter -h for help;\nenter -fp for the path to the database with clients;\nenter -lp for the path to the log file;\nenter -p for the port\n";
}

int main(int argc, const char* argv[])
{
    std::string fpath = "/home/stud/Desktop/kursach/kursachCode/SERVER/database.txt";
    int port = 33333;
    std::string lpath = "log.txt";

    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help,h", "produce help message")
    ("database-path,fp", po::value<std::string>(&fpath)->default_value("/home/stud/Desktop/kursach/kursachCode/SERVER/database.txt"), "path to the database with clients")
    ("log-path,lp", po::value<std::string>(&lpath)->default_value("log.txt"), "path to the log file")
    ("port,p", po::value<int>(&port)->default_value(33333), "port");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        help();
        return 1;
    }

    server srvr = server(fpath, port, lpath);

    while (true) {
        srvr.accepting_connection();
        if (srvr.authentication() == true)
            srvr.handling();
    }

    return 0;
}
