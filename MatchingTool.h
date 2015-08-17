#ifndef MATCHINGTOOL_H
#define MATCHINGTOOL_H

#include "IMatchingTool.h"

#include "TrigDecisionTool.h"
#include "Helper.h"
#include "IParticleHelper.h"
#include "MatchingImplementation.h"

  
struct MatchingTool : public IMatchingTool{
  friend class MatchingImplementation;
  MatchingTool():m_impl(*this){}
  bool match(const IParticle& reco, const std::string& chain);
  bool match(const IParticle& reco, const std::string& chain, class_id_type clid,  const IMetric<IParticle,IParticle>* metric);
  bool match(const std::vector<IParticle>& recos, const std::string& chain, class_id_type clid, const IMetric<IParticle,IParticle>* metric);

protected:
  bool matchFeatures(const std::vector<std::vector<double> >& distances);  
  std::vector<Combination> chainCombs(const std::string& chain);  

  MatchingImplementation* impl();

private:
  MatchingImplementation m_impl;
  TrigDecisionTool m_tdt;
};
#endif