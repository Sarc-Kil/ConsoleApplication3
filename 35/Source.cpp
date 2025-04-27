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
            throw runtime_error("������: ���������� ��������� ���������� ���� � �������.");
        }
        isActive = false;
        cout << "���� � ������� ���������." << endl;
    }
};

class FootballGame : public Game {
public:
    void endGame() override {
        if (!isActive) {
            throw runtime_error("������: ���������� ��������� ���������� ���� � ������.");
        }
        isActive = false;
        cout << "���� � ������ ���������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "������� ��� ���� (�������/������): ";
    cin >> input;

    Game* game;

    if (input == "�������") {
        game = new ChessGame();
    }
    else if (input == "������") {
        game = new FootballGame();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    char choice;
    cout << "������ ��������� ����? (y/n): ";
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
        cout << "���� ������������." << endl;
    }

    delete game;
    return 0;
}