
  /* Y-Quynh Nguyen & Daichi Malbranche */

%{
#include <stdio.h>
#include <stdlib.h>
#include "table_of_symbols.h"
#include "table_of_instructions.h"
#include "table_of_functions.h"

struct SymbolTable mySymbolsTable;
struct DeletedSymbolsTable myDeletedSymbolsTable;
struct InstructionTable myInstructionTable;
struct FunctionTable myFunctionTable;
%}

%code provides {
  int yylex (void);
  void yyerror (const char *);
}

%union {int nb;char* var;}

%token tADD tSUB tMUL tDIV tLT tGT tNE tEQ tGE tLE tASSIGN tAND tOR tNOT tLBRACE tRBRACE tLPAR tRPAR tSEMI tCOMMA tIF tELSE tWHILE  tPRINT tRETURN tINT tVOID tMAIN tCONST tERROR
%token <nb> tNB
%token <var> tID
%type <nb> add_sub div_mul single_value functionCall
%type <nb> condition equality_expression compare
%type <nb> action-if action-while action-getIndex action-else action-call1
%left tOR
%left tAND
%start program
%%








program:
  %empty                                                                        { printf("program: empty\n\n"); }
  |main_function                                                                  
  { printf("program: main\n\n"); 
  add_instruction(&myInstructionTable, "NOP", 0, 0,0); }
  |function_list main_function                                                  
  { printf("program: main and functions\n\n"); 
    add_instruction(&myInstructionTable, "NOP", 0, 0,0); 
  }
;





function_list:
  function                                                                        { printf("function_list: a function\n\n"); }
  |function_list function                                                         { printf("function_list: functions\n\n"); }

;

function:
  function_type tID tLPAR parameter_list tRPAR tLBRACE
    {//WARNING j'ai pas compris ce JMP
    add_instruction(&myInstructionTable,"JMP",-1,0,0);
    increment_scope(&mySymbolsTable);
    add_function(&myFunctionTable,$2,get_index_actuel_instructions(&myInstructionTable));
    add_symb(&mySymbolsTable,"?ADR");
    add_symb(&mySymbolsTable,"?VAL");} 
    body tRBRACE 
    {decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);
    //WARNING c'est quoi les args de RET
    add_instruction(&myInstructionTable,"RET",0,0,0);
   printf("function: %s\n\n", $2); }
;




main_function: 
  function_type tMAIN 
  {increment_scope(&mySymbolsTable);
  add_function(&myFunctionTable,"main",get_index_actuel_instructions(&myInstructionTable));
  //WARNING j'ai commenté ces parties parce que le scope marche pas bien avec les fonctions et que je peux pas déclarer de variables en dehors de fonctions mais j'aimerais les garder
  add_symb(&mySymbolsTable,"?ADR");
  add_symb(&mySymbolsTable,"?VAL");
  } 
  tLPAR parameter_list tRPAR tLBRACE body tRBRACE
  { decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);
    //WARNING c'est quoi les args de RET
    add_instruction(&myInstructionTable,"RET",0,0,0);
    int mainADDR = get_function_address(&myFunctionTable,"main");
    patch_instruction_arg1(&myInstructionTable,0,mainADDR);
    printf("main function\n\n"); }
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

functionCall:
  tID tLPAR action-call1 argument_list tRPAR
  {printf("function Call\n");
  //WARNING not yet done, look at trace p438
  //je comprends pas ces instructions, args pas ok
  add_tmp(&mySymbolsTable);
  int tmp = get_last_tmp(&mySymbolsTable);
  int calleeFrame = $3;
  int calleeADDR = get_function_address(&myFunctionTable,$1);
  add_instruction(&myInstructionTable,"PUSH",calleeFrame,0,0);
  add_instruction(&myInstructionTable,"CALL",calleeADDR,0,0);
  add_instruction(&myInstructionTable,"POP",tmp,-1,0);
  add_instruction(&myInstructionTable,"COP",tmp,-1,0);
  add_instruction(&myInstructionTable,"COP",tmp,tmp,0);
  $$ = tmp;}
;

action-call1:%empty
  {increment_scope(&mySymbolsTable);
  add_symb(&mySymbolsTable,"!ADR");
  add_symb(&mySymbolsTable,"!VAL");
  $$ = get_symbol_table_size(&mySymbolsTable);
  decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);};


argument_list:
%empty
|argument
|argument_list argument;

argument:
add_sub
;



body:
  %empty                                                                            { printf("body: empty\n\n"); }
  |declaration_list                                                                 { printf("body: declaration_list\n\n"); }
  
  |instruction_list                                                                 
  { 


    printf("body: instruction_list\n\n"); }
  
  |declaration_list instruction_list                                                { printf("body: declaration&instruction list\n\n"); }
  |return
;

