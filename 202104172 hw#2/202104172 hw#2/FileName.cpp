#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Player {
public:
    string name;
    int* results;

    Player(string playerName) : name(playerName) {
        results = new int[3]; 
    }

    ~Player() {
        delete[] results; 
    }
};

class GamblingGame {
    Player players[2]; 
public:
    GamblingGame(string p1, string p2) : players{ Player(p1), Player(p2) } {}

    void play() {
        for (int i = 0; i < 2; i++) { 
            cout << players[i].name << "님 <Enter>: ";
            cin.get(); 

            cout << "생성된 숫자: "; 
            for (int j = 0; j < 3; j++) {
                players[i].results[j] = rand() % 4; 
                cout << players[i].results[j] << " ";   
            }

            cout << endl;

            if (allEqual(players[i].results)) {
                cout << players[i].name << "님 승리!" << endl;
                return; 
            }
            else {
                cout << "아쉽군요!" << endl;
            }
        }
    }

    bool allEqual(int results[]) {
        return (results[0] == results[1] && results[1] == results[2]);
    }
};

int main() {
    string player1, player2;
    cout << "첫 번째 플레이어 이름을 입력하세요: ";
    getline(cin, player1); 
    cout << "두 번째 플레이어 이름을 입력하세요: ";
    getline(cin, player2); 

    srand((unsigned int)time(NULL));

    GamblingGame game(player1, player2);
    game.play();

    return 0;
}
