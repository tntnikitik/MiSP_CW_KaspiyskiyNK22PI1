/** @file errorhandler.сpp
 * @author Каспийский Н. К.
 * @version 1.0
 * @brief Класс обработки ошибок с записью в журнал (реализация)
 * @date 17.12.2023
 * @copyright ИБСТ ПГУ
 */
#include "headers/errorhandler.hpp"

using namespace std;

errorhandler::errorhandler(const string lpath,
                           const char* why,
                           const int exitCode = 1,
                           bool critical = false)
{
    string crtcl;
    if (critical == true)
        crtcl = "true";
    else
        crtcl = "false";
    auto now = std::chrono::system_clock::now();
    time_t dt = std::chrono::system_clock::to_time_t(now);
    string dtime = ctime(&dt);
    cerr << " ERR time: " << dtime << " ERR INFO: " << why << "; critical: " << crtcl << "\n";
    logger(lpath, why, dtime, crtcl);
    if (critical == true)
        exit(exitCode);
}

void errorhandler::logger(const string lpath,
                          const char* why,
                          const string dtime,
                          const string critical)
{
    ofstream out(lpath, std::ios::app);
    if (out.is_open()) {
        out << " ERR time: " << dtime << " ERR INFO: " << why << "; critical: " << critical << endl << endl;
    } else {
        cerr << " ERR time: " << dtime << " ERR INFO: " << why << "; critical: " << critical << "\n";
        exit(5);
    }
    out.close();
}
