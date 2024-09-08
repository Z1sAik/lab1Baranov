#include <iostream>
#include <string>
//Переменные
int k = 0;
int n = 0;
int z = 0;
//Переменные(трубы)
std::string pipe_name;
int pipe_length;
int pipe_diameter;
bool pipe_repair;
//Переменные(КС)
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
    std::cout << "///////  Меню  ///////" << std::endl << "1) Добавить трубу" << std::endl << "2) Добавить КС" << std::endl << "3) Просмотр всех объектов" << std::endl << "4) Редактировать трубу" << std::endl << "5) Редактировать КС" << std::endl << "6) Сохранить" << std::endl << "7) Загрузить" << std::endl << "0) Выход" << std::endl << "Введите комманду которую вы бы хотели выполнить(от 0 до 9): ";
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
        std::cout << "Вы еще не добавили трубу и не можете редактировать ее параметры. Пожалуйста настройтe трубу в меню(пункт 1)" << std::endl;
    }
    else if (z == 0) {
        std::cout << "Вы еще не добавили КС и не можете редактировать ее параметры. Пожалуйста настройтe КС в меню(пункт 2)" << std::endl;
    }
    else if (pipe_repair == true) {
        std::cout << "///////////" << std::endl << "Труба: " << std::endl << "Название трубы: " << pipe_name << "; Длина трубы: " << pipe_length << "; Диаметр трубы: " << pipe_diameter << "; Статус 'в ремонте': Да" << std::endl << "Компрессорная станция: " << std::endl << "Название КС: " << cs_name << "; Кол-во цехов: " << cs_workshops << "; Кол-во цехов в работе: " << cs_workshopsinwork << "; Коэффициент эффективности КС: " << cs_effectiveness << std::endl << "///////////" << std::endl;
    }
    else {
        std::cout << "///////////" << std::endl << "Труба: " << std::endl << "Название трубы: " << pipe_name << "; Длина трубы: " << pipe_length << "; Диаметр трубы: " << pipe_diameter << "; Статус 'в ремонте': Нет" << std::endl << "Компрессорная станция: " << std::endl << "Название КС: " << cs_name << "; Кол-во цехов: " << cs_workshops << "; Кол-во цехов в работе: " << cs_workshopsinwork << "; Коэффициент эффективности КС: " << cs_effectiveness << std::endl << "///////////" << std::endl;
    };
}
void edit_pipe() {
    int m = 0;
    if (n != 0) {
        while (true) {
            std::cout << "Выберите параметр который вы хотите отредактировать: " << std::endl << "1) Название трубы" << std::endl << "2) Длина трубы" << std::endl << "3) Диаметр трубы" << std::endl << "4) Статус 'в ремонте'" << std::endl << "0) Выход в меню" << std::endl << "Номер команды: ";
            (std::cin >> m).get();
            while (std::cin.fail() == 1)
            {
                std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "Выберите параметр который вы хотите отредактировать: ";
                (std::cin >> m).get();
            }
            while (m > 4 || m < 0) {
                std::cout << "Ошибка. Выбрана неккоректная команда!" << std::endl << "Выберите параметр который вы хотите отредактировать: ";
                (std::cin >> m).get();
                while (std::cin.fail() == 1)
                {
                    std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "Выберите параметр который вы хотите отредактировать: ";
                    (std::cin >> m).get();
                }
            }
            if (m == 0) {
                break;
            }
            else if (m == 1) {
                std::cout << "Старое название: " << pipe_name<<std::endl;
                std::cout << "Введите новое название трубы: ";
                getline(std::cin,pipe_name);
            }
            else if (m == 2) {
                std::cout << "Старая длина трубы: " << pipe_length << std::endl;
                std::cout << "Введите новую длину трубы в киллометрах: ";
                (std::cin >> pipe_length).get();
                while (std::cin.fail() == 1)
                {
                    std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "Введите новую длину трубы в киллометрах(корректно): ";
                    (std::cin >> pipe_length).get();
                }

            }
            else if (m == 3) {
                std::cout << "Старый диаметр трубы: " << pipe_diameter << std::endl;
                std::cout << "Введите новый диаметр трубы в миллиметрах: ";
                (std::cin >> pipe_diameter).get();
                while (std::cin.fail() == 1)
                {
                    std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "Введите новый диаметр трубы в миллиметрах (корректно): ";
                    (std::cin >> pipe_diameter).get();
                }

            }
            else if (m == 4) {
                int j = -1;
                if (pipe_repair == true) {
                    j = 1;
                    std::cout << "Старый статус трубы: в ремонте " << std::endl;
                }
                else {
                    j = 0;
                    std::cout << "Старый статус трубы: не в ремонте " << std::endl;
                }
                std::cout << "Выберите новый статус трубы: "<<std::endl<<"1)В ремонте"<<std::endl<<"2)Не в ремонте"<<std::endl<<"Введите номер команды: ";
                (std::cin >> j).get();
                while (std::cin.fail() == 1)
                {
                    std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "Выберите новый статус трубы (корректно): ";
                    (std::cin >> j).get();
                }
                while (j != 1 && j != 2) {
                    std::cout << "Выберите новый статус трубы (корректно): " << std::endl << "1)В ремонте" << std::endl << "2)Не в ремонте" << std::endl << "Введите номер команды: ";
                    (std::cin >> j).get();
                    while (std::cin.fail() == 1)
                    {
                        std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                        std::cout << "Выберите новый статус трубы (корректно): " << std::endl << "1)В ремонте" << std::endl << "2)Не в ремонте" << std::endl << "Введите номер команды: ";
                        (std::cin >> j).get();
                    }
                }
                if (j == 0) {
                    pipe_repair = true;
            }
                else {
                    pipe_repair = false;
                }
            }
        }
    }

    else {
        std::cout << "Вы еще не добавили трубу и не можете посмотреть ее параметры. Пожалуйста настройтe трубу в меню(пункт 1)" << std::endl;
    }
}
void edit_CS() {
    int m = 0;
    if (z != 0) {
        while (true) {
            std::cout << "Выберите параметр который вы хотите отредактировать: " << std::endl << "1) Название КС" << std::endl << "2) Кол-во цехов" << std::endl << "3) Кол-во цехов в работе" << std::endl << "4) Коэффициент эффективности (от 0 до 100)" << std::endl << "0) Выход в меню" << std::endl << "Номер команды: ";
            (std::cin >> m).get();
            while (std::cin.fail() == 1)
            {
                std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "Выберите параметр который вы хотите отредактировать: ";
                (std::cin >> m).get();
            }
            while (m > 4 || m < 0) {
                std::cout << "Ошибка. Выбрана неккоректная команда!" << std::endl << "Выберите параметр который вы хотите отредактировать: ";
                (std::cin >> m).get();
                while (std::cin.fail() == 1)
                {
                    std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "Выберите параметр который вы хотите отредактировать: ";
                    (std::cin >> m).get();
                }
            }
            if (m == 0) {
                break;
            }
            else if (m == 1) {
                std::cout << "Старое название: " << cs_name << std::endl;
                std::cout << "Введите новое название трубы: ";
                getline(std::cin, cs_name);
            }
            else if (m == 2) {
                std::cout << "Старое кол-во цехов: " << cs_workshops << std::endl;
                std::cout << "Введите новое кол-во цехов: ";
                (std::cin >> cs_workshops).get();
                while (std::cin.fail() == 1)
                {
                    std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "Введите новое кол-во цехов (корректно): ";
                    (std::cin >> cs_workshops).get();
                }

            }
            else if (m == 3) {
                std::cout<< "Общее кол-во цехов: "<<cs_workshops << "; Старое кол-во цехов в работе: " << cs_workshopsinwork << std::endl;
                std::cout << "Введите новое кол-во цехов в работе: ";
                (std::cin >> cs_workshopsinwork).get();
                while (std::cin.fail() == 1)
                {
                    std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "Введите новое кол-во цехов в работе (корректно): ";
                    (std::cin >> cs_workshopsinwork).get();
                }
                while (cs_workshopsinwork > cs_workshops) {
                    std::cout << "Ошибка. Введено кол-во цехов в работе больше чем общее кол-во цехов." << std::endl << "Общее кол-во цехов: " << cs_workshops << std::endl;
                    std::cout << "Введите новое кол-во цехов в работе: ";
                    (std::cin >> cs_workshopsinwork).get();
                    while (std::cin.fail() == 1)
                    {
                        std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                        std::cout << "Введите новое кол-во цехов в работе (корректно): ";
                        (std::cin >> cs_workshopsinwork).get();
                    }
                }

            }
            else if (m == 4) {
                std::cout << "Старый коэффициент эффективности: " << cs_effectiveness << std::endl;
                std::cout << "Введите новый коэффициент эффективности (от 0 до 100): ";
                (std::cin >> cs_effectiveness).get();
                while (std::cin.fail() == 1)
                {
                    std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "Введите новый коэффициент эффективности (от 0 до 100) (корректно): ";
                    (std::cin >> cs_effectiveness).get();
                }
                while (cs_effectiveness < 0 || cs_effectiveness > 100) {
                    std::cout << "Ошибка. Введён неккоректный коэффициент эффективности!" << std::endl;
                    std::cout << "Введите новый коэффициент эффективности (от 0 до 100): ";
                    (std::cin >> cs_effectiveness).get();
                    while (std::cin.fail() == 1)
                    {
                        std::cout << "Ошибка. Введено нецелое число или символ!" << std::endl;
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                        std::cout << "Введите новый коэффициент эффективности (от 0 до 100) (корректно): ";
                        (std::cin >> cs_effectiveness).get();
                    }
                }
            }
        }
    }

    else {
        std::cout << "Вы еще не добавили КС и не можете посмотреть ее параметры. Пожалуйста настройтe КС в меню(пункт 2)" << std::endl;
    }
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
        else if (k == 4) {
            edit_pipe();
        }
        else if (k == 5) {
            edit_CS();
        }
    }
    return 0;
}