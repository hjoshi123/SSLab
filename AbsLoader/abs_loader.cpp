#include<iostream>
#include<fstream>
#include<stdlib.h> 
using namespace std;

int main(){
    ifstream input("input.txt");
    ofstream out("output.txt");
    string x;
    int address;
    input >> x;
    if(x=="H"){
        input >> x >> x >> x >>x;
    }
    while(x!="E"){

            if(x=="T"){
              input >> x;
              address = stoi(x,nullptr,16);
              input >> x >> x;

            while(!(x=="T" || x=="E")){
                out<< hex << address << " " << x[0] << x[1] << endl;
                out<< hex << address + 1 << " " << x[2] << x[3] << endl;
                out<< hex << address + 2 << " " << x[4] << x[5] << endl;
                address += x.length()/2;
                input >> x;
            }
        }
    }
    return 0;
}