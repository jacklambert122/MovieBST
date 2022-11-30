#include <iostream>
#include "MovieTree.hpp"
using namespace std;


/* ======================================================================
 * MovieTree Class Methods
========================================================================= */

void MovieTree:: destroyNode(MovieNode *currNode)
{
    if(currNode!=NULL)
    {
        destroyNode(currNode->leftChild);
        destroyNode(currNode->rightChild);
        delete currNode;
        currNode = NULL;
    }
}
/* ================================================================ */

MovieTree::~MovieTree()
{
    destroyNode(root);
}
/* ================================================================ */

void MovieTree:: printMovieInventoryHelper(MovieNode* currNode)
{
    if (currNode == NULL)
        return;
    else
    {
        printMovieInventoryHelper(currNode->leftChild);
        cout << endl << "Movie: " << currNode->title << ", Quantity: " << currNode->quantity << endl;
        printMovieInventoryHelper(currNode->rightChild);

    }
}
/* ================================================================ */

void MovieTree::printMovieInventory()
{
    if( root == NULL)
    {
        cout << "Movie not in Inventory" << endl;
    }
    else
    {
        printMovieInventoryHelper(root);
    }
}
/* ================================================================ */

void printMovieAttributes(MovieNode* CurrNode)
{
    cout << endl;
    cout << "Movie " << "'"<< CurrNode->title <<"' Info:"<< endl;
    cout << "================================" << endl;
    cout << "Ranking : " << CurrNode->ranking << endl;
    cout << "Title   : " << CurrNode->title << endl;
    cout << "Year    : " << CurrNode->year << endl;
    cout << "Quantity: " << CurrNode->quantity << endl;

}
/* ================================================================ */


/* ================================================================
 * Add Movie Functions 
================================================================= */
MovieNode* MovieTree:: addMovieNodeHelper(MovieNode* currNode, int ranking, string title, int releaseYear, int quantity)
{
    if (currNode == nullptr) // Reached a leaf
    {
        MovieNode* newNode = new MovieNode(ranking, title, releaseYear, quantity);
        return newNode;
    }
    else if ( currNode->title.compare(title) == 0)
    {
        currNode->quantity = currNode->quantity + 1;
    }
    else if( currNode->title.compare(title) < 0) // If after alphabetically
    {
        currNode->rightChild = addMovieNodeHelper(currNode->rightChild, ranking, title, releaseYear, quantity);
    }
    else if( currNode->title.compare(title) > 0)  // If before alphabetically
    {
        currNode->leftChild = addMovieNodeHelper(currNode->leftChild,ranking, title, releaseYear, quantity);
    }
    return currNode;
}
/* ================================================================ */

void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{
    if(root == nullptr) // Movie is first node in tree
    {
        MovieNode* newNode = new MovieNode(ranking, title, releaseYear, quantity);
        root = newNode;
    }
    else // Not first node in tree
    {
        addMovieNodeHelper(root, ranking, title, releaseYear, quantity);
    }
}
/* ================================================================ */


/* ================================================================
 * Find Movie Functions
================================================================= */
MovieNode* MovieTree :: searchHelper(MovieNode *currNode, std::string title)
{
    // No Movies in library or parent node is the movie
    if (currNode == NULL || currNode->title == title )
    {
        return currNode;
    }
    // if title searched is greater than the parent keep going till null or found (recursiverly)
    else if ( currNode->title.compare(title) < 0)
    {
        if (currNode->rightChild == NULL)
        {
            return currNode;
        }
        return searchHelper(currNode->rightChild, title); // Recursively loops till found or NULL
    }
    else
    {
        if (currNode->leftChild == NULL) {
            return currNode;
        }
        return searchHelper(currNode->leftChild, title);
    }

}
/* ================================================================ */

void MovieTree::findMovie(std::string title)
{
    MovieNode* tempMovie = searchHelper(root, title);
    // If there are no movies
    if(tempMovie == NULL)
    {
        cout << "Movie not found." << endl;
        return;
    }
        // temp movie is the parent node and this checks the right child
    else if(tempMovie->title.compare(title)<0)
    {
        if( tempMovie->rightChild == NULL) // If the parent node points to nothing
        {
            cout << "Movie not found." << endl;
            return;
        }
        else
        {
            tempMovie = tempMovie->rightChild;
        }
    }
    else if(tempMovie->title.compare(title)>0)
    {
        if( tempMovie->leftChild == NULL)
        {
            cout << "Movie not found." << endl;
            return;
        }
        else
        {
            tempMovie = tempMovie->leftChild;
        }
    }
    printMovieAttributes(tempMovie);

}
/* ================================================================ */

