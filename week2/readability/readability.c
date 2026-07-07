#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

float calculate_readability(string text);
float letters_per_100_words(int letters, int words);
float sentences_per_100_words(int sentences, int words);

int main()
{
    string text = "In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.";
    float index = calculate_readability(text);

    printf("index: %f\n", index);

    return 0;
}

float calculate_readability(string text)
{
    int letters = 0;
    // Final word doesn't get picked up due to conflict with period
    // this accounts for it
    int words = 1;
    int sentences = 0;

    char letter = ' ';
    // Letters are alphabetic, sentences delimited by a period
    // words delimited by a space
    for(int i = 0; i < strlen(text); ++i){
        
        if(isalpha(text[i])){
            letters++;
        }else if(text[i] == '.'){
            sentences++;
        }else if(isspace(text[i])){
            printf("butts\n");
            words++;
        }
    }


    // 0.0588 * L - 0.296 * S - 15.8
    float letter_part = 0.0588 * letters_per_100_words(letters, words);
    float sentence_part = 0.296 * sentences_per_100_words(sentences, words);
    return letter_part - sentence_part - 15.8;
}

float letters_per_100_words(int letters, int words)
{    
    return (float)letters / ((float)words / 100);
}

float sentences_per_100_words(int sentences, int words)
{
    return (float)sentences / ((float)words / 100);
}