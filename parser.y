
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

%type <nb> add_sub div_mul single_value condition equality_expression compare functionCall action-if action-while action-getIndex action-else action-call1 action-call0 ifpart
%left tOR tAND tNOT
%start program
%%


//--------------------------GENERAL ACTIONS----------------------------------------------------

action-inc: 
  %empty
  {
    increment_scope(&mySymbolsTable);
    printf("\t\t\t\tincrement scope to %d \n\n", mySymbolsTable.scope_general); 
  }
;

action-dec: 
  %empty
  {
    decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);
    printf("\t\t\t\tdecrement scope to %d \n\n", mySymbolsTable.scope_general); 
  }
;

action-getIndex:
  %empty
  { 
    $$ = get_index_actuel_instructions(&myInstructionTable);
    printf("\t\t\t\taction-getIndex\n\n"); 
  }
;

//--------------------------GENERAL----------------------------------------------------


program:
  %empty                                                                        
  { //empty program
    printf("\t\t\t\tprogram: empty\n\n"); 
  }

  |action-start main_function                                                                  
  { //only a main
    add_instruction(&myInstructionTable, "NOP", 0, 0,0); 
    printf("\t\t\t\tprogram: main\n\n"); 
  }

  |action-start function_list main_function                       
  { //functions and a main 
    add_instruction(&myInstructionTable, "NOP", 0, 0,0);
    printf("\t\t\t\tprogram: main + functions\n\n"); 
  }
;

action-start:
  %empty
  { //adds a jump at start to begin compiling from main
    add_instruction(&myInstructionTable,"JMP",-1,0,0);
    printf("\t\t\t\taction-start\n\n"); 
  }
;


//--------------------------STRUCTURE OF FUNCTIONS----------------------------------------------------


function_type:
  tVOID                                                                           
  { //there should not be a return
    printf("\t\t\t\tfunction type: void\n\n"); 
  }

  |tINT                                                                           
  { //there should be a return somewhere
    printf("\t\t\t\tfunction type: int\n\n"); 
  }
;

variable_type:
  tINT                                                                             
  { 
    printf("\t\t\t\tvariable_type: int\n\n"); 
  }
;

parameter_list:
  %empty                                                                          
  { 
    printf("\t\t\t\tparameter_list: empty\n\n"); 
  }
  |tVOID                                                                          
  { 
    printf("\t\t\t\tparameter_list: void\n\n"); 
  }
  |parameter                                                                      
  { 
    printf("\t\t\t\tparameter_list: a parameter\n\n"); 
  }
  |tCOMMA parameter tCOMMA parameter_list                                            
  { 
    printf("\t\t\t\tparameter_list: several parameters\n\n"); 
  }
;

parameter:
  variable_type tID                                                               
  { 
    add_symb(&mySymbolsTable, $2); 
    printf("\t\t\t\tparameter\n\n"); 
  }
;

body:
  %empty                                                                            
  { //empty body
    printf("\t\t\t\tbody: empty\n\n");
  }

  |declaration_list                                                                 
  { //declarations
    printf("\t\t\t\tbody: declaration_list\n\n"); 
  }
  
  |instruction_list                                                                 
  { //instructions
    printf("\t\t\t\tbody: instruction_list\n\n"); 
  }
  
  |declaration_list instruction_list                                                
  { //declarations and instructions
    printf("\t\t\t\tbody: declaration&instruction list\n\n"); 
  }
;

declaration_list:
  declaration                                                                      
  { 
    printf("\t\t\t\ta declaration\n\n"); 
  }
  |declaration_list declaration                                                    
  { 
    printf("\t\t\t\tseveral declarations\n\n"); 
  }
;

declaration:
  variable_type identifiers_list tSEMI                                           
  { 
    printf("\t\t\t\tdeclaration\n\n"); 
  }
;

