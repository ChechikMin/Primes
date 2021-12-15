#ifndef PRIMES_H
#define PRIMES_H

#include<vector>
#include<iostream>
#include<math.h>
#include<cstdint>
#include<functional>
#include<fstream>
#include<chrono>
#include<string>
/*

@mainpage Этот модкль содержит объявление класса Primes и подкласс Iterator

*/
static int global_memory = 0; //глобальная переменная для подсчета используемой памяти

class Primes
{
private:
/*
	@brief поля содержат массив простых чисел, размер массива, флаг сигнализирующий о достигаемости конца массива
*/
    std::vector <uint32_t> data;
    size_t size_ = 0;
    bool end_flag = false;
public:
    Primes(uint32_t &max); // конструктор при создании простых чисел до максимального элемента
    Primes(Primes &prime); // конструктор копирования
    Primes(Primes &&prime); // конструктор перемещения
    Primes();// содержит по умолчанию простые числа до 100(без верхней границы)
    bool Isprime(uint32_t &value);//проверка числа на простоту
    bool IsprimeProt(uint32_t &value);//проверка пренадлежности специальной последовательности
    void setData(uint32_t &value);//метод для добавления простого числа в контейнер
    uint32_t modul_power(uint32_t &base,uint32_t &n,uint32_t &modulus);//возведение числа в степень по модулю
    void showValue();//вывод в консоль элементов контейнера
    void resize_(uint32_t &new_size);//корректировка размера если чисел требуется меньше чем макс 100

/*
	@brief Вспомогательный класс для прогонки по контейнеру
*/
    class Iterator;

    Iterator begin(){return data.data();};//возвращает указатель на первый член
    Iterator end(){
        if(end_flag){//проверка на возможность достижения онца
            std::cout<<"Cant get end of series!Returned pointer on the first element.";
            return data.data();
        }

        uint32_t *tmp = data.data();
        tmp+=data.size();
        return tmp;//возвращение указателя на следующий элемент после последнего
    };
    uint32_t size(){return this->size_;};
/*
	доступ к элементу через перегруженные []
*/
    uint32_t operator[](const uint32_t& index){

        if(index > 0 && index < this->size_)
            return data[index];
        /*
	@throw index is not range если обращаемся за пределы
*/
        else{
            std::cout<<"Error,index is not range!";
            std::exit(1);
        }

    }

    Primes& operator = (const Primes &prime) = delete;//запрет на копирование

    class Iterator{
/*
	содержит указатель на элемент		
*/
        uint32_t *current;

    public:
        Iterator(uint32_t *first) : current(first){}

        Iterator operator ++(){current++;return current; }
        Iterator operator --(){current--;return current; }
        uint32_t operator *(){return *current;}
    };


};


#endif // PRIMES_H
