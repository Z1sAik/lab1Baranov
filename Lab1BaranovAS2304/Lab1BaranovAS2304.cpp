#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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

float floatcheck(int max, float low) {
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

void menu_new_Pipe(Pipe &P) {
    cout << "Введите название трубы (на английском язык): ";
    getline(cin, P.Name);
    cout << "Введите длину трубы в километрах: ";
    P.length = floatcheck(0, 0.1);
    cout << "Введите диаметр трубы в миллиметрах: ";
    P.diameter = check(0, 1);
    cout << "Выберите в каком состоянии труба: " << endl << "0)Не в ремонте" << endl << "1)В ремонте" << endl;
    int k=-1;
    k = check(1, 0);
    P.repair = k;
    cout << "Труба создана: " << endl << "Название трубы: " << P.Name << "; Длина трубы: " << P.length << "; Диаметр трубы: " << P.diameter << "; Статус 'в ремонте': " << boolalpha << P.repair << endl;
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

void show_Pipe(Pipe &P) {
    cout << "Труба: " << endl << "Название трубы: " << P.Name << "; Длина трубы: " << P.length << "; Диаметр трубы: " << P.diameter << "; Статус 'в ремонте': " << boolalpha << P.repair << endl;
}
void show_cs(compressor_station &CS) {
    cout << "Компрессорная станция: " << endl << "Название КС: " << CS.Name << "; Кол-во цехов: " << CS.workshops << "; Кол-во цехов в работе: " << CS.workshopsinwork << "; Коэффициент эффективности КС: " << CS.effectiveness << endl;
}

void view_all(Pipe &P,compressor_station &CS) {
    int m = 0;
    while (true) {
        cout << "Выберите что вы хотите просмотреть: " << endl << "1) Просмотреть трубу" << endl << "2) Просмотреть КС" << endl << "3) Просмотреть все объекты"<<endl<<"0) Выход в меню" << endl << "Введите комманду: ";
        m = check(3, 0);
        if (m == 0) {
            break;
        }
        else if (m == 1) {
            if (P.diameter < 1) {
                cout << "Вы еще не добавили трубу." << endl;
            }
            else {
                show_Pipe(P);
            }
        }
        else if (m == 2) {
            if (CS.workshops < 1) {
                cout << "Вы еще не добавили КС." << endl;
            }
            else {
                show_cs(CS);
            }
        }
        else if (m == 3) {
            if (P.diameter < 1 && CS.workshops < 1) {
                cout << "Вы еще не добавили ни одного объекта." << endl;
            }
            else if (P.diameter > 0 && CS.workshops < 1) {
                cout << "Вы еще не добавили КС." << endl;
            }
            else if (P.diameter < 1 && CS.workshops > 0) {
                cout << "Вы еще не добавили трубу." << endl;
            }
            else {
                show_Pipe(P);
                show_cs(CS);
            }
        }
    }
}

void edit_Pipe(Pipe &P) {
    int m = 0;
    if (P.diameter >0) {
        while (true) {
            cout << "Выберите параметр который вы хотите отредактировать: " << endl << "1) Название трубы" << endl << "2) Статус 'в ремонте'" << endl << "0) Выход в меню" << endl << "Номер команды: ";
            m = check(2, 0);
            if (m == 0) {
                break;
            }
            else if (m == 1) {
                cout << "Старое название: " << P.Name <<endl;
                cout << "Введите новое название трубы: ";
                getline(cin,P.Name);
            }
            else if (m == 2) {
                cout << "Старый статус трубы: в ремонте " << boolalpha << P.repair << endl;
                cout << "Выберите новый статус трубы: "<<endl<<"0)Не в ремонте"<<endl<<"1)В ремонте"<<endl<<"Введите номер команды: ";
                int k = -1;
                k = check(1, 0);
                P.repair = k;
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

void save(Pipe& P, Pipe& P_save, compressor_station& CS, compressor_station& CS_save, int k) {
    ifstream in("datapipecs.txt");
    if (in.is_open())
    {
        getline(in, P_save.Name);
        in >> P_save.length >> P_save.diameter >> P_save.repair;
        in.ignore();
        getline(in, CS_save.Name);
        in >> CS_save.workshops >> CS_save.workshopsinwork >> CS_save.effectiveness;
        in.ignore();
    }
    in.close();
    if (k == 6 && P.Name.empty()) {
        cout << "У вас нет данных о трубе для записи." << endl;
        return;
    }
    if (k == 8 && CS.Name.empty()) {
        cout << "У вас нет данных о КС для записи." << endl;
        return;
    }

    ofstream out;
    out.open("datapipecs.txt");
    if (out.is_open())
    {
        if (k == 6) {
            out << P.Name << endl;
            out << P.length << " " << P.diameter << " " << P.repair << endl;
            out << CS_save.Name << endl;
            out << CS_save.workshops << " " << CS_save.workshopsinwork << " " << CS_save.effectiveness;
            cout << "Данные о трубе записаны!" << endl;
        }
        if (k == 8) {

            out << P_save.Name << endl;
            out << P_save.length << " " << P_save.diameter << " " << P_save.repair << endl;
            out << CS.Name << endl;
            out << CS.workshops << " " << CS.workshopsinwork << " " << CS.effectiveness;
            cout << "Данные о КС записаны!" << endl;
        }
    }
    out.close();
}

void load(Pipe &P,Pipe &P_save,compressor_station &CS,compressor_station &CS_save, int k) {
    ifstream in("datapipecs.txt");
    if (in.is_open())
    {
        getline(in, P_save.Name);
        in >> P_save.length >> P_save.diameter >> P_save.repair;
        in.ignore();
        getline(in, CS_save.Name);
        in >> CS_save.workshops >> CS_save.workshopsinwork >> CS_save.effectiveness;
        in.ignore();
    }
    in.close();
    if (k == 7) {
        if (P_save.Name.empty()) {
            cout << "В файле нет данных о трубе!" << endl;
            return;
        }
        else{
            P = P_save;
            cout << "Настройки трубы были загружены из файла!" << endl;
        } 
    }
    if (k == 9) {
        if (CS_save.Name.empty()) {
            cout << "В файле нет данных о КС!" << endl;
            return;
        }
        else {
            CS = CS_save;
            cout << "Настройки КС были загружены из файла!" << endl;
        }
    }
}

int main(){
    setlocale(LC_ALL, "RU");
    Pipe P;
    compressor_station CS;
    Pipe P_save{ "",0,0,0 };
    compressor_station CS_save{ "",0,0,0 };
    while (true) {
        int k = menu();
        if (k == 0) {
            break;
        }
        else if (k == 1) {
            menu_new_Pipe(P);
        }
        else if (k == 2) {
            menu_new_ks(CS);
        }
        else if (k == 3) {
            view_all(P,CS);
        }
        else if (k == 4) {
            edit_Pipe(P);
        }
        else if (k == 5) {
            edit_CS(CS);
        }
        else if (k == 6) {
            save(P, P_save, CS, CS_save, 6);
        }
        else if (k == 7) {
            load(P,P_save,CS,CS_save,7);
        }
        else if (k == 8) {
            save(P, P_save, CS, CS_save, 8);
        }
        else if (k == 9) {
            load(P, P_save, CS, CS_save, 9);
        }
    }
    return 0;
}