#include <bits/stdc++.h>
#include"BigReal.h"
using namespace std;
int main(){
    BigReal r1("+3.3.3");
    BigReal r2("-22");

    cout<<r1.sign() <<" "<<r2.sign();

}
