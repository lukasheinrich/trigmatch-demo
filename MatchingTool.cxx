#include "MatchingTool.h"

bool MatchingTool::match(const IParticle& reco, const std::string& chain){
  std::vector<IParticle> v;
  v.push_back(reco);
  return match(reco,chain);
}

bool MatchingTool::match(const IParticle& reco, const std::string& chain, class_id_type clid,  const IMetric<IParticle,IParticle>* metric){
  return match({reco},chain);
}

bool MatchingTool::match(const std::vector<IParticle>& recos, const std::string& chain, class_id_type clid,  const IMetric<IParticle,IParticle>* metric){
  if(!metric){
    auto metric = IParticleHelper::getMetric(recos.at(0).type());
  }
  bool matched = false;
  for(auto comb : chainCombs(chain)){
    std::vector<Feature<IParticle> > feats_ip =  comb.get(clid);
    matched = matched || matchFeatures(Helper::distanceMatrix(recos,feats_ip,*metric));
  }
  return matched;
}

bool MatchingTool::matchFeatures(const std::vector<std::vector<unsigned int> >& distances){
  //do some complicated matching based on distance matrix
  return true;
}

std::vector<Combination> MatchingTool::chainCombs(const std::string& chain){
  auto fc = tdt()->features(chain);
  auto combs = fc.combinations();
  return combs;
}

TrigDecisionTool* MatchingTool::tdt(){
  return &m_tdt;
}