identifiers_list:
  tID                                                                             
  { //adds tID to symbols table
    add_symb(&mySymbolsTable, $1); 
    printf("\t\t\t\tidentifier: decl of '%s'\n\n", $1); 
  }
  |tID tASSIGN condition                                               
  { //adds tID to symbols table and assigns value
    add_symb(&mySymbolsTable, $1); 

    int address_nb = get_symb(&mySymbolsTable,$1);
    add_instruction(&myInstructionTable, "COP", address_nb, $3,0);   
    free_last_tmp(&mySymbolsTable);
    printf("\t\t\t\tidentifiers: decl + init of '%s'\n\n", $1); 
  }
  |identifiers_list tCOMMA tID                                                   
  { //adds tID to symbols table
    add_symb(&mySymbolsTable, $3); 
    printf("\t\t\t\tseveral identifiers: decl '%s'\n\n", $3); 
  }  
  |identifiers_list tCOMMA tID tASSIGN condition                    
  { //adds tID to symbols table and assigns value
    add_symb(&mySymbolsTable, $3); 
    int address_nb = get_symb(&mySymbolsTable,$3);
    add_instruction(&myInstructionTable, "COP", address_nb, $5,0);
    free_last_tmp(&mySymbolsTable);
    printf("\t\t\t\tseveral identifiers: decl + init '%s'\n\n", $3); 
  }
;

instruction_list:
  instruction                                                                       
  { 
    printf("\t\t\t\tan instruction\n\n"); 
  }
  |instruction_list instruction                                                     
  { 
    printf("\t\t\t\tseveral instructions\n\n"); 
  }
;

instruction:
  assignment_list                                                                
  { 
    printf("\t\t\t\tinstruction: assignment\n\n"); 
  }
  |ifblock                                                                        
  { 
    printf("\t\t\t\tinstruction: if block\n\n"); 
  }
  |whileblock                                                                     
  { 
    printf("\t\t\t\tinstruction: while block\n\n"); 
  }
  |printblock                                                                     
  { 
    printf("\t\t\t\tinstruction: print block\n\n"); 
  }
  |returnblock
  {
    printf("\t\t\t\tbody: retur blockn\n\n"); 
  }
;

//--------------------------FUNCTIONS OTHER THAN MAIN----------------------------------------------------

action-fun:
  %empty
  { //add symbols to frame to return address and value
    add_symb(&mySymbolsTable,"?ADR");
    add_symb(&mySymbolsTable,"?VAL");
    printf("\t\t\t\taction-fun: adding ?ADR and ?VAL\n\n"); 

  }
;


function_list:
  function                                                                        
  { 
    printf("\t\t\t\t\t\t\t\tfunction_list: a function\n\n"); 
  }

  |function_list function                                                         
  { 
    printf("\t\t\t\tfunction_list: functions\n\n"); 
  }
;


function:
  function_type tID action-inc action-fun action-getIndex
  { //add function to functions table
    add_function(&myFunctionTable,$2,$5);
  } 
  tLPAR parameter_list tRPAR tLBRACE action-inc body tRBRACE action-dec 
  {
    add_instruction(&myInstructionTable,"RET",0,0,0);
    printf("\t\t\t\tfunction: %s\n\n", $2); 
  }
  action-dec
;


functionCall:
  tID tLPAR action-call0 action-call1 argument_list tRPAR action-getIndex
  {
    char* caller = get_current_function(&myFunctionTable,$7);
    int calleeFrame = $4;

    int callerFrame = $3;

    add_instruction(&myInstructionTable,"PUSH",callerFrame+1,0,0);

    //We call the function f
    int calleeADDR = get_function_address(&myFunctionTable,$1);
    add_instruction(&myInstructionTable,"CALL",calleeADDR,0,0);

    //
    add_instruction(&myInstructionTable,"POP",callerFrame+1,0,0);
    add_tmp(&mySymbolsTable);

    //copy return value !VAL of callee into temp
    int temp = get_last_tmp(&mySymbolsTable);
    add_instruction(&myInstructionTable,"COP",temp,callerFrame+2,0);
    $$ = temp;
    printf("\t\t\t\tfunction Call\n");

  }
;


action-call0:
  %empty
  { //we save size of current frame (caller function)
    $$ = get_symbol_table_size(&mySymbolsTable);
    printf("\t\t\t\taction-call0: save size of current frame\n\n"); 

  }
;


