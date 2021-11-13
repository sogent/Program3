//
// Created by Sarah Ogent on 11/7/21.
//

#ifndef PROGRAM3A_MOVIE_H
#define PROGRAM3A_MOVIE_H
#include <string>
#include <vector>
using namespace std;

class Movie {

public:

    //setters
    void SetTitle(string movieTitle);
    void SetDirector(string movieDirector);
    void SetRating(int movieRating);
    void SetGenre(string movieGenre);
    void SetDuration(int movieDuration);
    void SetYearReleased(int movieYearReleased);


    //getters
    string GetTitle();
    string GetDirector();
    int GetRating();
    string GetGenre();
    int GetDuration();
    int GetYearReleased();
    vector<string> starList;
private:
    string title;
    string director;
    int rating;
    string genre;
    int duration;
    int yearReleased;
};
#endif //PROGRAM3A_MOVIE_H
