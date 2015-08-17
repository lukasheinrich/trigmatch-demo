#ifndef IPARTICLE_H
#define IPARTICLE_H



struct IParticle{
  enum Type{
    Electron,
    Muon
  };
  Type type() const {return Electron;}
};

#endif