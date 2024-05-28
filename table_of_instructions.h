#ifndef TABLE_OF_INSTRUCTIONS_H
#define TABLE_OF_INSTRUCTIONS_H

#define MAX_INSTRUCTIONS 1000

struct Instruction {
    char *instruction;
    int arg1;
    int arg2;
    int arg3;
    int index;
};

struct InstructionTable {
    struct Instruction instructions[MAX_INSTRUCTIONS];
    int current_index;
};

void initialize_instruction_table(struct InstructionTable *table);

void add_instruction(struct InstructionTable *table, char *instruction, int arg1, int arg2, int arg3);
struct Instruction read_instruction(struct InstructionTable *table, int index);

void patch_instruction_arg1(struct InstructionTable *table,int index,int arg1);
void patch_instruction_arg2(struct InstructionTable *table,int index,int arg2);

int get_index_actuel_instructions(struct InstructionTable *table);

void print_instruction_table(struct InstructionTable *table);


void write_instructions_to_file(struct InstructionTable table);
void write_instructions_to_file_read(struct InstructionTable table);
void write_instructions_to_file_VHDL(struct InstructionTable table);

char * convert_instruction_into_hexa(struct Instruction anInstruction);
char * convert_instruction_name_into_number(char * instructionName);

#endif
