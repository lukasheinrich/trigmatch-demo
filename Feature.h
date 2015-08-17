#ifndef FEATURE_H
#define FEATURE_H

template <typename T>
struct Feature{
  T* cptr(){return new T();}
};

#endif