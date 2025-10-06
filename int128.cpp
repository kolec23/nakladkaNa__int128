#include "int128.h"

//konstruktory
int128::int128()
{
	this->wartosc=0;
}

int128::int128(__int128 value)
{
	this->wartosc=value;
}

int128::int128(std::string number) 
{
	
	__int128 waga=1;
	__int128 cyfra;
	__int128 wynik=0;
	if(this->sprawdzCzyLiczba(number[0])==false) throw std::invalid_argument("That isn't number'");
	if(number[0]=='-')
	{
		for(int i=number.size()-1; i>0; i--)
		{
			if(this->sprawdzCzyLiczba(number[i])==false) throw std::invalid_argument("That isn't number'");
			cyfra=number[i]-'0';
			wynik=wynik+cyfra*waga;
			waga=waga*10;
		}
		wynik=(-1)*wynik;
	}
	else
	{
		
		for(int i=number.size()-1; i>=0; i--)
		{	if(this->sprawdzCzyLiczba(number[i])==false) throw std::invalid_argument("That isn't number'");
			cyfra=number[i]-'0';
			wynik=wynik+cyfra*waga;
			waga=waga*10;
		}
		
	}
	this->wartosc=wynik;
}

//operatory dzialan
int128 int128::operator+ (int128 b)
{
	__int128 pom=this->wartosc+b.wartosc;
	int128 wynik(pom);
	return wynik;
}

int128 int128::operator- (int128 b)
{
	__int128 pom=this->wartosc-b.wartosc;
	int128 wynik(pom);
	return wynik;
}

int128 int128::operator* (int128 b)
{
	__int128 pom=this->wartosc*b.wartosc;
	int128 wynik(pom);
	return wynik;
}

int128 int128::operator% (int128 b)
{
	__int128 pom=this->wartosc%b.wartosc;
	int128 wynik(pom);
	return wynik;
}

int128 int128::operator/ (int128 b)
{
	if(b.wartosc==0) throw std::invalid_argument("Divide by zero don't allowed.");
	__int128 pom=this->wartosc/b.wartosc;
	int128 wynik(pom);
	return wynik;
}


int128 int128::operator++ ()
{
	this->wartosc=wartosc+1;
	return (*this);
}

int128 int128::operator++ (int)
{
	this->wartosc=wartosc+1;
	return (*this);
}

int128 int128::operator--()
{
	this->wartosc=wartosc-1;	
	return (*this);
}

int128 int128::operator--(int)
{
	this->wartosc=wartosc-1;	
	return (*this);
}


//operatory porownania
bool int128::operator== (int128 b)
{
	__int128 pom=this->wartosc;
	return pom==b.wartosc;
}

bool int128::operator> (int128 b)
{
	__int128 pom=this->wartosc;
	return pom>b.wartosc;
}

bool int128::operator>= (int128 b)
{
	__int128 pom=this->wartosc;
	return pom>=b.wartosc;	
}

bool int128::operator<= (int128 b)
{
	__int128 pom=this->wartosc;
	return pom<=b.wartosc;	
}

bool int128::operator< (int128 b)
{
	__int128 pom=this->wartosc;
	return pom<b.wartosc;	
}

bool int128::operator!= (int128 b)
{
	__int128 pom=this->wartosc;
	return pom!=b.wartosc;
}


void int128::write()
{
	std::cout<<konwertuj()<<std::endl;
}

std::string int128::konwertuj()
{
	std::string wynik="";
	__int128 a=this->wartosc;
	if (a==0) return "0";
	if(a<0)
	{
		a=a*(-1);	
	}
	while(a>0)
	{
		char znak='0';
		short cyfra=a%10;
		znak+=cyfra;
		wynik=znak+wynik;
		a=a/10;
	}
	if(this->wartosc<0)
	{
		wynik="-"+wynik;
	}
	return wynik;
}

bool int128::sprawdzCzyLiczba( char z)
{
	switch(z)
	{
		case '-': return true; break;
		case '0': return true; break;
		case '1': return true; break;
		case '2': return true; break;
		case '3': return true; break;
		case '4': return true; break;
		case '5': return true; break;
		case '6': return true; break;
		case '7': return true; break;
		case '8': return true; break;
		case '9': return true; break;
		default: return false;
	}
}

