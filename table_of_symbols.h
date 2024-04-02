#ifndef TABLE_OF_SYMBOLS_H
#define TABLE_OF_SYMBOLS_H

#include <stdbool.h>


#define MAX_SYMBOLS 100




struct Symbol {
   char id[50]; 
   //bool initialized;
   int address;     //address of the symbol in the table of symbols
};






struct SymbolTable {
   struct Symbol symbols[MAX_SYMBOLS];
   int ptr;
   int ptr_tmp;
};


struct SymbolTable initialize_table(struct SymbolTable table);


struct SymbolTable add_symb(struct SymbolTable table, char* id);
int get_symb(struct SymbolTable table, char* id);




struct SymbolTable add_tmp(struct SymbolTable table);
int get_last_tmp(struct SymbolTable table);
struct SymbolTable free_tmp(struct SymbolTable table);
void PrintTable(struct SymbolTable table);



#endif





