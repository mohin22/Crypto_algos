/*
  Author: Mohin Nadaf
  Created on: 23-07-2024 20:09:23
                                 */

#include <bits/stdc++.h>
using namespace std;
// function to calculate caesar_cipher
string caesarCipher(string &input, int key)
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
int main()
{
    // input a text string to encrypt
    string text;
    cin >> text;

    // input key size of shift
    int key;
    cin >> key;

    // call function which calculates caesar cipher
    string cipher_text = caesarCipher(text, key);

    // print cipher text(encrypted text)
    cout << cipher_text;

    return 0;
}
