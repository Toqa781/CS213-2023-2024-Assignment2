// File:BigReal.h.cpp
// Purpose:The implementation of class BigReal
// Author:Toqa Abdalla Ahmed, Mai Hassan Awad, Farah
// Section:s7,8
// ID:20220093,20221172,20220453
// TA:Khaled Ibrahim
// Date: 5 Nov 2023
#include <bits/stdc++.h>
#include "BigReal.h"
using namespace std;
bool BigReal::isValidReal(string realNumber) {
    if(realNumber.empty()){
        return false;
    }
    int decimalPointCount=0;
    for(int i=0;i<realNumber.size();i++){
        if(!isdigit(realNumber[i])&& realNumber[i]!='.'
           && realNumber[i]!='+'&& realNumber[i]!='-')
            return false;
        if(realNumber[i]=='.'){
            decimalPointCount++;
        }
        if(decimalPointCount>1)
            return false;
    }

    return true;
}
BigReal::BigReal(double realNumber ) {

    value = to_string(realNumber);
    if(!isValidReal(value)){
        value = "0.0";
    }
}
BigReal::BigReal(string realNumber) {
    if(isValidReal(realNumber)){
        value=realNumber;
    }
    else
        value="0.0";
}

BigReal::BigReal(BigReal &other) :value(other.value){}
BigReal& BigReal::operator=(BigReal& other){
    if (this != &other) {
        value = other.value;
    }
    return *this;
}
void BigReal::setNum(string &realNumber) {
    if(isValidReal(realNumber)){
        value= realNumber;
    }
    else
        value="0.0";
}
int BigReal::size() const {

    int decimalPointPosition = value.find('.');
    if (decimalPointPosition != -1) {
        return (value.size()) - 1;
    } else
        return (value.size());

}
int BigReal::sign() const {
    if(value[0] == '-'){
        return -1;
    }
    else if(value[0] == '+'){
        return +1;
    }
    else return 0;
}

bool BigReal::operator==(BigReal &anotherReal) {
    return value==anotherReal.value;
}
ostream& operator<<(ostream& out,BigReal& num){
    out<<num.value;
    return out;
}
BigReal BigReal:: operator+( BigReal& other) {
    BigReal r(stod(this->value) + stod(other.value));

    return r;
}
BigReal BigReal:: operator-( BigReal& other) {
    BigReal r(stod(this->value) - stod(other.value));

    return r;
}

bool BigReal::operator> (BigReal& other) {

    return stod(this->value) > stod(other.value);
}

bool BigReal::operator< (BigReal& other) {

    return stod(this->value) < stod(other.value);
}

