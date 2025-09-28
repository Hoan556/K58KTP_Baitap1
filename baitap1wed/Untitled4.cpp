// vigenere.cpp
#include <bits/stdc++.h>
using namespace std;

string format(const string &s){
    string r;
    for(char c:s) if(isalpha(c)) r.push_back(toupper(c));
    return r;
}

string vigenere_encrypt(const string &pt, const string &key){
    string p = format(pt), k = format(key);
    if(k.empty()) return p;
    string ct;
    for(size_t i=0;i<p.size();++i){
        int pi = p[i]-'A';
        int ki = k[i % k.size()] - 'A';
        ct.push_back(char('A' + (pi + ki) % 26));
    }
    return ct;
}

string vigenere_decrypt(const string &ct, const string &key){
    string k = format(key);
    if(k.empty()) return ct;
    string pt;
    for(size_t i=0;i<ct.size();++i){
        int ci = ct[i] - 'A';
        int ki = k[i % k.size()] - 'A';
        pt.push_back(char('A' + (ci - ki + 26) % 26));
    }
    return pt;
}

int main(){
    string pt, key;
    cout<<"Plaintext: "; getline(cin, pt);
    cout<<"Key: "; getline(cin, key);
    string ct = vigenere_encrypt(pt, key);
    cout<<"Ciphertext: "<<ct<<"\n";
    cout<<"Decrypted: "<<vigenere_decrypt(ct, key)<<"\n";
}
