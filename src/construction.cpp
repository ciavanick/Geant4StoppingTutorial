#include "construction.h"

MyDetectorConstruction::MyDetectorConstruction() {}

MyDetectorConstruction::~MyDetectorConstruction() {}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    G4NistManager *nist = G4NistManager::Instance();

    G4Material *worldMat = nist->FindOrBuildMaterial("G4_Galactic"); //defining Galactic (vacuum) material

    //make the world
    G4Box *solidWorld = new G4Box("solidWorld", 1.*m, 1.*m, 1.*m);
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld"); 
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

    G4Material *alMat = nist->FindOrBuildMaterial("G4_Al"); //defining Aluminium material

    //make the aluminium block with a blue color
    auto BlueVisAtt = new G4VisAttributes(G4Colour(0.0, 127, 255));
    G4Box *solidAlBlock = new G4Box("solidAlBlock", 0.5*m, 0.5*m, 0.5*m);
    G4LogicalVolume *logicAlBlock = new G4LogicalVolume(solidAlBlock, alMat, "logicAlBlock"); 
    logicAlBlock->SetVisAttributes(BlueVisAtt);
    G4VPhysicalVolume *physAlMat = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.5*m), logicAlBlock, "physAlMat", logicWorld, false, 0, true);

    return physWorld;
}