//la fonction ne renvoie qu'un parametre
return:
tRETURN add_sub tSEMI 
{printf("tRETURN\n");
  int val = get_symb(&mySymbolsTable,"?VAL");
add_instruction(&myInstructionTable,"COP",val,$2,0);
//WARNING pas sur de comprendre les args de RET
add_instruction(&myInstructionTable,"RET",0,0,0);

}
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
  { add_symb(&mySymbolsTable, $1); 
    printf("identifier: '%s'\n\n", $1); }

  |tID tASSIGN add_sub /*equality_expression */                                                
  { add_symb(&mySymbolsTable, $1); 

    int address_nb = get_symb(&mySymbolsTable,$1);
    add_instruction(&myInstructionTable, "COP", address_nb, $3,0);   
    free_last_tmp(&mySymbolsTable);
    printf("declaration and initialization: '%s'\n\n", $1); }


  |identifiers_list tCOMMA tID                                                   
  { add_symb(&mySymbolsTable, $3); 
    printf("several identifiers: '%s'\n\n", $3); }
    
  |identifiers_list tCOMMA tID tASSIGN add_sub /*equality_expression */                      
  { add_symb(&mySymbolsTable, $3); 

    int address_nb = get_symb(&mySymbolsTable,$3);
    add_instruction(&myInstructionTable, "COP", address_nb, $5,0);
    free_last_tmp(&mySymbolsTable);
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
  { 
    int address_nb = get_symb(&mySymbolsTable,$1);
    add_instruction(&myInstructionTable, "COP", address_nb, $3,0);
    free_last_tmp(&mySymbolsTable);
    printf("assignment: '%s'\n\n", $1); }

  |tID tASSIGN add_sub tCOMMA assignment_list
  { get_symb(&mySymbolsTable,$1);
    int address_nb = get_symb(&mySymbolsTable,$1);
    add_instruction(&myInstructionTable, "COP", address_nb, $3,0);  
    free_last_tmp(&mySymbolsTable);
    printf("assignment: '%s'\n\n", $1); }




ifblock:
	  tIF tLPAR condition tRPAR action-if tLBRACE body tRBRACE action-getIndex
    {patch_instruction_arg1(&myInstructionTable,$5,$3);
    free_last_tmp(&mySymbolsTable); // free temp of condition
      patch_instruction_arg2(&myInstructionTable,$5,$9);
    decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);
     } 
    { printf("if block: if\n\n"); }
	| tIF tLPAR condition tRPAR action-if tLBRACE body tRBRACE action-getIndex tELSE action-else tLBRACE body tRBRACE action-getIndex
    {patch_instruction_arg1(&myInstructionTable,$5,$3); //patch jump of if
      free_last_tmp(&mySymbolsTable); // free temp of condition
      patch_instruction_arg2(&myInstructionTable,$5,$9+1);  
      patch_instruction_arg1(&myInstructionTable,$11,$15);  //patch jump    
    decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);
     } 
    { printf("if block: if else\n\n"); }
	| tIF tLPAR condition tRPAR action-if tLBRACE body tRBRACE action-getIndex tELSE ifblock
    {patch_instruction_arg1(&myInstructionTable,$5,$3);
    free_last_tmp(&mySymbolsTable); // free temp of condition
      patch_instruction_arg2(&myInstructionTable,$5,$9);
    decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);
     } 
    { printf("if block: if else if\n\n"); }
;

action-if:%empty
{add_instruction(&myInstructionTable,"JMF",-1,-1,0);  
$$ = get_index_actuel_instructions(&myInstructionTable)-1;
increment_scope(&mySymbolsTable);
} 
;

action-else:%empty 
{add_instruction(&myInstructionTable,"JMP",-1,0,0);    
$$ = get_index_actuel_instructions(&myInstructionTable)-1;} 
;

action-getIndex:%empty
  {$$ = get_index_actuel_instructions(&myInstructionTable);};





whileblock:
	tWHILE tLPAR condition tRPAR action-while tLBRACE body tRBRACE 
  {add_instruction(&myInstructionTable,"JMP",$5-2,0,0); //backward jump
    patch_instruction_arg1(&myInstructionTable,$5,$3);
    free_last_tmp(&mySymbolsTable); // free temp of condition
    patch_instruction_arg2(&myInstructionTable,$5,get_index_actuel_instructions(&myInstructionTable));
    decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);}
  { printf("while block\n\n"); }         
;

action-while:%empty
{add_instruction(&myInstructionTable,"JMF",-1,-1,0);    //arg1 ?
$$ = get_index_actuel_instructions(&myInstructionTable)-1;
increment_scope(&mySymbolsTable);
} 
;



