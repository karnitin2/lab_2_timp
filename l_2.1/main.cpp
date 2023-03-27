#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText)
            cipherText.front() = tolower(cipherText.front());
        decryptedText = cipher.decrypt(cipherText);
        wcout<<"key="<<key<<endl;
        wcout<<Text<<endl;
        wcout<<cipherText<<endl;
        wcout<<decryptedText<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
int main(int argc, char **argv)
{
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
    check(L"Димаревинильясёмовалексейивашкинтут",L"Начало");
    check(L"Димаревинильясёмовалексейивашкинтут",L"");
    check(L"Димаревинильясёмовалексейивашкинтут",L"ДРУГ777");
    check(L"Дима ревин илья сёмов алексей ивашкин тут",L"СЕРЕДИНА");
    check(L"Димаревинильясёмовалексейивашкинтут",L"КОНЕЦ",true);
    check(L"777",L"ДРУГ");
    return 0;
}
