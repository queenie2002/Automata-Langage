#include <stdio.h>
#include "table_of_symbols.h"

int main() {
    // Initialize the symbol table
    struct SymbolTable table;
    table = initialize_table(table);

    // Add symbols
    table = add_symb(table, "x");
    table = add_symb(table, "y");
    table = add_symb(table, "z");

    // Add temporary symbols
    table = add_tmp(table);
    table = add_tmp(table);

    // Print the symbol table
    PrintTable(table);

    // Get the address of a symbol
    printf("Address of symbol 'x': %d\n", get_symb(table, "x"));

    // Get the address of the last temporary symbol
    printf("Address of last temporary symbol: %d\n", get_last_tmp(table));

    // Free the last temporary symbol
    table = free_tmp(table);

    // Print the updated symbol table
    PrintTable(table);

    return 0;
}
