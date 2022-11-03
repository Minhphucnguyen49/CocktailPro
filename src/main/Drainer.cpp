//@(#) Drainer.cpp


#include "Drainer.h"

Drainer::Drainer(float g, int ze, Waage * wg) : InternalDevice() {
  needsCleaning = true;
  this->grammProZeit = g;
  this->zeiteinheit = ze;
  this->myWaage = wg;
  this->myWaage->attach(this);
}

Drainer::~Drainer(){

}

//

void Drainer::update() {
    if (!this->doinIt) return;
  checkWaage();
}
void Drainer::checkWaage() {
  if (myWaage->getWeight() <= value) {
    doinIt = 0;
  }
}

void Drainer::doIt(int nvalue) {
    std::cout << "Ihr Cocktail hat ein Gesamtgewicht von " << myWaage->getWeight() << "g" << std::endl;
    std::cout << "Entleervorgang wird begonnen..." << std::endl;
    this->value = nvalue;
    doinIt = 1;
    while (doinIt) {
      myTimer->sleep_in_intervals(zeiteinheit);
        myWaage->changeWeight(-grammProZeit);
    }
    std::cout << std::endl;
    std::cout << "Entleervorgang wurde beendet, bitte entnehmen Sie ihren Cocktail!" << std::endl;
    std::cout << std::endl;
}
