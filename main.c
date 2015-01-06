#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int stat_roll();

int main()
{
    int stats[6];
    printf("Welcome to the Stat Roller!\n");
    printf("This Stat Roller uses the Pathfinder Standard Roll to determine stats\n");
    printf("Do remember that these stats may be re-arranged at the players choice unless the GM says otherwise");

    srand(time(NULL));
    char player_continue[4];
    do
    {
        // Rolls for the six player stats using stat_roll function
        int x;
        for(x = 0; x <= 5; x++)
        {
            stats[x] = stat_roll();
        }

        // Prints all stats on one line. Create new blank line
        printf("\n%i, %i, %i, %i, %i, %i\n",
                stats[0], stats[1], stats[2], stats[3], stats[4], stats[5]);

        // Asks user if they wish to continue
        // At the moment, anything will allow the programm to roll again
        // Only "no" can be used as the exit statement
        printf("Enter \'no\' to exit. Enter \'yes\' to continue: ");
        scanf("%s", &player_continue);
    }
    while(strcmp(player_continue, "no"));
    return 0;
}

int stat_roll()
{
    // Initaliztion of varaibles
    int roll1, roll2, roll3, roll4;

    // Variables have random values between 'one' and 'six' set to them
    // Variables then placed into an array
    roll1 = rand()%6+1, roll2 = rand()%6 + 1, roll3 = rand()%6 + 1, roll4 = rand()%6 + 1;
    int rolls[4] = {roll1, roll2, roll3, roll4};

    // Initializing search for lowest variable

    // The idea is that this will look for the smallest number using the first variable in the array
    // If any other variable is smaller, that variable will be set to small
    int x, small = rolls[0];
    for(x = 0; x < 4; x++)
    {
        if (rolls[x] < small)
        {
            small = rolls[x];

        }

    }

    // Debug code. Keeping in for any further use
    //printf("Small is %i\n", small);


    // The moment the smallest number is found, it is set to '0'
    // Break statement is done in the case that there are numbers of
    // identical value to the 'small' variable, those numbers do not get
    // made into a '0'
    for(x = 0; x < 4; x++)
    {
        if(rolls[x] == small)
        {
            rolls[x] = 0;
            break;
        }
    }

    // Debug code. Keeping it in for any further use
    //printf("%i, %i, %i, %i\n\n", rolls[0],rolls[1],rolls[2], rolls[3]);

    // Addition of all numbers
    int final_stat = rolls[0] + rolls[1] + rolls[2] + rolls[3];

    return final_stat;

}

/*

Particular issue has been realized.
I wish to broadent the scope of this so that Pathfinder/D&D's other systems
for rolling stats is taken into account as well. Future steps would be to
add a GUI interface on top of all this. What may need to be done is to have the
function 'stat_roll' accept an X amount for the variable size for rolls and then to have
the search functions also call upon this size.

To elabore, Pathfinder detailes at least three basic roll systems for Ability Score generation.

Standard makes you roll 4d6 and discard the lowest, adding the rest of the numbers.

Classic makes you roll only 3d6 and just add them there and then.

Heroic makes you roll 2d6, add the dice, then add 6.

So what I would want to do very much so is have 'stat_roll' accept two variables.
A variable for dice and a variable signifying if the roll is for a heroic roll.
Or maybe I could have an if statement that checks the variable for dice amount
and signifies from there whether a flat six needs to be added to the roll.

*/
