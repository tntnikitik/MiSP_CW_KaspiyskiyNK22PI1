/** @file server.hpp
 * @author Каспийский Н. К.
 * @version 1.0
 * @brief Класс, управляющий работой сервера
 * @date 17.12.2023
 * @copyright ИБСТ ПГУ
 */
#pragma once
#include <cstdlib> 
#include <cstring> 
#include <unistd.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <bitset>
#include <cstdint>
#include <limits>
/**
 * @brief Класс управления работой сервера
 */
class server
{
private:
    ///Путь к файлу с логом
    std::string lp;
    ///Сокет
    int sckt;
    ///Действующее соединение с клиентом
    int wrkr;
    ///Ответ от клиента
    int rc;
    ///Буфер
    char *buf = new char[4096];
    ///Данные клиента ID:PASS
    std::map <std::string, std::string> userdata;
public:
    /**
     * @brief Конструктор класса
     * @param fpath Путь к файлу с ID:PASS клиентов
     * @param port Порт для приема соединения
     * @param lpath Путь к файлу журнала
     */
    server(std::string fpath, int port, std::string lpath);
    /**
     * @brief Функция запуска сервера и привязки порта
     * @param port Порт для приема соединения
     * @param address Сетевой адрес для приема соединения
     * @return sckt Сокет
     */
    int start(int port, char* address);
    /**
     * @brief Функция ожидания и принятия соединения с клиентом
     * @return wrkr Действующее соединение с клиентом
     */
    int accepting_connection();
    /**
     * @brief Функция аутентификации пользователя
     * @return True, если аутентификация удалась, False - если нет
     */
    bool authentication();
    /**
     * @brief Функция обработки векторов
     * @return True, если обработка удалась, False - если нет
     */
    bool handling();
};
