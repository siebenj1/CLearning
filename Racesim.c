#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Race{
  int numberOfLaps;
  int currentLap;
  char firstPlaceDriverName[20];
  char firstPlaceRaceCarColor[20];
};

struct Racecar{
  char driverName[20];
  char raceCarColor[20];
  int totalLapTime;
};

//***********

void printIntro(void){
  printf("Welcome to our main event digital race fans!\nI hope everbody has their snacks because we are about to begin!\n");
}

void printCountDown(){
  printf("Racers Ready! In....\n");
  int i = 5;
  while(i > 0){
    printf("%i\n", i);
    i--;
  }
  printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race race){
  printf("After Lap number %i\n", race.currentLap);
  printf("First Place Is: %s", race.firstPlaceDriverName);
  printf(" in the %s race car!\n", race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race){
  printf("Lets all congratulate %s in the %s race car for\nan amazing performance.\nIt Truly was a great race and everybody, have a goodnight!", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

// ******************

int calculateTimeToCompleteLap(void){
  int speed = rand() % 3 + 1;
  int acceleration = rand() % 3 + 1;
  int nerves = rand() % 3 + 1;
  return speed + acceleration + nerves;
}

void updateRaceCar(struct Racecar* racecar){
  racecar->totalLapTime = calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race, struct Racecar* racecar1, struct Racecar* racecar2){
  if (racecar1->totalLapTime >= racecar2->totalLapTime){
    strcpy(race->firstPlaceDriverName, racecar1->driverName);
    strcpy(race->firstPlaceRaceCarColor, racecar1->raceCarColor);
  }else if (racecar1->totalLapTime < racecar2->totalLapTime){ 
    strcpy(race->firstPlaceDriverName, racecar2->driverName);
    strcpy(race->firstPlaceRaceCarColor, racecar2->raceCarColor);
  } 
}

void startRace(struct Racecar racecar1, struct Racecar racecar2){
  struct Race race = {5,1,"",""};
  for (race.numberOfLaps >= 0; race.numberOfLaps--; race.currentLap++)
  {
    updateRaceCar(&racecar1);
    updateRaceCar(&racecar2);
    updateFirstPlace(&race, &racecar1, &racecar2);
    printFirstPlaceAfterLap(race);
    }
  printCongratulation(race);
}
//********

int main() {
  struct Racecar bob = {"Bobert", "Pink", 0};
  struct Racecar duke = {"Duke Nukem", "Red", 0};
	srand(time(0));
  printIntro();
  printCountDown();
  startRace(bob, duke);
  
};
