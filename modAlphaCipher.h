/**
 * @file modAlphaCipher.h
 * @author Глебов И. Д.
 * @brief Заголовочный файл для модуля программы шифрования алгоритмом Гронсфельда
 * @details Программа шифрует строку текста при помощи алгоритма Гронсфельда
 * @date 2023-01-26
 */
#pragma once
#include <vector>
#include <string>
#include <map>
#include <stdexcept>
class modAlphaCipher
{
private:
    std::string numAlpha = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///<алфавит по порядку
    std::map <char,int> alphaNum; ///<ассоциативный массив "номер по символу"
    std::vector <int> key; ///<ключ
    std::vector<int> convert(const std::string& s); ///<преобразование строка-вектор
    std::string convert(const std::vector<int>& v); ///<преобразование вектор-строка
    std::string getValidKey(const std::string& s);
    std::string getValidOpenText(const std::string& open_text);
    std::string getValidCipherText(const std::string& cipher_text);
public:
    modAlphaCipher()=delete; ///<запретим конструктор без параметров
    /**
     * @brief конструктор для класса modAlphaCipher
     * @details принимает std::string& skey
     * @param skey ключ автоматически приводит к прописным и удаляет лишние символы. вызывает ошибку когда пустой
     * @throw cipher_error  если у нас skey пустой
     */
    modAlphaCipher(const std::string& skey);
    /**
     * @brief зашифровщик
     * @param open_text текст который нужно зашифровать, автоматически приводит к прописным и удаляет лишние символы
     * @return std::string  выходная строка, которую зашифровал зашифровщик
     * @throw cipher_error  если у нас пустой open_text
     */
    std::string encrypt(const std::string& open_text); ///<зашифрование
    /**
     * @brief зашифровщик
     * @param cipher_text зашифрованный текст который нужно расшифровать, автоматически приводит к прописным и удаляет лишние символы
     * @return std::string  выходная строка, которую зашифровал зашифровщик
     * @throw cipher_error  если у нас пустой cipher_text
     */
    std::string decrypt(const std::string& cipher_text);///<расшифрование
};
/**
 * @brief класс cipher_error
 * @details обработка ошибок
*/
class cipher_error: public std::invalid_argument {
public:
    explicit cipher_error (const std::string& what_arg):
    std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
    std::invalid_argument(what_arg) {}
};