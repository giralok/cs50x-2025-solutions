#include <cs50.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int get_last_digit(long);
int digit_counter(long card_number);

int main(void)
{
    int sum1 = 0;
    int sum2 = 0;

    long card_number, card_sum1, card_sum2;

    card_number = get_long("Number: ");
    int digits = digit_counter(card_number);

    // FIRST CYCLE

    int d0 = 2 * get_last_digit(card_number / 10);

    if (d0 >= 10)
    {
        int d1 = get_last_digit(d0);
        sum1 = sum1 + d1;

        int d2 = d0 / 10;
        sum1 = sum1 + d2;
    }
    else
    {
        sum1 = sum1 + d0;
    }

    card_sum1 = card_number; // igualo o valor de card number pra card_sum
    card_sum1 /= 10;         // divido card sum por 10 pra comecar a dividir por 100

    do
    {
        card_sum1 /= 100;
        int d = 2 * get_last_digit(card_sum1);

        // if digit is greather or equals to ten (2 digits); first add the last digit (%10) then
        // adds the rest as it is an int (integer value)
        if (d >= 10)
        {
            int d1 = get_last_digit(d);
            sum1 = sum1 + d1;

            int d2 = d / 10;
            sum1 = sum1 + d2;
        }

        else

        {
            sum1 = sum1 + d;
        }
        // reduces card number by /10 every loop
    }
    while (card_sum1 > 0);

    // finish second to last
    // starts the second cycle
    // SECOND CYCLE

    card_sum2 = card_number;

    int firstdigit = get_last_digit(card_sum2); // nao precisamos dividir por 10 aqui

    if (firstdigit >= 10)
    {
        int d1 = get_last_digit(firstdigit);
        sum2 = sum2 + d1;

        int d2 = firstdigit / 10;
        sum2 = sum2 + d2;
    }
    else
    {
        sum2 = sum2 + firstdigit;
    }

    do
    {
        card_sum2 /= 100;
        int dd = get_last_digit(card_sum2);

        // if digit is bigger than 10
        if (dd >= 10)

        {

            int d11 = get_last_digit(dd);
            sum2 = sum2 + d11;

            int d22 = dd / 10;
            sum2 = sum2 + d22;
        }

        else

        {
            sum2 = sum2 + dd;
        }
        // reduces card number by x every loop
    }
    while (card_sum2 > 0);

    int total_sum = sum1 + sum2;
    bool valid;
    valid = false;

    if (total_sum % 10 == 0) // if checksum is true then sets valid to 1
    {
        valid = true;
        printf("total sum right");
    }

    do
    {
        card_number /= 10;
    }
    while (card_number > 99); // divides by ten until two digits
    long last_two_digits = card_number;

    // Flag identifier based in the first two digits; only outputs if valid = 1 (checksum = true)

#define MASTERCARD_STARTER_DIGITS_1 51
#define MASTERCARD_STARTER_DIGITS_2 55
#define AMEX_STARTER_DIGITS_1 34
#define AMEX_STARTER_DIGITS_2 37
#define VISA_STARTER_DIGITS_1 40
#define VISA_STARTER_DIGITS_2 49

#define MASTERCARD_POSSIBLE_DIGITS 16
#define AMEX_POSSIBLE_DIGITS 15
#define VISA_POSSIBLE_DIGITS_1 13
#define VISA_POSSIBLE_DIGITS_2 16

    if ((valid == true) &&
        (last_two_digits >= MASTERCARD_STARTER_DIGITS_1 &&
         last_two_digits <= MASTERCARD_STARTER_DIGITS_2) &&
        (digits == MASTERCARD_POSSIBLE_DIGITS))
    {
        printf("MASTERCARD\n");
    }
    else if ((valid == true) &&
             (last_two_digits == AMEX_STARTER_DIGITS_1 ||
              last_two_digits == AMEX_STARTER_DIGITS_2) &&
             (digits == AMEX_POSSIBLE_DIGITS))
    {
        printf("AMEX\n");
    }
    else if ((valid == true) &&
             (last_two_digits >= VISA_STARTER_DIGITS_1 &&
              last_two_digits <= VISA_STARTER_DIGITS_2) &&
             (digits == VISA_POSSIBLE_DIGITS_1 || digits == VISA_POSSIBLE_DIGITS_2))
    {
        printf("VISA\n");
    }
    else
    {
        printf("last two digits: %li\n digits: %i", last_two_digits, digits);
        printf("INVALID\n");
    }
}

// get first last digit of the first number cycle picker; right or wrong means first an second
// cycle, respectively

int digit_counter(long card_number)
{
    int digit = 0;
    do
    {
        card_number /= 10;
        digit++;
    }
    while (card_number > 0);
    return digit;
}

int get_last_digit(long card_number)
{
    // does the remainder of 10 because thats how you get a last digit
    // return the digit that just got as its going to be added a variable in each loop access
    long last_digit = (card_number % 10);
    return last_digit;
}
