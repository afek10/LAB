
#include "complex.h"

void execute_command(char* command);
complex* find_comp (char comp);

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
        read_comp(find_comp(comp), real, imag);
    } 
    else if (sscanf(command, "print_comp %c", &comp) == 1) 
    {
        printf("Printing complex %c\n", comp);
        print_comp(*find_comp(comp)); 
    } 
    else if (sscanf(command, "print_comp %c", &comp) == 1) 
    {
        printf("Printing complex %c\n", comp);
        print_comp(*find_comp(comp)); 
    } 
    else 
    {
        printf("Error: Unknown command or invalid format.\n");
    }
}


complex* find_comp (char comp)
{
    switch (comp)
    {
    case 'A':
        return &A;
        break;
    case 'B':
        return &B;
        break;
    case 'C':
        return &C;
        break;
    case 'D':
        return &D;
        break;
    case 'E':
        return &E;
        break;
    case 'F':
        return &F;
        break;
    default: 
        return NULL;
    }
}