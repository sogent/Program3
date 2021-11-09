//
// Created by Sarah Ogent on 11/7/21.
//
#include <string>
#include <vector>
#include "Movie.h"
using namespace std;


#ifndef PROGRAM3A_MOVIES_H
#define PROGRAM3A_MOVIES_H

class Movies {
public:
    int loadMovies ();
    void printMovies();
    void getMovie (string t);
    static int movieCount;


    vector <Movie> movieList;
};
#endif //PROGRAM3A_MOVIES_H
