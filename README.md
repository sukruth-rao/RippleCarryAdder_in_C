# RippleCarryAdder in C
#### This branch contains the command-line tool

**Clone the CLI branch and compile the source code found in the RCA directory**


Open a terminal
```
git clone -b CLI https://github.com/sukruth-rao/RippleCarryAdder_in_C.git
cd RippleCarryAdder_in_C/RCA
```

## Compile the source code RCA.c

### GCC &middot; [![GCC](https://img.shields.io/badge/GCC-red)](https://gcc.gnu.org/)
`gcc RCA.c -o <anyname>`

eg:
```
gcc RCA.c -o rca
```

### LLVM Clang &middot; [![LLVM](https://img.shields.io/badge/LLVM-green)](https://llvm.org/)
`clang RCA.c -o <anyname>`

eg:
```
clang RCA.c -o rca
```
> [!IMPORTANT]
> Replace anyname with whatever you prefer, ignore the angular graces as well
&nbsp;

&nbsp;


**Run the executable along with the arguments**
```
./<anyname><leader>a<leader>b
```
or
```
./<anyname> a b
```
> eg: ./rca 1 15

a and b are unsigned 32-bit numbers 
> 0 - 4294967295
