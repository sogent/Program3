//
// Created by Sarah Ogent on 11/7/21.
//

#include "Movie.h"
#include <iostream>
#include <vector>

using namespace std;

//default constructor
Movie::Movie(){
title="";
director="";
rating=0;
genre="";
duration=0;
yearReleased=0000;

}


//setters
void Movie::SetTitle(string movieTitle){
    title=movieTitle;
}
void Movie::SetDuration(int movieDuration){
    duration=movieDuration;
}
void Movie::SetDirector(string movieDirector){
    director=movieDirector;
}
void Movie::SetRating(int movieRating){
    rating=movieRating;
}
void Movie::SetGenre(string movieGenre){
    genre=movieGenre;
}

void Movie::SetYearReleased(int movieYearReleased){
    yearReleased=movieYearReleased;
}









//getters
string Movie::GetTitle(){
    return title;
}
int Movie::GetDuration(){
    return duration;
}
string Movie::GetDirector(){
    return director;
}
int Movie::GetRating(){
    return rating;
}
string Movie::GetGenre(){
    return genre;
}

int Movie::GetYearReleased(){
    return yearReleased;
}





