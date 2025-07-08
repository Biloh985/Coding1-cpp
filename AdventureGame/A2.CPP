//Favorite Games Program

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main () {
    
    cout << "Hello! Welcome to your favortie games.\n";

do {
    cout << "What would you like to do?\n";
    cout << "Add, Edit, Delete, Show, or Quit\n";
    
    int counter;
    counter = 3;
    vector<string> favGames = {"Undertale", "Portal 2", "Dead by Daylight"}; //create vector of strings
    string input; //Create string named input
    getline (cin, input); //use getline to get input
    cin >> input;

    if (input == "Add") {
        cout << "What game would you like to add?\n";

        string gameName;
        getline (cin, gameName);
        cin >> gameName;
        
        favGames.push_back(gameName);
        cout << "You added " << gameName << " to your favorite games.\n";

        counter ++;
    } // End of ADD
    if(input == "edit") {

        bool gameFound;
        do {
         cout << "Which game would you like to edit?\n";

         string gameName;
         getline (cin, gameName);
         cin >> gameName;
         auto game = find(favGames.begin(), favGames.end(), gameName);

         if (game != favGames.end()) {
                gameFound = true;
               cout << "You chose to edit " << gameName << ".\n";
               cout << "What would you like to change it to?\n";

               int input;
               cin >> input;
               *game = input;
               
               cout << input << " is now on your list\n";
               break;
            } 
            else {
                
                cout << gameName << " was not found on your list\n";
                continue;
            } 
        } while (gameFound == false);
    } //End of EDIT

    if (input == "delete") {

        
         do {
             cout << "Which game would you like to delete?\n";
             cout << "Press 0 to quit.\n";

             string gameName;
             getline (cin, gameName);
             cin >> gameName;

             if (gameName != "0") {
    
                auto game = find(favGames.begin(), favGames.end(), gameName);

                if (game != favGames.end()) {
                    gameFound = true;
                    favGames.erase(game);
                    cout << gameName << " has been deleted from the list.\n";\
                    counter--;
                    break;
                }
                else {
                gameFound = false;
                cout << gameName << " was not found on your list\n";
                continue;
                }
            } else 
                {
                "Thanks for playing!\n";
                return 0;
                }
            } while (gameFound == false);
        
        }// end of DELETE

     if (input == "show") {

        sort(favGames.begin(), favGames.end());

        cout << "Here are your favorite games:\n";
        for(int i = 0; i = favGames.size(); i++) {
            cout << favGames[i] << "\n";
        }
        //for (auto game : favGames) {
        //cout << game << "\n";
    }// end of SHOW

    if (input == "quit") {
        do {
            cout << "Are you sure you want to quit?\n";
            cout << "Press 1 to confirm.\n";
            cout << "Press 2 to cancel.\n";
            
            string input;
            cin >> input;
            
            if (input != "1" && input != "2") {
                cout << "Invalid input, please try again\n";
                continue;
            }
            
            if(input == "1") {
                cout << "Thanks for playing!\n";
                break;
            }
        } while (input != "2");
    }
} while (input == "2");

}
