#include<iostream>
#include<string>
using namespace std;

int str_length(string st){
    int len = st.length();

    return len;
}

string str_reverse(string st){
    int n = str_length(st);
    for (int i = 0; i < n / 2; i++){
        swap(st[i], st[n - i - 1]);
    }

    return st;
}

string str_concat(string st1,string st2){
    string s = st1 + " " + st2;
    return s;
}