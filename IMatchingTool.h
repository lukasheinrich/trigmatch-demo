#ifndef IMATCHINGTOOL_H
#define IMATCHINGTOOL_H

#include <string>
#include <vector>

struct IParticle;
template<typename R,typename T> struct IMetric;
struct MatchingImplementation;
struct TrigDecisionTool;
typedef unsigned int class_id_type;

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