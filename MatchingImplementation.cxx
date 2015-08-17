#include "MatchingImplementation.h"
#include "MatchingTool.h"


bool MatchingImplementation::matchFeatures(const std::vector<std::vector<double> >& distances){
  //do some complicated matching based on distance matrix
  return true;
}

std::vector<Combination> MatchingImplementation::chainCombs(const std::string& chain){
  auto fc = tdt()->features(chain);
  auto combs = fc.combinations();
  return combs;
}

TrigDecisionTool* MatchingImplementation::tdt(){
  return &mt.m_tdt;
}
