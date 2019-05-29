#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<fstream>

using namespace std;

int main() {
    string label,opcode,operand,newlabel,newoperand,newopcode,macroname,ex;
    int i,lines;
    ifstream input("input.txt");
    ofstream output("output.txt");
    fstream deftab("deftab.txt");

    input>>label>>opcode>>operand;
    while(opcode != "END")
    {
        if(opcode == "MACRO") {
            macroname = label;
            input>>label>>opcode>>operand;
            lines=0;
            while(opcode != "MEND") {
                deftab<<label<<" "<<opcode<<" "<<operand<<endl;
                input>>label>>opcode>>operand;
                lines++;
            }
        }
        else if(opcode == macroname) {
            fstream argtab("argtab.txt");
            if(label != "-")
            output<<label;
            int n = operand.length();
            char arr[n+1];
            strcpy(arr, operand.c_str());
            char * ar = strtok(arr,",");
            while (ar != NULL) {
                argtab<<ar<<endl;
                ar = strtok(NULL, ",");
            }
            argtab.seekg(0,ios::beg);
            deftab.seekg(0,ios::beg);
            argtab>>ex;
            deftab>>newlabel>>newopcode>>newoperand;
            for(i=0;i<lines;i++) {
                if(newoperand[0]=='&') {
                    output<<newlabel<<" "<<newopcode<<" "<<ex<<endl;
                    argtab>>ex;
                    deftab>>newlabel>>newopcode>>newoperand;
                }
                else
                    output<<newlabel<<" "<<newopcode<<" "<<newoperand<<endl;
                deftab>>newlabel>>newopcode>>newoperand;
            }
        }
        else
        output<<label<<" "<<opcode<<" "<<operand<<endl;
        input>>label>>opcode>>operand;
    }
    output<<label<<" "<<opcode<<" "<<operand<<endl;
    return 0;
}