// File:Task1 question 3.cpp
// Purpose: split a string from it's delimiter
// Author:Toqa Abdalla Ahmed
// Section:s7,8
// ID:20220093
// TA:Khaled Ibrahim
// Date: 5 Nov 2023

#include <bits/stdc++.h>
using namespace std;

vector<string>split(string target,string delimiter){
    vector<string>result;
    string token;
    for(int i=0;i<target.length();i++){
        if(target[i] !=delimiter[0]){
            token+=target[i];
        }
        else{
            if(!token.empty()){
                result.push_back(token);
                token.clear();
            }
        }
    }
    if(!token.empty()){
        result.push_back(token);
    }
    return result;
}

int main() {
    string target,delimiter;
    cout<<"Enter the target: ";
    cin>>target;
    cout<<"Enter the delimiter: ";
    cin>>delimiter;
    vector<string> substrings = split(target,delimiter);

    for (int i=0;i<substrings.size();i++) {
        cout << substrings[i] <<endl;
    }

    return 0;
}
