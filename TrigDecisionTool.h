#ifndef TRIGDECISIONTOOL_H
#define TRIGDECISIONTOOL_H

#include <string>
#include "FeatureContainer.h"

struct TrigDecisionTool{

  FeatureContainer features(const std::string& chain){
    return FeatureContainer();
  }

};

#endif