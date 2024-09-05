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
    int x = -1;
    std::cout << "Меню" << std::endl;
    std::cout << "1) Добавить трубу" << std::endl;
    std::cout << "2) Добавить КС" << std::endl;
    std::cout << "3) Просмотр всех объектов" << std::endl;
    std::cout << "4) Редактировать трубу" << std::endl;
    std::cout << "5) Редактировать КС" << std::endl;
    std::cout << "6) Сохранить" << std::endl;
    std::cout << "7) Загрузить" << std::endl;
    std::cout << "0) Выход" << std::endl;
    std::cout << "Введите число: ";
    do {
        std::cin >> x;
    } while (x == 0, std::cout << x);
    /*Pipe_settings Pipe;
    std::cout << "Введите название трубы (на английском язык): ";
    getline(std::cin, Pipe.Name);
    std::cout << Pipe.Name;*/
    return 0;
}