#include<bits/stdc++.h>
using namespace std;
class ProgramCounter{
private:
    int address;

public:
    ProgramCounter() : address(0) {}

    void increment() {
        address++;
    }

    void jump(int newAddress) {
        address = newAddress;
    }

    int getAddress() {
        return address;
    }

};

class Memory{
private:
    vector<string>memoryData;
public:
    void loadMemory(string filename){
        ifstream file(filename);
        if(file.is_open()){
            string data;
            while(!file.eof()){
                file>>hex>>data;
                memoryData.push_back(data.substr(0,2));
                memoryData.push_back(data.substr(2,2));
            }
            file.close();
        }
        else
            cout<<"Unable to open file: "<<filename<<endl;
    }
    string readMemory(int address){
        return memoryData[address];
    }
    void writeMemory(int address,string data){
        memoryData[address]=data;
    }

};
class Register{
private:
    vector<string>registerData;
public:
    string readRegister(int address){
        return registerData[address];
    }
    void writeRegister(int address,string data){
        registerData[address]=data;
    }

};
class Machine{
public:
    Memory memory;
    ProgramCounter PC;
    Register registers;
    void DisplayPC(){
        cout<<"The content of the PC is: "<<PC.getAddress()<<endl;
    }
    void DisplayRegisters(int address){
        cout<<"The content of the Register is: "<<registers.readRegister(address)<<endl;
    }
    void DisplayMemory(int address){
        cout<<"The content of the memory is :"<<memory.readMemory(address)<<endl;
    }
    virtual void executeInstructions() = 0;
};


class ALU: public Machine{
    vector<string> instructions;
public:
    void loadInstructions(string filename){
        ifstream file(filename);
        if(!file.is_open()){
            cout<<"Error opening file"<<endl;
            return;
        }
        string hexa;
        string newHexa;
        while(file>>hexa){
            hexa=hexa.substr(2);
            newHexa+=hexa;
        }
        for(int i=0;i<newHexa.size();i+=4){
            instructions.push_back(newHexa.substr(i,4));
        }
    }
    void executeInstructions() {
        for (int i = 0; i < instructions.size(); i++) {
            string x = instructions[i];
            int dec_val = 0;
            int R = 0;
            int S = 0;
            int T = 0;
            if (x[0] == '1') {
                // converting the last two characters from hexadecimal to decimal
                if (x[3] >= '0' && x[3] <= '9') {
                    dec_val = x[3] - '0';
                } else if (x[3] >= 'A' && x[3] <= 'F') {
                    dec_val = (int(x[3]) - 55);
                }
                if (x[2] >= '0' && x[2] <= '9') {
                    dec_val += (x[2] - '0') * 16;

                } else if (x[2] >= 'A' && x[2] <= 'F') {
                    dec_val += (int(x[2]) - 55) * 16;
                }
                if (x[1] >= '0' && x[1] <= '9') {
                    R = x[1] - '0';
                } else if (x[1] >= 'A' && x[1] <= 'F') {
                    R = (int(x[1]) - 55);
                }
                //loading data from a specific memory address into a specific register
                int address = dec_val;
                string datafrommemory = memory.readMemory(address);
                registers.writeRegister(R, datafrommemory);

            } else if (x[0] == '2') {


            } else if (x[0] == '3') {

            } else if (x[0] == '4') {
                    if(x[2]>='0'&& x[2]<='9'){
                        R=int(x[2]);
                    }
                    else if(x[2]>='A'&& x[2]<='F'){
                        R=(int(x[2])-55);
                    }
                    if(x[3]>='0'&&x[3]<='9'){
                        S=int(x[3]);
                    }
                    else if(x[3]>='A'&& x[3]<='F'){
                        S=(int(x[3])-55);
                    }
                    registers.registerData[S]=registers.registerData[R];
                    registers.registerData[R].clear();

            } else if (x[0] == '5') {
                // converting the last 3 characters from hexadecimal to decimal
                if (x[1] >= '0' && x[1] <= '9') {
                    R = x[1] - '0';
                } else if (x[1] >= 'A' && x[1] <= 'F') {
                    R = (int(x[1]) - 55);
                }
                if (x[2] >= '0' && x[2] <= '9') {
                    S = (x[2] - '0');

                } else if (x[2] >= 'A' && x[2] <= 'F') {
                    S = (int(x[2]) - 55);
                }
                if (x[3] >= '0' && x[3] <= '9') {
                    T = x[3] - '0';
                } else if (x[3] >= 'A' && x[3] <= 'F') {
                    T = (int(x[3]) - 55);
                }

                //Adding the data in registers S and T then storing the sum in register R
                string datafromS =  registers.readRegister(S) ;
                string datafromT =  registers.readRegister(T) ;

                //converting data inside registers S and T from hex to decimal
                int dec1 = stoi(datafromS, nullptr, 16);
                int dec2 = stoi(datafromT, nullptr, 16);

                // add the two numbers
                int sum = dec1 + dec2;

                //convert the sum from decimal to hex
                string hex = "";
                for (int i = 0; i < 2; i++) {
                    int remainder = sum % 16;
                    if (remainder <= 9) {
                        hex = char(remainder + '0') + hex;
                    } else {
                        hex = char(remainder + 55)  + hex;
                    }
                    sum = sum / 16;
                }

                //store the sum in register R
                registers.writeRegister(R,hex);

            } else if (x[0] == 'B') {


            } else if (x[0] == 'C') {
                return;

            }
        }
    }
};
int main() {

    return 0;
}
