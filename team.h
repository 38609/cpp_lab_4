#include <string>
#include <vector>
#include "player.h"

using namespace std;

class Team {
private:
    string name;
    vector<Player> players;
public:
    Team(string name);

    Team(const Team &);

    string getName();

    string getDetails();

    Player replacePlayer(int index, Player player);

    void changePlayerData(int index, string firstName, string lastName, int growth);

    void addPlayer(const Player &player);

    void readFromFile(string path);

    bool saveToFile();
};