#ifndef PHHepMCParitcleSelectorBase_H_
#define PHHepMCParitcleSelectorBase_H_

#include <fun4all/SubsysReco.h>

#include <vector>

/// Base class for PHHepMC particle selection
class PHHepMCParticleSelectorBase: public SubsysReco
{
 public:
  virtual ~PHHepMCParticleSelectorBase();

  virtual int InitRun(PHCompositeNode *topNode);
  virtual int process_event(PHCompositeNode *topNode);

/// Set the particle ID you want in your output.
  virtual void SetParticle(const int pid);

/// Add aparent of the particle you want in your output.
  virtual void AddParent(const int pid);

/// Add decay products of the particle you want in your output.
  virtual void AddDaughter(const int pid);

/// Set a particle required to be present in the event. Otherwise, skip event.
  void SetTriggerParticle(int part) { _theTrigger=part; }

 protected:
  PHHepMCParticleSelectorBase(const std::string &name="PARTICLESELECTORBASE");

/// The particle you want to have in your output
  int _theParticle;
/// List of decay products of the particle you want in your output
  std::vector<int> _theDaughters;
/// List of possible parents of the particle you want in your output
  std::vector<int> _theParents;
/// The particle which must be present in the event. Otherwise event is skipped.
  int _theTrigger;

};

#endif


