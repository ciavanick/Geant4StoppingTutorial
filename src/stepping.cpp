#include "stepping.h"

MySteppingAction::MySteppingAction()
{
    firstStep = false;
    previousEvent = G4RunManager::GetRunManager()->GetCurrentEvent();
    initialPosition = {0.,0.,0.};
}

MySteppingAction::~MySteppingAction() {}

void MySteppingAction::UserSteppingAction(const G4Step *step) //here we track particle each step they make
{
   G4AnalysisManager *man = G4AnalysisManager::Instance();

    const auto track = step->GetTrack();
    const auto &partName = track->GetDefinition()->GetParticleName();
    const auto &physVolume = step->GetPreStepPoint()->GetPhysicalVolume()->GetName();
    //const auto globalTime = step->GetPreStepPoint()->GetGlobalTime() / ns;
    const auto kinE = step->GetPreStepPoint()->GetKineticEnergy();
    G4ThreeVector momentum = track->GetDynamicParticle()->GetMomentum();
    const auto p = std::sqrt(momentum.x()*momentum.x() + momentum.y()*momentum.y() + momentum.z()*momentum.z());
    const auto stepNb = track->GetCurrentStepNumber();
    const auto parentID = track->GetParentID();
    const auto trackStatus = track->GetTrackStatus();
    const auto currentEvent = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

    const auto stopCondition = ((trackStatus == fStopButAlive) || (trackStatus == fStopAndKill) || (trackStatus == fSuspend)); //stopping condition
    if((parentID == 0) && stopCondition == true)
    {
        const auto range = std::abs(-500 - track->GetPosition().z()/ mm);
        man->FillNtupleDColumn(0, 0, track->GetPosition().x()/ mm); //x posirion in cm
        man->FillNtupleDColumn(0, 1, track->GetPosition().y()/ mm); //y posirion in cm
        man->FillNtupleDColumn(0, 2, track->GetPosition().z()/ mm); //z posirion in cm
        man->FillNtupleIColumn(0, 4, (physVolume == "physAlMat")); //check if the volume is Alluminium
        man->AddNtupleRow(0);
    }
}