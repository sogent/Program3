//
// Created by Sarah Ogent on 11/7/21.
//

#include "Movies.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Movies.h"
using namespace std;

int Movies::loadMovies (){
    ifstream inFile;
    int duration, rating, yearReleased;
    inFile.open("/Users/sogent/Downloads/movieList (1).csv");
    Movie tempMovie;
    vector <string> row;
    string type, inLine, sstream, word, title, director, genre, star1, star2, star3;


    while (getline(inFile, inLine)){
        type = inLine.substr(0,1);

        if (type == "M"){
            row.clear();
            stringstream inSS(inLine);

            while (getline(inSS, word, ',')){
                row.push_back(word);
            }


            try{
                title = row[1];

                director=row[2];

                rating=stoi(row[3]);

                genre=row[4];

                duration =  stoi(row[5]);

                yearReleased=stoi(row[6]);

                star1=row[7];

                star2=row[8];

                star3=row[9];

                row[9].clear();

            }
            catch (invalid_argument& e){
                cout << e.what() << " can not be converted to int" << endl;
                return -1;
            }
            //setting all the data members then pushing onto vector that holds Movie objects
            tempMovie.SetTitle(title);
            tempMovie.SetDirector(director);
            tempMovie.SetRating(rating);
            tempMovie.SetGenre(genre);
            tempMovie.SetDuration(duration);
            tempMovie.SetYearReleased(yearReleased);
            tempMovie.addStar(star1);
            tempMovie.addStar(star2);
            tempMovie.addStar(star3);
            movieList.push_back(tempMovie);
            movieCount += 1;

        }

    }

    return 0;
}


void Movies::getMovie (string t){
    for (int i = 0; i < movieList.size(); i++){
        if (movieList.at(i).GetTitle() == t){
            cout << movieList.at(i).GetTitle() << endl;
        }
    }
}



void Movies::printMovies (){
Movie movies;

for (int i = 0; i < movieList.size(); i++) {

    movies = movieList.at(i);

    cout << movieList.at(i).GetTitle() << endl;
    cout << movieList.at(i).GetDirector() << endl;
    cout << movieList.at(i).GetRating() << endl;
    cout << movieList.at(i).GetGenre() << endl;
    cout << movieList.at(i).GetDuration() << endl;
    cout << movieList.at(i).GetYearReleased() << endl;

    //how the f do I print the list of movie stars out
    for(int i=0;i<movies.starList.size();++i){
        cout<<movies.starList.at(i)<<endl;



    }

  }

}
