#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

char *assemble_x86_64(char *instruction, uint64_t immediate, char *reg1, char *reg2, int mem) {
    // Define opcodes for x86-64 instructions
    const uint8_t MOVQ = 0x48;
    const uint8_t ADDQ = 0x48;
    const uint8_t ADDL = 0x83;
    const uint8_t IMULW = 0x66;
    const uint8_t MULQ = 0x48;
    uint8_t opcode = 0;
    uint8_t reg1_encoding = 0;
    uint8_t reg2_encoding = 0;
    
    if (strcmp(instruction, "movl") == 0) {
        opcode = MOVQ;
        immediate &= 0xFFFFFFFF;
    } else if (strcmp(instruction, "movq") == 0) {
        opcode = MOVQ;
    } else if (strcmp(instruction, "addq") == 0) {
        opcode = ADDQ;
    } else if (strcmp(instruction, "addl") == 0) {
        opcode = ADDL;
        immediate &= 0xFFFFFFFF;
    } else if (strcmp(instruction, "imulw") == 0) {
        opcode = IMULW;
    } else if (strcmp(instruction, "mulq") == 0) {
        opcode = MULQ;
    } else {
        printf("Unknown instruction: %s\n", instruction);
        return NULL;
    }
    
    // Define the register encodings
    if (!strcmp(reg1, "rdi"))
        reg1_encoding = 0xC7;
    else if (!strcmp(reg1, "rsi"))
        reg1_encoding = 0xC3;
    else if (!strcmp(reg1, "rax"))
        reg1_encoding = 0xC0;
    else {
        printf("Invalid register 1: %s", reg1);
        return NULL;
    }
    
    if (!strcmp(reg2, "rdi"))
        reg2_encoding = 0xC7;
    else if (!strcmp(reg2, "rsi"))
        reg2_encoding = 0xC3;
    else if (!strcmp(reg2, "rax"))
        reg2_encoding = 0xC0;
    
    printf("Assembly Instruction: %s\n", instruction);
    printf("Machine Code: %02X %02X %02X %08lX\n", opcode, reg1_encoding, reg2_encoding, immediate);
    char *assemblyString = malloc(100);
    if (assemblyString != NULL) {
        sprintf(assemblyString, "Assembly Instruction: %s\nMachine Code: %02X %02X %02X %08lX\n", instruction, opcode, reg1_encoding, reg2_encoding, immediate);
    }
    return assemblyString;
}

int main() {
    char *reg1;
    char *reg2;
    char *operation;
    uint64_t immediate;
    int flagOpFound;
    int flagRegFound;
    int i;
    char *operationList[] = {"movl", "movq", "addq", "addl", "imulw", "mulq"};
    char *registerList[] = {"rdi", "rsi", "rax"};
    char const* const fileName = "project1input.txt";
    FILE* file = fopen(fileName, "r"); 
    if (!file){
        printf("\n Unable to open : %s ", fileName);
        return -1;
    }
    FILE* outputFile = fopen("project1output.txt", "w");
    if (!outputFile) {
        printf("\n Unable to create output file");
        return -1;
    }
    
    char line[500];
    char *newLine;
    
    while (fgets(line, 500, file)) {
        reg1 = "";
        reg2 = "";
        operation = "";
        immediate = 0;
        flagOpFound = 0;
        flagRegFound = 0;
        i = 0;
        
        // Searching for operation in the line
        while (operationList[i] && !flagOpFound) {
            if (strstr(line, operationList[i])) {
                flagOpFound = 1;
                operation = operationList[i];
            }
            i++;
        }
        
        if (!flagOpFound) {
            printf("Unknown operation in line: %s\n", line);
            continue;  // Skip to the next line if operation is not found
        }
        
        newLine = line + strlen(operation);
        i = 0;
        
        // Searching for registers after the operation
        while (newLine[i] != '\0') {
            if (newLine[i] == '$') {
                i++;
                char *endptr;
                int value = strtol(&newLine[i], &endptr, 10);
                // check
                if (endptr != &newLine[i]) 
                    immediate = value;
    
            } else if (newLine[i] == '%' && newLine[i + 1] != '\0' && newLine[i + 1] >= 'a' && newLine[i + 1] <= 'z') {
                // Assuming registers are lowercase in the assembly code
                char registerName[4]; // Assuming the maximum length of a register name is 3 characters
                int j = 0;
                i++; // skip '%'
                while (newLine[i] >= 'a' && newLine[i] <= 'z') {
                    registerName[j++] = newLine[i++];
                }
                registerName[j] = '\0';
                // Check if the register name is valid
                int validRegister = 0;
                for (int k = 0; k < sizeof(registerList) / sizeof(registerList[0]); k++) {
                    if (strcmp(registerName, registerList[k]) == 0) {
                        validRegister = 1;
                        break;
                    }
                }
                
                if (validRegister) {
                    if (!flagRegFound) {
                        reg1 = strdup(registerName);
                        flagRegFound = 1;
                    } else {
                        reg2 = strdup(registerName);
                    }
                } else {
                    printf("Invalid register name: %s\n", registerName);
                }
            }
            i++;
        }
        char* assemblyOutput = assemble_x86_64(operation, immediate, reg1, reg2, 0);
        fprintf(outputFile, "%s\n", assemblyOutput);
        free(assemblyOutput);
    }
    fclose(file);
    return 0;
}
