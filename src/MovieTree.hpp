#ifndef MOVIETREE_HPP
#define MOVIETREE_HPP

#include <string>

/* ======================================================================
 * Namespace name: UserSelection
 * Purpose: enumerate case/switch in handleUserInput with a non-public scope
========================================================================= */
namespace UserSelection
{
    enum class Choices
    {
        findMovie = 1,
        rentMovie = 2,
        printInventory = 3,
        removeMovieFromInventory = 4,
        countMovies = 5,
        quit = 6,
        _defualt = 7
    };
}

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
     *          title. Makes recursive implementation easier with UI handoff
     * @param currNode: 
     * param ranking: ranking of movie
     * @param title: title of movie
     * @param releaseYear: release year of movie
     * @param quantity: # of copies available to rent
     * @return 
    ========================================================================= */
    MovieNode* addMovieNodeHelper(MovieNode* currNode, int ranking, std::string title, int releaseYear, int quantity);

    /* ======================================================================
     * Purpose: recursive function to search movie tree for a give movie title
     * @param currNode : current node in movie tree
     * @param title : movie to search for
     * @return MovieNode (nullptr if not found)
    ========================================================================= */
    MovieNode* searchHelper(MovieNode* root, std::string title);

    /* ======================================================================
     * Purpose: function to recursively count movies in movie tree
     * @param currNode
     * @return movie count
    ========================================================================= */
    int countMoviesHelper(MovieNode* root);

    /* ======================================================================
     * Purpose: deletes a movie node from movie tree with given title
     * @param curNode : node to start search from
     * @param title : movie to delete
     * @return MovieNode to delete
    ========================================================================= */
    MovieNode*  deleteMovieHelper(MovieNode* root, std::string title);

    /* ======================================================================
     * Purpose: returns the min value in subtree given current node
     * @param currNode
     * @return MovieNode that is min 
    ========================================================================= */
    MovieNode* getMinValueHelper(MovieNode* root);


public:
    // Defualt Constructor 
    MovieTree() : root(nullptr) {}

    // Destructor
    ~MovieTree();

    /* ======================================================================
     * Purpose: print entire movie inventory
     * @param 
     * @return None
    ========================================================================= */
    void printMovieInventory();

     /* ======================================================================
     * Purpose: print movies attributes
     * @param MovieNode
     * @return None
    ========================================================================= */
    void printMovieAttributes(MovieNode* CurrNode);

    /* ======================================================================
     * Purpose: UI for addMovieHandler
     * @param rating: IMDB rating of movie
     * @param title: title of movie
     * @param releaseYear: release year of movie
     * @param quantity: # of copies available to rent
     * @return None
    ========================================================================= */
    void addMovieNode(int ranking, std::string title, int releaseYear, int quantity);

   
    /* ======================================================================
     * Purpose: Search the BST for the given title and print that movie's 
     *          info in the predefined format. 
     * @param title of node to find
     * @return None
    ========================================================================= */
    void findMovie(std::string title);

     /* ======================================================================
     * Purpose: Update the inventory to indicate a movie has been rented and 
     *         print predefined info.
     * @param title of node to rent
     * @return None
    ========================================================================= */
    void rentMovie(std::string title);

    /* ======================================================================
     * Purpose: Count movies in movie tree
     * @param None
     * @return None
    ========================================================================= */
    void countMovies();

    /* ======================================================================
     * Purpose: Remove movie from movie tree
     * @param title of node to delete
     * @return None
    ========================================================================= */
    void deleteMovie(std::string title);

};

#endif // MOVIETREE_HPP
