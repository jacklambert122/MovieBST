# include "MovieTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

/* ======================================================================
 * Pre-declaring user-interface functions
========================================================================= */
void UserInterface(MovieTree& Movies); 
void displayMenu(); 
/* ================================================================ */

/* ======================================================================
 * Main
========================================================================= */
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
/* ================================================================ */

void UserInterface(MovieTree& Movies)
{
    bool quit = false;
    string s_input;
    UserSelection::Choices input;

    while(!quit)
    {
        displayMenu();

        getline(cin, s_input);
        try
        {
            input = static_cast<UserSelection::Choices>(stoi(s_input));
        }
        catch (exception& e)
        {
            // non-numeric input. trigger the default switch case.
            input = UserSelection::Choices::_defualt;
        }

        switch (input)
        {
            case UserSelection::Choices::findMovie:
            {
                string MovieInput;
                cout << "Enter title: " << endl;
                getline(cin, MovieInput);
                Movies.findMovie(MovieInput);
                break;
            }

            case UserSelection::Choices::rentMovie:
            {
                string RentInput;
                cout << "Enter title: " << endl;
                getline(cin, RentInput);
                Movies.rentMovie(RentInput);
                break;
            }

            case UserSelection::Choices::printInventory:
            {
                Movies.printMovieInventory();
                break;
            }
            case UserSelection::Choices::removeMovieFromInventory:
            {
                string DeleteInput;
                cout << "Enter title:" << endl;
                getline(cin, DeleteInput);
                Movies.deleteMovie(DeleteInput);
                break;
            }
            case UserSelection::Choices::countMovies:
            {
                Movies.countMovies();
                break;
            }
            case UserSelection::Choices::quit:       
            {
                quit = true;
                cout << "Goodbye! " << endl;
                break;
            }
            default:     // invalid input
            {
                cout << "Invalid Input" << endl;
                break;
            }
        }
    }
}
/* ================================================================ */

void displayMenu()
{
    cout << endl;
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Rent a movie" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Delete a movie" << endl;
    cout << "5. Count movies" << endl;
    cout << "6. Quit" << endl;
}
/* ================================================================ */
