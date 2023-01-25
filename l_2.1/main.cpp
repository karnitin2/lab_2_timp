#include <iostream>
#include "modAlphaCipher.h"
using namespace std;
void check(const wstring& Text, const wstring& key, bool destructCipherText=false)
{
    wstring cipherText;
    wstring decryptedText;
    try {
         modAlphaCipher cipher(key);
         cipherText = cipher.encrypt(Text);
         decryptedText = cipher.decrypt(cipherText);
         wcout<<L"key=" << key <<endl;
         wcout<<Text<<endl;
         wcout<<cipherText<<endl;
         wcout<<decryptedText<<endl<<endl;
    } catch (const cipher_error & e) {
 cerr << "Error: " << e.what() << endl;
    }
}
int main(int argc, char **argv)
{
     locale loc("ru_RU.UTF-8");
     locale::global(loc);
     check(L"АЛФАВИТ",L"АБВГД");
     check(L"ЮНОСТЬ",L"ПИЖЕН55");
     check(L"ДРУЖБА",L"");
     check(L"0ПОЦЕЛЬСИЮ",L"РТИП");
     return 0;
}
