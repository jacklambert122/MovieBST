# Movie Rental BST

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

## Purpose
Create a class that stores movie inventory data in a binary search tree, sorted by the movies title name. This class will allow a user to input inventory from a text file as well as the ability to add movies using a command line interface. The class will facilitate store nodes representing movies in a binary search tree in POST ORDER and will maintain this structure as trees are added and removed. This class will allow the user to update the inventory as movies are rented. This class will also allow the the user to print the contentents of the tree. Lastly, this class will also have a method to recieve the movie inventory movie count.

The overall purpose of storing the movie inventory in a BST is the assumption that the tree will be mostly balanced so that search, insertion and deletion times are near O(log(N)). This could me modified to be a AVL tree so there could be no instance of naive user input causing O(N) worst case for search, insertion and deletion into the tree.

## Command Line Inputs
- Text file with movie intventory (optional - can build from cmdline)
    - format: rank, title, year, quantity

## User Interface Inputs
1. findMovie
    - Movie title

2. rentMovie
    - Movie title

3. printInventory
    - None

4. removeMovieFromInventory
    - Movie title

5. countMovies
    - None

6. quit
    - None

## User Interface Outputs
1. findMovie
    - Status on finding movie
    - Movie ranking
    - Movie title
    - Movie year
    - Movie quantity

2. rentMovie
    - Status on renting movie
    - Movie ranking
    - Movie title
    - Movie year
    - Movie quantity

3. printInventory
    - Movie
    - Quantity

4. removeMovieFromInventory
    - Movie title

5. countMovies
    - Total movie inventory count

6. quit
    - None

## CMAKE Build:

### For Mac: 
```sh
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
make all
```

### Run:
```sh
./src/MovieBST_run [Movies.txt]
```

### Run w/ Example Movies.txt:
```sh
../src/MovieBST_run ../inc/Movies.txt
```
