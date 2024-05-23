#include "table_of_symbols.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void initialize_table(struct SymbolTable *table) {
    table->ptr = -1;
    table->ptr_tmp = MAX_SYMBOLS;
}

void add_symb(struct SymbolTable *table, char *id) {
    if (table->ptr < MAX_SYMBOLS - 1) { // Check if there is space in the table
        table->ptr++;
        struct Symbol symb;
        strcpy(symb.id, id);
        symb.address = table->ptr; // Assign the next available address
        table->symbols[table->ptr] = symb;
    } else {
        printf("Error: Symbol table is full!\n");
    }
}

void add_tmp(struct SymbolTable *table) {
    table->ptr_tmp--;
    struct Symbol symb;
    symb.address = table->ptr_tmp;
    table->symbols[table->ptr_tmp] = symb;
    printf("Number of temporary variables: %d\n", MAX_SYMBOLS - table->ptr_tmp);
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

int get_last_tmp(struct SymbolTable *table) {
    return table->symbols[table->ptr_tmp].address;
}

void free_last_tmp(struct SymbolTable *table) {
    table->ptr_tmp++;
    printf("Number of temporary variables: %d\n", MAX_SYMBOLS - table->ptr_tmp);
}

void PrintTable(struct SymbolTable *table) {
    printf("--------SYMBOL TABLE------\n");
    printf("--------SYMBOLS------\n");
    for (int i = 0; i <= table->ptr; i++) {
        printf("address: %d   id: %s\n", table->symbols[i].address, table->symbols[i].id);
    }
    printf("------TEMPS--------\n");
    printf("Number of temporary variables: %d\n", MAX_SYMBOLS - table->ptr_tmp);
    printf("-----------------------------\n\n\n");
}
