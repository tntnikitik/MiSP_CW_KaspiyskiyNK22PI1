/** @file getdata.сpp
 * @author Каспийский Н. К.
 * @version 1.0
 * @brief Класс, обрабатывающий файл с ID:PASS клиентов (реализация)
 * @date 17.12.2023
 * @copyright ИБСТ ПГУ
 */
#include "headers/getdata.hpp"
using namespace std;
getdata::getdata(const string lpath)
{
    lp = lpath;
}
map <string, string> getdata::get(string fpath)
{
    map <string, string> userdata;
    string line;
    ifstream in(fpath);
    if (in.is_open()) {
        while (getline(in, line)) {
            int position = line.find(':');
            string ID;
            string password;
            for (int n = 0; n < position; n++)
                ID += line[n];
            for (uint n = position+1; n < line.length(); n++)
                password += line[n];
            userdata[ID] = password;
        }
    } else
        errorhandler(lp, "failed open client base file", 4, true);
    in.close();
    return userdata;
}
