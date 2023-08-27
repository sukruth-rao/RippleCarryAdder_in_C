# RippleCarryAdder in C

<h1 align="center">
  <img src="https://github.com/Sukruth-Rao7/RippleCarryAdder_in_CPP/blob/master/img/rca.jpeg">
</h1>

Implementing the delay logic for calculating sum using Ripple Carry Adder for 32-bit unsigned integers.

Takes user input for Two unsigned integers A , B (0 to 4294967295).
Converts the unsigned int to 32-bit binary number ans stores it in two distinct arrays of length 32 each.
  - eg, 15 = 00000000000000000000000000001111

Performs 1-bit binary addition between each element of array a with the corresponding element of array b according to Full Adder Logic (Sum = A ⊕ B ⊕ C, C-out = A.B + C.(A ⊕ B) )
A, B are 1 bit binary numbers & C is the Carry.
