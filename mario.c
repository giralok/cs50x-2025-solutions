
// In a file called mario.c in a folder called mario-more, implement a program in C that recreates
// that pyramid, using hashes (#) for bricks, as in the below: And let’s allow the user to decide
// just how tall the pyramids should be by first prompting them for a positive int between, say, 1
// and 8, inclusive.

#include <cs50.h>
#include <stdio.h>

// declare all functions
int get_positive_int(void);
void row_builder(int);
void space_printer(int);

int main(void) // main function

{

    int height = get_positive_int(); // gets the int height input

    for (int i = 1; i <= height; i++) //
    {
        space_printer(height - i);
        row_builder(height - height + i);
    }
}

int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void row_builder(int height) // we need to print from the top to behind as the logical order of
                             // reading of the C compiler
{

    for (int i = 0; i < height; i++) // we loop the first print
    {

        printf("#");
    }

    printf("  ");

    for (int i = 0; i < height; i++)
    {
        printf("#");
    }
    printf("\n");
}

void space_printer(int height)
{

    for (int i = 1; i <= height; i++)
    {
        printf(" ");
    }
}
