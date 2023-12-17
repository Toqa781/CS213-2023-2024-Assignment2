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

    // testing isvalid
    BigReal x1("+1.1.1"), x2("+0.000222200265") , x3("-0.3000015686"), x4("+49.89x"); ;
    cout<< x1 <<'\n'<< x2 <<'\n'<< x3 <<'\n'<< x4 <<endl;

    //testing + and - operators
    BigReal r1("+11900000.0004568479401");
    BigReal r2("+2333333333339.1134322222222292");
    BigReal r4 = r1 + r2;
    BigReal r5 = r1 - r2;
    cout<<"first number is: "<< r1<<endl;
    cout<< "second number is: "<< r2 <<endl;
    cout<< "r1 + r2 = " << r4 <<endl ;
    cout<< "r1 - r2 = " << r5 <<endl ;

    //testing < and > operators
    BigReal b1("-9999999.6666555555555559");
    BigReal b2("-9999999.15698746235");
    BigReal b3("+1111596.666655559");
    BigReal b4("+8965187.666655559");

        cout<< (b1 < b2)<<endl; //true
        cout<< (b1 > b3)<<endl; //false
        cout<<(b4 > b3)<<endl; //true
        cout<<(b3 > b4)<<endl; //false
        cout<< (b2 < b4)<<endl; //true

    //testing == operator
    BigReal y1("0.95"), y2("0.95");

    cout<<(y1 ==  y2)<<endl; //true


    return 0;
}
