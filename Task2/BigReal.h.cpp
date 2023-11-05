// File:BigReal.h.cpp
// Purpose:A header for a class BigReal
// Author:Toqa Abdalla Ahmed, Mai Hassan Awad, Farah Mohamed Magdy
// Section:s7,8
// ID:20220093,20221172,20220453
// TA:Khaled Ibrahim
// Date: 5 Nov 2023

#ifndef BIGREAL_H
#define BIGREAL_H
#include <bits/stdc++.h>
using namespace std;

class BigReal{
private:
    string value;
    bool isValidReal(string realNumber);

public:
    BigReal(double realNumber );
    BigReal(string realNumber);
    BigReal(BigReal& other);
    BigReal& operator=(BigReal& other);

    void setNum(string& realNumber);
    int size() const;
    int sign() const;

    BigReal operator+(BigReal& other);
    BigReal operator-(BigReal& other);
    bool operator<(BigReal& anotherReal);
    bool operator>(BigReal& anotherReal);
    bool operator==(BigReal& anotherReal);

    friend ostream& operator<<(ostream& out,BigReal& num);


};
#endif
