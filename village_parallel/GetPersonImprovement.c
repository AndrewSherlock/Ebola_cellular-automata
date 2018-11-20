#include "Person.h"
#include "Config.h"

int GetPersonImprovement(Person *person)
{
  int personHealthLevel = person->healthLevel;
  int age = person->age;
  
  int recovery = (MAX_RECOVERY / 100.f) * personHealthLevel;

  if(age < YOUTH_RISK_THRESHOLD || age > OLD_RISK_THRESHOLD)
  {
   return recovery / 2;
  }

  return recovery;
// target_max /100 * level


}