action-call1:
  %empty
  { //allocate space for adr and val of callee function
    add_symb(&mySymbolsTable,"!ADR");
    add_symb(&mySymbolsTable,"!VAL");
    add_tmp(&mySymbolsTable);
    $$ = get_symbol_table_size(&mySymbolsTable);
    printf("\t\t\t\taction-call1: allocate space for ADR and VAL\n\n"); 

  }
;


argument_list:
  %empty
  { 
    printf("\t\t\t\targumentlist: no argument\n\n");
  }
  |argument_list tCOMMA condition
  { 
    printf("\t\t\t\targumentlist\n\n");
  }
  |condition
  { 
    printf("\t\t\t\targument\n\n");
  }
;

//--------------------------MAIN----------------------------------------------------


main_function: 
  function_type tMAIN action-inc action-fun action-getIndex
  { //adds function to table
    add_function(&myFunctionTable,"main",$5);
  } 
  tLPAR parameter_list tRPAR tLBRACE action-inc body tRBRACE action-dec action-dec
  { //RET + updates JMP with @main
    add_instruction(&myInstructionTable,"RET",0,0,0);
    int mainADDR = get_function_address(&myFunctionTable,"main");
    patch_instruction_arg1(&myInstructionTable,0,mainADDR);
    printf("\t\t\t\tmain function\n\n"); 
  }
;

//--------------------------ASSIGNMENT BLOCK----------------------------------------------------

assignment_list:
  assignment tSEMI                                           
  { 
    printf("\t\t\t\tassignmentlist: an assignment\n\n"); 
  }

  |assignment tCOMMA assignment_list
  { 
    printf("\t\t\t\tassignment_list: several assignments\n\n"); 
  }
;

assignment:
  tID tASSIGN condition
  { 
    int address_nb = get_symb(&mySymbolsTable,$1);
    add_instruction(&myInstructionTable, "COP", address_nb, $3,0);
    free_last_tmp(&mySymbolsTable);
    printf("\t\t\t\tassignment: '%s'\n\n", $1); 
  }
;


//--------------------------IF BLOCK----------------------------------------------------

ifblock:
  ifpart
  { //if
    printf("\t\t\t\tif block: if\n\n"); 
  }

	|ifpart tELSE action-else action-getIndex action-inc tLBRACE body tRBRACE action-getIndex action-dec
  { //if else
    patch_instruction_arg2(&myInstructionTable,$1,$4); //to jump after the jump of else
    patch_instruction_arg1(&myInstructionTable,$3,$9);  //patch jump of else   
    printf("\t\t\t\tif block: if else\n\n"); 
  }

  |ifpart tELSE action-else action-getIndex action-inc ifblock action-getIndex action-dec
  { //if else if
    patch_instruction_arg2(&myInstructionTable,$1,$4); //to jump after the jump of else
    patch_instruction_arg1(&myInstructionTable,$3,$7);  //patch jump of else  
    printf("\t\t\t\tif block: if else if\n\n"); 
  }
;

ifpart: 
  tIF tLPAR condition tRPAR action-if action-inc tLBRACE body tRBRACE action-getIndex action-dec
  {
    //update jmf with where and when to jump
    patch_instruction_arg1(&myInstructionTable,$5,$3); //updates jmf with which reg to check whether we jump or not
    free_last_tmp(&mySymbolsTable); // free temp of condition
    patch_instruction_arg2(&myInstructionTable,$5,$10); //updates jmf with which instruction to jump to 
    printf("\t\t\t\tifpart\n\n"); 
    $$ = $5;
  }
;

action-if:
  %empty
  { 
    //adds a jmf to be able to jump depending on cond
    //returns where that jump is to update it
    add_instruction(&myInstructionTable,"JMF",-1,-1,0);  
    $$ = get_index_actuel_instructions(&myInstructionTable)-1;
    printf("\t\t\t\taction-if: rajoute un jump if\n\n"); 
  } 
;

action-else:
  %empty 
  {
    //adds a jump to skip else
    //returns where that jump is to update it
    add_instruction(&myInstructionTable,"JMP",-1,0,0);    
    $$ = get_index_actuel_instructions(&myInstructionTable)-1;
    printf("\t\t\t\taction-else: rajoute un jump if\n\n"); 
  } 
