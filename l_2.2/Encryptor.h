#pragma once
#include <iostream>
#include <string>
using namespace std;
class Encryptor {
public:
                string encrypt(string in, const int key); ///Зашифровывание
                string decrypt(string in, const int key); ///Расшифровывание
};
class cipher_error: public invalid_argument{
public:
explicit cipher_error(const string& what_arg): /// what_arg содержит сообщение вызываемое при исключительной ситуации
invalid_argument(what_arg) {}
};
