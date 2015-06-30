# erebus
reverse engineering for linux

#### short build guide
As libraries you need gtk.
To build this project you need the headerfiles for gtkmm.

You need make,cmake

If you have the packages installed, navigate to the directory where you want to build erebus and type:
```
git clone https://github.com/SuppenGeist/erebus
cd erebus
mkdir build
cd build
cmake ..
make
```

To execute the program type:
```
./erebus
```
