#include "run.h"

MyRunAction::MyRunAction()
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->CreateNtuple("t1", "all data for primary muons here");
    man->CreateNtupleDColumn("fPosX");
    man->CreateNtupleDColumn("fPosY");
    man->CreateNtupleDColumn("fPosZ");
    man->CreateNtupleIColumn("StopInAl");
    man->CreateNtupleIColumn("fEventID");
    man->FinishNtuple(0);

}

MyRunAction::~MyRunAction() {}

void MyRunAction::BeginOfRunAction(const G4Run *run)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    G4int runID = run->GetRunID();
    std::stringstream strRunID;
    strRunID << runID;

    man->OpenFile("output" + strRunID.str() + ".root");
}

void MyRunAction::EndOfRunAction(const G4Run *)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->Write();
    man->CloseFile();
}