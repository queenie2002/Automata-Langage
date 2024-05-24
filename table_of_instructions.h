#ifndef TABLE_OF_INSTRUCTIONS_H
#define TABLE_OF_INSTRUCTIONS_H

#define MAX_INSTRUCTIONS 100

struct Instruction {
    char *instruction;
    int arg1;
    int arg2;
    int index;
};

struct InstructionTable {
    struct Instruction instructions[MAX_INSTRUCTIONS];
    int current_index;
};

void initialize_instruction_table(struct InstructionTable *table);
void add_instruction(struct InstructionTable *table, char *instruction, int arg1, int arg2);
struct Instruction read_instruction(struct InstructionTable *table, int index);
void print_instruction_table(struct InstructionTable *table);

#endif
