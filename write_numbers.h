#ifndef WRITE_NUMBERS_H
#define WRITE_NUMBERS_H
#include"Primes.h"
/*
	@section содержит вспомогательную функцию для добавления элементов в контейнер без верхней границы
	проверку на степень двойки 
	проверка на пренадлежность специальной последовательности 
*/
void make_without_upperbound(Primes &prime,uint32_t &tmp);
bool isPowerOfTwo(uint32_t value);
bool isProthPrime(Primes &prime,uint32_t &value,uint32_t& i);
#endif // WRITE_NUMBERS_H
