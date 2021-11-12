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
void Movie::addStar(string movieStar1, string movieStar2, string movieStar3){
  // starList.push_back(movieStar1);
   //starList.push_back(movieStar2);
   //starList.push_back(movieStar3);

}

//void Movie::SetStars()




void Movie::DisplayStars() {

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




void Movie::PrintMovie(){
    cout << "Movie: " << title << " : " << duration <<endl;
    int i;
    for(i=0;i<starList.size();++i){
        cout<<starList.at(i)<<endl;
    }

}


ostream& operator<<(ostream& out, Movie const& movie){
    out<<movie.title<<endl;
    out<<movie.director<<endl;
    out<<movie.rating<<endl;
    out<<movie.genre<<endl;
    out<<movie.duration<<endl;
    out<<movie.yearReleased<<endl;


    //copy(movie.starList.begin(), movie.starList.end(), ostream_iterator<string>(out, "\n"));

return out;

}