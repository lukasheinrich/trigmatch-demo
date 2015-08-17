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
  for(auto comb : impl()->chainCombs(chain)){
    std::vector<Feature<IParticle> > feats_ip =  comb.get(clid);
    matched = matched || impl()->matchFeatures(Helper::distanceMatrix(recos,feats_ip,*metric));
  }
  return matched;
}

MatchingImplementation* MatchingTool::impl(){
  return &m_impl;
}
