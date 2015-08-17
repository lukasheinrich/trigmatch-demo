#ifndef MATCHINGIMPLEMENTATION_H
#define MATCHINGIMPLEMENTATION_H

#include "Combination.h"
#include "TrigDecisionTool.h"

struct MatchingTool;
struct MatchingImplementation{
  MatchingImplementation(MatchingTool& t):mt(t){}
  std::vector<Combination> chainCombs(const std::string& chain);
  bool matchFeatures(const std::vector<std::vector<double> >& distances);
  virtual TrigDecisionTool* tdt();

private:
  MatchingTool& mt;
};

#endif