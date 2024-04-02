  /* Y-Quynh Nguyen & Daichi Malbranche */

%{
#include <stdio.h>
#include <stdlib.h>
#include "table_of_symbols.h"

struct SymbolTable mySymbolsTable;
%}

%code provides {
  int yylex (void);
  void yyerror (const char *);
}

%union {int nb;char* var;}

%token tADD tSUB tMUL tDIV tLT tGT tNE tEQ tGE tLE tASSIGN tAND tOR tNOT tLBRACE tRBRACE tLPAR tRPAR tSEMI tCOMMA tIF tELSE tWHILE  tPRINT tRETURN tINT tVOID tMAIN tERROR
%token <nb> tNB
%token <var> tID
%type <nb> add_sub div_mul single_value

%start program


%%

program:
  %empty                                                                           { printf("program: empty\n\n"); }
  |main_function                                                                  { printf("program: main\n\n"); }
  /*|function_list main_function                                                     { printf("program: main and functions\n\n"); }*/
;




/*function_list:
  function                                                                        { printf("function_list: a function\n\n"); }
  |function_list function                                                         { printf("function_list: functions\n\n"); }

;

function:
  function_type tID tLPAR parameter_list tRPAR tLBRACE body tRBRACE           	{ printf("function: %s\n\n", $2); }
;*/




main_function: 
  function_type tMAIN tLPAR parameter_list tRPAR tLBRACE body tRBRACE           	{ printf("main function\n\n"); }
;
       
function_type:
  tVOID                                                                           { printf("function type: void\n\n"); }
  |tINT                                                                           { printf("function type: int\n\n"); }
;

parameter_list:
  %empty                                                                          { printf("parameter_list: empty\n\n"); }
  |tVOID                                                                          { printf("parameter_list: void\n\n"); }
  |parameter                                                                      { printf("parameter_list: with a parameter\n\n"); }
  |parameter_list tCOMMA parameter                                                { printf("parameter_list: with several parameters\n\n"); }
;

parameter:
  parameter_type tID                                                              { printf("parameter: id '%s'\n\n", $2); }
  |parameter_type tID tASSIGN equality_expression                                 { printf("parameter and initialization: id '%s'\n\n", $2); }
;

parameter_type:
  tINT                                                                             { printf("parameter_type: int\n\n"); }
;



body:
  %empty                                                                            { printf("body: empty\n\n"); }
  |declaration_list                                                                 { printf("body: declaration_list\n\n"); }
  
  |instruction_list                                                                 
  { 
    printf("\t\t\t\tNOP\n\n");   

    printf("body: instruction_list\n\n"); }
  
  |declaration_list instruction_list                                                { printf("body: declaration&instruction list\n\n"); }
;


instruction_list:
  instruction                                                                       { printf("an instruction\n\n"); }
  |instruction_list instruction                                                     { printf("several instructions\n\n"); }
;


declaration_list:
  declaration                                                                      { printf("a declaration\n\n"); }
  |declaration_list declaration                                                    { printf("several declarations\n\n"); }
;


declaration:
  declaration_type identifiers_list tSEMI                                           { printf("declaration\n\n"); }
;


declaration_type:
  tINT                                                                             { printf("declaration_type: int\n\n"); }
;

identifiers_list:

  tID                                                                             
  { mySymbolsTable = add_symb(mySymbolsTable, $1); 
    printf("identifier: '%s'\n\n", $1); }

  |tID tASSIGN add_sub /*equality_expression */                                                
  { mySymbolsTable = add_symb(mySymbolsTable, $1); 

    int address_nb = get_symb(mySymbolsTable,$1);
    printf("\t\t\t\tCOP %d %d\n\n", address_nb, $3);   
    mySymbolsTable = free_tmp(mySymbolsTable);
    printf("declaration and initialization: '%s'\n\n", $1); }


  |identifiers_list tCOMMA tID                                                   
  { mySymbolsTable = add_symb(mySymbolsTable, $3); 
    printf("several identifiers: '%s'\n\n", $3); }
    
  |identifiers_list tCOMMA tID tASSIGN add_sub /*equality_expression */                      
  { mySymbolsTable = add_symb(mySymbolsTable, $3); 

    int address_nb = get_symb(mySymbolsTable,$3);
    printf("\t\t\t\tCOP %d %d\n\n", address_nb, $5);   
    
    printf("several identifiers: '%s'\n\n", $3); }
;




instruction:
   assignment_list                                                                { printf("instruction: assignment\n\n"); }
  |ifblock                                                                        { printf("instruction: if block\n\n"); }
  |whileblock                                                                     { printf("instruction: while block\n\n"); }
  |printblock                                                                     { printf("instruction: print block\n\n"); }
;


