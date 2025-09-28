// affine.cpp
#include <bits/stdc++.h>
using namespace std;

int egcd(int a,int b){ if(b==0) return a; return egcd(b, a%b); }
int modinv(int a,int m){
    a = (a%m + m) % m;
    for(int x=1;x<m;x++) if((a*x)%m==1) return x;
    return -1;
}

string affine_encrypt(const string &pt,int a,int b){
    string res=pt;
    for(size_t i=0;i<res.size();++i){
        char c=res[i];
        if(isalpha(c)){
            char base = isupper(c)?'A':'a';
            int x = c - base;
            res[i] = char(base + (a*x + b) % 26);
        }
    }
    return res;
}

string affine_decrypt(const string &ct,int a,int b){
    int inv = modinv(a,26);
    if(inv==-1) return "[a has no inverse mod26]";
    string res=ct;
    for(size_t i=0;i<res.size();++i){
        char c=res[i];
        if(isalpha(c)){
            char base = isupper(c)?'A':'a';
            int y = c - base;
            int x = (inv * ( (y - b + 26) %26 )) %26;
            res[i] = char(base + x);
        }
    }
    return res;
}

int main(){
    string s; cout<<"Plaintext: "; getline(cin,s);
    int a,b; cout<<"a (must be coprime with 26): "; cin>>a;
    cout<<"b: "; cin>>b;
    cout<<"Cipher: "<<affine_encrypt(s,a,b)<<"\n";
    cout<<"Decrypted: "<<affine_decrypt(affine_encrypt(s,a,b),a,b)<<"\n";
}
