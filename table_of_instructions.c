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

        printf("\t\t\t%d - %s  %d  %d  %d\n",
        table->instructions[table->current_index].index,
        table->instructions[table->current_index].instruction,
        table->instructions[table->current_index].arg1,
        table->instructions[table->current_index].arg2,
        table->instructions[table->current_index].arg3);

        table->current_index++;

    } else {
        perror("Instruction table is full, cannot add more instructions.\n");
    }
}

struct Instruction read_instruction(struct InstructionTable *table, int index) {
    if (index < 0 || index >= table->current_index){
        perror( "Invalid index\n");
    }
    return table->instructions[index];
}

void patch_instruction_arg1(struct InstructionTable *table,int index,int arg1){
    if (table->current_index>=index) {
        table->instructions[index].arg1 = arg1;
        printf("Patch instruction at index %d\n",index);
    } else {
        perror( "Invalid index\n");
    }
} 

void patch_instruction_arg2(struct InstructionTable *table,int index,int arg2){
    if (table->current_index>=index) {
        table->instructions[index].arg2 = arg2;
        printf("Patch instruction at index %d\n",index);
    }
    else {
        perror( "Invalid index\n");
    }
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

// Convert instruction name into hexadecimal number
char * convert_instruction_name_into_number(char * instructionName) {

    // Convert instruction into corresponding hexadecimal number

    if (strcmp(instructionName, "NOP") == 0) {
        return "00"; 
    } else if (strcmp(instructionName, "ADD") == 0) {
        return "01"; 
    } else if (strcmp(instructionName, "MUL") == 0) {
        return "02"; 
    } else if (strcmp(instructionName, "SUB") == 0) {
        return "03"; 
    } else if (strcmp(instructionName, "DIV") == 0) {
        return "04"; 
    } else if (strcmp(instructionName, "COP") == 0) {
        return "05"; 
    } else if (strcmp(instructionName, "AFC") == 0) {
        return "06"; 
    } else if (strcmp(instructionName, "JMP") == 0) {
        return "07"; 
    } else if (strcmp(instructionName, "JMF") == 0) {
        return "08"; 
    } else if (strcmp(instructionName, "INF") == 0) {
        return "09"; 
    } else if (strcmp(instructionName, "SUP") == 0) {
        return "0a"; 
    } else if (strcmp(instructionName, "EQU") == 0) {
        return "0b"; 
    } else if (strcmp(instructionName, "PRI") == 0) {
        return "0c"; 
    } else if (strcmp(instructionName, "RET") == 0) {
        return "0d";    
    } else if (strcmp(instructionName, "NEQ") == 0) {
        return "0e";
    } else if (strcmp(instructionName, "LEQ") == 0) {
        return "0f";
    } else if (strcmp(instructionName, "GEQ") == 0) {
        return "10";
    } else if (strcmp(instructionName, "AND") == 0) {
        return "11";
    } else if (strcmp(instructionName, "ORR") == 0) {
        return "12";
    } else if (strcmp(instructionName, "NOT") == 0) {
        return "13";
    } else {
        return "ff"; 
        printf("Didn't recognize a proper instruction: %s\n ", instructionName);
    }
}

// Convert instruction into hexa instruction (format: eeffaabbcc)
char * convert_instruction_into_hexa(struct Instruction anInstruction) {

    char hexInstruction[3];
    char hexArg1[3];
    char hexArg2[3];
    char hexArg3[3];

    // The Converted Instruction we return
    char *hexFinalInstruction = (char *) malloc (9 * sizeof(char));

    // Convert instruction into corresponding hexadecimal number

    strcpy(hexInstruction, convert_instruction_name_into_number(anInstruction.instruction));
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

// Writes the instructions in a file to be interpreted (format: ff ff ff ff)
void write_instructions_to_file(struct InstructionTable table) {

    // Open file to write in
    FILE *file = fopen("output_files/instructions.txt", "w");
    if (file == NULL) {
        perror("Couldn't open file");
    }

    // Get and write the instructions in file
    for (int i=0; i < table.current_index; i++) {
        struct Instruction anInstruction = table.instructions[i];
        fprintf(file, "%s %02x %02x %02x\n",
               convert_instruction_name_into_number(table.instructions[i].instruction),
               table.instructions[i].arg1,
               table.instructions[i].arg2,
               table.instructions[i].arg3);
    }

    // Close file
    if (fclose(file) != 0) {
        perror("Couldn't close file");
    }
}

// Writes the instructions in a file to read (format: ADD 01 01 01)
void write_instructions_to_file_read(struct InstructionTable table) {

    // Open file to write in
    FILE *file = fopen("output_files/instructions_to_read.txt", "w");
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
    }

    // Close file
    if (fclose(file) != 0) {
        perror("Couldn't close file");
    }
}

// Writes the instructions in a file for VHDL (format: fafafafa)
void write_instructions_to_file_VHDL(struct InstructionTable table) {

    // Open file to write in
    FILE *file = fopen("output_files/instructions_VHDL.txt", "w");
    if (file == NULL) {
        perror("Couldn't open file");
    }

    // Get and write the instructions in file
    for (int i=0; i < table.current_index; i++) {
        struct Instruction anInstruction = table.instructions[i];
        fprintf(file, "x\"%s\",\n",convert_instruction_into_hexa(anInstruction));
       
    }

    // Close file
    if (fclose(file) != 0) {
        perror("Couldn't close file");
    }
}