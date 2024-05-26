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


// Writes the instructions in a file to be used at the end of the parsing
void write_instructions_to_file(const char *text, struct InstructionTable table) {

    // Open file to write in
    FILE *file = fopen("output/instructions.txt", "w");
    if (file == NULL) {
        perror("Couldn't open file");
        return 1;
    }

    // Get and write the instructions in file
    for (int i=0; i < table->current_index; i++) {
        struct Instruction anInstruction = table.instructions[i];
        fprintf(fprintf, "%d %s %d %d\n",
               table->instructions[i].index,
               table->instructions[i].instruction,
               table->instructions[i].arg1,
               table->instructions[i].arg2);

        // fprintf(fprintf, "%x\n",convert_instruction_into_hexa(anInstruction));
       
    }

    // Close file
    if (fclose(file) != 0) {
        perror("Couldn't to close file");
        return 1;
    }
    //write_instructions_to_file(myInstructionTable);

}

// Convert instruction into hexa instruction
char * convert_instruction_into_hexa(struct Instruction anInstruction) {

    char hexInstruction[2];
    char hexArg1[2];
    char hexArg2[2];
    char hexArg3[2];

    char hexFinalInstruction[8];

    // Convert instruction into corresponding hexadecimal number

    switch (anInstruction.instruction) {
        case "nop":
            hexInstruction = "00";
            break;
        case "add":
            hexInstruction = "01";
            break;
        case "mul":
            hexInstruction = "02";
            break;
        case "sou":
            hexInstruction = "03";
            break;
        case "div":
            hexInstruction = "04";
            break;
        case "cop":
            hexInstruction = "05";
            break;
        case "afc":
            hexInstruction = "06";
            break;
        case "jmp":
            hexInstruction = "07";
            break;
        case "jmf":
            hexInstruction = "08";
            break;
        case "inf":
            hexInstruction = "09";
            break;
        case "sup":
            hexInstruction = "0a";
            break;
        case "equ":
            hexInstruction = "0b";
            break;
        case "pri":
            hexInstruction = "0c";
            break;
        default:
            hexInstruction = "ff";
            printf("Didn't recognize a proper instruction.\n");
            break;
    }

    sprintf(hexArg1, "%x", anInstruction.arg1);
    sprintf(hexArg2, "%x", anInstruction.arg2);
    sprintf(hexArg3, "%x", anInstruction.arg2);

    // Concatenate all strings
    strcpy(hexFinalInstruction, hexInstruction);
    strcat(hexFinalInstruction, hexArg1);
    strcat(hexFinalInstruction, hexArg2);
    strcat(hexFinalInstruction, hexArg3);
   
   return hexFinalInstruction;
}