assignment_list:
  tID tASSIGN add_sub tSEMI                                           
  { get_symb(mySymbolsTable,$1);
    int address_nb = get_symb(mySymbolsTable,$1);
    printf("\t\t\t\tCOP %d %d\n\n", address_nb, $3);   
    mySymbolsTable = free_tmp(mySymbolsTable);
    printf("assignment: '%s'\n\n", $1); }

  |tID tASSIGN add_sub tCOMMA assignment_list
  { get_symb(mySymbolsTable,$1);
    int address_nb = get_symb(mySymbolsTable,$1);
    printf("\t\t\t\tCOP %d %d\n\n", address_nb, $3);   
    mySymbolsTable = free_tmp(mySymbolsTable);
    printf("assignment: '%s'\n\n", $1); }




ifblock:
	  tIF tLPAR condition tRPAR tLBRACE body tRBRACE                               { printf("if block: if\n\n"); }
	| tIF tLPAR condition tRPAR tLBRACE body tRBRACE tELSE tLBRACE body tRBRACE    { printf("if block: if else \n\n"); }
	| tIF tLPAR condition tRPAR tLBRACE body tRBRACE tELSE ifblock                 { printf("if block: if else if\n\n"); }
;

whileblock:
	tWHILE tLPAR condition tRPAR tLBRACE body tRBRACE                              { printf("while block\n\n"); }         
;

printblock:
	tPRINT tLPAR tID tRPAR tSEMI	                                                 { printf("print block: '%s'\n\n", $3); }      
;



condition:
	  tLPAR equality_expression tRPAR                                               { printf("condition\n\n"); }   
	| condition tAND condition                                                      { printf("condition: and\n\n"); }   
	| condition tOR condition                                                       { printf("condition: or\n\n"); }   
	| tNOT condition                                                                { printf("condition: not\n\n"); }   
;


equality_expression : 
  compare                                                                         { printf("equality_expression: compare\n\n"); }   
  | equality_expression tEQ compare                                               { printf("equality_expression: equal\n\n"); }   
  | equality_expression tNE compare                                               { printf("equality_expression: not equal\n\n"); }   
;



compare:
	  add_sub                                                                       { printf("compare: add_sub\n\n"); }   
	| compare tLT add_sub                                                           { printf("compare: less than\n\n"); }   
	| compare tGT add_sub                                                           { printf("compare: greater than\n\n"); }   
	| compare tLE add_sub                                                           { printf("compare: less or equal\n\n"); }   
	| compare tGE add_sub                                                           { printf("compare: greater or equal\n\n"); }   
;




add_sub:
   div_mul                                                                       { printf("add_sub: div_mul\n\n"); }   
	| add_sub tADD div_mul                                                          { printf("add_sub: addition\n\n"); }   
	| add_sub tSUB div_mul                                                          { printf("add_sub: substraction\n\n"); }         
;




div_mul:
  single_value                                                                           
  { //we add a tmp to ST
    mySymbolsTable = add_tmp(mySymbolsTable); 

    //we assign the value of @single_value to the @tmp
    int address_nb = get_last_tmp(mySymbolsTable);
    printf("\t\t\t\tCOP %d %d\n\n", address_nb, $1);  

    //we return the @tmp with the new value
    $$ = address_nb;
    printf("div_mul: single_value %d\n\n", $1); } 

  | div_mul tMUL single_value                                                             
  { //we assign the value of @single_value * @div_mul to @div_mul
    printf("\t\t\t\tMUL %d %d %d\n\n", $1, $1, $3);  

    //we free the tmp @single_value
    mySymbolsTable = free_tmp(mySymbolsTable);
    $$ = $1;
    printf("div_mul: multiplication\n\n"); } 

	| div_mul tDIV single_value                                                             
  { //we assign the value of @single_value / @div_mul to @div_mul
    printf("\t\t\t\tDIV %d %d %d\n\n", $1, $1, $3);   

    //we free the tmp @single_value
    mySymbolsTable = free_tmp(mySymbolsTable);
    $$ = $1;
    printf("div_mul: division\n\n"); } 
;



single_value:
    tID                                                                           
  { //we return the @ID
    $$ = get_symb(mySymbolsTable,$1);
    printf("single_value: identifier '%s'\n\n", $1); } 

	| tNB                                                                           
  { //we add a tmp to ST
    mySymbolsTable = add_tmp(mySymbolsTable);

    //we assign the value to the @NB
    int address_nb = get_last_tmp(mySymbolsTable);
    printf("\t\t\t\tAFC %d %d\n\n", address_nb, $1);   

    //we return the @NB
    $$ = address_nb;
    printf("single_value: number '%d'\n\n", $1); } 
;




%%

void yyerror(const char *msg) {
  fprintf(stderr, "error: %s\n", msg);
  exit(1);
}

int main(void) {
  mySymbolsTable = initialize_table(mySymbolsTable);
  yyparse();
  return 0;
}


