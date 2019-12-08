#ifndef Header_H
#define Header_H
#include <iostream>
#include <cstdio>
#include <cmath>
#include <conio.h>
#include <bitset>
#include <cstdlib>
#include <ctime>


enum Nucleotide
{
	G = 0b00000000000000000000000000000000,
	C = 0b00000000000000000000000000000001,
	T = 0b00000000000000000000000000000010,
	A = 0b00000000000000000000000000000011,

};
enum Mask {
	a = 0b00000000000000000000000000000011,
	b = 0b11111111111111111111111111111100
};
class RNA;
class reference
{
	RNA *m_rna;
	size_t ind;
	friend RNA;
public:
	reference(RNA * rna, size_t num);

	//reference & reset_nucl(RNA * ptr, size_t ind, Nucleotide n);

	reference & operator = (Nucleotide N);
};
class RNA
{
private:
	size_t nuclNum; //3
	size_t * rnaArr;
	size_t length; //actual length = 1

	size_t count; //counts the written nucls

public:

	
	friend class reference;
	
	size_t get_count() const;
	size_t get_nuclNum() const;
	size_t get_length();

	void copy_data(size_t* pArr);//copydatafunction

	void mem_alloc(size_t s);

	friend void set_nucleotide(RNA * rna, Nucleotide ind);

	friend Nucleotide get_nucl(RNA * ptr, size_t ind);
	friend const Nucleotide get_nucl(const RNA * ptr, size_t ind);

	RNA(); //: rnaArr(nullptr), nuclNum(0), length(0), count(1)// default constructor 


	RNA(int s, Nucleotide n);//user constructor

	RNA(const RNA & rna);//copy-constr: memory allocation

	friend void build_nucl(RNA *rna, size_t k);

	void build_rna();

	size_t get_length() const;

	friend void length_reset(RNA &rna, const RNA &ptr);

	friend void copy(RNA &rna, const RNA &ptr);

	void rna_out_put();

	reference operator[] (size_t n);

	const RNA & operator [] (size_t n) const;

	RNA & operator=(const RNA& rna); //make iqual

	friend void set_NULL(RNA & rna);

	RNA operator >> (size_t n);

	RNA operator + (RNA &ptr);

	~RNA()
	{
		delete[] rnaArr;
		rnaArr = nullptr;
	}

};
// & reference::reset_nucl(RNA * ptr, size_t ind, Nucleotide n);


void Errore(double n);



#endif // !RNA_H#pragma once
