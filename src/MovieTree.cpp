#include <iostream>
#include "MovieTree.hpp"
using namespace std;


/* ======================================================================
 * MovieTree Class Methods
========================================================================= */


/**
This function will destroy the subtree rooted at currNode.
Think about in what order should you destroy. POSTORDER. or right-left-root
**/

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

MovieTree::~MovieTree()
{
    destroyNode(root);
}


/* --------------- Print Movie Functions ------------*/
void MovieTree:: printMovieInventoryHelper(MovieNode* currNode)
{
    if (currNode == NULL)
        return;
    else
    {
        printMovieInventoryHelper(currNode->leftChild);
        cout << "Movie: " << currNode->title << " " << currNode->quantity << endl;
        printMovieInventoryHelper(currNode->rightChild);

    }
}

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

/*--------------- Add Movie Functions ----------------*/

MovieNode* MovieTree:: addMovieNodeHelper(MovieNode* currNode,int ranking, string title, int releaseYear, int quantity)
{
    if (currNode == NULL)
    {
        // Creates a new Node for the new movie
        MovieNode* newNode = new MovieNode;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->title = title;
        newNode->year = releaseYear;
        newNode->quantity = quantity;
        newNode->ranking = ranking;
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

void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{
    if(root == NULL)
    {
        MovieNode* newNode = new MovieNode;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->title = title;
        newNode->year = releaseYear;
        newNode->quantity = quantity;
        newNode->ranking = ranking;
        root = newNode;
        return;
    }
    addMovieNodeHelper(root, ranking, title, releaseYear, quantity);
}

/* ------------------- Find Movie Functions ----------------- */
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
    cout << "Movie " << "'"<< tempMovie->title <<"' Info:"<< endl;
    cout << "================================" << endl;
    cout << "Ranking : " << tempMovie->ranking << endl;
    cout << "Title   : " << tempMovie->title << endl;
    cout << "Year    : " << tempMovie->year << endl;
    cout << "Quantity: " << tempMovie->quantity << endl;

}



/* ------------------- Rent Movie Functions ----------------- */

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
        cout << "Movie has been rented." << endl;
        cout << "Movie " << "'"<< tempMovie->title <<"' Info:"<< endl;
        cout << "================================" << endl;
        cout << "Ranking : " << tempMovie->ranking << endl;
        cout << "Title   : " << tempMovie->title << endl;
        cout << "Year    : " << tempMovie->year << endl;
        cout << "Quantity: " << tempMovie->quantity << endl;

    }
}
/** ------------ Function the gets total number of nodes in tree ----------- **/

int MovieTree::countMoviesHelper(MovieNode *currNode)
{
    if(currNode == NULL)
        return 0;
    return countMoviesHelper(currNode->leftChild)+ countMoviesHelper(currNode->rightChild)+1;
}

void MovieTree::countMovies()
{
    cout << "Count = " << countMoviesHelper(root) << endl;
}


MovieNode* MovieTree::getMinValueHelper(MovieNode* curNode)
{
    if(curNode->leftChild == NULL)
        return curNode;
    return getMinValueHelper(curNode->leftChild);
}


/** ------------ Function that deletes Node from tree    ----------- **/
MovieNode* MovieTree:: deleteMovieHelper(MovieNode* curNode, std::string title)
{
    if(curNode == nullptr)
    {
        /** Node Not Found **/
        return NULL;

    }
    else {
        if (curNode->title != title) {
            cout << " [visit] " << curNode->title << endl;
            if (curNode->title.compare(title) > 0) /** Key is less than the current root **/
            {
                curNode->leftChild = deleteMovieHelper(curNode->leftChild, title);
            } else /** Key is greater than the current root **/
            {
                curNode->rightChild = deleteMovieHelper(curNode->rightChild, title);
            }
        } else {
            cout << " [found]" << curNode->title;
            cout << ", left:" << curNode->leftChild;
            cout << ", right:" << curNode->rightChild << endl;
            /** found the key and now we need to delete it **/
/** ----------------- No children --------------------- **/
            if (curNode->leftChild == nullptr && curNode->rightChild == nullptr) {
                /** No Children, just delete **/
                delete curNode;
                curNode = nullptr;
            }
/** --------------- Only One child --------------- **/
            else if (curNode->rightChild == nullptr) {
                /** one child on left **/
                MovieNode *temp = curNode->leftChild;
                delete curNode;
                curNode = temp;
            } else if (curNode->leftChild == nullptr) {
                /** one child on right **/
                MovieNode *temp = curNode->rightChild;
                delete curNode;
                curNode = temp;
            }
/** --------------- Two children --------------- **/
            else {
                /** Lets take the min value of right sub-tree **/
                MovieNode* tempNode = getMinValueHelper(curNode->rightChild);
                curNode->title = tempNode->title;
                curNode->quantity = tempNode-> quantity;
                curNode->ranking = tempNode-> ranking;
                curNode->year = tempNode-> year;
                curNode->rightChild = deleteMovieHelper(curNode->rightChild, tempNode->title); // Saves update

            }
        }
    }
    return curNode;
}
/**   Delete the node with the given title    **/
void MovieTree:: deleteMovie(std::string title)
{
    MovieNode* tempMovie = searchHelper(root, title);
    // If there are no movies
    cout<<"temp movie: "<< tempMovie->title <<endl;
    cout<<"temp right child: "<< tempMovie->rightChild <<endl;
    cout<<"temp left child: "<< tempMovie->leftChild<<endl;

    if(tempMovie->title != title &&  (tempMovie->rightChild == NULL && tempMovie->leftChild == NULL))
    {
        cout << "Movie not found." << endl;
        return;
    }
    else
    {
        cout<<"Deleting "<<title<<endl;
        root = deleteMovieHelper(root, title);
    }

}


