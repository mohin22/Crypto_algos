/*
  Author: Mohin Nadaf
  Created on: 23-07-2024 23:45:36
                                 */

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int p, q, n, e, d, tot;
string text;
// Checks if the number is prime or not
bool isPrime(int a)
{
    if (a <= 1)
        return false;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

// Calculate GCD using Euclidean algorithm
int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Find modular inverse using Extended Euclidean Algorithm
int modInverse(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Find modular exponentiation
long long modPow(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

// Set RSA keys
void setKeys()
{
    tot = (p - 1) * (q - 1);
    n = p * q;

    // Check if e is coprime with tot
    if (gcd(e, tot) != 1)
    {
        throw invalid_argument("e is not coprime with totient.");
    }

    // Calculate private key d
    d = modInverse(e, tot);
}

// Encrypt plaintext
string encrypt(string s)
{
    string enc = "";
    for (char c : s)
    {
        long long encryptedChar = modPow((int)c, e, n);
        enc += to_string(encryptedChar) + " ";
    }
    return enc;
}

// Decrypt ciphertext
string decrypt(string s)
{
    string dec = "";
    size_t pos = 0;
    string token;
    while ((pos = s.find(" ")) != string::npos)
    {
        token = s.substr(0, pos);
        long long encryptedChar = stoll(token);
        long long decryptedChar = modPow(encryptedChar, d, n);
        dec += (char)decryptedChar;
        s.erase(0, pos + 1);
    }
    return dec;
}

int main()
{
    // Input values for p, q, and e
    cin >> p;
    if (!isPrime(p))
    {
        cout << "p is not a prime number." << endl;
        return 1;
    }

    cin >> q;
    if (!isPrime(q))
    {
        cout << "q is not a prime number." << endl;
        return 1;
    }

    cin >> e;

    // Set RSA keys
    try
    {
        setKeys();
    }
    catch (const invalid_argument &ia)
    {
        cout << ia.what() << endl;
        return 1;
    }

    cout << "Public key (e, n) is (" << e << ", " << n << ")" << endl;
    cout << "Private key (d, n) is (" << d << ", " << n << ")" << endl;

    // Input plaintext
    cin.ignore();
    getline(cin, text);

    string en = encrypt(text);
    cout << "Encrypted String: " << en << endl;

    string dec = decrypt(en);
    cout << "Decrypted String: " << dec << endl;

    return 0;
}
