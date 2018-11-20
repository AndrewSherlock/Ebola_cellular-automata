#include "function_prototypes.h"

int get_weighted_probability(int probabilty, int healthLevel) // takes in the health level of the person and probability
{
    if(healthLevel >= 85)
    {
        return Increment_probabilty(probabilty,healthLevel, 30); //  passes different values depending on different health values
    }
    else if (healthLevel >= 70 && healthLevel < 85)
    {
        return Increment_probabilty(probabilty, healthLevel, 10);
    }
    else if (healthLevel >= 50 && healthLevel < 70)
    {
        return Increment_probabilty(probabilty, healthLevel, 0);
    }
    else if (healthLevel >= 35 && healthLevel < 50)
    {
        return Increment_probabilty(probabilty, healthLevel, -10);
    }
    else if (healthLevel >= 20 && healthLevel < 35)
    {
         return Increment_probabilty(probabilty, healthLevel,-20);
    }
    else if (healthLevel < 20)
    {
         return Increment_probabilty(probabilty, healthLevel,-40);
    }
}
