# RationalNumber
Project created by COUARD Lou and DIEP Audrey

# Install dependencies

* cmake (at least version 3.15)
  - ** Linux ** : sudo apt install cmake
  - ** Mac ** : brew install cmake
  - ** Windows ** : https://cmake.org/install
* Doxygen
  - ** Linux ** : sudo apt install doxygen
  - ** Mac ** : brew install doxygen
  - ** Windows ** : https://www.doxygen.nl/manual/install.html

# Usage
## command line


* To compile a project, first :
```
cd RationalNumber
mkdir build 
cd build 
cmake .. 
./bin/rationalTest
```

* Then each time you compile, from the same directory
```
make
```
* If you add some new files and / or edit the *CMakeList.txt*, redo : 
```
cmake ..
make
```
* Optional : if you want to install a lib
```
sudo make install
```
* Optional : if you want to generate the doc
```
make html
```
then open the file build/INTERFACE/doc/doc-doxygen/html/index.html in your browser
