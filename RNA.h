#ifndef RNA_H
#define RNA_H
#include <iostream>
#include <cstdio>
#include <cmath>
#include <conio.h>
#include <bitset>
#include <cstdlib>
#include <ctime>


enum Nucleotide //присваиваем каждому нуклеотиду свой код/номер
{
	G = 0b00000000000000000000000000000000,
	C = 0b00000000000000000000000000000001,
	T = 0b00000000000000000000000000000010,
	A = 0b00000000000000000000000000000011,
};
enum Mask //маска нужна чтобы извлекать нужные нам нуклеотида из цепи
{
	a = 0b00000000000000000000000000000011,
	b = 0b11111111111111111111111111111100
};
class RNA;
class reference //класс ссылка поможет нам для хранения промежуточной копии рнк при работе с обрезанием
				//и сшиванием нескольких цепей
{
	RNA *m_rna;
	size_t ind;
	friend RNA;
public:
	reference(RNA * rna, size_t num); //конструктор
	reference & operator = (Nucleotide N); //оператор присваивания, как видим через класс нуклеотид
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
	
	size_t get_count() const; //счетчик нуклеотидов, показывает, сколько нуклеотидов записано в цепь, 
					//помогает узнать есть ли пустые ячейки и т.п.
	
	size_t get_nuclNum() const; //константный метод получения значения длины цепочки РНК
	
	size_t get_length(); //получение длины и кол-ва нуклеодитов одинаково

	void copy_data(size_t* pArr);//copydatafunction - функция копирования по блочное
	
	void mem_alloc(size_t s); //функция выделения памяти
	
	friend void set_nucleotide(RNA * rna, Nucleotide ind); //метод установки одного нуклеотида в ячейку памяти(2 бита вроде)
	
	friend Nucleotide get_nucl(RNA * ptr, size_t ind); //метод получения значения нуклеотида по указанному порядковому номеру
	
	friend const Nucleotide get_nucl(const RNA * ptr, size_t ind); //аналогичный метод получения нуклеотида, только константный

	RNA(); //: rnaArr(nullptr), nuclNum(0), length(0), count(1)// default constructor 

	RNA(int s, Nucleotide n);//user constructor

	RNA(const RNA & rna);//copy-constr: memory allocation

	friend void build_nucl(RNA *rna, size_t k); //метод заполнения контейнера РНК нуклеотидами, т.е. строим цепь

	void build_rna(); //кажись она не нужна

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
