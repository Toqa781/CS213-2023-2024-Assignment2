#include <bits/stdc++.h>
using namespace std;

vector<string>split(string target,char delimiter){
    vector<string>result;
    string token;
    for(int i=0;i<target.length();i++){
        if(target[i] !=delimiter){
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
    vector<string> substrings = split("10,20,30",',');

    for (int i=0;i<substrings.size();i++) {
        cout << substrings[i] <<endl;
    }

    return 0;
}
