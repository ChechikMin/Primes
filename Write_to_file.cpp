#ifndef WRITE_TO_FILE_H
#define WRITE_TO_FILE_H

#include"write_numbers.h"

/*
	функция записывает либо в фаил, либо в консоль (по выбору пользователя) числа которые принадлежат специальным последовательностям
	при этом контейнер содержит все простые числа заданного диапазона,которые был введен

*/

void Write(Primes &prime, bool key_){


    bool key = false;//для выбора последовательности
    std::vector<uint32_t> vec;// вспомогательный контейнер для хранения специальных чисел
    std::function<void(uint32_t)> f;//для последовательности Софи-Жермен и суперпростых
    std::function<bool(Primes&,uint32_t&,uint32_t&)> f_1;//для последовательности Прота и суперпростых


    f = [&prime,&vec](uint32_t tmp){
            for (uint32_t i = 1; i < prime.size() ; i++)
             if (prime[i] == 2*tmp + 1 && prime.Isprime(i))//проверка на пренадлежность двум последовательностям одновременно
              vec.push_back(tmp);
        };//лямбда функция добавления в контейнер чисел СЖ и суперпростых

    f_1 = isProthPrime;


    std::cout<<"Выбор печати простых чисел.\n"
               "Простые числа Софи-Жермен и суперпростые - 0\n"
               "Простые числа Прота и cуперпростые - 1\n";
    std::cin>>key;
	
    if(!key)
      for(uint32_t i = 1; i <prime.size();i++)
        f(prime[i]);
    if(key)
        for(uint32_t i = 1; i <prime.size();i++){
            uint32_t tmp = prime[i];
          if (f_1(prime,tmp,i) && prime.Isprime(i))//проверка на пренадлежность двум последовательностям одновременно
              vec.push_back(prime[i]);}
     else{
	std::cout<<"Неправильный ввод!";
	srd::exit(1);}

if(key_){//даные записываются в указанный фаил

    std::string path;
    std::cout<<"Введите имя файла:\n";
    std::cin>>path;

    std::fstream fin(path + ".txt",std::ios::out);
	

	fin<<vec.at(0)<<"\n";

    for(int i = 1;i < vec.size();i++)
	if(prime.Isprime(i))
         fin<<vec.at(i)<<"\n";
    fin.close();

    std::cout<<"Данные записаны успешно!\n";
}
/*
	аналагично, но данные записываются в терминал
*/
else
{	
	std::cout<<vec.at(0)<<" ";

    for(int i = 1;i < vec.size();i++)
         std::cout<<vec.at(i)<<" ";

        std::cout<<"\n";

        std::cout<<"Данные записаны успешно!\n";
    }

}

/*
	передаем функцию, которую пользователь выбрал в процессе работы программы и контейнер

*/


void how_write(std::function<void(Primes&,bool)> f,Primes &prime){
    char tmp;

    std::cout<<"Если вы хотите записать данные в файл - Y. Если нет - n"
               " .\n";
    std::cin>>tmp;

    if(tmp == 'Y')
        f(prime,true);
    if(tmp == 'n')
        f(prime,false);
    else{
	std::cout<<"Неправильный ввод!";
	srd::exit(1);}/*@throw error input завершение если неправильно ввели значение*/

    std::cout<<"\n";
}


#endif // WRITE_TO_FILE_H
