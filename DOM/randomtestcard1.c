#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"



#define DEBUG 0
#define NOISY_TEST 1

int smithyCard(struct gameState *state, int *currentPlayer, int *handPos);

int random_number(int min, int max){
    int result=0; 
	int low = 0;
	int high = 0;
    
	if(min < max)
    {
        low = min;
        high = max + 1; // this is done to include max_num in output.
    }else
	{
        low = max + 1;// this is done to include max_num in output.
        high = min;
    }

    srand(time(NULL));
    
	result = (rand()%(high - low)) + low;
    return result;
}

int main(int argc, char const *argv[])
{
	
	struct gameState game;

	int i, j;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int myCard;

	//smithycard specific variables
	int currentplayer;
	int handPos = -1;
	int cardsInHand;



	for (i = 0; i < random_number(5,100); i ++)
	{ //Loops a random number of times <100
	
		initializeGame(random_number(2,4), k, random_number(1, 9), &game); //initializes a game with a random seed
		 													//between 1-9

		for (j = 0; j < 10000; j++){ // run 10000 times with random variables in this game state
			currentplayer = game.whoseTurn;

			cardsInHand = game.handCount[currentplayer];

			if(myCard = smithyCard(&game, &currentplayer, &handPos) != 0)
				printf("Error: smithyCard returned something other than 0. Random Game[%d] iteration[%d]\n", i, j);
			if (cardsInHand <= game.handCount[currentplayer])
				// printf("Error: player did not pick up enough cards. Random Game[%d] iteration[%d]\n", i, j);
			
			game.outpostPlayed = 0;
  			game.phase = 0;
			game.numActions = 1;
			game.numBuys = 1;
			game.playedCardCount = 0;
			game.whoseTurn = random_number(2, game.numPlayers);
			game.handCount[game.whoseTurn] = 0;
		}
	}

	return 0;
}
