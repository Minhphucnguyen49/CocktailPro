//@(#) Observer.h

#ifndef OBSERVER_H_H
#define OBSERVER_H_H
/**
 * @class Observer
 *
 * @brief An abstract class
 *
 * This class serves as a pure abstract class
 * and will be used in class Subject 
 * as a type for pointer to point to in a vector
 *
 *
 * This is a concept of Observer pattern https://en.wikipedia.org/wiki/Observer_pattern
 * There is a loosly coupled relationship btw. Subject class and Observer class
 */
class Observer {
public:
    /** @brief creates a pure virtual method update()
    * 
    * This method will be called in other classes such as Waage or Subject
    */
    virtual void update() = 0;

};

#endif
