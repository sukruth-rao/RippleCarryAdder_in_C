#include <iostream>
#include <array>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class printArray {

	public:
		void displayArray(short array1[32]) {
			//cout << "the array is : ";
			for(int i = 31; i >= 0; i--){
				cout << array1[i] << " "; 
			}
			cout << "\n";
		}



};

class IntToBin {
	public:
		short *IntToBinaryArray(unsigned int e) {
			short *arr = (short*) malloc(32 * sizeof(short));
			for(int i = 0; i < 32; i++) {
				arr[i] = e % 2;
				e = e / 2;
			}
			return arr;
		}
};

class RippleCarryAdder_32 {

	public:
		int delayOfAdder;
		short* sum;
		int carryOut;
		
};
RippleCarryAdder_32 rca(short a_arr[32], short b_arr[32]) {

	RippleCarryAdder_32 rca_1;

	short *sum = (short*) malloc(32 * sizeof(short));
	int c = 0;
	int D = 0;
	int Dmax = 0;

	for (int i = 0; i < 32; i++) {
		sum[i] = a_arr[i] ^ b_arr[i] ^ c;
		if (c == 0) {
			if ((a_arr[i] == 0) && (b_arr[i] == 0)) {
				Dmax = std::max(Dmax, D);
				D = 0;
			}
			else if ((a_arr[i] ^ b_arr[i]) == 1) {
				D = 2;
				Dmax = std::max(Dmax, D);
				D = 0;
			}
			else if ((a_arr[i] & b_arr[i]) == 1) {
				D = 2;
				Dmax = std::max(Dmax, D);
			}
		}
		if (c == 1) {
			if ((a_arr[i] == 0) && (b_arr[i] == 0)) {
				D = D + 2;
				Dmax = std::max(Dmax, D);
				D = 0; // carry dies out
			}
			else if ((a_arr[i] ^ b_arr[i]) == 1) {
				D = D + 2;
				Dmax = std::max(Dmax, D);
			}
			else if ((a_arr[i] & b_arr[i]) == 1) {
				D = D + 2;
				Dmax = std::max(Dmax, D);
				D = 2;
			}
		}
		c = ((a_arr[i] & b_arr[i]) | c & (a_arr[i] ^ b_arr[i]));
	}

	rca_1.delayOfAdder = Dmax;
	rca_1.sum = sum;
	rca_1.carryOut = c;

	return rca_1;
}

int main() {

	unsigned int x, y;
	cout << "Enter the value of Integer A & B: ";
	cin >> x;
	cin >> y;

	IntToBin IntToBinObj;
	printArray printArrayObj; //object of printArray

	short *a;
	a = IntToBinObj.IntToBinaryArray(x);
	cout << " A : ";
	printArrayObj.displayArray(a);

	short *b;
	b = IntToBinObj.IntToBinaryArray(y);
	cout << " B : ";
	printArrayObj.displayArray(b);


	RippleCarryAdder_32 RCA = rca(a,b);
	cout << "Sum: ";
	printArrayObj.displayArray(RCA.sum);

	cout << "Delay :" << RCA.delayOfAdder << "D" << "\n";
	cout << "C_32 : " << RCA.carryOut << "\n";

	free(a);
	free(b); 
	free(RCA.sum);

	return 0;
}


