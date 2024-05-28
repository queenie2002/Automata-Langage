#include "table_of_symbols.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void initialize_symbol_table(struct SymbolTable *table) {
    table->ptr = -1;
    table->ptr_tmp = MAX_SYMBOLS;
    table->scope_general = 0;
    table->total_temps = 0; 
}

void initialize_deleted_symbols_table(struct DeletedSymbolsTable *table){
    table->count = 0;
}

void add_symb(struct SymbolTable *table, char *id) {
    if (table->ptr < MAX_SYMBOLS - 1) { // Check if there is space in the table
        table->ptr++;
        struct Symbol symb;
        strcpy(symb.id, id);
        symb.address = table->ptr; // Assign the next available address
        symb.scope = table->scope_general;
        table->symbols[table->ptr] = symb;
        printf("Added symbol - ID: %s, Address: %d, Scope: %d\n", id, table->symbols[table->ptr].address, table->symbols[table->ptr].scope);
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
    table->total_temps++;
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
void decrement_scope(struct SymbolTable *table, struct DeletedSymbolsTable *deletedTable){
        table->scope_general--;

        //on enleve les variable avec un scope trop grand
        int table_size = table->ptr;
        for (int i = 0; i <= table_size; i++) {




        if (table->symbols[i].scope == table->scope_general+1) {
        // Save the removed symbol in DeletedSymbolsTable
        //pour les fonctions on a un décalage de 1 entre ce qui est enlevé et ce qui est affiché comme enlevé
        strcpy(deletedTable->symbols[deletedTable->count].id, table->symbols[i].id);
        deletedTable->symbols[deletedTable->count].address = table->symbols[i].address;
        deletedTable->symbols[deletedTable->count].scope = table->symbols[i].scope;
        deletedTable->count++;

        printf("Remove symbol %s with scope %d\n", table->symbols[i].id, table->symbols[i].scope);
        table->ptr--;
        }
    }
} 

int get_last_tmp(struct SymbolTable *table) {
    return table->symbols[table->ptr_tmp].address;
    printf("get last temp - Number of temporary variables: %d\n", MAX_SYMBOLS - table->ptr_tmp);
}

int get_last_tmp_scope(struct SymbolTable *table) {
    return table->symbols[table->ptr_tmp].scope;
}  


int get_symbol_table_size(struct SymbolTable* table) {
    return table->ptr;
}

void free_all_tmp(struct SymbolTable *table) {
    table->ptr_tmp = MAX_SYMBOLS;
    printf("free all temp - Number of temporary variables: %d\n", MAX_SYMBOLS - table->ptr_tmp);
}

void free_last_tmp(struct SymbolTable *table) {
    table->ptr_tmp++;
    printf("free last temp - Number of temporary variables: %d\n", MAX_SYMBOLS - table->ptr_tmp);
}

void print_table(struct SymbolTable *table) {
    printf("\n--------SYMBOL TABLE------\n");
    printf("--------SYMBOLS------\n");
    for (int i = 0; i <= table->ptr; i++) {
        printf("address: %d   id: %s    scope: %d\n", table->symbols[i].address, table->symbols[i].id, table->symbols[i].scope);
    }
    printf("------TEMPS--------\n");
    printf("Number of temporary variables at the end of compilation: %d\n", MAX_SYMBOLS - table->ptr_tmp);
    printf("Total number of temporaries created during compilation: %d\n", table->total_temps);
    printf("-----------------------------\n\n");
}

void print_deleted_symbols_table(struct DeletedSymbolsTable *table) {
    printf("--------DELETED SYMBOLS TABLE------\n");
    for (int i = 0; i < table->count; i++) {
        printf("Address: %d, ID: %s, Scope: %d\n", table->symbols[i].address, table->symbols[i].id, table->symbols[i].scope);
    }
    printf("-----------------------------\n\n");
}
