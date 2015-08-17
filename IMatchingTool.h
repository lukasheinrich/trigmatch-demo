#ifndef IMATCHINGTOOL_H
#define IMATCHINGTOOL_H

struct IParticle;

#include <string>
#include <vector>
#include "Feature.h"
#include "Helper.h"
#include <memory>

struct MatchingImplementation;
struct TrigDecisionTool;
struct IMatchingTool{
  virtual bool match(const IParticle& reco, const std::string& chain, class_id_type clid, const IMetric<IParticle,IParticle>* metric = 0) = 0;
  virtual bool match(const std::vector<IParticle>& recos, const std::string& chain, class_id_type clid, const IMetric<IParticle,IParticle>* metric = 0) = 0;

  template<typename T, typename R>
  bool match(const R& reco, const std::string& chain, const IMetric<R,T>* metric);

  template<typename T, typename R>
  bool match(const std::vector<R>& recos, const std::string& chain, const IMetric<R,T>* metric);

protected:
  virtual MatchingImplementation* impl() = 0;

};

#endif