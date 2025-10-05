#ifndef INT128_H
#define INT128_H
#include <iostream>
#include <string>
 class int128 final 
{
	public:
		int128();
		int128 (std::string number); 
		int128(__int128 value); //wartosc liczby
		int128 operator+ (int128 b); //dodawanie dwóch liczb typu __int128
		int128 operator- (int128 b); //odejmowanie dwóch liczb typu __int128
		int128 operator* (int128 b); //mnozenie dwoch liczb typu __int128	
		int128 operator% (int128 b); //reszta z dzielenia
		int128 operator/ (int128 b); //dzielenie całkowito liczbowe
		int128 operator++ (); //inkrementacja o 1;
		int128 operator++ (int); //inkrementacja o 1;
		int128 operator-- (); //dekrementacja o 1
		int128 operator-- (int); //dekrementacja o 1
		bool operator==  (int128 b); //czy liczby rowne
		bool operator< (int128 b); //czy liczba jest mniejsza
		bool operator<= (int128 b); //czy liczba jest mniejsza bądż równe
		bool operator> (int128 b);   //czy liczba jest większa
		bool operator>= (int128 b); //czy liczba jest większa bądź rwne
		bool operator!= (int128 b); //czy liczby różnego
		void write(); //tymczasowe przerobić na funkcje zaprzyjaźniną do couta 
	private:
		__int128 wartosc=0;
		std::string konwertuj(); //rzutowanie wartosci na wartosc string ktury wyswietlic;
	
		
};
#endif