#pragma once
#include <vector>
#include <string>
#include <iostream>
class modAlphaCipher
{
private:
    int key;
    int getValidKey(const int key, const std::wstring & s);
    std::wstring getValidOpenText(const std::wstring & s);
    std::wstring getValidCipherText(const std::wstring & s);
public:
    modAlphaCipher()=delete;
    modAlphaCipher(int k);
    std::wstring encrypt(modAlphaCipher key, std::wstring& open_text);
    std::wstring decrypt(modAlphaCipher key, std::wstring& cipher_text);
};
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
