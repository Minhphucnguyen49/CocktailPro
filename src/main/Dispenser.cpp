//@(#) Dispenser.cpp


#include "Dispenser.h"

Dispenser::Dispenser(int g, int ze, const std::string &ninhalt, Waage * wg)
  : InternalDevice(), inhalt(ninhalt) {
    this->grammProZeit = g;
    this->zeiteinheit = ze;
    this->myWaage = wg;
    this->myWaage->attach(this);
}

void Dispenser::update() {
  if (!this->doinIt) return;
  if (myWaage->getDelta() >= gewicht)
    doinIt = false;
}

void Dispenser::doIt(int gramm) {

  //might become obsolete with User Story 3
  if(getGesamtgewicht()<gramm){
    std::cout << "Behälter müssen alle Neu befüllt werden.";
    exit(0);
  }

  if (gesamtgewicht >= gramm) {
    dispense(gramm);  //dispenser does it itself when it has enough
  } else if (additionalDispenser != nullptr) {  //when we have a backup
    if (gesamtgewicht > 0) {  //when the dispenser is not empty
      int remainder = gesamtgewicht;
      dispense(gesamtgewicht);  //dispense everything
      additionalDispenser->doIt(gramm - remainder); //have backup dispense the rest
    } else
      additionalDispenser->doIt(gramm); //when dispenser is empty, have other dispenser do everything
  }
  if (output)
    std::cout << "Es wurden " << gramm << "g " << inhalt
        << " abgefuellt. Restinhalt: " << getGesamtgewicht() << "g\n\n";
}

void Dispenser::dispense(int gramm) {
  needsCleaning = true;
  this->gewicht = gramm;
  myWaage->tara();
  doinIt = true;
  std::cout << inhalt << " Ventil wurde geoeffnet" << std::endl;
  while (doinIt) {
    myTimer->sleep_in_intervals(zeiteinheit);
    myWaage->changeWeight(grammProZeit);
    //myWaage->changeWeight(0);
  }
  std::cout << std::endl << inhalt << " Ventil wurde geschlossen" << std::endl;
  gesamtgewicht=gesamtgewicht-myWaage->getDelta();
}

int Dispenser::getStueckProZeit() const {
    return this->grammProZeit;
}
void Dispenser::addDispenser() {
  if (additionalDispenser == nullptr) { //when we don't have a backup already make one
    additionalDispenser = new Dispenser(grammProZeit, zeiteinheit, inhalt, myWaage);
    additionalDispenser->setOutput(false);
  }
  else
    additionalDispenser->addDispenser(); //tell our backup to add another dispenser
}
int Dispenser::getGesamtgewicht() const {
  if (additionalDispenser == nullptr)
    return gesamtgewicht;
  else
    return gesamtgewicht + additionalDispenser->getGesamtgewicht();
}
void Dispenser::putzen() {
  needsCleaning = false;
  if (additionalDispenser != nullptr)
    additionalDispenser->putzen();
}
