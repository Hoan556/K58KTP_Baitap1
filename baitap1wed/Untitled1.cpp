// caesar.cpp
#include <bits/stdc++.h>
using namespace std;

string caesar_encrypt(const string &pt, int k) {
    string res = pt;
    k = (k%26 + 26) % 26;
    for (size_t i=0;i<res.size();++i) {
        char c = res[i];
        if (isalpha(c)) {
            char base = isupper(c)?'A':'a';
            res[i] = char(base + (c - base + k) % 26);
        }
    }
    return res;
}

string caesar_decrypt(const string &ct, int k) {
    return caesar_encrypt(ct, -k);
}

int main(){
    string line;
    cout<<"Enter plaintext: ";
    getline(cin, line);
    cout<<"Key (0-25): ";
    int k; cin>>k;
    string ct = caesar_encrypt(line,k);
    cout<<"Ciphertext: "<<ct<<"\n";
    cout<<"Decrypted back: "<<caesar_decrypt(ct,k)<<"\n";
    return 0;
}
