#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{

    // Get input words from both players

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    printf("Score 1: %d ,Score 2: %d \n",score1,score2); // added a score indicator for easier bugfix
    if(score1 > score2)
    {
    printf("Player 1 Wins! \n");
    }
    else if(score1 < score2)
    {
    printf("Player 2 Wins! \n");
    }
    else if(score1 == score2)
    {
    printf("Tie! \n");
    }

}

int compute_score(string word)
{

    int a = 0;
    int n = strlen(word);
    for (int i=0; i < n; i++)//take all the characters and calculate the score
    {

        int s = word[i];
        char c = word[i];
        int x = (s-97);//97
        int y = (s-65);//64
        if(isupper(c) == 0 && (s >= 97 &&  s <= 122) )//if its lower decrease 97
        {
        a = a + POINTS[x];
        }
        else if(islower(c) == 0 && (s >= 65 && s <= 90))//else if its upper decrease 65 because of the ASCII table
        {
        a = a + POINTS[y];
        }

    }

return a;
}