;

//--------------------------WHILE BLOCK----------------------------------------------------

whileblock:
	tWHILE tLPAR action-getIndex condition tRPAR action-while action-inc tLBRACE body tRBRACE 
  { //loops in block while cond
    //a backward jump to stay in loop, goes to before the condition to update it
    add_instruction(&myInstructionTable,"JMP",$3,0,0); //backward jump

    //update jmf to know where and when it should jump
    patch_instruction_arg1(&myInstructionTable,$6,$4); //updates jmf to check condition to know if we should stay in loop
    free_last_tmp(&mySymbolsTable); // free temp of condition
    patch_instruction_arg2(&myInstructionTable,$6,get_index_actuel_instructions(&myInstructionTable)); //updates jmf to know where to jump to
    printf("\t\t\t\twhile block\n\n"); 
  }         
  action-dec
;

action-while:
  %empty
  { //adds JMF to know whether we should stay in loop
    //returns where that JMF is to be able to update it after
    add_instruction(&myInstructionTable,"JMF",-1,-1,0);    
    $$ = get_index_actuel_instructions(&myInstructionTable) - 1;
    printf("\t\t\t\taction-while: rajoute un jump if\n\n"); 

  } 
;

//--------------------------PRINT BLOCK----------------------------------------------------

printblock:
	tPRINT tLPAR condition tRPAR tSEMI	                                                 
  { //prints value   
    add_instruction(&myInstructionTable,"PRI",$3,0,0);
    printf("\t\t\t\tprint block\n\n");
  } 
;

//--------------------------RETURN BLOCK----------------------------------------------------

returnblock:
  tRETURN condition tSEMI 
  { //returns one parameter
    int val = get_symb(&mySymbolsTable,"?VAL");
    add_instruction(&myInstructionTable,"COP",val,$2,0);
    free_last_tmp(&mySymbolsTable);

    add_instruction(&myInstructionTable,"RET",0,0,0);
    printf("\t\t\t\treturnblock\n");
  }
;

//--------------------------VALUES ----------------------------------------------------

condition:
  equality_expression
  { //we push forward the value of compare
    $$ = $1;}   
	| condition tAND condition
  { //we return the @condition and condition
    add_instruction(&myInstructionTable,"AND",$1,$1,$3);
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("\t\t\t\tcondition: and\n\n");}   
	| condition tOR condition
  { //we return the @condition and condition
    add_instruction(&myInstructionTable,"ORR",$1,$1,$3);
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("\t\t\t\tcondition: or\n\n"); }   
	| tNOT condition
  { //we return the @condition and condition
    add_instruction(&myInstructionTable,"NOT",$2,$2,0);
    $$ = $2;
    printf("\t\t\t\tcondition: not\n\n");}   
;


equality_expression : 
  compare  
  { //we push forward the value of compare
    $$ = $1;} 

  |equality_expression tEQ compare   
  { //we return the @equality_expression == equality_expression
    add_instruction(&myInstructionTable,"EQU",$1,$1,$3);
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("\t\t\t\tequality_expression: equal\n\n"); }  

  |equality_expression tNE compare
  { //we return the @equality_expression != equality_expression
    add_instruction(&myInstructionTable,"NEQ",$1,$1,$3);
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("\t\t\t\tequality_expression: not equal\n\n");}   
;


compare:
	add_sub   
  { //we push forward the value of add_sub
    $$ = $1;}   
	|compare tLT add_sub     
  { //we return the @compare<add_sub
    add_instruction(&myInstructionTable,"INF",$1,$1,$3);
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("\t\t\t\tcompare: less than\n\n"); }   
	| compare tGT add_sub     
  { //we return the @compare>add_sub
    add_instruction(&myInstructionTable,"SUP",$1,$1,$3);
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("\t\t\t\tcompare: greater than\n\n"); }   
	| compare tLE add_sub
  { //we return the @compare<=add_sub
    add_instruction(&myInstructionTable,"LEQ",$1,$1,$3);
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("\t\t\t\tcompare: less or equal\n\n");}   
	| compare tGE add_sub
  { //we return the @compare>=add_sub
    add_instruction(&myInstructionTable,"GEQ",$1,$1,$3);
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("\t\t\t\tcompare: greater or equal\n\n");}   
;


