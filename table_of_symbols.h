#ifndef TABLE_OF_SYMBOLS_H
#define TABLE_OF_SYMBOLS_H

#include <stdbool.h>

#define MAX_SYMBOLS 100

struct Symbol {
    char id[50];
    char *type;
    int address; // Address of the symbol in the table of symbols
};

struct SymbolTable {
    struct Symbol symbols[MAX_SYMBOLS];
    int ptr;
    int ptr_tmp;
};

void initialize_table(struct SymbolTable *table);

void add_symb(struct SymbolTable *table, char *id);
void add_tmp(struct SymbolTable *table);

int get_symb(struct SymbolTable *table, char *id);
int get_last_tmp(struct SymbolTable *table);

void free_last_tmp(struct SymbolTable *table);

void PrintTable(struct SymbolTable *table);

#endif