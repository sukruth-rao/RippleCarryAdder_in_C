# RippleCarryAdder in C
#### This branch contains the command-line tool

**Clone the CLI branch and compile the source code found in the RCA directory**


Open a terminal
```
git clone -b CLI https://github.com/sukruth-rao/RippleCarryAdder_in_CPP.git
cd RippleCarryAdder_in_CPP/RCA
```

### Compile the source code RCA.c

## GCC
```
gcc RCA.c -o <anyname>
```

## LLVM Clang
```
clang RCA.c -o <anyname>
```

Run the executable along with the arguments
```
./<anyname><leader>a<leader>b
```
or 
```
./<anyname> a b
```

a and b are unsigned 32-bit numbers 
> 0 - 4294967295
