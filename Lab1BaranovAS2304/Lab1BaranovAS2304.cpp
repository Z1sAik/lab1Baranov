#include <iostream>
#include <string>
//Перменные
int k = 0;
//структуры
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
//Функции
void menu() {
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
    (std::cin >> k).get();
    while (std::cin.fail() == 1)
    {
        std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n');
        menu();
    }
}
void menu_new_pipe() {
    Pipe_settings Pipe;
    std::cout << "Введите название трубы (на английском язык): ";
    getline(std::cin, Pipe.Name);
    std::cout << "Введите длину трубы в километрах: ";
    (std::cin >> Pipe.length).get();
    while (std::cin.fail() == 1)
    {
        std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Введите длину трубы в километрах: ";
        (std::cin >> Pipe.length).get();
    }
    std::cout << "Введите диаметр трубы в миллиметрах: ";
    (std::cin >> Pipe.diameter).get();
    while (std::cin.fail() == 1)
    {
        std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Введите диаметр трубы в миллиметрах: ";
        (std::cin >> Pipe.diameter).get();
    }
    std::cout << "Выберите в каком состоянии труба: " << std::endl;
    std::cout << "1)В ремонте" << std::endl;
    std::cout << "2)Не в ремонте" << std::endl;
    int n = 0;
    (std::cin >> n).get();
    while (std::cin.fail() == 1)
    {
        std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Выберите в каком состоянии труба: " << std::endl;
        std::cout << "1)В ремонте" << std::endl;
        std::cout << "2)Не в ремонте" << std::endl;
        (std::cin >> n).get();
    }
    while (n != 1 && n != 2) {
        std::cout << "Выберите число 1 или 2: ";
        (std::cin >> n).get();
    };
    if (n == 1) {
        Pipe.repair = true;
    }
    else if (n == 2)
    {
        Pipe.repair = false;
    }
    if (Pipe.repair == true) {
        std::cout << "Труба создана: " << std::endl << "Название трубы: " << Pipe.Name << "; Длина трубы: " << Pipe.length << "; Диаметр трубы: " << Pipe.diameter << "; Статус 'в ремонте': Да" << std::endl;
    }
    else {
        std::cout << "Труба создана: " << std::endl << "Название трубы: " << Pipe.Name << "; Длина трубы: " << Pipe.length << "; Диаметр трубы: " << Pipe.diameter << "; Статус 'в ремонте': Нет" << std::endl;
    };
   
}
int main(){
    setlocale(LC_ALL, "RU");
    while (true) {
        menu();
        if (k > 10 || k < 0) {
            std::cout << "ВВЕДИТЕ КОРРЕКТНУЮ КОМАНДУ!"<<std::endl;
        }
        if (k == 0) {
            break;
        }
        if (k == 1) {
            menu_new_pipe();
        }
    }
    return 0;
}