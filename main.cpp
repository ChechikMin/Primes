#include"write_to_file.h"
/*
	@brief точка входа программы определяет её старт
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"ru");

/*
	переменные для работы по ветвям программы
*/
    bool insert = false;
    std::string path;
    std::fstream data_of_process;
    char key = 'Y';
    uint32_t tmp = 1;
    std::function<void(Primes&,bool)> f;

    f = Write;//присваиваем указатель на выполнение данной функции

/*
	учет памяти, запись в глобальную переменную
*/
    global_memory+=sizeof(f);
    global_memory+=sizeof(key);
    global_memory+=sizeof(path);
    global_memory+=sizeof(data_of_process);
    global_memory+=sizeof(tmp);

    while (key == 'Y') {

    std::cout<<"Поиск простых чисел в диапазоне с верхней границей используйте - 1.\n"
               "Поиск определенного количества простых чисел  используйте - 0.\n";
    std::cin>>tmp;

    if(tmp)//если ввели максимальное число
    {

        std::cout<<"Введите верхнюю границу:\n";
        std::cin>>tmp;


        auto start = std::chrono::high_resolution_clock::now();//создание объекта для подсчета времени

        Primes *prime = new Primes(tmp);//динамически выделяем т.к контейнер может содержать много чисел

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start; //расчет времени
        global_memory+=sizeof(duration);

        how_write(f,*prime);

        std::cout<<"Для нахождения простых чисел до верхней границы:"<<tmp<<"\n";
    }
    if(!tmp){//водим кол-во простых чисел
        std::cout<<"Введите количество простых чисел:\n";
        std::cin>>tmp;
        auto start = std::chrono::high_resolution_clock::now();

        Primes *prime = new Primes;
        make_without_upperbound(*prime,tmp);


        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        global_memory+=sizeof(duration);

        how_write(f,*prime);//выбор опции записи

        std::cout<<"Для нахождения простых чисел заданного количества:"<<tmp<<"\n";
        
        }
    if(tmp)
        std::cout<<"Неправильный ввод!\n";

	std::cout<<"Было потрачено:"<<duration.count()<<"s "<<global_memory+sizeof (prime)<<"byte\n";
        std::cout<<"Ввведите имя файла для записи данных о работе:\n";
        std::cin>>path;

        if(!insert)//в файле есть данные стираем
        	data_of_process.open(path + ".txt", std::ios::app);

	if(insert)//если уже было записаны данный добавляем
		data_of_process.open(path + ".txt");
        data_of_process<<duration.count()<<" "<<global_memory+sizeof (prime)<<"\n";
        data_of_process.close();
        std::cout<<"Данные записаны успешно!\n";
        delete prime;


	insert = true;
        std::cout<<"Если хотите выйти, нажмите любую клавишу и Enter.\n"
               "Расчитать еще раз, нажмите - Y.\n";
        std::cin>>key;//считаем пока не будет нажата клавиша Y

}
  return 0;
}
