#ifndef WRITE_TO_FILE_H
#define WRITE_TO_FILE_H
#include"write_numbers.h"
/*
	@section Модуль для записи в файл чисел, которые принадлежат специальным последовательностям
*/
void Write(Primes &prime, bool key_);
void how_write(std::function<void(Primes&,bool)> f,Primes &prime);
#endif // WRITE_TO_FILE_H
