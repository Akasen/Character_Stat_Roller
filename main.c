#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int statCalc(int dice);
int diceRoll();
void operation(int dice);

int main()
{
    printf("Welcome to the Stat Roller!\n");
    printf("This Stat Roller can use the Standard, Classic, or Heroic rolls to determine stats\n");

    int choice;
    int dice;

    do
    {
        printf("\n1. Standard\n2. Classic\n3. Heroic\nChoose a roll type: ");
        choice = 9;
        scanf("%i", &choice);

            if(choice == 1)
            {
                dice = 4;
                operation(dice);
            }
            if(choice == 2)
            {
                int dice = 3;
                operation(dice);
            }
            if(choice == 3)
            {
                int dice = 2;
                operation(dice);
            }
    }while(choice != 0);
    return 0;
}

void operation(int dice)
{
    int stats[6];
    char player_continue[4];

    do
        {
            // Rolls for the six player stats using stat_roll function
            int x;
            for(x = 0; x <= 5; x++)
            {
                stats[x] = statCalc(dice);
            }

            // Prints all stats on one line. Create new blank line
            printf("\n%i, %i, %i, %i, %i, %i\n",
                    stats[0], stats[1], stats[2], stats[3], stats[4], stats[5]);

            // Asks user if they wish to continue
            // At the moment, anything will allow the program to roll again
            printf("Enter \'n\' to exit. Enter \'y\' to continue: ");
            scanf("%s", player_continue);
        }while(strcmp(player_continue, "n"));
}


int diceRoll()
{
    return rand()%6+1;
}


int statCalc(int dice)
{
    // Initialization of variables
    // i and total
    int i, total, small;

    total = small = diceRoll();
    //For loop
    for(i = 1; i < dice; i++) {
        int roll = diceRoll();
        total += roll;
    }
    if (dice == 2) { total += 6; }
    else if (dice == 4) { total -= small; }
    return total;
}


/*

Particular issue has been realized.
I wish to broaden the scope of this so that Pathfinder/D&D's other systems
for rolling stats is taken into account as well. Future steps would be to
add a GUI interface on top of all this. What may need to be done is to have the
function 'stat_roll' accept an X amount for the variable size for rolls and then to have
the search functions also call upon this size.

To elaborate, Pathfinder details at least three basic roll systems for Ability Score generation.

Standard makes you roll 4d6 and discard the lowest, adding the rest of the numbers.

Classic makes you roll only 3d6 and just add them there and then.

Heroic makes you roll 2d6, add the dice, then add 6.

So what I would want to do very much so is have 'stat_roll' accept two variables.
A variable for dice and a variable signifying if the roll is for a heroic roll.
Or maybe I could have an if statement that checks the variable for dice amount
and signifies from there whether a flat six needs to be added to the roll.

*/

