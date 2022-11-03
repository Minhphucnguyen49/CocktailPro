//@(#) CocktailPro.cpp

//hauptklasse des programms
//steuerung des Programmablaufs

#include "CocktailPro.h"
#include <string>

//startfunction
void CocktailPro::start() {
  while (OperatingMode == OpMode::NORMAL || OperatingMode == HAPPYHOUR) {
    int cocktailNo = userSelection();  //nutzereingabe
    int userInput = cocktailNo;  //temporary saving userinput for errormessage
    switch (cocktailNo) {
      case -1:
        OperatingMode = OpMode::STOP;
        break;
      case -10:
        std::cout << "MEEEP! Too many fingers on keyboard error!\n"
                  << "Ihre Eingabe war nicht zwischen 1 und "
                  << pMixableRecipeBook->getNumberOfRecipes() << "!\n";
        break;
      case -20:
        if (OperatingMode == HAPPYHOUR) {
          std::cout << "\nDeactiviere Happy Hour Modus\n";
          pMixableRecipeBook->multiplyAllIngredients(0.5);
          OperatingMode = NORMAL;
        }
        break;
      case -21:
        if (OperatingMode == NORMAL) {
          std::cout << "\nActiviere Happy Hour Modus\n Alle Cocktails werdem mit doppelten Zutaten zubereitet\n";
          pMixableRecipeBook->multiplyAllIngredients(2);
          OperatingMode = HAPPYHOUR;
        }
        break;
      default:
        Recipe *rezeptptr = pMixableRecipeBook->getRecipe(cocktailNo-1);
        if (rezeptptr != nullptr) {
          std::cout << rezeptptr->getName() << std::endl; //ausgabe des repzeptnamens
          pBarTender->cocktailZubereiten(rezeptptr);
        } else {
          std::cout << "Rezept Nummer " << userInput << " ist nicht verfügbar\n";
        }
    }
  }
}

//Constructor
CocktailPro::CocktailPro(int argc, char **param) {

  //objekt mit liste der verfügbaren zutaten
  pAvailableIngredients = new AvailableIngredients;
  //objekt für liste mischbarer rezepte
  pMixableRecipeBook = new MixableRecipeBook(pAvailableIngredients);
  //objekt zur verwaltung der internen geräte
  pDeviceVerwalter = new DeviceVerwalter(pAvailableIngredients);
  //objekt das die zubereitung durchführt
  pBarTender = new BarTender(pDeviceVerwalter);
  //warum? wird nicht mehr verwendet, warum die liste neu erstellen?
  pAvailableIngredients = new AvailableIngredients;

  //Funktion setzt Timergeschwindigkeit für Demomodus
  Timer *theTimer = Timer::getInstance();
  if (argc == 2) {// this has to be changed later  //was never changed apparently
    if (std::string(param[1]) == "-D") {
      this->OperatingMode = OpMode::DEMO;
      theTimer->set_Turbo(1000);
      this->demo();
    } else { // Parameter => Turbo an
      theTimer->set_Turbo(10);
    }
  }
}

CocktailPro::~CocktailPro()
{
  delete pBarTender;
  delete pDeviceVerwalter;
  delete pMixableRecipeBook;
  delete pAvailableIngredients;
}
//Function for demo
void CocktailPro::demo() {
  int CocktailNo = 1;
  int max = pMixableRecipeBook->getNumberOfRecipes();
  if (CocktailNo <= max) {
    Recipe *rezeptptr = pMixableRecipeBook->getRecipe(CocktailNo - 1);
    std::cout << rezeptptr->getName() << std::endl;
    pBarTender->cocktailZubereiten(rezeptptr);
  }
}

//function for user input
int CocktailPro::userSelection() {
  while (true) {
    std::cout << "********** Mischbare Rezepte **********" << std::endl;
    pMixableRecipeBook->browse();
    if (OperatingMode == HAPPYHOUR) std::cout<<"HAPPY HOUR MODUS ACTIV\nCocktails werden mit doppelten Zutaten gemischt\n";
    std::cout << "Was haetten Sie denn gern? (-1 zum Verlassen)" << std::endl;

    std::string eingabe;

    //cin.ignore();
    std::cin >> eingabe;
    if (eingabe == "stophappyhour")
      return -20;
    else if(eingabe == "happyhour")
      return -21;

    int zahl = atoi(eingabe.c_str());
    int max = pMixableRecipeBook->getNumberOfRecipes();// currently (praktikum 3 and before) we have 6 Recipes

    if (zahl == -1){
      return -1;
    }
    return validateUserInput(zahl, max);
  }
}
int CocktailPro::validateUserInput(int zahl, int max) const {
  if ( zahl >= 1 && zahl <= max ) {
    return zahl;
  }
  return -10;
}
