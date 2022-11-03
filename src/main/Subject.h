//@(#) Subject.h

#ifndef SUBJECT_H_H
#define SUBJECT_H_H

#include "Observer.h"

#include <vector>
#include <iostream>

/**
 * @class Subject
 *
 * @brief This class does something with vector of observers
 *
 */
class Subject {
public:

    /** @brief attach
    * @param [in] observer is an object of type Observer
    * @return nothing 
    * 
    * This method adds an observer to the the vector observers std::vector<Observer *> observers;
    */
    void attach(Observer * observer);

  //  /** @brief detach
  //  * @param [in] observer is an object of type Observer
  //  * @return nothing
  //  *
  //  * This method erases an observer from the the vector observers std::vector<Observer *> observers;
  //  */
    void detach(Observer * observer);

    /** updates all elements in vector ob ser vers
    *
    * It iterates the whole vector and calls at every element 
    * a methode update(), which I am not so sure if it's a
    * method of class std::vector - I could not find it on the internet
    */    
    void notify();

private:

    /**
    * This is the list of pointers to type Observer
    * defined in pure abstract class Observer
    *
    */
    std::vector<Observer *> observers;

};

#endif
