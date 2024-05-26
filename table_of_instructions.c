#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_of_instructions.h"

void initialize_instruction_table(struct InstructionTable *table) {
    table->current_index = 0;
}

void add_instruction(struct InstructionTable *table, char *instruction, int arg1, int arg2, int arg3) {
    if (table->current_index < MAX_INSTRUCTIONS) {
        table->instructions[table->current_index].instruction = strdup(instruction);
        table->instructions[table->current_index].arg1 = arg1;
        table->instructions[table->current_index].arg2 = arg2;
        table->instructions[table->current_index].arg3 = arg3;
        table->instructions[table->current_index].index = table->current_index;

        printf("\t\t\t%d - %s   %d  %d  %d\n",
        table->instructions[table->current_index].index,
        table->instructions[table->current_index].instruction,
        table->instructions[table->current_index].arg1,
        table->instructions[table->current_index].arg2,
        table->instructions[table->current_index].arg3);


        table->current_index++;


        
    } else {
        printf("Instruction table is full, cannot add more instructions.\n");
    }
}

struct Instruction read_instruction(struct InstructionTable *table, int index) {
    if (index < 0 || index >= table->current_index){
        printf( "Invalid index: %d\n", index);
    }
        return table->instructions[index];
    
}

void patch_instruction_arg2(struct InstructionTable *table,int index,int arg2){
    table->instructions[index].arg2 = arg2;
    printf("Patch instruction at index %d\n",index);
} 

int get_index_actuel_instructions(struct InstructionTable *table){
    return table->current_index;
}  

void print_instruction_table(struct InstructionTable *table) {
    printf("-------INSTRUCTIONS TABLE--------\n");
    for (int i = 0; i < table->current_index; i++) {
        printf("%d - %s   %d  %d  %d\n",
               table->instructions[i].index,
               table->instructions[i].instruction,
               table->instructions[i].arg1,
               table->instructions[i].arg2,
               table->instructions[i].arg3);
    }
    printf("-----------------------------\n\n\n");
}
