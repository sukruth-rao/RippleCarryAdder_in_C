#include <iostream>
#include <array>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void printarray(short array1[32]) {
    //cout << "the array is : ";
    for(int i = 31; i >= 0; i--){
        cout << array1[i] << " "; 
    }
    cout << "\n";

}

short *test1(unsigned int e) {
    short *arr = (short*) malloc(32 * sizeof(short));
    //int array[32];
    for (int i = 0; i < 32; i++) {
        arr[i] = e % 2;
        e = e / 2;
    }
    //cout << arr;
    return arr;
}

struct RippleCarryAdder {
	int delayOfAdder;
	short* sum;
	int carryOut;
};
RippleCarryAdder rca_1(short a_arr[32], short b_arr[32]) {

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

	RippleCarryAdder rca1;
	rca1.delayOfAdder = Dmax;
	rca1.sum = sum;
	rca1.carryOut = c;

	return rca1;
}


//int *rca(int a_arr[32], int b_arr[32]){
   

int main() {

	unsigned int x, y;
	cout << "Enter the value of Integer A & B: ";
	cin >> x;
	cin >> y;

	short *a;
	a = test1(x);
	cout << " A : ";
	printarray(a);

	short *b;
	b = test1(y);

	cout << " B : ";
	printarray(b);

	RippleCarryAdder RCA = rca_1(a,b);

	cout << "Sum: ";
	printarray(RCA.sum);

	cout << "Delay :" << RCA.delayOfAdder << "D" << "\n";
	cout << "C_32 : " << RCA.carryOut << "\n";

	free(a);
	free(b); 
	free(RCA.sum);
}



