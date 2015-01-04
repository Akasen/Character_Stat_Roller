#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int stat_roll();

int main()
{

    int strength, dexterity, constitution, intelligence, wisdom, charisma;
    printf("Welcome to the Stat Roller!\n");
    printf("This Stat Roller uses the Pathfinder Standard Roll to determine stats\n");
    printf("Do remember that these stats may be re-arranged at the players choice unless the GM says otherwise")

    int player_continue = 1;
    do
    {
        srand(time(NULL));
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

    int rolls[4] = {roll1, roll2, roll3, roll4};

    int x, small = rolls[0];
    for(x = 0; x < 4; x++)
    {
        if (rolls[x] < small)
        {
            small = rolls[x];

        }

    }

    //printf("Small is %i\n", small);

    for(x = 0; x < 4; x++)
    {
        if(rolls[x] == small)
        {
            rolls[x] = 0;
            break;
        }
    }

    //printf("%i, %i, %i, %i\n\n", rolls[0],rolls[1],rolls[2], rolls[3]);
    int final_stat = rolls[0] + rolls[1] + rolls[2] + rolls[3];

    return final_stat;

}
