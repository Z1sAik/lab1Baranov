#include <iostream>
#include <string>

struct Pipe_settings
{
    std::string Name; //название трубы
    int length; //километры 
    int diameter; //миллиметры
};

int main(){
    setlocale(LC_ALL, "RU");
    Pipe_settings Pipe;
    std::cout << "Введите название трубы: ";
    getline(std::cin, Pipe.Name);
    std::cout << Pipe.Name;
    return 0;
}