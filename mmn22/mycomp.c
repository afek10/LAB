
#include "complex.h"

void execute_command(char* command);
complex A = {0, 0}, B = {0, 0}, C = {0, 0}, D = {0, 0}, E = {0, 0}, F = {0, 0};

int main() {
    
    char input[INPUT_SIZE];

    printf("Welcome to the Complex Numbers Program!\nPlease enter a command (or 'stop' to exit):");

    while (1) 
    {
        printf("\n> ");
        fgets(input, INPUT_SIZE, stdin);
        if (input[strlen(input) - 1] == '\n') {input[strlen(input) - 1] = '\0';}

        if (strcmp(input, "stop") == 0) {
            printf("Program terminated.\n");
            break;
        }

        execute_command(input);
    }
    return 0;
}

void execute_command(char* command) 
{
    char comp;
    double real, imag;
    
    if (sscanf(command, "read_comp %c, %lf, %lf", &comp, &real, &imag) == 3) 
    {
        printf("Setting complex %c to %.2f + (%.2f)i\n", comp, real, imag);
        switch (comp)
        {
        case 'A':
            read_comp(&A, real, imag);
            break;
        case 'B':
            read_comp(&B, real, imag);
            break;
        case 'C':
            read_comp(&C, real, imag);
            break;
        case 'D':
            read_comp(&D, real, imag);
            break;
        case 'E':
            read_comp(&E, real, imag);
            break;
        case 'F':
            read_comp(&F, real, imag);
            break;
        default:
            break;
        }
    } 
    else if (sscanf(command, "print_comp %c", &comp) == 1) 
    {
        printf("Printing complex %c\n", comp);
                switch (comp)
        {
        case 'A':
            print_comp(A);
            break;
        case 'B':
            print_comp(B);
            break;
        case 'C':
            print_comp(C);
            break;
        case 'D':
            print_comp(D);
            break;
        case 'E':
            print_comp(E);
            break;
        case 'F':
            print_comp(F);
            break;
        default:
            break;
        }
    } 
    
    else 
    {
        printf("Error: Unknown command or invalid format.\n");
    }
}
