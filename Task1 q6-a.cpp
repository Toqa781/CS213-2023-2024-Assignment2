// File:Task1 question 6)a).cpp
// Purpose: print the Binary number for a decimal number
// Author:Toqa Abdalla Ahmed
// Section:s7,8
// ID:20220093
// TA:Khaled Ibrahim
// Date: 5 Nov 2023
#include <bits/stdc++.h>
using namespace std;

void binaryPrint(int n) {
    if (n > 1) {
        binaryPrint(n / 2);
    }
   cout << n % 2;
}

int main() {
   cout << "output:";
    binaryPrint(27);


    return 0;
}
