#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{   srand(time(NULL));

    char guesswords[][16] = {
        "berhampur",
        "friend",
        "hello",
        "help",
        "India",
        "Kill"
    };
    //  for random index number
    int randomIndex = rand() % 6;

    int numLives = 5;
    int numCorrect =0;
    int oldcorrect=0;

    //length of word
    int lengthOfWord = strlen(guesswords[randomIndex]);

    int letterGuessed[8] ={0,0,0,0,0,0,0,0};
    int quit =0;
    int loopIndex =0;

    char guess[16];
    char letterEntered;

    printf("guesswords:%s\nrandomIndex:%d\nlengthOfWord:%d\n",
            guesswords[randomIndex],
            randomIndex,
            lengthOfWord);

    printf("-------------------------------------------------\n");



    while ( numCorrect < lengthOfWord )
    {
        printf("Enter a Guess letter ");
        fgets(guess,16,stdin);

        if( strncmp(guess,"quit",4) ==0 )
		{

            quit = 1;
            break;
        }

        letterEntered = guess[0];

        printf("letter entered:%c\n",letterEntered);

        oldcorrect = numCorrect;


        for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++ )
        {
            if(letterGuessed[loopIndex] == 1)
			{
             continue;
            }

            if( letterEntered == guesswords[randomIndex][loopIndex] )
				{
				letterGuessed[loopIndex] = 1;
				++numCorrect;
				if(1){printf("correct guess\n");}
				}



        }
        if(oldcorrect == numCorrect)
            {
                numLives--;
                printf("\n Sorry , wrong guess\n");
                if(numLives == 0)
                    {
                        break;
                    }
            }

			printf("Number correct so far is %d \n\n",numCorrect);

    }//while loop

        if(quit==1){printf("\n The user quit early\n");
         }

         if(numCorrect == lengthOfWord ){printf("\nYou Won!!!!\n");}
         else if (numLives == 0)
            {printf("\n Sorry you loose\n");
            }

return 0;
}
