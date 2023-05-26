#include <iostream>
#include <string>
#include "Cipher.h"
using namespace std;
string cipher(string str, const int key);
string decipher(string str, const int key);
int main()
{
    Cipher cpr;
    try {
        string original = "TEXTFORTRANSCRYPT";
        int key = cpr.key();
        string encrypted = cpr.cipher(original, key);
        string decrypted = cpr.decipher(encrypted, key);
        cout << original << endl;
        cout << encrypted << endl;
        cout << decrypted << endl;
    } catch (const cipher_error & e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
