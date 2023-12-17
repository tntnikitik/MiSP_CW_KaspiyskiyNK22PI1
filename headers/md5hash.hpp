/** @file md5Hash.hpp
 * @author Каспийский Н. К.
 * @version 1.0
 * @brief Класс, обрабатывабщий HASH MD5
 * @date 17.12.2023
 * @copyright ИБСТ ПГУ
 */
#pragma once
#include <cryptopp/hex.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>

using namespace std;
/**
 * @brief Класс, обрабатывабщий HASH MD5
 */
class md5h
{
private:
	/**
	 * @brief Генератор соли
	 * @return tmp_s Соль
	 */
	string salt_generator();
public:
	/**
	 * @brief Конструктор класса
	 */
	md5h();
	///Соль
	string salt;
	/**
	 * @brief Получение хэша от пароля
	 * @param password Пароль
	 * @return digest Хэш от пароля
	 */
	string hash(const string password);
};
