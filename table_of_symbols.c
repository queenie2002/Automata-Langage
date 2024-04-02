#include "table_of_symbols.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>














struct SymbolTable initialize_table(struct SymbolTable table) {
   table.ptr=-1;
   table.ptr_tmp=MAX_SYMBOLS;
   return table;
}








struct SymbolTable add_symb(struct SymbolTable table, char* id){
   table.ptr ++;
   struct Symbol symb;
   strcpy(symb.id, id);
   symb.address = table.ptr;
   //symb.initialized = true;
   table.symbols[table.ptr] = symb;
   return table;
}








struct SymbolTable add_tmp(struct SymbolTable table) {
   table.ptr_tmp--;
   struct Symbol symb;
   symb.address = table.ptr_tmp;
   table.symbols[table.ptr_tmp] = symb;
   return table;
}












int get_symb(struct SymbolTable table, char* id) {
for (int i = 0; i< table.ptr; i++) {
if (*table.symbols[i].id == *id) {
return table.symbols[i].address;
       }
   }
return -1;  // Return -1 if the target is not found
}
















int get_last_tmp(struct SymbolTable table) {
   return table.symbols[table.ptr_tmp].address;
}








struct SymbolTable free_tmp(struct SymbolTable table) {
   table.ptr_tmp++;
   return table;
}




void PrintTable(struct SymbolTable table){
   printf("--------Declared variables and constants------\n");
   for (int i=0;i<=table.ptr;i++){
      printf("address :%c   id :%s\n",table.symbols[i].address, table.symbols[i].id);
   }
   printf("------temporary variables--------");
   for (int i=MAX_SYMBOLS;i>=table.ptr;i--){
       printf("address :%c",table.symbols[i].address);
   }


}


























