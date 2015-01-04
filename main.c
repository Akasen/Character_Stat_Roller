#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int strength, dexterity, constitution, intelligence, wisdom, charisma;
    printf("Welcome to the Stat Roller!\n");
    printf("This Stat Roller uses the Pathfinder Standard Roll to determine stats\n");

    int player_continue = 1;
    do
    {
        strength = stat_roll(), dexterity = stat_roll(), constitution = stat_roll();
        intelligence = stat_roll(), wisdom = stat_roll(), charisma = stat_roll();

        printf("\nStrength: %i \nDexterity: %i \nConstitution: %i \nIntelligence: %i \nWisdom: %i \nCharisma: %i\n",
                strength, dexterity, constitution, intelligence, wisdom, charisma);

        printf("Enter \'0\' to exit. Enter \'1\' to continue: ");
        scanf("%i", &player_continue);
    }
    while(player_continue == 1);
    return 0;
}

int stat_roll()
{
    int roll1, roll2, roll3, roll4;
    int rollCheck1, rollCheck2;

    roll1 = rand()%6+1, roll2 = rand()%6 + 1, roll3 = rand()%6 + 1, roll4 = rand()%6 + 1;

    if(roll1 > roll2)
    {
        rollCheck1 = 1;
    }
    else
    {
        rollCheck1 = 0;
    }

    if(roll3 > roll4)
    {
        rollCheck2 = 1;
    }
    else
    {
        rollCheck2 = 0;
    }

    if(rollCheck1 == rollCheck2)
    {
        if(roll2 > roll4)
        {
            roll4 = 0;
        }
        else
        {
            roll2 = 0;
        }
    }


    int final_stat = roll1 + roll2 + roll3 + roll4;

    return final_stat;

}
