#include <iostream>
#include <string>

struct Pipe_settings
{
    std::string Name; //название трубы
    int length; //километры 
    int diameter; //миллиметры
    bool repair; //признак "в ремонте" 
};

struct compressor_station 
{
    std::string Name; //название КС
    int workshops; //Кол-во цехов
    int workshopsinwork; //Кол-во цехов в работе
    int effectiveness; //Коэфф. эффективности
};

int main(){
    setlocale(LC_ALL, "RU");
    int x = 0;
    do {
        std::cout << "Меню"<<std::endl;
    } while (x != 1);
    /*Pipe_settings Pipe;
    std::cout << "Введите название трубы (на английском язык): ";
    getline(std::cin, Pipe.Name);
    std::cout << Pipe.Name;*/
    return 0;
}