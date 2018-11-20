#include "Config.h"

float AddInfectionRateForAge(int age) // takes in a age from the person
{
  if(age > 15 && age < 60)
    return 0;

  int gap = 0;
  float addPercentage = 1.66f; // for a child thats 0, we wanted to give a max of 25% so 15 * 1.66

  if(age < YOUTH_RISK_THRESHOLD)
    gap = YOUTH_RISK_THRESHOLD - age;
  else
    gap = age - OLD_RISK_THRESHOLD;

  if(gap == 0)
    return addPercentage / 100;
  else
    return (addPercentage * gap) / 100;

  
}
