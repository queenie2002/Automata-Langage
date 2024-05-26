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


void patch_instruction_arg1(struct InstructionTable *table,int index,int arg1){
    table->instructions[index].arg1 = arg1;
    printf("Patch instruction at index %d\n",index);
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


// Writes the instructions in a file to be used at the end of the parsing
void write_instructions_to_file(struct InstructionTable table) {

    // Open file to write in
    FILE *file = fopen("output/instructions.txt", "w");
    if (file == NULL) {
        perror("Couldn't open file");
    }

    // Get and write the instructions in file
    for (int i=0; i < table.current_index; i++) {
        struct Instruction anInstruction = table.instructions[i];
        fprintf(file, "%s %d %d %d\n",
               table.instructions[i].instruction,
               table.instructions[i].arg1,
               table.instructions[i].arg2,
               table.instructions[i].arg3);

        
        //the hexa version
        fprintf(file, "%s\n",convert_instruction_into_hexa(anInstruction));
       
    }

    // Close file
    if (fclose(file) != 0) {
        perror("Couldn't to close file");
    }
}


// Convert instruction into hexa instruction
char * convert_instruction_into_hexa(struct Instruction anInstruction) {

    char hexInstruction[3];
    char hexArg1[3];
    char hexArg2[3];
    char hexArg3[3];

    // The Converted Instruction we return
    char *hexFinalInstruction = (char *) malloc (9 * sizeof(char));

    // Convert instruction into corresponding hexadecimal number

    if (strcmp(anInstruction.instruction, "NOP") == 0) {
        strcpy(hexInstruction, "00");
    } else if (strcmp(anInstruction.instruction, "ADD") == 0) {
        strcpy(hexInstruction, "01");
    } else if (strcmp(anInstruction.instruction, "MUL") == 0) {
        strcpy(hexInstruction, "02");
    } else if (strcmp(anInstruction.instruction, "SUB") == 0) {
        strcpy(hexInstruction, "03");
    } else if (strcmp(anInstruction.instruction, "DIV") == 0) {
        strcpy(hexInstruction, "04");
    } else if (strcmp(anInstruction.instruction, "COP") == 0) {
        strcpy(hexInstruction, "05");
    } else if (strcmp(anInstruction.instruction, "AFC") == 0) {
        strcpy(hexInstruction, "06");
    } else if (strcmp(anInstruction.instruction, "JMP") == 0) {
        strcpy(hexInstruction, "07");
    } else if (strcmp(anInstruction.instruction, "JMF") == 0) {
        strcpy(hexInstruction, "08");
    } else if (strcmp(anInstruction.instruction, "INF") == 0) {
        strcpy(hexInstruction, "09");
    } else if (strcmp(anInstruction.instruction, "SUP") == 0) {
        strcpy(hexInstruction, "0a");
    } else if (strcmp(anInstruction.instruction, "EQU") == 0) {
        strcpy(hexInstruction, "0b");
    } else if (strcmp(anInstruction.instruction, "PRI") == 0) {
        strcpy(hexInstruction, "0c");
    } else {
        strcpy(hexInstruction, "ff");
        printf("Didn't recognize a proper instruction: %s\n ", anInstruction.instruction);
    }

    sprintf(hexArg1, "%02x", anInstruction.arg1);    
    sprintf(hexArg2, "%02x", anInstruction.arg2);
    sprintf(hexArg3, "%02x", anInstruction.arg3);

    // Concatenate all strings
    strcpy(hexFinalInstruction, hexInstruction);
    strcat(hexFinalInstruction, hexArg1);
    strcat(hexFinalInstruction, hexArg2);
    strcat(hexFinalInstruction, hexArg3);

   return hexFinalInstruction;
}


