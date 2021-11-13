//
// Created by Sarah Ogent on 11/7/21.
//

#include "Movie.h"
#include <iostream>
#include <vector>

using namespace std;

//setters
/*
 * Pre-condition:
 *movieTitle must be string
 * Post-condition:
 * data member title is set to the value of the input argument
 */
void Movie::SetTitle(string movieTitle){
    title=movieTitle;
}

/*
 * Pre-condition:
 *movieDuration must be int
 * Post-condition:
 * data member duration is set to the value of the input argument
 */
void Movie::SetDuration(int movieDuration){
    duration=movieDuration;
}

/*
 * Pre-condition:
 * movieDirector must be string
 * Post-condition:
 * data member director is set to the value of the input argument
 */
void Movie::SetDirector(string movieDirector){
    director=movieDirector;
}

/*
 * Pre-condition:
 *movieRating must be int
 * Post-condition:
 * data member rating is set to the value of the input argument
 */
void Movie::SetRating(int movieRating){
    rating=movieRating;
}

/*
 * Pre-condition:
 *movieGenre must be string
 * Post-condition:
 * data member genre is set to the value of the input argument
 */
void Movie::SetGenre(string movieGenre){
    genre=movieGenre;
}

/*
 * Pre-condition:
 *movieYearReleased must be int
 * Post-condition:
 * data member yearReleased is set to the value of the input argument
 */
void Movie::SetYearReleased(int movieYearReleased){
    yearReleased=movieYearReleased;
}





//getters

/*
 * Pre-condition:
 * data member title must be set to string value
 * Post-condition:
 * value of title is returned
 */
string Movie::GetTitle(){
    return title;
}

/*
 * Pre-condition:
 * data member duration must be set to int value
 * Post-condition:
 * value of duration is returned
 */
int Movie::GetDuration(){
    return duration;
}

/*
 * Pre-condition:
 * data member director must be set to string value
 * Post-condition:
 * value of director is returned
 */
string Movie::GetDirector(){
    return director;
}

/*
 * Pre-condition:
 * data member rating must be set to string value
 * Post-condition:
 * value of rating is returned
 */
int Movie::GetRating(){
    return rating;
}

/*
 * Pre-condition:
 * data member genre must be set to string value
 * Post-condition:
 * value of genre is returned
 */
string Movie::GetGenre(){
    return genre;
}


/*
 * Pre-condition:
 * data member yearReleased must be set to string value
 * Post-condition:
 * value of yearReleased is returned
 */
int Movie::GetYearReleased(){
    return yearReleased;
}