%{
    int pnum = 0, nnum = 0, pf = 0, nf = 0;
%}

%%
[-][0-9]+ {nnum++;}
[+]?[0-9]+ {pnum++;}
[-][0-9]*\.[0-9]+ {nf++;}
[+]?[0-9]*\.[0-9]+ {pf++;}
. {;}
%%

int main() {
    yyin = fopen("input.txt", "r");
    yylex();
    printf ("Positive numbers: %d\n", pnum);
    printf ("Negative numbers: %d\n", nnum);
    printf ("Negative Fractions %d\n", nf);
    printf ("Positive Fractions %d\n", pf);
    return 0;
}