#ifndef MATCHINGIMPLEMENTATION_H
#define MATCHINGIMPLEMENTATION_H

#include "IMatchingTool.h"
#include "Combination.h"
#include "TrigDecisionTool.h"

struct MatchingImplementation{
  MatchingImplementation(IMatchingTool& t):imt(t){}
  std::vector<Combination> chainCombs(const std::string& chain);
  bool matchFeatures(const std::vector<std::vector<double> >& distances);

private:
  IMatchingTool& imt;
};

#endif