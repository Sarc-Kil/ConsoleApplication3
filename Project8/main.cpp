#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Game {
public:
    virtual void start() const = 0;
    virtual ~Game() {}
};

class Chess : public Game {
public:
    void start() const override {

        cout << "Игра в шахматы началась!" << endl;
    }
};

class Tennis : public Game {
public:
    void start() const override {
   
        cout << "Игра в теннис началась!" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Game* game = nullptr;
    char choice;

    cout << "Выберите игру (c для шахмат, t для тенниса): ";
    cin >> choice;

    try {
        if (choice == 'c') {
            game = new Chess();
        }
        else if (choice == 't') {
            game = new Tennis();
        }
        else {
            throw runtime_error("Ошибка: Неверный выбор игры.");
        }

        game->start();
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl; 
    }

    return 0;
}