printblock:
	tPRINT tLPAR single_value tRPAR tSEMI	                                                 
  { printf("print block: '%d'\n\n", $3);      
  add_instruction(&myInstructionTable,"PRI",$3,0,0);
  //$$ = get_index_actuel_instructions(&myInstructionTable)-1;
  } 
;



condition:
  tID {
    add_tmp(&mySymbolsTable);
    int temp = get_last_tmp(&mySymbolsTable);
    int addr = get_symb(&mySymbolsTable,$1);
    $$ = temp;
    add_instruction(&myInstructionTable, "COP", temp, addr,0); }
	|equality_expression
  { $$ = $1;
    printf("condition\n\n"); }   
	| condition tAND condition
  { printf("condition: and\n\n");
  printf("WARNING This is not implemented"); }   
	| condition tOR condition
  { printf("condition: or\n\n"); 
  printf("WARNING This is not implemented");}   
	| tNOT condition
  { printf("condition: not\n\n");
  printf("WARNING This is not implemented"); }   
;


equality_expression : 
  compare  {$$ = $1;    
  printf("equality_expression: compare\n\n"); }   
  | equality_expression tEQ compare   
  {add_instruction(&myInstructionTable,"EQU",$1,$1,$3);
  free_last_tmp(&mySymbolsTable);
  $$ = $1;
  printf("equality_expression: equal\n\n"); }   
  | equality_expression tNE compare
  { printf("equality_expression: not equal\n\n"); 
  printf("WARNING This is not implemented");}   
;



compare:
	  add_sub   {$$ = $1;
    printf("compare: add_sub\n\n"); }   
	| compare tLT add_sub     
  {add_instruction(&myInstructionTable,"INF",$1,$1,$3);
  free_last_tmp(&mySymbolsTable);
  $$ = $1;
  printf("compare: less than\n\n"); }   
	| compare tGT add_sub     
  {add_instruction(&myInstructionTable,"SUP",$1,$1,$3);
  free_last_tmp(&mySymbolsTable);
  $$ = $1;
  printf("compare: greater than\n\n"); }   
	| compare tLE add_sub
  { printf("compare: less or equal\n\n");
   printf("WARNING This is not implemented");}   
	| compare tGE add_sub
  { printf("compare: greater or equal\n\n");
  printf("WARNING This is not implemented"); }   
;




add_sub:
    functionCall {printf("reducing functionCall to add_sub\n");}
   |div_mul                                                                       
     {$$ = $1;}

	| add_sub tADD div_mul                                                          
  { //we assign the value of @div_mul + @add_sub to @add_sub
    add_instruction(&myInstructionTable, "ADD", $1,$1, $3);

    //we free the tmp @div_mul
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("add_sub: addition\n\n"); }  

	| add_sub tSUB div_mul                                                          
  { //we assign the value of @div_mul - @add_sub to @add_sub
    add_instruction(&myInstructionTable, "SUB", $1,$1, $3); 

    //we free the tmp @div_mul
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("add_sub: substraction\n\n"); }         
;




div_mul:
  single_value {$$ = $1;}                                                                          

  | div_mul tMUL single_value                                                             
  { //we assign the value of @single_value * @div_mul to @div_mul
    add_instruction(&myInstructionTable, "MUL", $1,$1, $3);

    //we free the tmp @single_value
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("div_mul: multiplication\n\n"); } 

	| div_mul tDIV single_value                                                             
  { //we assign the value of @single_value / @div_mul to @div_mul
    add_instruction(&myInstructionTable, "DIV", $1, $1,$3);

    //we free the tmp @single_value
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("div_mul: division\n\n"); } 
;



single_value:
    tID                                                                           
  { //we return the @ID
    add_tmp(&mySymbolsTable);
    int temp = get_last_tmp(&mySymbolsTable);
    int addr = get_symb(&mySymbolsTable,$1);
    $$ = temp;
    add_instruction(&myInstructionTable, "COP", temp, addr,0); 
    printf("single_value: identifier '%s'\n\n", $1); } 

	| tNB                                                                           
  { //we add a tmp to ST
    add_tmp(&mySymbolsTable);

    //we assign the value to the @NB
    int address_nb = get_last_tmp(&mySymbolsTable);
    add_instruction(&myInstructionTable, "AFC", address_nb, $1,0);  

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
  initialize_symbol_table(&mySymbolsTable);
  initialize_instruction_table(&myInstructionTable);
  initialize_function_table(&myFunctionTable);
  yyparse();
  print_table(&mySymbolsTable);
  print_deleted_symbols_table(&myDeletedSymbolsTable);
  print_instruction_table(&myInstructionTable);
  print_function_table(&myFunctionTable);
  //WARNING following lines smashes the stack when there are functions in the code to compile
  write_instructions_to_file(myInstructionTable);
  write_instructions_to_file_read(myInstructionTable);
  write_instructions_to_file_VHDL(myInstructionTable);
  return 0;
}