add_sub:

   div_mul                                                                       
  { //we push forward the value of div_mul
      $$ = $1;}

	| add_sub tADD div_mul                                                          
  { //we return the @add_sub+div_mul
    //we assign the value of @div_mul + @add_sub to @add_sub
    add_instruction(&myInstructionTable, "ADD", $1,$1, $3);

    //we free the tmp @div_mul
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("\t\t\t\tadd_sub: addition\n\n"); }  

	| add_sub tSUB div_mul                                                          
  { //we return the @add_sub-div_mul
    //we assign the value of @div_mul - @add_sub to @add_sub
    add_instruction(&myInstructionTable, "SUB", $1,$1, $3); 

    //we free the tmp @div_mul
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("\t\t\t\tadd_sub: substraction\n\n"); }         
;


div_mul:
  single_value 
  { //we push forward the value of single_value
    $$ = $1;}                                                                          

  |div_mul tMUL single_value                                                             
  { //we return the @divmul*single_value
    //we assign the value of @single_value * @div_mul to @div_mul
    add_instruction(&myInstructionTable, "MUL", $1,$1, $3);

    //we free the tmp @single_value
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("\t\t\t\tdiv_mul: multiplication\n\n"); } 

	|div_mul tDIV single_value                                                             
  { //we return the @divmul/single_value
    //we assign the value of @single_value / @div_mul to @div_mul
    add_instruction(&myInstructionTable, "DIV", $1, $1,$3);

    //we free the tmp @single_value
    free_last_tmp(&mySymbolsTable);
    $$ = $1;
    printf("\t\t\t\tdiv_mul: division\n\n"); } 
;


single_value:
  functionCall 
  { add_tmp(&mySymbolsTable);
    int temp = get_last_tmp(&mySymbolsTable);
    $$ = temp;
    add_instruction(&myInstructionTable, "COP", temp, $1,0); 
    printf("\t\t\t\tsingle value: function call\n");}

  |tID                                                                           
  { //we return the @tmp that holds the value of tID
    //we create a variable to put the value of tID in
    //we get the address of ID and adress of the tmp we created
    //copy the value of ID in tmp 
    add_tmp(&mySymbolsTable);
    int temp = get_last_tmp(&mySymbolsTable);
    int addr = get_symb(&mySymbolsTable,$1);
    $$ = temp;
    add_instruction(&myInstructionTable, "COP", temp, addr,0); 
    printf("\t\t\t\tsingle_value: identifier '%s'\n\n", $1); } 

	
  |tNB                                                                           
  { //we return the @tmp that holds the value tNB
    //we create a tmp to ST
    //we assign the value of tNB to tmp
    add_tmp(&mySymbolsTable);

    int address_nb = get_last_tmp(&mySymbolsTable);
    add_instruction(&myInstructionTable, "AFC", address_nb, $1,0);  

    $$ = address_nb;
    printf("\t\t\t\tsingle_value: number '%d'\n\n", $1); } 
;

%%

void yyerror(const char *msg) {
  fprintf(stderr, "error: %s\n", msg);
  exit(1);
}

int main(void) {
  //Initialize Tables
  initialize_symbol_table(&mySymbolsTable);
  initialize_instruction_table(&myInstructionTable);
  initialize_function_table(&myFunctionTable);

  //Parse
  yyparse();

  //Print final tables in terminal
  print_table(&mySymbolsTable);
  print_deleted_symbols_table(&myDeletedSymbolsTable);
  print_instruction_table(&myInstructionTable);
  print_function_table(&myFunctionTable);

  //Creates and writes into the files
  //WARNING following lines smashes the stack when there are functions in the code to compile
  write_instructions_to_file(myInstructionTable);
  write_instructions_to_file_read(myInstructionTable);
  write_instructions_to_file_VHDL(myInstructionTable);
  return 0;
}