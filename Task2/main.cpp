// File:BigReal.h.cpp
// Purpose:The main function
// Author:Toqa Abdalla Ahmed, Mai Hassan Awad, Farah Mohamed Magdy
// Section:s7,8
// ID:20220093,20221172,20220453
// TA:Khaled Ibrahim
// Date: 5 Nov 2023
#include <bits/stdc++.h>
#include"BigReal.h"
using namespace std;
int main(){
    BigReal r1("+3.3.3");
    BigReal r2("-22");

    cout<<r1.sign() <<" "<<r2.sign();

}
