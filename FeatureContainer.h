#ifndef FEATURECONTAINER_H
#define FEATURECONTAINER_H

#include <vector>
#include "Combination.h"
#include "Helper.h"

struct FeatureContainer{
  std::vector<Combination> combinations(){
    std::vector<Combination> v;
    Combination c;
    v.push_back(c);
    return v;
  }

  template<typename T>
  typename std::enable_if<!std::is_same<T,IParticle>::value,
  std::vector<Feature<T> >
   >::type
  get(){
    std::vector<Feature<T> > v;
    for(auto c : combinations()){
      auto combfeats = c.get<T>();
      v.insert(v.end(),combfeats.begin(),combfeats.end());
    }
    return v;
  }

  std::vector<Feature<IParticle> > get(class_id_type clid){
    std::vector<Feature<IParticle> > v;
    for(auto c : combinations()){
      auto combfeats = c.get(clid);
      v.insert(v.end(),combfeats.begin(),combfeats.end());
    }
    return v;
  }

};

#endif