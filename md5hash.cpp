/** @file md5Hash.cpp
 * @author Каспийский Н. К.
 * @version 1.0
 * @brief Класс, обрабатывабщий HASH MD5 (реализация)
 * @date 17.12.2023
 * @copyright ИБСТ ПГУ
 */
#include "headers/md5hash.hpp"
#include <cryptopp/hex.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <iostream>
#include <unistd.h> 
#include <ctime> 
using namespace std;

md5h::md5h(){
	salt = salt_generator();
	}
	
string md5h::hash(const string password){
	using namespace CryptoPP;
    Weak::MD5 hash;
    std::string msg = salt + password;
    std::string digest;
    StringSource(msg, true,           
                 new HashFilter(hash,      
                                new HexEncoder(     
                                    new StringSink(digest))));
    return digest;
}
string md5h::salt_generator(){
	srand(time(NULL));
	static const char alphanum[] =
        "0123456789"
        "ABCDEF";
    string tmp_s;
    tmp_s.reserve(16);
    for (int i = 0; i < 16; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return tmp_s;
}
