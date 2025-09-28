// playfair.cpp
#include <bits/stdc++.h>
using namespace std;

string prepare_key(string key){
    string s;
    vector<bool> seen(26,false);
    for(char ch:key){
        if(!isalpha(ch)) continue;
        char c = toupper(ch);
        if(c=='J') c='I';
        if(!seen[c-'A']) { s.push_back(c); seen[c-'A']=true; }
    }
    for(char c='A'; c<='Z'; ++c){
        if(c=='J') continue;
        if(!seen[c-'A']) { s.push_back(c); seen[c-'A']=true; }
    }
    return s; // length 25
}

pair<vector<vector<char>>, unordered_map<char,pair<int,int>>> build_table(string key){
    string s = prepare_key(key);
    vector<vector<char>> table(5, vector<char>(5));
    unordered_map<char,pair<int,int>> pos;
    int idx=0;
    for(int r=0;r<5;r++){
        for(int c=0;c<5;c++){
            char ch = s[idx++];
            table[r][c] = ch;
            pos[ch] = {r,c};
        }
    }
    return {table,pos};
}

vector<pair<char,char>> make_pairs(string pt){
    string s;
    for(char ch:pt) if(isalpha(ch)) { char c=toupper(ch); if(c=='J') c='I'; s.push_back(c); }
    vector<pair<char,char>> pairs;
    for(size_t i=0;i<s.size();){
        char a = s[i];
        char b = (i+1 < s.size())? s[i+1] : '\0';
        if(b==0 || a==b){
            pairs.push_back({a,'X'});
            i += (a==b)?1:1;
            if(a==b) i = i; // next loop will use next char (already advanced by 1)
        } else {
            pairs.push_back({a,b});
            i += 2;
        }
    }
    if(!pairs.empty()){
        auto &last = pairs.back();
        if(last.second == '\0') last.second = 'X';
    }
    return pairs;
}

string playfair_encrypt(const string &pt, const string &key){
    auto t = build_table(key);
    auto table = t.first; auto pos = t.second;
    auto pairs = make_pairs(pt);
    string ct;
    for(auto pr: pairs){
        char A = pr.first, B = pr.second;
        auto pa = pos[A], pb = pos[B];
        if(pa.first == pb.first){ // same row
            int r = pa.first;
            ct.push_back(table[r][(pa.second+1)%5]);
            ct.push_back(table[r][(pb.second+1)%5]);
        } else if(pa.second == pb.second){ // same column
            int c = pa.second;
            ct.push_back(table[(pa.first+1)%5][c]);
            ct.push_back(table[(pb.first+1)%5][c]);
        } else {
            ct.push_back(table[pa.first][pb.second]);
            ct.push_back(table[pb.first][pa.second]);
        }
    }
    return ct;
}

string playfair_decrypt(const string &ct, const string &key){
    auto t = build_table(key);
    auto table = t.first; auto pos = t.second;
    // assume ct length even
    string pt;
    for(size_t i=0;i<ct.size(); i+=2){
        char A = toupper(ct[i]), B = toupper(ct[i+1]);
        if(A=='J') A='I'; if(B=='J') B='I';
        auto pa = pos[A], pb = pos[B];
        if(pa.first == pb.first){
            int r = pa.first;
            pt.push_back(table[r][(pa.second+5-1)%5]);
            pt.push_back(table[r][(pb.second+5-1)%5]);
        } else if(pa.second == pb.second){
            int c = pa.second;
            pt.push_back(table[(pa.first+5-1)%5][c]);
            pt.push_back(table[(pb.first+5-1)%5][c]);
        } else {
            pt.push_back(table[pa.first][pb.second]);
            pt.push_back(table[pb.first][pa.second]);
        }
    }
    return pt;
}

int main(){
    string pt,key;
    cout<<"Key: "; getline(cin,key);
    cout<<"Plaintext: "; getline(cin,pt);
    string ct = playfair_encrypt(pt,key);
    cout<<"Ciphertext: "<<ct<<"\n";
    cout<<"Decrypted: "<<playfair_decrypt(ct,key)<<"\n";
    return 0;
}
