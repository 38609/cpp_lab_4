#include <iostream>
#include <vector>
#include <sstream>
#include "player.h"

Player::Player(string firstName, string lastName, int growth, vector<string> skills) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->growth = growth;
    this->skills = skills;
}

Player::Player(string line) {
    string player[8];
    stringstream playerStringStream;

    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ';') {
            line[i] = ' ';
        }
    }

    playerStringStream << line;
    for (int i = 0; i < 8; i++) {
        playerStringStream >> player[i];
        cout << player[i] << endl;;
    }
    for (int i = 3; i < 8; i++) {
        this->skills.push_back(player[i]);
    }

    this->firstName = player[0];
    this->lastName = player[1];
    this->growth = atoi(player[2].c_str());
    this->skills = skills;
}

string Player::getFirstName() {
    return this->firstName;
}

string Player::getLastName() {
    return this->lastName;
}

double Player::getGrowth() {
    return this->growth;
}

string Player::getSkills() {
    string result;

    for (auto const &s : skills) {
        result += s + " ";
    }

    return result;
}

string Player::getDetails() {
    string details;

    details += "First name: " + this->getFirstName() + "\n";
    details += "Last name: " + this->getLastName() + "\n";
    details += "Growth: " + to_string(this->getGrowth()) + "cm\n";
    details += "Skills: " + this->getSkills() + "\n";

    return details;
}

void Player::changeData(string firstName, string lastName, int growth) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->growth = growth;
}

string Player::toFile() {
    auto save = stringstream();
    save << getFirstName() << ";" << getLastName() << ";" << getGrowth() << ";";
    for (const string &skill : skills) {
        save << skill << ";";
    }
    return save.str();
}