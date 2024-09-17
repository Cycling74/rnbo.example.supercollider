# RNBO SuperCollider UGen Example

## Build the example

- Clone this repository
- Pull in `supercollider` git submodule: `git submodule update --init --recursive`
- Open the example RNBO patch (`example/RNBOSaw.maxpat`) and export the RNBO patch to `rnbo-export`
  in your copy of this repository.
  * *NOTE* make sure that your export name is `rnbo_source.cpp`
- Configure the CMake build: `mkdir build && cd build && cmake ..`
- Build (from `/build`): `cmake --build .`
- The new `*.scx` file should now be available from the `/build` directory.
