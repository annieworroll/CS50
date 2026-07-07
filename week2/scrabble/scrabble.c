#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int score_word(string word);

int main()
{
    int s = score_word("Ace");

    printf("%i\n", s);

    int first_word_score = score_word(get_string("Player One: "));
    int second_word_score = score_word(get_string("Player Two: "));
    
    if(first_word_score > second_word_score){
        printf("Player One wins!\n");
    }else if(first_word_score < second_word_score){
        printf("Player Two wins!\n");
    }else{
        printf("Tie!\n");
    }

    return 0;
}


int score_word(string word)
{
    // Store letter values in an array
    int values[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1,
                      3, 10, 1, 1, 1, 4, 4, 8, 4, 10};

    int score = 0;

    // Accumulate score, adjusting letter value to a 0-26 range, case 
    // insensitively
    for(int i = 0; i < strlen(word); ++i){
        if(isupper(word[i])){
            score += values[word[i] - 'A'];
        }else if(islower(word[i])){
            score += values[word[i] - 'a'];
        }else{
            //Non alphabetic characters are scored zero
            score += 0;
        }
    }


    return score;
}

