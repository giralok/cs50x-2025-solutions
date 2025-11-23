// Implement a program in C that prompts the user for their name and then says hello to that user.
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("Whats your name? ");
    printf("hello, %s\n", answer);
}
