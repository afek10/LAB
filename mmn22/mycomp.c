
#include "complex.h"

void execute_command(char* command);
complex* find_comp (char comp);
void clean_input(char* input);
int checkCommand(char ch, double real, double img, int numOfVar, char* cmd);

complex A = {0, 0}, B = {0, 0}, C = {0, 0}, D = {0, 0}, E = {0, 0}, F = {0, 0};

int main() {
    
    char input[INPUT_SIZE];

    printf("Welcome to the Complex Numbers Program!\nPlease enter a command (or 'stop' to exit):");

    while (1) 
    {
        printf("\n> ");
        fgets(input, INPUT_SIZE, stdin);
        clean_input(input);
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
    char comp1, comp2;
    double real = -1, imag = -1;
    int numOfVar = 0;

    if (numOfVar = sscanf(command, "read_comp %c, %lf, %lf", &comp1, &real, &imag)) 
    {
        if (find_comp(comp1) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        if (numOfVar < 3) 
        {
            printf("Missing parameter\n");
            return;
        }
        printf("Setting complex %c to %.2f + (%.2f)i\n", comp1, real, imag);
        read_comp(find_comp(comp1), real, imag);
    } 
    else if (numOfVar = sscanf(command, "print_comp %c", &comp1)) 
    {
        if (find_comp(comp1) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        if (numOfVar < 1) 
        {
            printf("Missing parameter\n");
            return;
        }
        printf("Printing complex %c\n", comp1);
        print_comp(*find_comp(comp1)); 
    } 
    else if (numOfVar = sscanf(command, "add_comp %c, %c", &comp1, &comp2)) 
    {
        if (find_comp(comp1) == NULL || find_comp(comp2) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        if (numOfVar < 2) 
        {
            printf("Missing parameter\n");
            return;
        }
        printf("Add complex %c to complex %c\n", comp1, comp2);
        add_comp(*find_comp(comp1), *find_comp(comp2)); 
    }
    else if (numOfVar = sscanf(command, "sub_comp %c, %c", &comp1, &comp2)) 
    {
        if (find_comp(comp1) == NULL || find_comp(comp2) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        if (numOfVar < 2) 
        {
            printf("Missing parameter\n");
            return;
        }
        printf("Sub complex %c from complex %c\n", comp2, comp1);
        sub_comp(*find_comp(comp1), *find_comp(comp2)); 
    }
    else if (numOfVar = sscanf(command, "mult_comp_real %c, %lf", &comp1, &real)) 
    {
        if (find_comp(comp1) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        if (numOfVar < 2) 
        {
            printf("Missing parameter\n");
            return;
        }
        printf("Multiply complex %c by real number %.2f\n", comp1, real);
        mult_comp_real(*find_comp(comp1), real); 
    }
    else if (numOfVar = sscanf(command, "mult_comp_img %c, %lf", &comp1, &imag)) 
    {
        if (find_comp(comp1) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        if (numOfVar < 2) 
        {
            printf("Missing parameter\n");
            return;
        }
        printf("Multiply complex %c by imaginary number %.2fi\n", comp1, imag);
        mult_comp_img(*find_comp(comp1), imag); 
    }
    else if (numOfVar = sscanf(command, "mult_comp_comp %c, %c", &comp1, &comp2)) 
    {
        if (find_comp(comp1) == NULL || find_comp(comp2) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        if (numOfVar < 2) 
        {
            printf("Missing parameter\n");
            return;
        }
        printf("Multiply complex %c by complex %c\n", comp1, comp2);
        mult_comp_comp(*find_comp(comp1), *find_comp(comp2)); 
    }
    else if (numOfVar = sscanf(command, "abs_comp %c", &comp1))
    {
        if (find_comp(comp1) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        if (numOfVar < 1) 
        {
            printf("Missing parameter\n");
            return;
        }
        printf("Calculate the absolute value of complex %c\n", comp1);
        abs_comp(*find_comp(comp1)); 
    }  
    else 
    {
        printf("Undefined command name\n");
    }
}

int checkCommand(char ch, double real, double img, int numOfVar, char* cmd)
{

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

void clean_input(char* input) 
{
    char cleaned[INPUT_SIZE];
    int i = 0, j = 0;

    while (input[i] != '\0') 
    {
        if (input[i] != ' ' && input[i] != '\t') 
        {
            cleaned[j] = input[i];
            j++;
        } 
        else 
        {
            if (j > 0 && cleaned[j - 1] != ',' && cleaned[j - 1] != ' ') 
            {
                cleaned[j] = ' ';
                j++;
            }
        }
        i++;
    }
    if (j > 0 && cleaned[j - 1] == ' ') 
    {
        j--;
    }

    cleaned[j] = '\0';
    printf("%s", cleaned);
    strcpy(input, cleaned);
}
