//@(#) Waage.h
#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "Subject.h"


/**
 * @class Waage
 * @brief This class controls the weight of the mixture 
 * 
 */
class Waage : public Subject {
 public:
  /** @brief Standard constructor
   *  initialises weight and deltaweight
   */
    Waage()
      :  weight(0), deltaweight (0)
    {}

  /** @brief This method obviously changes the weight with an desired amount of weight
   * @param [in] v an integer indicating that desired weight user want to add
   * @return void means that it just does the changing and does not return any value
   */
    void changeWeight(int v);

  /** @brief this method sets deltaweight to 0
   * @return This int is deltaweight but after it is set to 0 
   *
   * This method returns 0 and sets deltaweight = 0
   */
    int tara();

  /** @brief this method is getter
   * @return This int is weight of mixture
   */
    int getWeight();
       
  /** @brief this method is getter
   * @return This int is extra weight of mixture
   */
    int getDelta();
 private:
  /**
   * There are only two variables here: the weight of the mixture and
   * the desired extra weight (deltaweight)
   */
    int weight;
    int deltaweight;
};

#endif