/* ================================================================
 * Rent Movie Functions
================================================================= */
void MovieTree:: rentMovie(std::string title)
{
    MovieNode* tempMovie = searchHelper(root, title);
    // If there are no movies
    if(tempMovie == NULL)
    {
        cout << "Movie not found." << endl;
        return;
    }
    // temp movie is the parent node and this checks the right child
    else if(tempMovie->title.compare(title)<0)
    {
        if( tempMovie->rightChild == NULL) // If the parent node points to nothing
        {
            cout << "Movie not found." << endl;
            return;
        }
        else
        {
            tempMovie = tempMovie->rightChild;
        }
    }
    else if(tempMovie->title.compare(title)>0)
    {
        if( tempMovie->leftChild == NULL)
        {
            cout << "Movie not found." << endl;
            return;
        }
        else
        {
            tempMovie = tempMovie->leftChild;
        }
    }

    if ( tempMovie->quantity == 0)
    {
        cout << "Movie out of stock." << endl;
    }
    else
    {
        tempMovie->quantity = tempMovie->quantity - 1;
        printMovieAttributes(tempMovie);
    }
}
/* ================================================================ */

int MovieTree::countMoviesHelper(MovieNode *currNode)
{
    if(currNode == NULL)
        return 0;
    return countMoviesHelper(currNode->leftChild)+ countMoviesHelper(currNode->rightChild)+1;
}
/* ================================================================ */

void MovieTree::countMovies()
{
    cout << "Count = " << countMoviesHelper(root) << endl;
}
/* ================================================================ */

MovieNode* MovieTree::getMinValueHelper(MovieNode* curNode)
{
    if(curNode->leftChild == NULL)
        return curNode;
    return getMinValueHelper(curNode->leftChild);
}
/* ================================================================ */

MovieNode* MovieTree:: deleteMovieHelper(MovieNode* curNode, std::string title)
{
    if(curNode == nullptr) // Node Not Found
    {
        return nullptr;
    }
    else 
    {
        if (curNode->title != title) // Not the node to delete
        {
            // cout << " [visit] " << curNode->title << endl;
            if (curNode->title.compare(title) > 0) // Key is less than the current root
            {
                curNode->leftChild = deleteMovieHelper(curNode->leftChild, title);
            }
            else // Key is greater than the current root 
            {
                curNode->rightChild = deleteMovieHelper(curNode->rightChild, title);
            }
        } 
        else // found the node to delete
        {
            /** ------------------  UI Outputs -------------------- **/
            // cout << " [found] " << curNode->title;
            // cout << ", left:" << curNode->leftChild;
            // cout << ", right:" << curNode->rightChild << endl;
    
            /** ----------------- No children --------------------- **/
            if (curNode->leftChild == nullptr && curNode->rightChild == nullptr)
            {
                /** No Children, just delete **/
                delete curNode;
                curNode = nullptr;
            }
            /** --------------- Only One child --------------- **/
            else if (curNode->rightChild == nullptr) // left child
            {
                MovieNode *temp = curNode->leftChild;
                delete curNode;
                curNode = temp;
            }
            else if (curNode->leftChild == nullptr) // right child
            {
                MovieNode *temp = curNode->rightChild;
                delete curNode;
                curNode = temp;
            }
            /** --------------- Two children --------------- **/
            else
            {
                /** Take the min value of right sub-tree **/
                MovieNode* tempNode = getMinValueHelper(curNode->rightChild);
                curNode->title = tempNode->title;
                curNode->quantity = tempNode->quantity;
                curNode->ranking = tempNode->ranking;
                curNode->year = tempNode->year;
                curNode->rightChild = deleteMovieHelper(curNode->rightChild, tempNode->title); // Saves update
            }
        }
    }
    return curNode;
}
/* ================================================================ */

void MovieTree:: deleteMovie(std::string title)
{
    MovieNode* tempMovie = searchHelper(root, title);
    if(tempMovie->title != title &&  (tempMovie->rightChild == NULL && tempMovie->leftChild == NULL))
    {
        cout << endl << "Movie not found." << endl;
        return;
    }
    else
    {
        cout << endl << "Deleting "<<title<<endl;
        root = deleteMovieHelper(root, title);
    }

}
/* ================================================================ */

