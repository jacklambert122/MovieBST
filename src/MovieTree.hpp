#ifndef MOVIETREE_HPP
#define MOVIETREE_HPP

#include <string>

/* ======================================================================
 * Class: MovieNode
 * Purpose: Node object to store in the binary search tree (BST). Each
 *          movie's info will be stored in one node.
 * @param previous name of the city that comes before the new city
 * @param cityName name of the new city
 * @return none
========================================================================= */
class MovieNode
{
    
public:
    // instance variables
    int ranking;
    std::string title;
    int year;
    int quantity;
    MovieNode *leftChild;
    MovieNode *rightChild;

    // Defualt Constructor
    MovieNode() :
        ranking(-1), title(nullptr), year(0), quantity(-1), leftChild(nullptr), rightChild(nullptr) {}
    
    // Constructor
    MovieNode(int _ranking, std::string _title, int _year, int _quantity) :
    ranking(_ranking), title(_title), year(_year), quantity(_quantity), leftChild(nullptr), rightChild(nullptr) {}

};

/* ======================================================================
 * Class: MovieTree
 * Purpose: Class implementing the BST
========================================================================= */
class MovieTree
{

private:
    // instance var pointing to root node in tree
    MovieNode* root;

    /* ======================================================================
    * Purpose: destroy the subtree rooted at currNode (POSTORDER)
    * @param currNode
    * @return None
    ========================================================================= */
    void destroyNode(MovieNode *currNode);

    /* ======================================================================
     * Purpose: 
     * @param 
     * @return None
    ========================================================================= */
    void printMovieInventoryHelper(MovieNode* root);

    /* ======================================================================
     * Purpose: Add movie to BST, at spot in tree alphabetically-sorted by 
     *          title. 
     * @param currNode: 
     * param ranking: ranking of movie
     * @param title: title of movie
     * @param releaseYear: release year of movie
     * @param quantity: # of copies available to rent
     * @return 
    ========================================================================= */
    MovieNode* addMovieNodeHelper(MovieNode* currNode, int ranking, std::string title, int releaseYear, int quantity);

    /* ======================================================================
     * Purpose: 
     * @param 
     * @return None
    ========================================================================= */
    MovieNode* searchHelper(MovieNode* root, std::string title);

    /* ======================================================================
     * Purpose: 
     * @param 
     * @return None
    ========================================================================= */
    int countMoviesHelper(MovieNode* root);

    /* ======================================================================
     * Purpose: 
     * @param 
     * @return None
    ========================================================================= */
    MovieNode*  deleteMovieHelper(MovieNode* root, std::string title);

    /* ======================================================================
     * Purpose: 
     * @param 
     * @return None
    ========================================================================= */
    MovieNode* getMinValueHelper(MovieNode* root);


public:
    // Defualt Constructor 
    MovieTree() : root(nullptr) {}

    // Destructor
    ~MovieTree();

    /* ======================================================================
     * Purpose: print entire movie inventorie
     * @param 
     * @return None
    ========================================================================= */
    void printMovieInventory();

   
    /* ======================================================================
     * Purpose: UI for addMovieHandler
     * @param rating: IMDB rating of movie
     * @param title: title of movie
     * @param releaseYear: release year of movie
     * @param quantity: # of copies available to rent
     * @return None
    ========================================================================= */
    void addMovieNode(int ranking, std::string title, int releaseYear, int quantity);

    // Descr: Search the BST for the given title and
    //    print that movie's info in the predefined
    //    format. See 'Find a movie' in the manual. 
    //  param title: title of node to find
    /* ======================================================================
     * Purpose: Search the BST for the given title and print that movie's 
     *          info in the predefined format. 
     * @param title of node to find
     * @return None
    ========================================================================= */
    void findMovie(std::string title);

    // Descr: update the inventory to indicate a movie
    //    has been rented and print predefined info.
    //    See 'Rent a movie' in the manual. 
    //  param title: title of node to rent
    void rentMovie(std::string title);

    void countMovies();

    void deleteMovie(std::string title);
};

#endif // MOVIETREE_HPP
