#include "Header.h"

using namespace std;


void main()
{
	size_t t,q;
	cout << "Hello! Let's start working with RNA" << endl;
	cout << "Pleas, enter your nucleotids amount" << endl;
	cin >> t;
	RNA rna1(t, A);
	rna1.build_rna();
	cout << "let's make another rna" << endl;
	cin >> q;
	RNA rna3(q, C);
	RNA rna2(5, T);
	rna2.build_rna();
	rna3.rna_out_put();
	RNA rna7(10, G);
	const RNA rna4(17, G); 
	rna4[1];
	rna1[1];
	rna3 = rna1;
	rna3 = rna1 >> 3;
	rna2 = rna1 + rna3;
	
}
