/*
  Author: Mohin Nadaf
  Created on: 23-07-2024 20:43:54
                                 */

#include <bits/stdc++.h>
using namespace std;

string vigenereCipher(string text, string key, bool encrypt)
{
    string result = "";
    int key_len = key.length();
    for (int i = 0; i < text.length(); i++)
    {
        if (isalpha(text[i]))
        {
            char offset = islower(text[i]) ? 'a' : 'A';
            int shift = tolower(key[i % key_len]) - 'a';
            if (encrypt)
            {
                result += (text[i] - offset + shift) % 26 + offset;
            }
            else
            {
                result += (text[i] - offset - shift + 26) % 26 + offset; // Handle negative shifts
            }
        }
        else
        {
            result += text[i];
        }
    }
    return result;
}

string vigenereEncrypt(string text, string key)
{
    return vigenereCipher(text, key, true);
}

string vigenereDecrypt(string ciphertext, string key)
{
    return vigenereCipher(ciphertext, key, false);
}

int main()
{
    string plaintext;
    // Enter text input
    cin >> plaintext;

    string key;
    // Enter key input
    cin >> key;

    string ciphertext = vigenereEncrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = vigenereDecrypt(ciphertext, key);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
