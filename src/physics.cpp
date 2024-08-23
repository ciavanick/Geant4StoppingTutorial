#include "physics.h"

MyPhysicsList::MyPhysicsList() //here we register the physics
{
    RegisterPhysics(new G4EmStandardPhysics());
}

MyPhysicsList::~MyPhysicsList() {}
