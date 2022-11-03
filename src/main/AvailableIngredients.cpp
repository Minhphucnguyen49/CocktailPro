//@(#) AvailableIngredients.cpp

#include "AvailableIngredients.h"
//What does this programm do?

//Objekt mit Liste aller verfügbaren Zutaten
//redundant void in parameter
AvailableIngredients::AvailableIngredients() {
  zutaten = new std::vector<std::string>;

  // int einlesen(list<string>* zutaten, std::string fileName)
// Stream anlegen

  if (DEBUG) {
    //DummyZutatenEinfuegen();
  } else {
    ZutatenDateiEinlesen(fileName);
  }
//ausgabe aller verfügbaren zutaten
  browse();

//einfügen der standardaktionen mischen und stampfen
  zutaten->push_back("Mischen");
  zutaten->push_back("Stampfen");
  zutaten->push_back("Schuetteln");

  anzahlDosierer = zutaten->size();

}
//deconstructor
//reduntant void in param
AvailableIngredients::~AvailableIngredients() = default;
//einlesen der zutaten us .txt
void AvailableIngredients::ZutatenDateiEinlesen(std::string &fname) {
    std::ifstream in;

    in.open(fname.c_str(), std::ios::in); // c_str wandelt den String in char[]
    // das braucht fstream

    if (!in) {// File konnte nicht geoeffnet werden
        std::string my_exception = "File not found: " + fileName;
        std::cout << my_exception << std::endl;
        throw my_exception;
    }

    std::cout << "Oeffne Zutatendatei " << fileName << std::endl;
//hinzufügen von zutaten zur liste
    std::string zeile;
    while (getline(in, zeile)) {

        // Cut trailing \r - to make Linux or Windows Files equal
        if (!zeile.empty() && zeile[zeile.size() - 1] == '\r') {
            zeile = zeile.substr(0, zeile.size() - 1);
        }

        this->zutaten->push_back(zeile);
    }
    in.close();
}
//funktion zum einfügen von zutaten für demo
/*
void AvailableIngredients::DummyZutatenEinfuegen() {
    zutaten->push_back("Limettenstuecke");
    zutaten->push_back("Zucker");
    zutaten->push_back("Cointreau");
    zutaten->push_back("Eis");
    zutaten->push_back("Wodka");
    zutaten->push_back("Rum weiss");
    zutaten->push_back("Zitronensaft");
    zutaten->push_back("Grenadine");
    //    zutaten->push_back("Limettensaft");
    //    zutaten->push_back("Tequilla");
    //    zutaten->push_back("Gin");
    //    zutaten->push_back("Noilly Prat");
}
*/
//ausgabe aller zutaten
void AvailableIngredients::browse() {
    std::cout << "*********** Verfuegbare Einheiten bzw. Zutaten: ***********" << std::endl;
    for (auto & i : *zutaten) {
        std::cout << i << std::endl;
    }
    std::cout << "**********************************************************" << std::endl;
}

std::string AvailableIngredients::getZutat(size_t i) {
    return zutaten->at(i);
}

size_t AvailableIngredients::getAnzahlVorhandeneZutaten() {
    return zutaten->size();
}
