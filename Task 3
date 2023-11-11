#include <bits/stdc++.h>
using namespace std;
class Machine{
    vector<int> instructions;
public :
    void menu(){
    cout<<"1.Load Program.\n"
          "2.Display the PC.\n"
          "3.Display the IR.\n"
          "4.Display the registers.\n"
          "5.Display the memory.\n"
          "6.Display the screen.\n"
          "7.Quit.\n";
    }
    void loadProgram(string fileN) {
        ifstream file(fileN);
        if (file.is_open()) {
            while (!file.eof()) {
                int instruction;
                file >> hex >> instruction;
                instructions.push_back(instruction);
            }
            file.close();
        } else {
            cout << "Unable to open file: " << fileN << endl;
        }

    }
    void DisplayPC(int pc){
    cout<<"the content of the PC is : "<<pc;
    }
    void DisplayRegisters(int r){
        cout<<"the content of the Register is : "<<r;
    }
    void DisplayMemory(int memo){
        cout<<"the content of the Memory is : "<<memo;
    }
    void DisplayScreen(){

    }
};

class ALU {
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
    void executeInstructions(){
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
