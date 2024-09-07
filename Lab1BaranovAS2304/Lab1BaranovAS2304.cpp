#include <iostream>
#include <string>
//Перменные
int k = 0;
int n = 0;
int z = 0;
std::string pipe_name;
int pipe_length;
int pipe_diameter;
bool pipe_repair;
std::string cs_name;
int cs_workshops;
int cs_workshopsinwork;
int cs_effectiveness;
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
    std::cout << "Меню" << std::endl << "1) Добавить трубу" << std::endl << "2) Добавить КС" << std::endl << "3) Просмотр всех объектов" << std::endl << "4) Редактировать трубу" << std::endl << "5) Редактировать КС" << std::endl << "6) Сохранить" << std::endl << "7) Загрузить" << std::endl << "0) Выход" << std::endl << "Введите комманду которую вы бы хотели выполнить(от 0 до 9): ";
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
    std::cout << "Выберите в каком состоянии труба: " << std::endl << "1)В ремонте" << std::endl << "2)Не в ремонте" << std::endl;
    (std::cin >> n).get();
    while (std::cin.fail() == 1)
    {
        std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Выберите в каком состоянии труба: " << std::endl << "1)В ремонте" << std::endl << "2)Не в ремонте" << std::endl;
        (std::cin >> n).get();
    }
    while (n != 1 && n != 2) {
        std::cout << "Ошибка. Выбрана невреная команда!" << std::endl << "Выберите в каком состоянии труба: " << std::endl << "1)В ремонте" << std::endl << "2)Не в ремонте" << std::endl;
        (std::cin >> n).get();
        while (std::cin.fail() == 1)
        {
            std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Выберите в каком состоянии труба: " << std::endl << "1)В ремонте" << std::endl << "2)Не в ремонте" << std::endl;
            (std::cin >> n).get();
        }
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
    pipe_name = Pipe.Name;
    pipe_length = Pipe.length;
    pipe_diameter = Pipe.diameter;
    pipe_repair = Pipe.repair;
}
void menu_new_ks() {
    compressor_station CS;
    std::cout << "Введите название компрессорной станции (на английском язык): ";
    getline(std::cin, CS.Name);
    std::cout << "Введите кол-во цехов: ";
    (std::cin >> CS.workshops).get();
    while (std::cin.fail() == 1)
    {
        std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Введите кол-во цехов: ";
        (std::cin >> CS.workshops).get();
    }
    z = 1;
    std::cout << "Введите кол-во цехов в работе: ";
    (std::cin >> CS.workshopsinwork).get();
    while (std::cin.fail() == 1)
    {
        std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Введите кол-во цехов в работе: ";
        (std::cin >> CS.workshopsinwork).get();
    }
    while (CS.workshopsinwork > CS.workshops) {
        std::cout << "Ошибка. Введено кол-во цехов в работе больше чем самих цехов!" << std::endl << "Введите кол-во цехов в работе: ";
        (std::cin >> CS.workshopsinwork).get();
        while (std::cin.fail() == 1)
        {
            std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Введите кол-во цехов в работе: ";
            (std::cin >> CS.workshopsinwork).get();
        }
    }
    std::cout << "Введите коэффициент эффективности КС(от 0 до 100): ";
    (std::cin >> CS.effectiveness).get();
    while (std::cin.fail() == 1)
    {
        std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Введите коэффициент эффективности КС(от 0 до 100): ";
        (std::cin >> CS.effectiveness).get();
    }
    while (CS.effectiveness < 0 || CS.effectiveness > 100) {
        std::cout << "Введите коэффициент от 0 до 100!: ";
        (std::cin >> CS.effectiveness).get();
        while (std::cin.fail() == 1)
        {
            std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Введите коэффициент эффективности КС(от 0 до 100): ";
            (std::cin >> CS.effectiveness).get();
        }
    }
    std::cout << "Компрессорная станция создана: " << std::endl << "Название КС: " << CS.Name << "; Кол-во цехов: " << CS.workshops << "; Кол-во цехов в работе: " << CS.workshopsinwork << "; Коэффициент эффективности КС: " << CS.effectiveness << std::endl;
    cs_name = CS.Name;
    cs_workshops = CS.workshops;
    cs_workshopsinwork = CS.workshopsinwork;
    cs_effectiveness = CS.effectiveness;
}
void view_all() {
    if (n == 0 && z == 0) {
        std::cout << "Вы еще не добавили ни одного объекта." << std::endl;
    }
    else if (n == 0) {
        std::cout << "Вы еще не добавили трубу и не можете посмотреть ее параметры. Пожалуйста настройтe трубу в меню(пункт 1)" << std::endl;
    }
    else if (z == 0) {
        std::cout << "Вы еще не добавили КС и не можете посмотреть ее параметры. Пожалуйста настройтe КС в меню(пункт 2)" << std::endl;
    }
    else if (pipe_repair == true) {
        std::cout << "///////////" << std::endl << "Труба: " << std::endl << "Название трубы: " << pipe_name << "; Длина трубы: " << pipe_length << "; Диаметр трубы: " << pipe_diameter << "; Статус 'в ремонте': Да" << std::endl << "Компрессорная станция: " << std::endl << "Название КС: " << cs_name << "; Кол-во цехов: " << cs_workshops << "; Кол-во цехов в работе: " << cs_workshopsinwork << "; Коэффициент эффективности КС: " << cs_effectiveness << std::endl << "///////////" << std::endl;
    }
    else {
        std::cout << "///////////" << std::endl << "Труба: " << std::endl << "Название трубы: " << pipe_name << "; Длина трубы: " << pipe_length << "; Диаметр трубы: " << pipe_diameter << "; Статус 'в ремонте': Нет" << std::endl << "Компрессорная станция: " << std::endl << "Название КС: " << cs_name << "; Кол-во цехов: " << cs_workshops << "; Кол-во цехов в работе: " << cs_workshopsinwork << "; Коэффициент эффективности КС: " << cs_effectiveness << std::endl << "///////////" << std::endl;
    };
}
void edit_pipe() {
    return;
}
void edit_CS() {
    return;
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
        else if (k == 1) {
            menu_new_pipe();
        }
        else if (k == 2) {
            menu_new_ks();
        }
        else if (k == 3) {
            view_all();
        }
    }
    return 0;
}