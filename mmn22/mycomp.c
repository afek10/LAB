#include "complex.h"

/**
 * Function declarations for managing complex numbers and commands.
 */
void execute_command(char* command);
complex* find_comp (char comp);
void clean_input(char* input);
int num_of_commas(char* cmd);
bool multiple_commas(char* cmd);

/**
 * Definitions of complex numbers A, B, C, D, E, F, initialized to (0, 0).
 */
complex A = {0, 0}, B = {0, 0}, C = {0, 0}, D = {0, 0}, E = {0, 0}, F = {0, 0};

/**
 * Main function of the program. It runs an infinite loop to accept user commands for performing operations on complex numbers.
 * The program stops when the user enters the command "stop".
 */
int main() {
    char input[INPUT_SIZE];

    printf("Welcome to the Complex Numbers Program!\nPlease enter a command (or 'stop' to exit):");

    while (1) 
    {
        printf("\n> ");
        fgets(input, INPUT_SIZE, stdin);
        clean_input(input);
        if (input[strlen(input) - 1] == '\n') {input[strlen(input) - 1] = '\0';}

        if (strncmp(input, "stop", 4) == 0) 
        {
            if(strlen(input) > 4)
            {
                printf("Extraneous text after end of command\n");
            }
            else
            {
                printf("Program terminated.\n");
                break;
            }
        }

        execute_command(input);
    }
    return 0;
}

/**
 * Parses and executes the user command for complex number operations.
 * Supports commands like read_comp, print_comp, add_comp, sub_comp, etc.
 * Handles various errors such as missing parameters, invalid commands, and undefined variables.
 * 
 * @param command The input command provided by the user.
 */
