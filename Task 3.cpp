#include <bits/stdc++.h>
using namespace std;

class ProgramCounter {
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
    vector<int> memoryData;
public:
    void loadMemory(string filename){
        ifstream file(filename);
        if(file.is_open()){
            int data;
            while(!file.eof()){
                file>>hex>>data;
                memoryData.push_back(data);
            }
            file.close();
        }
        else
            cout<<"Unable to open file: "<<filename<<endl;
    }
    int readMemory(int address){
        return memoryData[address];
    }
    void writeMemory(int address, int data){
        memoryData[address]=data;
    }
};
class Register {
private:
    int registerData;
public:
    int readRegister() {
        return registerData;
    }

    void writeRegister(int data) {
        registerData = data;
    }
};
class Machine {
    ProgramCounter PC;
    Memory memory;
    Register registers;
public :
    void DisplayPC(){
        cout<<"the content of the PC is : "<<PC.getAddress()<< endl;
    }
    void DisplayRegisters(){
        int data=registers.readRegister();
        cout<<"the content of the Register is : "<<data<<endl;
    }
    void DisplayMemory(int address){
        int data=memory.readMemory(address);
        cout<<"the content of the Memory is : "<<data << endl;
    }
    virtual void executeInstructions() = 0;
};

class ALU : public Machine {
private:
    vector<string> instructions;
public:
    void loadInstructions(string filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file " ;
            return;
        }
        string hexa;
        string newhexa;
        while (file >> hexa) {
            hexa = hexa.substr(2);
            newhexa += hexa;
        }

        for (int i = 0; i < newhexa.size(); i += 4) {
            instructions.push_back(newhexa.substr(i, 4));
        }
    }
    void executeInstructions()  {
        for (int i = 0; i < instructions.size(); i++){
            string x=instructions[i];
            if (x[0]=='1'){


            }else if (x[0]=='2'){


            }else if (x[0]=='3'){


            }else if (x[0]=='4'){


            }else if (x[0]=='5'){


            }else if (x[0]=='6'){


            }else if (x[0]=='B'){


            }else if (x[0]=='C'){

            }
        }
    }
};



