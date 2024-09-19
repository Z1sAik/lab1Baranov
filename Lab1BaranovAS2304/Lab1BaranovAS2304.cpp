#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//структуры
struct Pipe
{
    string Name; //название трубы
    float length; //километры 
    int diameter; //миллиметры
    bool repair; //признак "в ремонте" 
};

struct compressor_station 
{
    string Name; //название КС
    int workshops; //Кол-во цехов
    int workshopsinwork; //Кол-во цехов в работе
    int effectiveness; //Коэфф. эффективности
};
//Функции
int check(int max, int low) {
    int z;
    cin >> z;
    cin.ignore();
    while (true) {
        if (cin.fail()) {
            cout << "Ошибка. Введено не целое число или символ! Попробуйте ещё раз: ";
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (z < low) {
            cout << "Ошибка. Введено отрицательное число или ноль! Попробуйте ещё раз: ";
        }
        else if (max != 0 && z > max) {
            cout << "Ошибка. Введено число больше максимального! Попробуйте ещё раз: ";
        }
        else {
            break;
        }
        cin >> z;
        cin.ignore();
    }
    return z;
}

float floatcheck(int max, int low) {
    float z;
    cin >> z;
    cin.ignore();
    while (true) {
        if (cin.fail()) {
            cout << "Ошибка. Введено не целое число или символ! Попробуйте ещё раз: ";
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (z < low) {
            cout << "Ошибка. Введено отрицательное число или ноль! Попробуйте ещё раз: ";
        }
        else if (max != 0 && z > max) {
            cout << "Ошибка. Введено число больше максимального! Попробуйте ещё раз: ";
        }
        else {
            break;
        }
        cin >> z;
        cin.ignore();
    }
    return z;
}

int menu() {
    int k = -1;
    while (true) {
        cout << "///////  Меню  ///////" << endl
            << "1) Добавить трубу" << endl
            << "2) Добавить КС" << endl
            << "3) Просмотр всех объектов" << endl
            << "4) Редактировать трубу" << endl
            << "5) Редактировать КС" << endl
            << "6) Сохранить настройки трубы" << endl
            << "7) Загрузить настройки трубы" << endl
            << "8) Сохранить настройки КС" << endl
            << "9) Загрузить настройки КС" << endl
            << "0) Выход" << endl
            << "Введите команду которую вы бы хотели выполнить(от 0 до 9): ";
        k = check(9, 0);
        return k;
    }
}

void menu_new_pipe(Pipe &Pipe) {
    cout << "Введите название трубы (на английском язык): ";
    getline(cin, Pipe.Name);
    cout << "Введите длину трубы в километрах: ";
    Pipe.length = floatcheck(0, 0);
    cout << "Введите диаметр трубы в миллиметрах: ";
    Pipe.diameter = check(0, 1);
    cout << "Выберите в каком состоянии труба: " << endl << "0)Не в ремонте" << endl << "1)В ремонте" << endl;
    int k=-1;
    k = check(1, 0);
    Pipe.repair = k;
    cout << "Труба создана: " << endl << "Название трубы: " << Pipe.Name << "; Длина трубы: " << Pipe.length << "; Диаметр трубы: " << Pipe.diameter << "; Статус 'в ремонте': " << boolalpha << Pipe.repair << endl;
}
void menu_new_ks(compressor_station &CS) {
    cout << "Введите название компрессорной станции (на английском язык): ";
    getline(cin, CS.Name);
    cout << "Введите кол-во цехов: ";
    CS.workshops = check(0,1);
    cout << "Введите кол-во цехов в работе: ";
    CS.workshopsinwork = check(CS.workshops,0);
    cout << "Введите коэффициент эффективности КС(от 0 до 100): ";
    CS.effectiveness = check(100, 0);
    cout << "Компрессорная станция создана: " << endl << "Название КС: " << CS.Name << "; Кол-во цехов: " << CS.workshops << "; Кол-во цехов в работе: " << CS.workshopsinwork << "; Коэффициент эффективности КС: " << CS.effectiveness << endl;
}
void view_all(Pipe &Pipe,compressor_station &CS) {
    int m = 0;
    while (true) {
        cout << "Выберите что вы хотите просмотреть: " << endl << "1) Просмотреть трубу" << endl << "2) Просмотреть КС" << endl << "3) Просмотреть все объекты"<<endl<<"0) Выход в меню" << endl << "Введите комманду: ";
        m = check(3, 0);
        if (m == 0) {
            break;
        }
        else if (m == 1) {
            if (Pipe.diameter < 1) {
                cout << "Вы еще не добавили трубу." << endl;
            }
            else {
                cout << "Труба: " << endl << "Название трубы: " << Pipe.Name << "; Длина трубы: " << Pipe.length << "; Диаметр трубы: " << Pipe.diameter << "; Статус 'в ремонте': " << boolalpha << Pipe.repair << endl;
            }
        }
        else if (m == 2) {
            if (CS.workshops < 1) {
                cout << "Вы еще не добавили КС." << endl;
            }
            else {
                cout << "Компрессорная станция: " << endl << "Название КС: " << CS.Name << "; Кол-во цехов: " << CS.workshops << "; Кол-во цехов в работе: " << CS.workshopsinwork << "; Коэффициент эффективности КС: " << CS.effectiveness << endl;
            }
        }
        else if (m == 3) {
            if (Pipe.diameter < 1 && CS.workshops < 1) {
                cout << "Вы еще не добавили ни одного объекта." << endl;
            }
            else if (Pipe.diameter > 0 && CS.workshops < 1) {
                cout << "Вы еще не добавили КС." << endl;
            }
            else if (Pipe.diameter < 1 && CS.workshops > 0) {
                cout << "Вы еще не добавили трубу." << endl;
            }
            else {
                cout << "Труба: " << endl << "Название трубы: " << Pipe.Name << "; Длина трубы: " << Pipe.length << "; Диаметр трубы: " << Pipe.diameter << "; Статус 'в ремонте': " << boolalpha << Pipe.repair << endl << "Компрессорная станция: " << endl << "Название КС: " << CS.Name << "; Кол-во цехов: " << CS.workshops << "; Кол-во цехов в работе: " << CS.workshopsinwork << "; Коэффициент эффективности КС: " << CS.effectiveness << endl;
            }
        }
    }
}
void edit_pipe(Pipe &Pipe) {
    int m = 0;
    if (Pipe.diameter >0) {
        while (true) {
            cout << "Выберите параметр который вы хотите отредактировать: " << endl << "1) Название трубы" << endl << "2) Статус 'в ремонте'" << endl << "0) Выход в меню" << endl << "Номер команды: ";
            m = check(2, 0);
            if (m == 0) {
                break;
            }
            else if (m == 1) {
                cout << "Старое название: " << Pipe.Name <<endl;
                cout << "Введите новое название трубы: ";
                getline(cin,Pipe.Name);
            }
            else if (m == 2) {
                cout << "Старый статус трубы: в ремонте " << boolalpha << Pipe.repair << endl;
                cout << "Выберите новый статус трубы: "<<endl<<"0)Не в ремонте"<<endl<<"1)В ремонте"<<endl<<"Введите номер команды: ";
                int k = -1;
                k = check(1, 0);
                Pipe.repair = k;
            }
        }
    }
    else {
        cout << "Вы еще не добавили трубу и не можете посмотреть ее параметры. Пожалуйста настройтe трубу в меню(пункт 1)" << endl;
    }
}
void edit_CS(compressor_station &CS) {
    int m = 0;
    if (CS.workshops > 0) {
        while (true) {
            cout << "Выберите параметр который вы хотите отредактировать: " << endl << "1) Название КС" << endl << "2) Кол-во цехов в работе" << endl << "3) Коэффициент эффективности (от 0 до 100)" << endl << "0) Выход в меню" << endl << "Номер команды: ";
            m = check(3, 0);
            if (m == 0) {
                break;
            }
            else if (m == 1) {
                cout << "Старое название: " << CS.Name << endl;
                cout << "Введите новое название трубы: ";
                getline(cin, CS.Name);
            }
            else if (m == 2) {
                cout<< "Общее кол-во цехов: "<<CS.workshops << "; Старое кол-во цехов в работе: " << CS.workshopsinwork << endl;
                cout << "Введите новое кол-во цехов в работе: ";
                CS.workshopsinwork = check(CS.workshops, 0);
            }
            else if (m == 3) {
                cout << "Старый коэффициент эффективности: " << CS.effectiveness << endl;
                cout << "Введите новый коэффициент эффективности (от 0 до 100): ";
                CS.effectiveness = check(100, 0);
            }
        }
    }
    else {
        cout << "Вы еще не добавили КС и не можете посмотреть ее параметры. Пожалуйста настройтe КС в меню(пункт 2)" << endl;
    }
}

void savePipe(Pipe &Pipe) {
    ofstream out;
    out.open("datapipecs.txt");
    if (out.is_open())
    {
        out << Pipe.Name << endl;
        out << Pipe.length << " " << Pipe.diameter << " " << Pipe.repair;
    }
    out.close();
    cout << "Данные о трубе сохранены в файл!" << endl;
}
void saveCS(compressor_station &CS) {
    ofstream out;
    out.open("datapipecs.txt");
    if (out.is_open())
    {
        out << CS.Name << endl;
        out << CS.workshops << " " << CS.workshopsinwork << " " << CS.effectiveness;
    }
    out.close();
    cout << "Данные о КС сохранены в файл!" << endl;
}

Pipe loadPipe(Pipe Pipe) {
    ifstream in("datapipe.txt");
    if (in.is_open())
    {
        getline(in, Pipe.Name);
        in >> Pipe.length >> Pipe.diameter >> Pipe.repair;
    }
    in.close();
    cout << "Данные о трубе загружены из файла!" << endl;
    return Pipe;
}
compressor_station loadCS(compressor_station CS) {
    ifstream in("datapipe.txt");
    if (in.is_open())
    {
        getline(in, CS.Name);
        in >> CS.workshops >> CS.workshopsinwork >> CS.effectiveness;
    }
    in.close();
    cout << "Данные о КС загружены из файла!" << endl;
    return CS;
}
int main(){
    setlocale(LC_ALL, "RU");
    Pipe Pipe;
    compressor_station CS;
    while (true) {
        int k = menu();
        if (k == 0) {
            break;
        }
        else if (k == 1) {
            menu_new_pipe(Pipe);
        }
        else if (k == 2) {
            menu_new_ks(CS);
        }
        else if (k == 3) {
            view_all(Pipe,CS);
        }
        else if (k == 4) {
            edit_pipe(Pipe);
        }
        else if (k == 5) {
            edit_CS(CS);
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