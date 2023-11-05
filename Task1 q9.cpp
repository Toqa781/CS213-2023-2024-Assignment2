// File:Task1 question 9.cpp
// Purpose:find if i can win the game with 42 bears with numbers of bears given to me 
// Author:Toqa Abdalla Ahmed
// Section:s7,8
// ID:20220093
// TA:Khaled Ibrahim
// Date: 5 Nov 2023
#include <bits/stdc++.h>
using namespace std;
bool bears(int n){
    if(n==42)
        return true;
    if(n<42)
        return false;
    if(n%2==0 && bears(n/2))
        return true;
    int x=(n%100)/10;
    int y=n%10;
    if((n%3==0 || n%4==0)&& bears(n-x*y)){
        return true;
    }
    if(n%5==0&& bears(n-42)){
        return true;
    }
    return false;
}
int main() {
    int n;
    cout<<"Enter the numbers of bears: ";
    cin>>n;
    if(bears(n)){
        cout<<"You can win the game with "<<n<<" bears"<<endl;
    }
    else
        cout<<"You can't win the game with "<<n<<" bears"<<endl;

    return 0;
}
