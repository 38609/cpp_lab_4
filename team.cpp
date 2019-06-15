#include <fstream>
#include <sstream>
#include <iostream>
#include "team.h"

Team::Team(string name) {
    this->name = name;
}

Team::Team(const Team &fTeam) {
    this->name = fTeam.name + " - Copy";
    for (const Player &player : fTeam.players) {
        addPlayer(player);
    }
}

Player Team::replacePlayer(int index, Player player) {
    return this->players[index] = player;
}

void Team::changePlayerData(int index, string firstName, string lastName, int growth) {
    this->players[index].changeData(firstName, lastName, growth);
}

string Team::getName() {
    return name;
}

string Team::getDetails() {
    string result = "Team: " + getName() + "\n\n";
    result += "========= Players ===========\n";

    for (Player player : this->players) {
        result += player.getDetails() + "\n";
    }

    return result + "\n\n";
}

void Team::readFromFile(string path) {
    fstream file;
    file.open(path, fstream::in);
    string player;

    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, player);
            addPlayer(Player(player));
        }
    }

    file.close();
}

bool Team::saveToFile() {
    time_t t = time(0);
    tm *now = localtime(&t);
    stringstream fileName;
    fileName << "druzyna-" << this->getName() << "-" << now->tm_hour << now->tm_min << now->tm_sec << ".txt";
    fstream file;
    file.open(fileName.str(), fstream::out);
    stringstream saveStream = stringstream();

    for (Player player : this->players) {
        saveStream << player.toFile() << endl;
    }

    file << saveStream.str();
    file.close();
    return true;
}

void Team::addPlayer(const Player &player) {
    this->players.push_back(player);
}