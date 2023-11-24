#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MWS "%*[ \f\n\t\v]"

enum Operator { ADD, SUB, MUL, DIV };

struct Function {
    enum Operator op;
    int k;
    int N;
};

void generateAssembly(struct Function func) {
    FILE *outputFile = fopen("project2output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return;
    }
    fprintf(outputFile, "myFunction:\n");
    fprintf(outputFile, "\tpush %%ebp\n");
    fprintf(outputFile, "\tmov %%ebp, %%esp\n");
    fprintf(outputFile, "\tsub %%esp, $4\n");

    fprintf(outputFile, "\tmov %%eax, $0\n");

    fprintf(outputFile, "\tmov %%esi, $%d\n", func.k);
    fprintf(outputFile, "\tcmp %%esi, $%d\n", func.N);
    
    //check for loop unrolling loop(N-K)<=2
    int iterations = func.N - func.k;
    if (iterations <= 2) {
        if (iterations >= 1) {
            fprintf(outputFile, "\tmov %%ecx, 8(%%ebp)\n");
            fprintf(outputFile, "\tmov %%edx, 12(%%ebp)\n");

            switch (func.op) {
                case ADD:
                    fprintf(outputFile, "\tadd %%eax, %%ecx\n");
                    break;
                case SUB:
                    fprintf(outputFile, "\tsub %%eax, %%ecx\n");
                    break;
                case MUL:
                    fprintf(outputFile, "\timul %%ecx, %%edx\n");
                    fprintf(outputFile, "\tadd %%eax, %%ecx\n");
                    break;
                case DIV:
                    fprintf(outputFile, "\tcdq\n");
                    fprintf(outputFile, "\tidiv %%edx\n");
                    fprintf(outputFile, "\tadd %%eax, %%edx\n");
                    break;
                default:
                    fprintf(outputFile, "\t; Unsupported operator\n");
            }

            fprintf(outputFile, "\tshl %%eax, $3\n");
            if (iterations == 1) {
                fprintf(outputFile, "\tjmp endLoop\n");
            }
        }
        if (iterations == 2) {
            fprintf(outputFile, "\tmov %%ecx, 12(%%ebp)\n");
            fprintf(outputFile, "\tmov %%edx, 16(%%ebp)\n");

            switch (func.op) {
                case ADD:
                    fprintf(outputFile, "\tadd %%eax, %%ecx\n");
                    break;
                case SUB:
                    fprintf(outputFile, "\tsub %%eax, %%ecx\n");
                    break;
                case MUL:
                    fprintf(outputFile, "\timul %%ecx, %%edx\n");
                    fprintf(outputFile, "\tadd %%eax, %%ecx\n");
                    break;
                case DIV:
                    fprintf(outputFile, "\tcdq\n");
                    fprintf(outputFile, "\tidiv %%edx\n");
                    fprintf(outputFile, "\tadd %%eax, %%edx\n");
                    break;
                default:
                    fprintf(outputFile, "\t; Unsupported operator\n");
            }

            fprintf(outputFile, "\tshl %%eax, $3\n");
        }
    } else {
        fprintf(outputFile, "\tjge endLoop\n");
        fprintf(outputFile, "loopStart:\n");

        fprintf(outputFile, "\tmov %%ecx, 8(%%ebp)\n");
        fprintf(outputFile, "\tmov %%edx, 12(%%ebp)\n");

        switch (func.op) {
            case ADD:
                fprintf(outputFile, "\tadd %%eax, %%ecx\n");
                break;
            case SUB:
                fprintf(outputFile, "\tsub %%eax, %%ecx\n");
                break;
            case MUL:
                fprintf(outputFile, "\timul %%ecx, %%edx\n");
                fprintf(outputFile, "\tadd %%eax, %%ecx\n");
                break;
            case DIV:
                fprintf(outputFile, "\tcdq\n");
                fprintf(outputFile, "\tidiv %%edx\n");
                fprintf(outputFile, "\tadd %%eax, %%edx\n");
                break;
            default:
                fprintf(outputFile, "\t; Unsupported operator\n");
        }
        fprintf(outputFile, "\tshl %%eax, $3\n");
        fprintf(outputFile, "\tinc %%esi\n");
        fprintf(outputFile, "\tcmp %%esi, $%d\n", func.N);
        fprintf(outputFile, "\tjl loopStart\n");
    }

    fprintf(outputFile, "endLoop:\n");
    fprintf(outputFile, "\tmov %%esp, %%ebp\n");
    fprintf(outputFile, "\tpop %%ebp\n");
    fprintf(outputFile, "\tret");
}

int main() {
    FILE *file = fopen("project2Input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    struct Function myFunc;
    char op[2] = "";
    fscanf(file, " long" MWS "myFunction ( long" MWS "A [ ] , long" MWS
                 "B [ ] , int" MWS "k , int" MWS "N ) {");
    fscanf(file, " long" MWS "C ;");
    fscanf(file, " for ( int" MWS "i = %d ; i < %d ; i ++ ) {", &myFunc.k, &myFunc.N);
    fscanf(file, " ( C = ( A [ i ] %1[-+*/] B [ i ] ) + C ) << 3 ;", op);
    fscanf(file, " } return" MWS "C ; }");
    fclose(file);
    switch (op[0]) {
        case '+':
            myFunc.op = ADD;
            break;
        case '-':
            myFunc.op = SUB;
            break;
        case '*':
            myFunc.op = MUL;
            break;
        case '/':
            myFunc.op = DIV;
            break;
        default:
            printf("Unsupported operator\n");
            fclose(file);
            return 1;
    }

    generateAssembly(myFunc);
    return 0;
}