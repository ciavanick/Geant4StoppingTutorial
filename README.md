# Geant4StoppingTutorial
This an easy tutorial/example on how to stop particle in block of Aluminium in geant4.

## Geant4 installation

The simulation has been developed on a machine with an Apple M1 processor with Geant4 11.2.2.

To install Geant4 I recommend using a Conda environment (Anaconda or Miniconda) with [Conda Forge]([https://pages.github.com/](https://conda-forge.org)):

```
$ conda create -n geant4env
$ conda activate geant4env
$ conda config --add channels conda-forge
$ conda config --set channel_priority strict
$ conda install root geant4
```
The name `geant4env` can be changed.

## Run the simulation

To compile and run the simulation in batch mode you can:

```
$ cd /path/to/Geant4StoppingTutorial
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . -- -j $(nproc)
$ ./simulation run.mac
```
To run the simulation in visualization mode:
```
$ ./simulation
```

Note: the command $(nproc) does not work on MacOs, instead use `$(sysctl -n hw.logicalcpu)`

## Bibliography
The simulation is based on this [tutorials](https://www.youtube.com/playlist?list=PLLybgCU6QCGWgzNYOV0SKen9vqg4KXeVL).

