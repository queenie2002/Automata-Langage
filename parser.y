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

%type <nb> div_mul term


%%

program:
  %empty                                                                           { printf("program: empty\n\n"); }
  |main_function                                                                   { printf("program: main\n\n"); }
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
  |instruction_list                                                                 { printf("body: instruction_list\n\n"); }
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
  parameter_type identifiers_list tSEMI                                           { printf("declaration\n\n"); }
;

identifiers_list:
  tID                                                                             
  { add_symb(mySymbolsTable, $1); 
    printf("identifier: '%s'\n\n", $1); }

  |tID tASSIGN div_mul /*equality_expression */                                                
  { add_symb(mySymbolsTable, $1); 

    int address_nb = get_last_tmp(mySymbolsTable);
    printf("COP %d %d\n\n", address_nb, $3);   
    printf("declaration and initialization: '%s'\n\n", $1); }


  |identifiers_list tCOMMA tID                                                   
  { add_symb(mySymbolsTable, $3); 
    printf("several identifiers: '%s'\n\n", $3); }
    
  |identifiers_list tCOMMA tID tASSIGN div_mul /*equality_expression */                      
  { add_symb(mySymbolsTable, $3); 

    int address_nb = get_last_tmp(mySymbolsTable);
    printf("COP %d %d\n\n", address_nb, $5);   
    
    printf("several identifiers: '%s'\n\n", $3); }
;




instruction:
   assignment_list                                                                { printf("instruction: assignment\n\n"); }
  |ifblock                                                                        { printf("instruction: if block\n\n"); }
  |whileblock                                                                     { printf("instruction: while block\n\n"); }
  |printblock                                                                     { printf("instruction: print block\n\n"); }
;


assignment_list:
  tID tASSIGN equality_expression tSEMI                                           
  { 
     printf("assignment: '%s'\n\n", $1); }
  |tID tASSIGN equality_expression tCOMMA assignment_list





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
   term                                                                           
   { $$ = $1;
    printf("div_mul: term %d\n\n", $1); } 

  | div_mul tMUL term                                                             
  { add_tmp(mySymbolsTable);
    int address_nb = get_last_tmp(mySymbolsTable);
    int res = $1*$3;
    printf("AFC %d %d\n\n", address_nb, res);   
    $$ = address_nb;
    printf("div_mul: multiplication\n\n"); } 

	| div_mul tDIV term                                                             
  { add_tmp(mySymbolsTable);
    int address_nb = get_last_tmp(mySymbolsTable);
    int res = $1/$3;
    printf("AFC %d %d\n\n", address_nb, res);   
    $$ = address_nb;
    printf("div_mul: division\n\n"); } 
;



term:
    tID                                                                           
  { $$ = get_symb(mySymbolsTable,$1);
    printf("term: identifier '%s'\n\n", $1); } 

	| tNB                                                                           
  { add_tmp(mySymbolsTable);
    int address_nb = get_last_tmp(mySymbolsTable);
    printf("AFC %d %d\n\n", address_nb, $1);   
    $$ = address_nb;


    printf("printing table \n\n");
    PrintTable(mySymbolsTable);


    printf("term: number '%d'\n\n", $1); } 
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


