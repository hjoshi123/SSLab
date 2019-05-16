%{
#include<stdio.h>
int cvowel = 0,cconsonant = 0,cnumber = 0,cline = 0,cspecial = 0;
%}

%%
[ ] ;
[aeiouAEIOU] {cvowel++;}
[a-zA-Z] {cconsonant++;}
[0-9] {cnumber++;}
. {cspecial++;}
\n {cline++;}
%%

int yywrap() {
    return 1;
}

int main() {
    yyin=fopen("input.txt","r");
    yylex();
    printf("Number of vowels are %d \n Number of consonants are %d \n Number of numbers are %d \n Number of special are %d \n Number of lines are %d \n", cvowel, cconsonant, cnumber, cspecial, cline);
    return 0;
}