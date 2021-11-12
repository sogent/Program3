#include <iostream>
#include "Movies.h"
using namespace std;

int Movies::movieCount = 0;

int main() {

    Movies myMovies;

    myMovies.readData();
    cout<<"There are: " << Movies::movieCount << " movies in my library" << endl;
    cout<<endl;
    myMovies.printMovieList();

    //myMovies.listMovieStars();
    myMovies.printMenuOptions();








}