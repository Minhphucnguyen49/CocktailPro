//@(#) BarTender.cpp


#include "BarTender.h"
//constructor
BarTender::BarTender(DeviceVerwalter *dv) {
  myDeviceVerwalter = dv;
}
//zubereitung des cocktails
bool BarTender::cocktailZubereiten(Recipe *rzpt) {
  //std::system("clear");
  std::cout << "Hallo, ich bin der BarTender!" << std::endl
            << "Ich habe Ihre Bestellung: " << rzpt->getName() << " erhalten." << std::endl
            << "Jetzt geht es los!\n" << std::endl;
  //iteration über alle rezeptschritte
  bool mischbar=true;
  std::string fzutat="";
  for (int i = 0; i < rzpt->getNoOfRecipeSteps(); i++) {
    RecipeStep *schritt = rzpt->getRecipeStep(i);
    //folgende 2 variablen könnten direkt in die funktionen geschrieben werden.
    std::string zutat = schritt->getZutat();  //name der zutat
    float menge = schritt->getMenge();
    if (Dispenser *internalDevice = dynamic_cast< Dispenser * >( myDeviceVerwalter->myDevices->find(zutat)->second )){
        if(internalDevice->getGesamtgewicht()<menge) {
          mischbar=false;
          fzutat=zutat;
    }

    }

  }
  if(mischbar==false){
    std::cout<<"Nicht mischbar! Bitte "<<fzutat<<" auffuellen"<<std::endl;
  }else {

    for (int i = 0; i < rzpt->getNoOfRecipeSteps(); i++) {
      RecipeStep *schritt = rzpt->getRecipeStep(i);
      //folgende 2 variablen könnten direkt in die funktionen geschrieben werden.
      std::string zutat = schritt->getZutat();  //name der zutat
      float menge = schritt->getMenge();        //menge
      std::cout << "Rezeptschritt: " << zutat << ", " << menge << std::endl;
      //reptschritt wird von deviceverwalter durchgeführt
      myDeviceVerwalter->rezeptSchrittZubereiten(zutat, menge);
    }
    //ausleeren des gerätes
    myDeviceVerwalter->myEntleerer->doIt(0);

    //iteration über alle geräte zum reinigen
    //putzt auch die getränke, möglicher fehler
    for (std::map<std::string, InternalDevice *>::iterator
             i1 = myDeviceVerwalter->myDevices->begin();
         i1 != myDeviceVerwalter->myDevices->end(); ++i1) {
      if (i1->second->wasUsed()) {
        std::cout << "Device mit der Aktion: " << i1->first << " wird jetzt geputzt: " << std::endl;
        i1->second->putzen();
      }
    }
  }

  //rückgabewert wird nicht genutzt
  return (true);
}

