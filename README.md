# erebus
reverse engineering for linux

#### short build guide
You need gtkmm dev packages.
You need the gtk libraries.
You need make,cmake,svn,git programs.

If you have everything installed, navigate to the directory where you want to build erebus and type:
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

#### documentation

To create a documentation type (you need doxygen installed)
```
doxygen
```