#include <bits/stdc++.h>
using namespace std;

class BigReal{
private:
   double value;
   bool isValidReal(string& realNumber);

public:
    BigReal(double realNumber=0.0);
    BigReal(string& realNumber);
    BigReal(BigReal& other);

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
 bool BigReal::isValidReal(string &realNumber) {
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
 BigReal::BigReal(double realNumber):value(realNumber) {}
 BigReal::BigReal(string &realNumber) {
     if(isValidReal(realNumber)){
         value= stod(realNumber);
     }
     else
         value=0.0;
 }
 BigReal::BigReal(BigReal &other) :value(other.value){}

 void BigReal::setNum(string &realNumber) {
     if(isValidReal(realNumber)){
         value= stod(realNumber);
     }
     else
         value=0.0;
 }
 int BigReal::size() const {
        string numString= to_string(abs(value));
        int decimalPointPosition=numString.find('.');
        if(decimalPointPosition!=-1){
            return (numString.size())-1;
        }
        else
            return (numString.size());
 }
 int BigReal::sign() const {
     if(value<0)return -1;
     else if(value>0)return 1;
     else return 0;
 }

bool BigReal::operator==(BigReal &anotherReal) {
    return value==anotherReal.value;
 }
 ostream& operator<<(ostream& out,BigReal& num){
     out<<num.value;
     return out;
 }
 int main(){
     
 }
