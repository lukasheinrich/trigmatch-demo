#ifndef HELPER_H
#define HELPER_H

typedef unsigned int class_id_type;

template<typename R,typename T>
struct IMetric {
  virtual double distance(const R&, const T&) const = 0;
};

namespace Helper{

  template<typename R,typename T>
  std::vector<std::vector<double> > distanceMatrix(const std::vector<R>& reco, const std::vector<Feature<T> >& feats, const IMetric<R,T>& m){
  std::vector<std::vector<double> > matrix;
    for(auto r : reco){
      std::vector<double> distance_to_r;
      for(auto f : feats){
        distance_to_r.push_back(m.distance(r,*f.cptr()));
      }
      matrix.push_back(distance_to_r);
    }
    return matrix;
  }
}
#endif