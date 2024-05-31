#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_of_functions.h"

// Initialize the function table
void initialize_function_table(struct FunctionTable* table) {
    table->size = 0;
}

// Add a function to the table
void add_function(struct FunctionTable* table, const char* id, int startADDR) {
    if (table->size < MAX_FUNCTIONS) {
        strncpy(table->functions[table->size].id, id, 50);
        table->functions[table->size].startADDR = startADDR;
        table->size++;
    } else {
        printf("Function table is full!\n");
    }
}

// Get the starting address of a function by its identifier
int get_function_address(struct FunctionTable* table, const char* id) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->functions[i].id, id) == 0) {
            return table->functions[i].startADDR;
        }
    }
    return -1; // Return -1 if the function is not found
}

// Get the current function based on the instruction line
char* get_current_function(struct FunctionTable* table, int currentLine) {
    char* currentFunction = NULL;
    for (int i = 0; i < table->size; i++) {
        if (currentLine >= table->functions[i].startADDR) {
            if (i == table->size - 1 || currentLine < table->functions[i + 1].startADDR) {
                currentFunction = table->functions[i].id;
                break;
            }
        }
    }
    return currentFunction;
}

// Print the contents of the function table
void print_function_table(struct FunctionTable* table) {
    printf("---------FUNCTION TABLE-----------");
    printf("\nID\t\tStartAddress\n");
    printf("-----------------------------\n");
    for (int i = 0; i < table->size; i++) {
        printf("%s\t\t%d\n", table->functions[i].id, table->functions[i].startADDR);
    }
    printf("-----------------------------\n");
}