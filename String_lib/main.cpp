#include"String_lib.h"
#include<iostream>
using namespace std;

int main(){

    string st,st1,st2;
    cout << "Enter String for length and reversing: ";
    getline(cin,st);

    cout << "Enter 2 strings to concatenate:\n";
    cin >> st1;
    cin >> st2;
    
    int len = STRING_LIB_H::str_length(st);
    string rev = STRING_LIB_H:: str_reverse(st);
    string concat = STRING_LIB_H::str_concat(st1,st2);
    
    cout <<"Original String: "<< st;
    cout << endl <<"Length of String: "<< len;
    cout << endl << "Reversed String: " << rev;
    cout << endl << "Concatenated String: " << concat;

    return 0;
}
