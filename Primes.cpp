#include"Primes.h"

void Primes::resize_(uint32_t &new_size){

if(new_size == 0){std::cout<<"Размер нуль!\n";std::exit(1);}

        if(!end_flag)
            this->end_flag = true;
        this->size_ = new_size;
        data.resize(new_size);};


uint32_t Primes::modul_power(uint32_t &base,uint32_t &n,uint32_t &modulus)
{

   uint32_t c = 1;

   for (int n_ = 1; n_ <= n; n_++)
    c = (c * base) % modulus;

    return c;

};

Primes::Primes(uint32_t &max){
    for(uint32_t i = 1; i < max;i++){
        if(Isprime(i)){
            this->data.push_back(i);
            this->size_++;
        }
}}
Primes::Primes(Primes &prime){
    this->size_ = prime.size_;
    data.clear();
    data.resize(prime.size_);
    this->data = prime.data;
    this->end_flag = prime.end_flag;
}
Primes::Primes(Primes &&prime){

    this->data = prime.data;
    prime.data.resize(0);
    this->size_ = prime.size_;
    prime.size_ = 0;
    this->end_flag = prime.end_flag;
    prime.end_flag = false;
}


Primes::Primes(){
    for(uint32_t i = 1; i < 100;i++){
        if(Isprime(i)){
            this->data.push_back(i);
            this->size_++;
        }
}

}
/*
	@brief тест Миллера-Рабина для проверки числа на простоту
*/
bool Primes::Isprime(uint32_t &value){


    if (value <= 3 && value > 0)
       return true;

    if (value % 2 == 0 || value % 3 == 0)
        return false;

      uint32_t chetnost = 2;
      global_memory+=sizeof(chetnost);

      uint32_t k = std::log2(value);//подсчитывания числа раундов
      uint32_t digit = value -1;
      uint32_t s = 0;
      uint32_t t = 0;
/*
	@brief учет памяти использования программы
*/

      global_memory+=sizeof(k);
      global_memory+=sizeof(digit);
      global_memory+=sizeof(s);
      global_memory+=sizeof(t);



       while (digit % 2 == 0)
       {
          t = digit / 2;
          s++;
          digit/=2;
       }//для представления числа в виде n - 1 = 2^s * 2>

       for (int i = 0; i < k; i++)
       {
          uint32_t a = std::rand()% (value - 2) + 2;
          uint32_t tmp = modul_power(a,t,value);

          global_memory+=sizeof(a);
          global_memory+=sizeof(tmp);

          if(tmp == 1 || tmp == value - 1) return true;
          else
          {
             for (auto j = 0; j <= s - 1; j++)
             {
                tmp = modul_power(tmp,chetnost,value);
                if(tmp == 1) return false;
                if(tmp == value - 1)return true;
             }
          }
          return false;

       }
       return true;
    }//т.к тест вероятностый могут возникать ошибки

void Primes::setData(uint32_t &value){
    if(value <=0){std::cout<<"Контейнер не может содержать данное число!\n";std::exit(1);}/*@throw value error простые числа >0*/
    if(!end_flag)
     this->end_flag = true;
    this->data.push_back(value);
    this->size_++;
}
void Primes::showValue(){
    for(auto &i : this->data)
     std::cout<<i<<" ";
}
