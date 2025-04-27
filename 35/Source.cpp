#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Game {
protected:
    bool isActive;

public:
    Game() : isActive(true) {}
    virtual void endGame() = 0;
    void setActive(bool active) { isActive = active; }
};

class ChessGame : public Game {
public:
    void endGame() override {
        if (!isActive) {
            throw runtime_error("Ошибка: Невозможно завершить неактивную игру в шахматы.");
        }
        isActive = false;
        cout << "Игра в шахматы завершена." << endl;
    }
};

class FootballGame : public Game {
public:
    void endGame() override {
        if (!isActive) {
            throw runtime_error("Ошибка: Невозможно завершить неактивную игру в футбол.");
        }
        isActive = false;
        cout << "Игра в футбол завершена." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "Введите тип игры (шахматы/футбол): ";
    cin >> input;

    Game* game;

    if (input == "шахматы") {
        game = new ChessGame();
    }
    else if (input == "футбол") {
        game = new FootballGame();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    char choice;
    cout << "Хотите завершить игру? (y/n): ";
    cin >> choice;

    if (choice == 'y') {
        try {
            game->endGame();
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    else {
        cout << "Игра продолжается." << endl;
    }

    delete game;
    return 0;
}