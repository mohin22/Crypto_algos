/*
  Author: Mohin Nadaf
  Created on: 23-07-2024 20:09:23
                                 */

#include <bits/stdc++.h>
using namespace std;

// function to calculate caesar cipher (encryption)
string caesarEncrypt(string &input, int key)
{
    string cipher_text = "";
    for (char c : input)
    {
        if (isalpha(c))
        {
            char offset = islower(c) ? 'a' : 'A';
            cipher_text += (c - offset + key) % 26 + offset;
        }
        else
        {
            cipher_text += c;
        }
    }
    return cipher_text;
}

// function to calculate caesar cipher (decryption)
string caesarDecrypt(string &cipher_text, int key)
{
    string plain_text = "";
    for (char c : cipher_text)
    {
        if (isalpha(c))
        {
            char offset = islower(c) ? 'a' : 'A';
            plain_text += (c - offset - key + 26) % 26 + offset; // Handle negative values
        }
        else
        {
            plain_text += c;
        }
    }
    return plain_text;
}

int main()
{
    // input a text string to encrypt/decrypt
    string text;
    cin >> text;

    // input key size of shift
    int key;
    cin >> key;

    // encrypt the text
    string cipher_text = caesarEncrypt(text, key);
    cout << "Encrypted text: " << cipher_text << endl;

    // decrypt the encrypted text
    string plain_text = caesarDecrypt(cipher_text, key);
    cout << "Decrypted text: " << plain_text << endl;

    return 0;
}
