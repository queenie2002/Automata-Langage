#ifndef TABLE_OF_SYMBOLS_H
#define TABLE_OF_SYMBOLS_H

#include <stdbool.h>

#define MAX_SYMBOLS 256

struct Symbol {
    char id[50];
    int address; // Address of the symbol in the table of symbols
    int scope;
};

struct SymbolTable {
    struct Symbol symbols[MAX_SYMBOLS];
    int ptr;
    int ptr_tmp;
    int scope_general;
    int total_temps;
};

struct DeletedSymbol {
    char id[50];
    int address;
    int scope;
};

struct DeletedSymbolsTable {
    struct DeletedSymbol symbols[MAX_SYMBOLS];
    int count;
};

void initialize_symbol_table(struct SymbolTable *table);
void initialize_deleted_symbols_table(struct DeletedSymbolsTable *table);

void add_symb(struct SymbolTable *table, char *id);
void add_tmp(struct SymbolTable *table);

int get_symb(struct SymbolTable *table, char *id);
int get_last_tmp(struct SymbolTable *table);

int get_symbol_table_size(struct SymbolTable* table);

void free_all_tmp(struct SymbolTable *table);
void free_last_tmp(struct SymbolTable *table);


void increment_scope(struct SymbolTable *table);
void decrement_scope(struct SymbolTable *table, struct DeletedSymbolsTable *deletedTable);
int get_scope(struct SymbolTable *table, char *id);
int get_last_tmp_scope(struct SymbolTable *table);



void print_table(struct SymbolTable *table);
void print_deleted_symbols_table(struct DeletedSymbolsTable *table);

#endif