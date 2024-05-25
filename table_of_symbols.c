#include "table_of_symbols.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void initialize_symbol_table(struct SymbolTable *table) {
    table->ptr = -1;
    table->ptr_tmp = MAX_SYMBOLS;
    table->scope_general = 0;
}

void add_symb(struct SymbolTable *table, char *id) {
    if (table->ptr < MAX_SYMBOLS - 1) { // Check if there is space in the table
        table->ptr++;
        struct Symbol symb;
        strcpy(symb.id, id);
        symb.address = table->ptr; // Assign the next available address
        symb.scope = table->scope_general;
        table->symbols[table->ptr] = symb;
    } else {
        printf("Error: Symbol table is full!\n");
    }
}

void add_tmp(struct SymbolTable *table) {
    table->ptr_tmp--;
    struct Symbol symb;
    symb.address = table->ptr_tmp;
    symb.scope = table->scope_general;
    table->symbols[table->ptr_tmp] = symb;
    printf("add temp - Number of temporary variables: %d\n", MAX_SYMBOLS - table->ptr_tmp);
}

// Return address of symbol in symbol table
int get_symb(struct SymbolTable *table, char *id) {
    for (int i = 0; i <= table->ptr; i++) {
        if (strcmp(table->symbols[i].id, id) == 0) {
            return table->symbols[i].address;
        }
    }
    return -1; // Return -1 if the target is not found
}

int get_scope(struct SymbolTable *table, char *id) {
    for (int i = 0; i <= table->ptr; i++) {
        if (strcmp(table->symbols[i].id, id) == 0) {
            return table->symbols[i].scope;
        }
    }
    return -1; // Return -1 if the target is not found
}

void increment_scope(struct SymbolTable *table){
    table->scope_general++;
}  
void decrement_scope(struct SymbolTable *table){
        table->scope_general--;
} 

int get_last_tmp(struct SymbolTable *table) {
    return table->symbols[table->ptr_tmp].address;
    printf("get last temp - Number of temporary variables: %d\n", MAX_SYMBOLS - table->ptr_tmp);
}

int get_last_tmp_scope(struct SymbolTable *table) {
    return table->symbols[table->ptr_tmp].scope;
}  

void free_all_tmp(struct SymbolTable *table) {
    table->ptr_tmp = MAX_SYMBOLS;
    printf("free all temp - Number of temporary variables: %d\n", MAX_SYMBOLS - table->ptr_tmp);
}

void free_last_tmp(struct SymbolTable *table) {
    table->ptr_tmp++;
    printf("free last temp - Number of temporary variables: %d\n", MAX_SYMBOLS - table->ptr_tmp);
}

void PrintTable(struct SymbolTable *table) {
    printf("--------SYMBOL TABLE------\n");
    printf("--------SYMBOLS------\n");
    for (int i = 0; i <= table->ptr; i++) {
        printf("address: %d   id: %s    scope: %d\n", table->symbols[i].address, table->symbols[i].id, table->symbols[i].scope);
    }
    printf("------TEMPS--------\n");
    printf("Number of temporary variables: %d\n", MAX_SYMBOLS - table->ptr_tmp);
    printf("-----------------------------\n\n\n");
}
