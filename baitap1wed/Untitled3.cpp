// columnar.cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> keyOrder(const string &key){
    int n = key.size();
    vector<pair<char,int>> v;
    for(int i=0;i<n;i++) v.push_back({key[i], i});
    sort(v.begin(), v.end());
    vector<int> order(n);
    for(int i=0;i<n;i++) order[v[i].second] = i;
    return order; // order[i] = rank of column i (0..n-1)
}

string encrypt(const string &pt, const string &key){
    string t;
    for(char c:pt) if(c!=' ') t.push_back(c); // optionally remove spaces
    int n = key.size();
    int rows = (t.size() + n -1)/n;
    int len = rows*n;
    t.append(len - t.size(), 'X'); // pad with X
    vector<string> grid(rows, string(n,'X'));
    int idx=0;
    for(int r=0;r<rows;r++){
        for(int c=0;c<n;c++){
            grid[r][c] = t[idx++];
        }
    }
    vector<int> ord = keyOrder(key);
    string ct;
    for(int rank=0;rank<n;rank++){
        for(int c=0;c<n;c++){
            if(ord[c]==rank){
                for(int r=0;r<rows;r++) ct.push_back(grid[r][c]);
            }
        }
    }
    return ct;
}

string decrypt(const string &ct, const string &key){
    int n = key.size();
    int rows = (ct.size()+n-1)/n;
    vector<int> ord = keyOrder(key);
    // number of chars in each column = rows (assuming padded)
    vector<int> colLen(n, rows);
    vector<string> cols(n);
    int idx=0;
    for(int rank=0;rank<n;rank++){
        for(int c=0;c<n;c++){
            if(ord[c]==rank){
                cols[c] = ct.substr(idx, colLen[c]);
                idx += colLen[c];
            }
        }
    }
    string pt;
    for(int r=0;r<rows;r++){
        for(int c=0;c<n;c++){
            if(r < (int)cols[c].size()) pt.push_back(cols[c][r]);
        }
    }
    return pt;
}

int main(){
    string pt,key;
    cout<<"Plaintext: "; getline(cin,pt);
    cout<<"Key: "; getline(cin,key);
    string ct = encrypt(pt,key);
    cout<<"Ciphertext: "<<ct<<"\n";
    cout<<"Decrypted: "<<decrypt(ct,key)<<"\n";
    return 0;
}
