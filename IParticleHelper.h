#ifndef IPARTICLE_HELPER
#define IPARTICLE_HELPER

#include "Helper.h"

namespace IParticleHelper{


struct DefaultMetric : public IMetric<IParticle,IParticle>{
    double distance(const IParticle& lhs, const IParticle& rhs) const {
      return 1.0; //compute delta R
    }
  };


  static std::shared_ptr<IMetric<IParticle,IParticle> > getMetric(IParticle::Type reco_type){
    if(reco_type==IParticle::Electron){
      return std::make_shared<DefaultMetric>();
    }
    return std::make_shared<DefaultMetric>();
  }


}

#endif