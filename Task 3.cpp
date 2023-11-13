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
    
    int executeInstructions()  {
        for (int i = 0; i < instructions.size(); i++){
           string x=instructions[i];
            int dec_val = 0;
            int R = 0;
            int S = 0;
            int T = 0;
            if(x[0]=='1'){
            // converting the last two characters from hexadecimal to decimal
               if (x[3] >= '0' && x[3] <= '9'){
                   dec_val = x[3]-'0';
               }else if (x[3] >= 'A' && x[3] <= 'F') {
                   dec_val = (int(x[3]) - 55);
               }
               if (x[2] >= '0' && x[2] <= '9') {
                 dec_val+= (x[2] - '0') * 16;

               }else if (x[2] >= 'A' && x[2] <= 'F') {
                  dec_val+= (int(x[2]) - 55) * 16;
               }
               if (x[1] >= '0' && x[1] <= '9'){
                   R = x[1]-'0';
               }else if (x[1] >= 'A' && x[1] <= 'F') {
                   R = (int(x[1]) - 55);
               }
            //loading data from a specific memory address into a specific register
               int address = dec_val;
               int datafrommemory=memory.readMemory(address);
               registers.writeRegister(R, datafrommemory);

            }else if (x[0]=='2'){


            }else if (x[0]=='3'){

            }else if (x[0]=='4'){


            }else if (x[0]=='5'){
               // converting the last 3 characters from hexadecimal to decimal
                if (x[1] >= '0' && x[1] <= '9'){
                   R = x[1]-'0';
               }else if (x[1] >= 'A' && x[1] <= 'F') {
                   R = (int(x[1]) - 55);
               }
               if (x[2] >= '0' && x[2] <= '9') {
                  S = (x[2] - '0');

               }else if (x[2] >= 'A' && x[2] <= 'F') {
                  S = (int(x[2]) - 55);
               }
               if (x[3] >= '0' && x[3] <= '9'){
                   T = x[3]-'0';
               }else if (x[3] >= 'A' && x[3] <= 'F') {
                   T = (int(x[3]) - 55);
               }

            //Adding the data in registers S and T then storing the sum in register R
               int datafromS= registers.readRegister(S);
               int datafromT = registers.readRegister(T);

            //converting data inside registers S and T from hexa to decimal
               int dec1 = stoi(datafromS,nullptr,16);
               int dec2 = stoi(datafromT,nullptr,16);

            // add the two numbers
               int sum = dec1 + dec2;

             //store the sum in register R
               registers.writeRegister(R, sum);

            }else if (x[0]=='6'){


            }else if (x[0]=='B'){


            }else if (x[0]=='C'){
                return 0;

            }
        }
    };



