// File: A2_S8_20220453_Q5.cpp
// Purpose: program that manages a list of up to 10 players and their high scores 
//          allows the user to add players to the list, print the list, search for a player
//          in the list
// Author: Farah Mohamed Magdy Mohamed
// Section: 8
// ID: 20220453
// TA: Khalid Ibrahim
// Date: 4 Nov 2023

struct Player {
    string name;
    int score;
};

void add(Player players[], int& counter, Player newPlayer) {

    if (counter < 10) {
        players[counter] = newPlayer;
        counter++;
    }
    else {
        int minScore = players[0].score;
        int minIndex = 0;
        for (int i = 1; i < counter; i++) {
            if (players[i].score < minScore) {
                minScore = players[i].score;
                minIndex = i;
            }
        }
        if (newPlayer.score > minScore) {
            players[minIndex] = newPlayer;
        }
    }
}

bool compare(const Player& p1, const Player& p2) {
    return p1.score > p2.score;
}

void print(Player players[], int counter) {
    sort(players, players + counter,compare);
    cout << "Top 10 Players:\n";
    for (int i = 0; i < counter && i < 10; i++) {
        cout << players[i].name << ": " << players[i].score << endl;
    }
}

void search(Player players[], int counter, string name) {
    bool notfound = true;
    for (int i = 0; i < counter; i++) {
        if (players[i].name == name) {
            cout << name << " highest score: " << players[i].score << endl;
            notfound = false;
            break;
        }
    }
    if (notfound) {
        cout << "Player not found or not in top 10" << endl;
    }
}

int main() {
    Player players[10]
    int counter = 0;

    while (true) {

        int choice;
        cout << "\n1- Add a new player and score\n2- Print top 10 names and scores\n3- Search for a player's highest score\n4- Exit\n";
        cin >> choice;

        if(choice==1){
            string name;
                int score;

                cout << "Enter player name: ";
                cin >> name;

                cout << "Enter player score: ";
                cin >> score;

                add(players, counter, { name, score });

        }else if (choice==2){
             print(players, counter);

        }else if(choice==3){
            string name;

                cout << "Enter player name: ";
                cin >> name;

                search(players, counter, name);


        }else {
            return 0;
        }
    }

    return 0;
}
