#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate_word_score(string word);
void string_lower(string s);

int main(void)
{

    // asks user 1 and user 2 string inputs
    string player1, player2;
    player1 = get_string("Player 1: ");
    //   alph_input_checker(player1);

    player2 = get_string("Player 2: ");
    //   alph_input_checker(player2);

    string_lower(player1);
    string_lower(player2);

    int sum_player_1 = calculate_word_score(player1);
    int sum_player_2 = calculate_word_score(player2);

    if (sum_player_1 > sum_player_2)
    {
        printf("Player 1 wins!\n");
    }
    else if (sum_player_1 < sum_player_2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    // checks which sum (user1 or user2) is greater or tie

    // print all letters of a word
}

// assign the right index for inputed char and sum their values
// e.g: "j index in alph is:  ('j'-'a') = 9 (ascii);
int calculate_word_score(string word)
{
    int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int sum = 0;
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        // indexar alph correspondente ao index char i
        int alph_index = word[i] - 'a';
        int array_elements_counter = sizeof(values) / sizeof(values[0]);
        if (alph_index >= 0 && alph_index < array_elements_counter)
        {
            sum += values[alph_index];
        }
    }
    return sum;
}

// transform all string chars into lowercases
void string_lower(string s)
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        char newchar = tolower(s[i]);
        char oldchar = s[i];
        if (isalpha(oldchar))
        {
            s[i] = newchar;
        }
    }
}
