#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

class errorhandler {
    private:
        void logger(const std::string lpath, const char* why, const std::string dtime, const std::string critical);
    public:
        errorhandler(const std::string lpath, const char* why, const int exitCode, bool critical);
};