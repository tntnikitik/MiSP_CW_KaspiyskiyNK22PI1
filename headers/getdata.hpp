/** @file getdata.hpp
 * @author Каспийский Н. К.
 * @version 1.0
 * @brief Класс, обрабатывающий файл с ID:PASS клиентов
 * @date 17.12.2023
 * @copyright ИБСТ ПГУ
 */
#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "errorhandler.hpp"

using namespace std;
/**
 * @brief Класс, обрабатывающий файл с ID:PASS клиентов
 */
class getdata
{
private:
    ///Путь к файлу с журналом
    string lp;
public:
    /**
     * @brief Конструктор класса
     * @param lpath Путь к файлу с журналом
     */
    getdata(const string lpath);
    /**
     * @brief Запись ID:PASS в словарь
     * @param fpath Путь к файлу с ID:PASS клиентов
     * @return userdata ID:PASS
     */
    map<string, string> get(string fpath);
};
