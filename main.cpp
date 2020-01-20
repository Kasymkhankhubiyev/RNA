#include "Header.h"

using namespace std;


void main()
{
	size_t t,q;
	cout << "Hello! Let's start working with RNA" << endl;
	cout << "Pleas, enter your nucleotids amount" << endl;
	cin >> t;  //считываем рамер РНК (кол-во нуклеотидов)
	RNA rna1(t, A);
	rna1.build_rna();
	cout << "let's make another rna" << endl;
	cin >> q;  //считываем рамер РНК (кол-во нуклеотидов)
	RNA rna3(q, C); //создаем РНК - задаем кол-во нуклеотидов и начальный нуклеотид
	RNA rna2(5, T); 
	rna2.build_rna(); //заполняем РНК нуклеотидами, т.е. создаем цепочку
	rna3.rna_out_put();
	RNA rna7(10, G);
	const RNA rna4(17, G); //константная цепочка
	rna4[1]; //первый элемент цепочки РНК
	rna1[1];
	rna3 = rna1; //приравниваем
	rna3 = rna1 >> 3; //отрезаем у РНК хвост размеров в 3 нуклеотида и присваиваем остаток новой РНК
	rna2 = rna1 + rna3; //склеиваем две цепочки РНК	
}
