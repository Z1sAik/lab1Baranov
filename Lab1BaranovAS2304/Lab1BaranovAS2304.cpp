#include <iostream>
#include <string>
#include <fstream>
//структуры
struct Pipe_settings
{
    std::string Name; //название трубы
    float length; //километры 
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
int check(int z, int l) {
    (std::cin >> z).get();
    while (true) {
        if (std::cin.fail()) {
            std::cout << "Ошибка. Введено не целое число или символ! Попробуйте ещё раз: ";
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
        else if (z < l) {
            std::cout << "Ошибка. Введено отрицательное число или ноль! Попробуйте ещё раз: ";
        }
        else {
            break;
        }
        (std::cin >> z).get();
    }
    return z;
}

int menu() {
    int k = -1;
    while (true) {
        std::cout << "///////  Меню  ///////" << std::endl
            << "1) Добавить трубу" << std::endl
            << "2) Добавить КС" << std::endl
            << "3) Просмотр всех объектов" << std::endl
            << "4) Редактировать трубу" << std::endl
            << "5) Редактировать КС" << std::endl
            << "6) Сохранить настройки трубы" << std::endl
            << "7) Загрузить настройки трубы" << std::endl
            << "8) Сохранить настройки КС" << std::endl
            << "9) Загрузить настройки КС" << std::endl
            << "0) Выход" << std::endl
            << "Введите команду которую вы бы хотели выполнить(от 0 до 7): ";
        k = check(k, 0);
        if (k < 9 || k > 0) {
            return k;
        }
        if (k == 0) {
            break;
        }
    }
}

Pipe_settings menu_new_pipe() {
    Pipe_settings Pipe;
    std::cout << "Введите название трубы (на английском язык): ";
    getline(std::cin, Pipe.Name);
    std::cout << "Введите длину трубы в километрах: ";
    std::cin >> Pipe.length;
    while (true) {
        if (std::cin.fail()) {
            std::cout << "Ошибка. Введено не число! Попробуйте ещё раз: ";
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
        else if (Pipe.length < 0.001) {
            std::cout << "Ошибка. Введено отрицательное число или ноль! Попробуйте ещё раз: ";
        }
        else {
            break;
        }

        std::cin >> Pipe.length;
    }
    std::cout << "Введите диаметр трубы в миллиметрах: ";
    Pipe.diameter = check(Pipe.diameter, 1);
    std::cout << "Выберите в каком состоянии труба: " << std::endl << "0)Не в ремонте" << std::endl << "1)В ремонте" << std::endl;
    int k=-1;
    k = check(k, 0);
    while (k != 1 && k != 0) {
        std::cout << "Ошибка. Выбрана невреная команда!" << std::endl << "Выберите в каком состоянии труба: " << std::endl << "0)Не в ремонте" << std::endl << "1)В ремонте" << std::endl;
        k = check(k, 0);
    }
    Pipe.repair = k;
    std::cout << "Труба создана: " << std::endl << "Название трубы: " << Pipe.Name << "; Длина трубы: " << Pipe.length << "; Диаметр трубы: " << Pipe.diameter << "; Статус 'в ремонте': " << std::boolalpha << Pipe.repair << std::endl;
    return Pipe;
}
compressor_station menu_new_ks() {
    compressor_station CS;
    std::cout << "Введите название компрессорной станции (на английском язык): ";
    getline(std::cin, CS.Name);
    std::cout << "Введите кол-во цехов: ";
    CS.workshops = check(CS.workshops,1);
    std::cout << "Введите кол-во цехов в работе: ";
    CS.workshopsinwork = check(CS.workshopsinwork,0);
    while (CS.workshopsinwork > CS.workshops || CS.workshopsinwork < 0) {
        std::cout << "Ошибка. Введено неккоректное кол-во цехов в работе!" << std::endl << "Введите кол-во цехов в работе: ";
        CS.workshopsinwork = check(CS.workshopsinwork,0);
    }
    std::cout << "Введите коэффициент эффективности КС(от 0 до 100): ";
    CS.effectiveness = check(CS.effectiveness, 0);
    while (CS.effectiveness < 0 || CS.effectiveness > 100) {
        std::cout << "Введите коэффициент от 0 до 100!: ";
        CS.effectiveness = check(CS.effectiveness, 0);
    }
    std::cout << "Компрессорная станция создана: " << std::endl << "Название КС: " << CS.Name << "; Кол-во цехов: " << CS.workshops << "; Кол-во цехов в работе: " << CS.workshopsinwork << "; Коэффициент эффективности КС: " << CS.effectiveness << std::endl;
    return CS;
}
void view_all(Pipe_settings Pipe,compressor_station CS) {
    if (Pipe.diameter < 1 && CS.workshops < 1) {
        std::cout << "Вы еще не добавили ни одного объекта." << std::endl;
    }
    else if (Pipe.diameter < 1 && CS.workshops > 0) {
        std::cout << "///////////" << std::endl << "Труба: ещё не настроена, вы можете настроить ее в меню (пункт 1)!" << std::endl << "Компрессорная станция: " << std::endl << "Название КС: " << CS.Name << "; Кол-во цехов: " << CS.workshops << "; Кол-во цехов в работе: " << CS.workshopsinwork << "; Коэффициент эффективности КС: " << CS.effectiveness << std::endl << "///////////" << std::endl;
    }
    else if (CS.workshops < 1 && Pipe.diameter > 0) {
        std::cout << "///////////" << std::endl << "Труба: " << std::endl << "Название трубы: " << Pipe.Name << "; Длина трубы: " << Pipe.length << "; Диаметр трубы: " << Pipe.diameter << "; Статус 'в ремонте': " << std::boolalpha << Pipe.repair << std::endl << "Компрессорная станция: ещё не настроена, вы можете настроить ее в меню (пункт 2)!" << std::endl;
    }
    else {
        std::cout << "///////////" << std::endl << "Труба: " << std::endl << "Название трубы: " << Pipe.Name << "; Длина трубы: " << Pipe.length << "; Диаметр трубы: " << Pipe.diameter << "; Статус 'в ремонте': " << std::boolalpha << Pipe.repair << std::endl << "Компрессорная станция: " << std::endl << "Название КС: " << CS.Name << "; Кол-во цехов: " << CS.workshops << "; Кол-во цехов в работе: " << CS.workshopsinwork << "; Коэффициент эффективности КС: " << CS.effectiveness << std::endl << "///////////" << std::endl;
    }
}
Pipe_settings edit_pipe(Pipe_settings Pipe) {
    int m = 0;
    if (Pipe.diameter >0) {
        while (true) {
            std::cout << "Выберите параметр который вы хотите отредактировать: " << std::endl << "1) Название трубы" << std::endl << "2) Статус 'в ремонте'" << std::endl << "0) Выход в меню" << std::endl << "Номер команды: ";
            m = check(m, 0);
            while (m > 2 || m < 0) {
                std::cout << "Ошибка. Выбрана неккоректная команда!" << std::endl << "Выберите параметр который вы хотите отредактировать: ";
                m = check(m, 0);
            }
            if (m == 0) {
                break;
            }
            else if (m == 1) {
                std::cout << "Старое название: " << Pipe.Name <<std::endl;
                std::cout << "Введите новое название трубы: ";
                getline(std::cin,Pipe.Name);
            }
            else if (m == 2) {

                std::cout << "Старый статус трубы: в ремонте " << std::boolalpha << Pipe.repair << std::endl;

                std::cout << "Выберите новый статус трубы: "<<std::endl<<"0)Не в ремонте"<<std::endl<<"1)В ремонте"<<std::endl<<"Введите номер команды: ";
                (std::cin >> Pipe.repair).get();
                std::cout << "Выберите в каком состоянии труба: " << std::endl << "0)Не в ремонте" << std::endl << "1)В ремонте" << std::endl;
                int k = -1;
                k = check(k, 0);
                while (k != 1 && k != 0) {
                    std::cout << "Ошибка. Выбрана невреная команда!" << std::endl << "Выберите в каком состоянии труба: " << std::endl << "0)Не в ремонте" << std::endl << "1)В ремонте" << std::endl;
                    k = check(k, 0);
                }
                Pipe.repair = k;
            }
        }
    }

    else {
        std::cout << "Вы еще не добавили трубу и не можете посмотреть ее параметры. Пожалуйста настройтe трубу в меню(пункт 1)" << std::endl;
    }
    return Pipe;
}
compressor_station edit_CS(compressor_station CS) {
    int m = 0;
    if (CS.workshops > 0) {
        while (true) {
            std::cout << "Выберите параметр который вы хотите отредактировать: " << std::endl << "1) Название КС" << std::endl << "2) Кол-во цехов в работе" << std::endl << "3) Коэффициент эффективности (от 0 до 100)" << std::endl << "0) Выход в меню" << std::endl << "Номер команды: ";
            m = check(m, 0);
            while (m > 3 || m < 0) {
                m = check(m, 0);
            }
            if (m == 0) {
                break;
            }
            else if (m == 1) {
                std::cout << "Старое название: " << CS.Name << std::endl;
                std::cout << "Введите новое название трубы: ";
                getline(std::cin, CS.Name);
            }
            else if (m == 2) {
                std::cout<< "Общее кол-во цехов: "<<CS.workshops << "; Старое кол-во цехов в работе: " << CS.workshopsinwork << std::endl;
                std::cout << "Введите новое кол-во цехов в работе: ";
                CS.workshopsinwork = check(CS.workshopsinwork, 1);
                while (CS.workshopsinwork > CS.workshops || CS.workshopsinwork < 0) {
                    std::cout << "Ошибка. Введено неккоректное кол-во цехов в работе!" << std::endl << "Введите кол-во цехов в работе: ";
                    CS.workshopsinwork = check(CS.workshopsinwork, 1);
                }

            }
            else if (m == 3) {
                std::cout << "Старый коэффициент эффективности: " << CS.effectiveness << std::endl;
                std::cout << "Введите новый коэффициент эффективности (от 0 до 100): ";
                CS.effectiveness = check(CS.effectiveness, 0);
                while (CS.effectiveness < 0 || CS.effectiveness > 100) {
                    std::cout << "Введите коэффициент от 0 до 100!: ";
                    CS.effectiveness = check(CS.effectiveness, 0);
                }
            }
        }
    }

    else {
        std::cout << "Вы еще не добавили КС и не можете посмотреть ее параметры. Пожалуйста настройтe КС в меню(пункт 2)" << std::endl;
    }
    return CS;
}

void savePipe(Pipe_settings Pipe) {
    std::ofstream out;
    out.open("datapipe.txt");
    if (out.is_open())
    {
        out << Pipe.Name << std::endl;
        out << Pipe.length << " " << Pipe.diameter << " " << Pipe.repair;
    }
    out.close();
    std::cout << "Данные о трубе сохранены в файл!" << std::endl;
}
void saveCS(compressor_station CS) {
    std::ofstream out;
    out.open("dataCS.txt");
    if (out.is_open())
    {
        out << CS.Name << std::endl;
        out << CS.workshops << " " << CS.workshopsinwork << " " << CS.effectiveness;
    }
    out.close();
    std::cout << "Данные о КС сохранены в файл!" << std::endl;
}

Pipe_settings loadPipe(Pipe_settings Pipe) {
    std::ifstream in("datapipe.txt");
    if (in.is_open())
    {
        std::getline(in, Pipe.Name);
        in >> Pipe.length >> Pipe.diameter >> Pipe.repair;
    }
    in.close();
    std::cout << "Данные о трубе загружены из файла!" << std::endl;
    return Pipe;
}
compressor_station loadCS(compressor_station CS) {
    std::ifstream in("datapipe.txt");
    if (in.is_open())
    {
        std::getline(in, CS.Name);
        in >> CS.workshops >> CS.workshopsinwork >> CS.effectiveness;
    }
    in.close();
    std::cout << "Данные о КС загружены из файла!" << std::endl;
    return CS;
}
int main(){
    setlocale(LC_ALL, "RU");
    Pipe_settings Pipe;
    compressor_station CS;
    while (true) {
        int k = menu();
        if (k > 9 || k < 0) {
            std::cout << "ВВЕДИТЕ КОРРЕКТНУЮ КОМАНДУ!"<<std::endl;
        }
        if (k == 0) {
            break;
        }
        else if (k == 1) {
            Pipe = menu_new_pipe();
        }
        else if (k == 2) {
            CS = menu_new_ks();
        }
        else if (k == 3) {
            view_all(Pipe,CS);
        }
        else if (k == 4) {
            Pipe = edit_pipe(Pipe);
        }
        else if (k == 5) {
            CS = edit_CS(CS);
        }
        else if (k == 6) {
            savePipe(Pipe);
        }
        else if (k == 7) {
            Pipe = loadPipe(Pipe);
        }
        else if (k == 8) {
            saveCS(CS);
        }
        else if (k == 9) {
            CS = loadCS(CS);
        }
    }
    return 0;
}