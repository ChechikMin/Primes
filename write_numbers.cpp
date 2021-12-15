#ifndef WRITE_STATISTIC_H
#define WRITE_STATISTIC_H
#include "Primes.h"


void make_without_upperbound(Primes &prime,uint32_t &tmp){//функция для добавления простых чисел в контейнер, если не задана верхняя граница
    if(tmp > 26){
        uint32_t k = 0;
        for(uint32_t i = 98; k < tmp;i++)
         if(prime.Isprime(i)){
             prime.setData(i);
             k++;

   global_memory+=sizeof(k);
}
}
    else if(tmp < 26)//если размер больше 26(максимальный элемент до 100(по умолчанию пустой контейнер))
        prime.resize_(tmp);
}
bool isPowerOfTwo(uint32_t value)//проверка на степень двойки
{
    return (value && !(value & (value - 1)));
}

bool isProthPrime(Primes &prime,uint32_t &value,uint32_t& i)
{
   std::function <bool(uint32_t)> f_1;
   f_1 = [](uint32_t tmp){//лмбда функция на принадлежность числа последовательности Прота
        uint32_t k = 1;
         while (k < (tmp / k)) {

             if (tmp % k == 0) {

                 if (isPowerOfTwo(tmp / k) )
                     return true;
             }
             k = k + 2;
         }
         return false;
    };
   if (f_1(value - 1)) {//проверяем принадлежит ли число последовательности Прота последовательности простых чисел

           uint32_t tmp = prime[i];
           if (prime.Isprime(tmp))
               return true;
           else
               return false;
       }
       else
           return false;
   }







#endif // WRITE_STATISTIC_H
