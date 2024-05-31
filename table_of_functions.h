#include <stdio.h>
#include <string.h>

#define MAX_FUNCTIONS 100


struct Function{
    char id[50];      
    int startADDR;    
} ;


struct FunctionTable {
    struct Function functions[MAX_FUNCTIONS]; 
    int size;                             
} ;


void initialize_function_table(struct FunctionTable* table);
void add_function(struct FunctionTable* table, const char* id, int startADDR);
int get_function_address(struct FunctionTable* table, const char* id);
char* get_current_function(struct FunctionTable* table, int currentLine);
void print_function_table(struct FunctionTable* table);

