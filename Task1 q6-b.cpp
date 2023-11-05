// File:Task1 question 6)b).cpp
// Purpose:print the prefix followed by the all combinations of the suffix of k digits
// Author:Toqa Abdalla Ahmed
// Section:s7,8
// ID:20220093
// TA:Khaled Ibrahim
// Date: 5 Nov 2023
#include <bits/stdc++.h>
using namespace std;
 void number(string prefix,int k){
     if(k==0){
         cout<<prefix<<endl;
     }
     else{
         number(prefix+"0",k-1);
         number(prefix+"1",k-1);
     }
 }
int main() {
    number("00101",2);

    return 0;
}
