#include "MatchingTool.h"
#include "IParticle.h"

#include "IMatchingTool.icc"

struct RecoType{};
struct TriggerType{};

struct MyMetric : public IMetric<RecoType,TriggerType>{
  double distance(const RecoType&, const TriggerType&) const {return 2.0;}
};


int main(){
  IMatchingTool* imt = new MatchingTool();

  RecoType r;
  IParticle p;
  
  class_id_type TrigElectronCLID = 1234;
  
  auto m = new MyMetric();
  imt->match<TriggerType>(r,"chain_name",m);
  imt->match(p,"chain_namme",TrigElectronCLID);

  
  return 0;
}