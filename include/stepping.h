#ifndef STEPPING_HH
#define STEPPING_HH

#include "G4UserSteppingAction.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"

#include "run.h"

class MySteppingAction : public G4UserSteppingAction
{
public:
    MySteppingAction();
    ~MySteppingAction();

    virtual void UserSteppingAction(const G4Step*) override;
private:
    G4ThreeVector initialPosition;
    G4bool firstStep;
    G4bool isSame;
    G4int prevEvt;
    const G4Event* previousEvent;
};

#endif