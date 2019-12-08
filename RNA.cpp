#include "RNA.h"

reference::reference(RNA * rna, size_t num)
{
	m_rna = rna;
	ind = num;
	//std::cout << "reference is consructed" << std::endl;
}

reference & reference :: operator = (Nucleotide N)
{
	size_t m, n;
	Nucleotide g;
	size_t block = ind / 16;
	//cout << block << endl;
	if (ind <= 16) m = ind;
	else
	{
		m = ind - 16 * block;
	}
	//cout << "block number is" << block << endl;
	n = (m_rna->rnaArr[block])&(b << (16 - m)); // добавляем еще одну маску.
	//std::cout << "mask is made" << std::endl;
	m_rna->rnaArr[block] = (n | (N << (16 - m)));
	//g = get_nucl(this, ind);
	return *this;
	//return reset_nucl(m_rna, ind, N);
}
size_t RNA::get_count() const
{
	return count;
}
size_t RNA :: get_nuclNum() const
{
	return this->nuclNum;
}
size_t RNA :: get_length()
{
	return this->length;
}

void RNA::copy_data(size_t* pArr) //copydatafunction
{
	for (int i = 0; i < (this->length); i++)
	{
		*(rnaArr + i) = *(pArr + i);
	}
	//std::cout << "copy is well done" << std::endl;
}

void RNA::mem_alloc(size_t s)
{
	size_t n = (s / 16) + 1;
	this->length = s;
	//std::cout << "number is" << n << std::endl;
	this->rnaArr = new size_t[n];
	//std::cout << "the length is" << length << std::endl;
	//std::cout << "Memmory is allocated" << std::endl;
	//for(int i)
}

void set_nucleotide(RNA * rna, Nucleotide ind)
{
	size_t n = (rna->count / 16);
	//size_t m = ind;
	rna->rnaArr[n] = ((rna->rnaArr[n]) | (ind << (16 - rna->count)));
	rna->count++;
}

Nucleotide get_nucl(RNA * ptr, size_t ind)
{
	size_t m;
	size_t block = ind / 16;
	//cout << block << endl;
	if (ind <= 16) m = ind;
	else
	{
		m = ind - 16 * block;
	}
	//cout << "block number is" << block << endl;
	size_t s = (ptr->rnaArr[block])&(a << (16 - m));
	if (s == (G << (16 - m)))
	{
		std::cout << "G";
		return G;
	}
	if (s == (C << (16 - m)))
	{
		std::cout << "C";
		return C;
	}
	if (s == (T << (16 - m)))
	{
		std::cout << "T";
		return T;
	}
	if (s == (A << (16 - m)))
	{
		std::cout << "A";
		return  A;
	}
}

const Nucleotide get_nucl(const RNA * ptr, const size_t ind)
{
	size_t m;
	size_t block = ind / 16;
	//cout << block << endl;
	if (ind <= 16) m = ind;
	else
	{
		m = ind - 16 * block;
	}
	//cout << "block number is" << block << endl;
	size_t s = (ptr->rnaArr[block])&(a << (16 - m));
	if (s == (G << (16 - m)))
	{
		std::cout << "G" << std::endl;
		return G;
	}
	if (s == (C << (16 - m)))
	{
		std::cout << "C";
		return C;
	}
	if (s == (T << (16 - m)))
	{
		std::cout << "T";
		return T;
	}
	if (s == (A << (16 - m)))
	{
		std::cout << "A";
		return  A;
	}
}

RNA::RNA() : rnaArr(nullptr), nuclNum(0), length(0), count(1) // default constructor 
{
	std::cout << "Hello, RNA!" << std::endl;
}

RNA::RNA(int s, Nucleotide n) //user constructor
{
	nuclNum = s;
	length = s;
	mem_alloc(s);// memory allocation;
	set_nucleotide(this, n);
}

RNA::RNA(const RNA & rna) //copy-constr: memory allocation
{
	this->nuclNum = rna.get_nuclNum();
	this->length = rna.get_length();
	this->count = rna.get_count();
	mem_alloc(this->get_length());
	copy_data(rna.rnaArr);
}

void build_nucl(RNA *rna, size_t k)
{
	Nucleotide f;
	int j = k % 4;
	if (j == 0) f = G;
	if (j == 1) f = C;
	if (j == 2) f = T;
	if (j == 3) f = A;
	set_nucleotide(rna, f);
}

void RNA::build_rna()
{
	size_t k;
	//srand((time(NULL)));
	for (int i = 1;i <= length;i++)
	{
		k = rand();
		build_nucl(this, k);
	}
}

size_t RNA::get_length() const
{
	return this->length;
}

void length_reset(RNA &rna, const RNA &ptr)
{
	rna.length = ptr.get_length();
	rna.count = ptr.get_count();
}

void copy(RNA &rna, const RNA &ptr)
{
	length_reset(rna, ptr);
	size_t g = ptr.get_length();
	int n = (g / 16) + 1;
	for (int i = 0;i < n;i++)
	{
		rna.rnaArr[i] = ptr.rnaArr[i];
	}//копируем значения
}

void RNA::rna_out_put()
{
	for (int i = 1;i <= length;i++)
	{
		get_nucl(this, i);
	}
	std::cout << "this is your RNA" << std::endl;
}

reference RNA :: operator[] (size_t n)
{
	Nucleotide M = get_nucl(this, n);
	std::cout << std::endl;
	return reference(this, n);
}

void set_NULL(RNA & rna)
{
	delete[] rna.rnaArr;
	rna.rnaArr = nullptr;
}

RNA & RNA :: operator=(const RNA &rna) //make iqual
{
	//rna = rna;
	size_t g = rna.get_length();
	if (this->get_length() == g)
	{
		Nucleotide q;
		copy(*this, rna);
		std::cout << "now they are equal (1) !" << std::endl;
	}
	else
	{
		delete[] rnaArr;
		rnaArr = nullptr;
		size_t n = ((g) / 16) + 1;
		rnaArr = new size_t[n];
		copy(*this, rna);
		std::cout << "now they are equal! (2) " << std::endl;
		//нужно сделать функцию ресет
	}
	return *this;
}

void Errore(double n)
{
	std::cout << "up's... please reput your number" << std::endl;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cin >> n;
}

RNA RNA :: operator >> (size_t n)
{
	size_t m = this->get_length();
	size_t l = m - n;
	Nucleotide N = get_nucl(this, n + 1);
	RNA ref(l, N);
	for (int i = n + 2; i <= m; i++)
	{
		N = get_nucl(this, i);
		set_nucleotide(&ref, N);
	}
	//*this = ref; 
	return ref;

}

RNA RNA :: operator + (RNA &ptr)
{
	size_t n = this->get_length();
	size_t m = ptr.get_length();
	size_t l = n + m;
	Nucleotide N = get_nucl(this, 1);
	RNA ref(l, N);
	for (int i = 2; i <= n; i++)
	{
		N = get_nucl(this, i);
		set_nucleotide(&ref, N);
	}
	for (int i = 1; i <= m; i++)
	{
		N = get_nucl(this, i);
		set_nucleotide(&ref, N);
	}
	return ref;
}

const RNA & RNA :: operator[] (const size_t n) const
{
	Nucleotide M;
	M = get_nucl(this, n);
	std::cout << M;
	return *this;

}
