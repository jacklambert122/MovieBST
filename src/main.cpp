# include "MovieTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void UserInterface(MovieTree& Movies); // Pre-declaring user-interface function
void displayMenu(); // Displays menu options

int main(int argc, char *argv[] ) {

    MovieTree Movies;
    ifstream file;
    string info, ranking_str, title, year_str, quantity_str;

    file.open(argv[1]);
    if(file.fail())
        cout << "File did not open" << endl;
    else
    {
        while(getline(file, info))
        {
            stringstream ss(info);
            getline(ss, ranking_str, ',' );
            getline(ss, title, ',');
            getline(ss, year_str,',');
            getline(ss, quantity_str,',');

            // Converting integers back
            int ranking, year, quantity;
            ranking = stoi(ranking_str);
            year = stoi(year_str);
            quantity = stoi(quantity_str);
            Movies.addMovieNode(ranking, title, year, quantity);
        }
    }
    UserInterface(Movies);


    return 0;
}

void UserInterface(MovieTree& Movies)
{
    bool quit = false;
    string s_input;
    int input;

    while(!quit)
    {
        displayMenu();

        getline(cin, s_input);
        try
        {
            input = stoi(s_input);
        }
        catch (exception& e)
        {
            // non-numeric input. trigger the default switch case.
            input = 10;
        }

        switch (input)
        {
            case 1:      // Find Movie
            {
                string MovieInput;
                cout << "Enter title: " << endl;
                getline(cin, MovieInput);
                Movies.findMovie(MovieInput);
                break;
            }

            case 2:        // Rent a Movie
            {
                string RentInput;
                cout << "Enter title: " << endl;
                getline(cin, RentInput);
                Movies.rentMovie(RentInput);
                break;
            }

            case 3: // Print Inventory
            {
                Movies.printMovieInventory();
                break;
            }
            case 4:
            {
                string DeleteInput;
                cout << "Enter title:" << endl;
                getline(cin, DeleteInput);
                Movies.deleteMovie(DeleteInput);
                break;
            }
            case 5:
            {
                Movies.countMovies();
                break;
            }
            case 6:       // add city
            {
                quit = true;
                cout << "Goodbye! " << endl;
                break;
            }

            default:     // invalid input
                cout << "Invalid Input" << endl;
                break;
        }
    }
}


void displayMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Rent a movie" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Delete a movie" << endl;
    cout << "5. Count movies" << endl;
    cout << "6. Quit" << endl;
}