#include <stdio.h>
#include "table_of_instructions.h"

int main() {
    InstructionTable table;
    initialize_table(&table);

    add_instruction(&table, "AFC", 1, 10);
    add_instruction(&table, "COP", 2, 3);
    add_instruction(&table, "JMF", 1, 4);

    print_table(&table);

    Instruction *instr = read_instruction(&table, 1);
    if (instr) {
        printf("Read instruction - Index: %d, Instruction: %s, Operand1: %d, Operand2: %d\n",
               instr->index, instr->instruction, instr->arg1, instr->arg2);
    }

    return 0;
}
