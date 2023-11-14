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
    void executeInstructions(){
        for(int i=0;i<instructions.size();i++){
            string x=instructions[i];
            int dec_val=0;
            int R=0;
            int S=0;
            int T=0;
            if(x[0]=='1'){
                if(x[3]>='0'&&x[3]<='9'){
                    dec_val=x[3]-'0';
                }
                else if(x[3]>='A'&& x[3]<='F'){
                    dec_val=(int(x[3])-55);
                }
                if(x[2]>='0'&& x[2]<=9){
                    dec_val+=(x[2]-'0')*16;
                }
                else if(x[2]>='A'&& x[2]<='F'){
                    dec_val+=(int(x[2])-55)*16;
                }
                if (x[1] >= '0' && x[1] <= '9') {
                    R = x[1] - '0';
                } else if (x[1] >= 'A' && x[1] <= 'F') {
                    R = (int(x[1]) - 55);
                }
                int address=dec_val;
                string dataMemory=memory.readMemory(address);
                registers.writeRegister(R,dataMemory);
            }
        }
    }
};
int main() {
    return 0;
}
