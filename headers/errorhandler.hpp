/** @file errorhandler.hpp
 * @author Каспийский Н. К.
 * @version 1.0
 * @brief Класс обработки ошибок с записью в журнал
 * @date 17.12.2023
 * @copyright ИБСТ ПГУ
 */
#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
/**
 * @brief Класс обработки ошибок
 */
class errorhandler{
private:
        /**
         * @brief Функция записи ошибок в журнал
         * @param lpath Путь к файлу журнала
         * @param why Содержание ошибки
         * @param dtime Время ошибки
         * @param critical Критичность ошибки
         */
        void logger(const std::string lpath, const char* why, const std::string dtime, const std::string critical);
public:
        /**
         * @brief Конструктор класса
         * @param lpath Путь к файлу журнала
         * @param why Содержание ошибки
         * @param exitCode Код ошибки
         * @param critical Критичность ошибки
         */
        errorhandler(const std::string lpath, const char* why, const int exitCode, bool critical);
};