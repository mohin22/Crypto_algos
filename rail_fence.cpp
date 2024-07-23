/*
  Author: Mohin Nadaf
  Created on: 23-07-2024 20:56:35
                                 */

#include <bits/stdc++.h>
using namespace std;

// Encryption function
string encryptRailFence(string text, int key)
{
    int n = text.length();
    vector<vector<char>> rail(key, vector<char>(n, '\n'));

    bool dir_down = false;
    int row = 0, col = 0;

    for (int i = 0; i < n; i++)
    {
        rail[row][col++] = text[i];
        if (row == key - 1)
            dir_down = false;
        else if (row == 0)
            dir_down = true;
        row += dir_down ? 1 : -1;
    }

    string cipherText;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < n; j++)
            if (rail[i][j] != '\n')
                cipherText += rail[i][j];

    return cipherText;
}
// Decryption function
string decryptRailFence(string cipher, int key)
{
    int n = cipher.length();
    vector<vector<char>> rail(key, vector<char>(n, '\n'));

    bool dir_down;
    int row = 0, col = 0;

    for (int i = 0; i < n; i++)
    {
        rail[row][col++] = '*';
        if (row == key - 1)
            dir_down = false;
        else if (row == 0)
            dir_down = true;
        row += dir_down ? 1 : -1;
    }

    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < n; j++)
            if (rail[i][j] == '*' && index < cipher.length())
                rail[i][j] = cipher[index++];

    string plainText;
    row = 0, col = 0;
    for (int i = 0; i < n; i++)
    {
        plainText += rail[row][col++];
        if (row == key - 1)
            dir_down = false;
        else if (row == 0)
            dir_down = true;
        row += dir_down ? 1 : -1;
    }
    return plainText;
}

int main()
{
    // Enter plaintext
    string text;
    cin >> text;

    // Enter number of rails to be performed
    int key;
    cin >> key;

    // Encryption of plaintext
    string cipherText = encryptRailFence(text, key);
    cout << "Ciphertext: " << cipherText << endl;

    // Decryption of cipher_text
    string decryptedText = decryptRailFence(cipherText, key);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
