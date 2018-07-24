/*this program prompts the user for plain text and converts it into ciphertext by rotating each letter by k positions
specified in the command line argument*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
//check to see if user entered one command line argument
    if (argc != 2)
    {
        printf("Error! You have to enter one command line argument only.\n");
        return 1;
    }

    int k = atoi(argv[1]);

    string plain_text;
    plain_text = get_string("plaintext:  ");
    char ciphertext[strlen(plain_text)];
    char temp;

//the for loop keeps all plain text characters that are not alphabets while rotating all alphabets to the specified position from the user
    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        if ((plain_text[i] < 'A') || (('Z' < plain_text[i]) && (plain_text[i] < 'a')) || (plain_text[i] > 'z'))
        {
            ciphertext[i] = plain_text[i];
        }

        else if ((('A' <= plain_text[i]) && (plain_text[i] <= 'Z')) || (('a' <= plain_text[i]) && (plain_text[i] <= 'z')))
        {
            temp = plain_text[i] + (k % 26);

            if ((('A' <= temp) && (temp <= 'Z')) || (('a' <= temp) && (temp <= 'z')))
            {
                ciphertext[i] = temp;
            }

            else
            {
                temp = temp - 26;
                ciphertext[i] = temp;
            }
        }
    }

    printf("ciphertext: %s\n", ciphertext);
}

