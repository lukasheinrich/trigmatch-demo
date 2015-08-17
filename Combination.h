#ifndef COMBINATION_H
#define COMBINATION_H

#include <type_traits>

#include "IParticle.h"
#include "Feature.h"
#include <iostream>

#include "Helper.h"

struct Combination{
  template<typename T>
  typename std::enable_if<!std::is_same<T,IParticle>::value,
  std::vector<Feature<T> >
   >::type
  get(){
    std::cout << "getting features for non-IParticle types" << std::endl;
    return std::vector<Feature<T> >();
  }

  std::vector<Feature<IParticle> > get(class_id_type clid){
    std::cout << "getting features for IParticle types" << std::endl;
    return std::vector<Feature<IParticle> >();
  }
};
#endif