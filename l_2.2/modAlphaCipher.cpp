#include "modAlphaCipher.h"

modAlphaCipher::modAlphaCipher(int k)
{
    this->key=k;
}

std::wstring modAlphaCipher::encrypt(modAlphaCipher key, std::wstring& open_text)
{
    std::wstring Result;
    const int str = ((open_text.size()-1)/key.key)+1;
    int index = 0;
    wchar_t mtr[str][key.key];
    for (int i = 0; i <str; i++) {
        for (int j = 0; j < key.key; j++ ) {
            if (index < open_text.size()) {
                mtr[i][j] = open_text[index];
                index++;
            } else {
                mtr[i][j] =' ';
            }
        }
    }
    for (int i = 0; i < key.key; i++) {
        for (int j = 0; j < str; j++ ) {
            Result.push_back(mtr[j][i]);
        }
    }
    return Result;
}
std::wstring modAlphaCipher::decrypt(modAlphaCipher key, std::wstring& cipher_text)
{
    std::wstring Result;
    int index = 0;
    const int str = ((cipher_text.size()-1)/key.key)+1;
    wchar_t mtr[str][key.key];

    for (int i = 0; i < key.key; i++) {
        for (int j = 0; j < str; j++ ) {
            if (index < cipher_text.size()) {
                mtr[j][i] = cipher_text[index];
                index++;
            } else {
                mtr[j][i] = ' ';
                index++;
            }
        }
    }
    for(int i = 0; i < str; i++) {
        for (int j = 0; j< key.key; j++) {
            Result.push_back(mtr[i][j]);
        }
    }
    return Result;
}
inline int modAlphaCipher::getValidKey(const int k, const std::wstring & s)
{
    if (k<=0)
        throw cipher_error("Invalid key");
    else if (k>(s.size()/2))
        throw cipher_error("Invalid key");
    else
        return k;
}
inline std::wstring modAlphaCipher::getValidOpenText(const std::wstring & s)
{
    int i=0;
    std::wstring tmp;
    for (auto c:s) {
        if (isalpha(c)) {
            if (islower(c))                {
                tmp.push_back(toupper(c));
                i++;
                if (i==1)
                    std::wcout<<L"Часть входного текста была перенесена в верхний регистр: "<<std::endl;
            } else
                tmp.push_back(c);
        }
    }
    if (tmp.empty())
        throw cipher_error("No input text");
    return tmp;
}
inline std::wstring modAlphaCipher::getValidCipherText(const std::wstring & s)
{
    int i=0;
    std::wstring tmp;
    for (auto c:s) {
        if (isalpha(c)) {
            if (islower(c))                {
                tmp.push_back(toupper(c));
                i++;
                if (i==1)
                    throw cipher_error("Invalid cipher text");
            } else
                tmp.push_back(c);
        }
    }
    if (tmp.empty())
        throw cipher_error("No output text");
    return tmp;
}
