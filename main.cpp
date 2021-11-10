#include <iostream>
#include "Movies.h"
using namespace std;

int Movies::movieCount = 0;

int main() {

    Movies myMovies;

    myMovies.loadMovies();
    cout<<"There are: " << Movies::movieCount << " movies in my library" << endl;
    cout<<endl;
    myMovies.printMovies();

}