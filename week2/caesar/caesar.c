// Program implementing a Caesar cypher

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string new_string(int length);
string encypher_string(string plaintext, int key);
char encypher_letter(char letter, int key);

int main(int argc, char **argv)
{
    if(argc != 2){
        printf("Usage: caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    //Input a plaintext
    string plaintext = get_string("Plaintext: ");
    printf("ciphertext: %s\n", encypher_string(plaintext, key));
    
    return 0;
}

string new_string(int length)
{
    char *new_string = malloc(sizeof(char) * length + 1);
    new_string[length] = '\0';
    return new_string;
}

string encypher_string(string plaintext, int key)
{
    int length = strlen(plaintext);
    // ciphertext will be same length, 
    string ciphertext = new_string(length);

    for(int c = 0; c < length; ++c){
        ciphertext[c] = encypher_letter(plaintext[c], key);
    }

    return ciphertext;
}

char encypher_letter(char letter, int key)
{
    char encoded_letter = ' ';
    char letter_adjust = ' ';
    // Normalize to 0-25 numerical range
    if(islower(letter)){
        letter_adjust = 'a' ;
    }else if(isupper(letter)){
        letter_adjust = 'A';
    }else{
        letter_adjust = 0;
    }
    encoded_letter = letter - letter_adjust;

    // Encode to a different character per key
    encoded_letter = (encoded_letter + key) % 26;

    //Correct to alphabetical range
    encoded_letter += letter_adjust;

    return encoded_letter;
}   


