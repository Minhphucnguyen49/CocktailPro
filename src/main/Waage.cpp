//@(#) Waage.cpp


#include "Waage.h"

/**
* This method apdapts the weight of the mixture
* with a particular amount of input v
* Logically v should be a positive weight of ingredient
* in case "v" is a negative value, we have to adapt  
* our weight back to the standard 0 value
*/
void Waage::changeWeight(int v) {
    weight += v;
    if (weight < 0)
        weight = 0;
    deltaweight += v;
    notify();
}

/**
* This method sets deltaweight to 0
* and returns value 0 
*
* So what does this method do???
*/
int Waage::tara() {
    return deltaweight = 0;
}

int Waage::getWeight() {
    return weight;
}

int Waage::getDelta() {
    return deltaweight;
}