void execute_command(char* command) 
{
    char comp1 = -1, comp2 = -1;
    double real = -1, imag = -1;
    int numOfVar = 0, numOfCommas = num_of_commas(command);
    
    printf("%s", command);
    
    // Check for extraneous text or multiple commas in the command.
    if(command[strlen(command) - 1] == ',')
    {
        printf("Extraneous text after end of command\n");
        return;
    }
    if(multiple_commas(command))
    {
        printf("Multiple consecutive commas\n");
        return;
    }

    // Process the command using sscanf to determine its type and arguments.
    if (numOfVar = sscanf(command, "read_comp %c, %lf, %lf", &comp1, &real, &imag)) 
    {
        if (numOfVar < 3) 
        {
            if(numOfCommas == 2)
            {
                printf("Invalid parameter – not a number\n");
                return;
            }
            if(numOfCommas > 2)
            {
                printf("Extraneous text after end of command\n");
                return;
            }
            printf("Missing parameter\n");
            return;
        }
        if(comp1 == ',')
        {
            printf("Illegal comma\n");
            return;
        }
        if (find_comp(comp1) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        printf("Setting complex %c to %.2f + (%.2f)i\n", comp1, real, imag);
        read_comp(find_comp(comp1), real, imag);
    } 
    else if (numOfVar = sscanf(command, "print_comp %c", &comp1)) 
    {
        if (numOfVar < 1) 
        {
            if(numOfCommas > 0)
            {
                printf("Extraneous text after end of command\n");
                return;
            }
            printf("Missing parameter\n");
            return;
        }
        if(comp1 == ',')
        {
            printf("Illegal comma\n");
            return;
        }
        if (find_comp(comp1) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        printf("Printing complex %c\n", comp1);
        print_comp(*find_comp(comp1)); 
    } 
    else if (numOfVar = sscanf(command, "add_comp %c, %c", &comp1, &comp2)) 
    {
        if (numOfVar < 2) 
        {
            if(numOfCommas == 1)
            {
                printf("Invalid parameter – not a number\n");
                return;
            }
            if(numOfCommas > 1)
            {
                printf("Extraneous text after end of command\n");
                return;
            }
            printf("Missing parameter\n");
            return;
        }
        if(comp1 == ',')
        {
            printf("Illegal comma\n");
            return;
        }
        if (find_comp(comp1) == NULL || find_comp(comp2) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        printf("Add complex %c to complex %c\n", comp1, comp2);
        add_comp(*find_comp(comp1), *find_comp(comp2)); 
    }
    else if (numOfVar = sscanf(command, "sub_comp %c, %c", &comp1, &comp2)) 
    {
        if (numOfVar < 2) 
        {
            if(numOfCommas == 1)
            {
                printf("Invalid parameter – not a number\n");
                return;
            }
            if(numOfCommas > 1)
            {
                printf("Extraneous text after end of command\n");
                return;
            }
            printf("Missing parameter\n");
            return;
        }
        if(comp1 == ',')
        {
            printf("Illegal comma\n");
            return;
        }
        if (find_comp(comp1) == NULL || find_comp(comp2) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        printf("Sub complex %c from complex %c\n", comp2, comp1);
        sub_comp(*find_comp(comp1), *find_comp(comp2)); 
    }
    else if (numOfVar = sscanf(command, "mult_comp_real %c, %lf", &comp1, &real)) 
    {
        if (numOfVar < 2) 
        {
            if(numOfCommas == 1)
            {
                printf("Invalid parameter – not a number\n");
                return;
            }
            if(numOfCommas > 1)
            {
                printf("Extraneous text after end of command\n");
                return;
            }
            printf("Missing parameter\n");
            return;
        }
        if(comp1 == ',')
        {
            printf("Illegal comma\n");
            return;
        }
        if (find_comp(comp1) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        printf("Multiply complex %c by real number %.2f\n", comp1, real);
        mult_comp_real(*find_comp(comp1), real); 
    }
    else if (numOfVar = sscanf(command, "mult_comp_img %c, %lf", &comp1, &imag)) 
    {
        if (numOfVar < 2) 
        {
            if(numOfCommas == 1)
            {
                printf("Invalid parameter – not a number\n");
                return;
            }
            if(numOfCommas > 1)
            {
                printf("Extraneous text after end of command\n");
                return;
            }
            printf("Missing parameter\n");
            return;
        }
        if(comp1 == ',')
        {
            printf("Illegal comma\n");
            return;
        }
        if (find_comp(comp1) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        printf("Multiply complex %c by imaginary number %.2fi\n", comp1, imag);
        mult_comp_img(*find_comp(comp1), imag); 
    }
    else if (numOfVar = sscanf(command, "mult_comp_comp %c, %c", &comp1, &comp2)) 
    {
        if (numOfVar < 2) 
        {
            if(numOfCommas == 1)
            {
                printf("Invalid parameter – not a number\n");
                return;
            }
            if(numOfCommas > 1)
            {
                printf("Extraneous text after end of command\n");
                return;
            }
            printf("Missing parameter\n");
            return;
        }
        if(comp1 == ',')
        {
            printf("Illegal comma\n");
            return;
        }
        if (find_comp(comp1) == NULL || find_comp(comp2) == NULL) 
        {
            printf("Undefined complex variable\n");
            return;
        }
        printf("Multiply complex %c by complex %c\n", comp1, comp2);
        mult_comp_comp(*find_comp(comp1), *find_comp(comp2)); 
    }
    else if (numOfVar = sscanf(command, "abs_comp %c", &comp1))
    {
        if (numOfVar < 1) 
        {
            if(numOfCommas > 0)
            {
                printf("Extraneous text after end of command\n");
                return;
            }
            printf("Missing parameter\n");
            return;
        }
        if (find_comp(comp1) == NULL) 
        {
            printf("Undefined complex variable\n");
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

/**
 * Checks if there are multiple consecutive commas in the given command.
 * 
 * @param cmd The input command string.
 * @return true if multiple consecutive commas are found, false otherwise.
 */
bool multiple_commas(char* cmd)
{
    int i;
    for(i = 1; cmd[i] != '\0'; i++)
    {
        if (cmd[i] == ',' && cmd[i - 1] == ','){return true;}
    }
    return false;
}

/**
 * Counts the number of commas in the given command.
 * 
 * @param cmd The input command string.
 * @return The number of commas in the command.
 */
int num_of_commas(char* cmd)
{
    int result = 0, i;
    for(i = 0; cmd[i] != '\0'; i++)
    {
        if (cmd[i] == ','){result++;}
    }
    return result;
}

/**
 * Finds and returns a pointer to the specified complex number variable (A, B, C, D, E, F).
 * 
 * @param comp The character representing the complex number (e.g., 'A').
 * @return A pointer to the complex number if it is defined, otherwise NULL.
 */
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

/**
 * Cleans the input command by removing unnecessary spaces and tabs.
 * Converts multiple spaces/tabs to a single space and removes trailing spaces.
 * 
 * @param input The input command string to be cleaned.
 */
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
    strcpy(input, cleaned);
}
