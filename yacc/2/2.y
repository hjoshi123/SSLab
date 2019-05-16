%{
  #include<stdlib.h>
  #include<stdio.h>
%}

%token DIGIT LETTER UND NL

%%
stmt : var NL {printf ("Valid expression\n"); exit(0);}
;

var : LETTER alpha
;

alpha : LETTER alpha
|DIGIT alpha
|UND alpha
|LETTER
|DIGIT
|UND
;
%%

int yyerror(char *msg) {
    printf ("Invalid\n");
    exit(0);
}

int main() {
    yyparse();
    return 0;
}