#include <string>
#include <vector>

#ifndef Z4_PLAYER_H
#define Z4_PLAYER_H

using namespace std;

class Player {
private:

    string firstName;
    string lastName;
    int growth;
    vector<string> skills;
public:
    Player(string firstName, string lastName, int growth, vector<string> skills);

    string getDetails();

    string getSkills();

    double getGrowth();

    string getLastName();

    string getFirstName();

    void changeData(string firstName, string lastName, int growth);

    Player(string line);

    string toFile();
};

#endif