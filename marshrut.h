/**
 * @file marshrut.h
 * @author Глебов И. Д.
 * @brief Заголовочный файл для модуля программы шифрования методом табличной маршрутной перестановки
 * @details Программа шифрует строку текста при помощи алгоритма табличной маршрутной перестановки
 * @date 2023-01-26
 */
#pragma once
#include <string>
#include <stdexcept>
using namespace std;
class marshrut
{
private:
    int key;
    string getValidText(string stroka);
public:
    marshrut()=delete;
    /**
     * @brief конструктор для класса marshrut
     * @details принимает int key
     * @param key может быть только целым числом
     * @throw invalid_argument  когда key не целое число
     * @throw cipher_error когда key у нас пустой
     */
    marshrut(int key);
    /**
     * @brief зашифровщик/расшифровщик
     * @details принимает string stroka
     * @param stroka текст который нужно зашифровать или расшифровать, автоматически приводит к прописным и удаляет лишние символы
     * @throw cipher_error  если у нас stroka пустой
     */
    string transform(string stroka);
};
/**
 * @brief класс cipher_error
 * @details обработка ошибок
*/
class cipher_error: public invalid_argument {
public:
    explicit cipher_error (const string& what_arg):
    invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
    invalid_argument(what_arg) {}
};