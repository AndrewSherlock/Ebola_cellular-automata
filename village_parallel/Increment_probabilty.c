#include <math.h>
#include "function_prototypes.h"

int Increment_probabilty(int probabilty, int healthlevel, int decValue)
{
    int x = healthlevel + (100 - healthlevel) - decValue; // forumla that was tried out to give right feeling values
    float percent = (x / 100.f); // convert to percentage
    float newProb = (probabilty * percent); // multiply out probabilty with survival level
    int ans = floor(newProb); // convert to integer
    return ans;
}
