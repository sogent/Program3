#include <iostream>
#include "Movies.h"
#include <fstream>
using namespace std;

int Movies::movieCount = 0;

int main() {

    Movies myMovies;

    myMovies.readData();

    myMovies.outputMovieErrorLog();

    myMovies.printMenuOptions();











}