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



    if(i==0){
        cout<<movies.starList.at(0)<<endl;
        cout<<movies.starList.at(1)<<endl;
        cout<<movies.starList.at(2)<<endl;

    }

    if(i==1){
        cout<<movies.starList.at(3)<<endl;
        cout<<movies.starList.at(4)<<endl;
        cout<<movies.starList.at(5)<<endl;
        cout<<endl;

    }

    if(i==2){
        cout<<movies.starList.at(6)<<endl;
        cout<<movies.starList.at(7)<<endl;
        cout<<movies.starList.at(8)<<endl;
        cout<<endl;
    }

    if(i==3){
        cout<<movies.starList.at(9)<<endl;
        cout<<movies.starList.at(10)<<endl;
        cout<<movies.starList.at(11)<<endl;
        cout<<endl;
    }

    if(i==4){
        cout<<movies.starList.at(12)<<endl;
        cout<<movies.starList.at(13)<<endl;
        cout<<movies.starList.at(14)<<endl;
        cout<<endl;
    }

    if(i==5){
        cout<<movies.starList.at(15)<<endl;
        cout<<movies.starList.at(16)<<endl;
        cout<<movies.starList.at(17)<<endl;
        cout<<endl;
    }

    if(i==6){
        cout<<movies.starList.at(18)<<endl;
        cout<<movies.starList.at(19)<<endl;
        cout<<movies.starList.at(20)<<endl;
        cout<<endl;
    }

    if(i==7){
        cout<<movies.starList.at(21)<<endl;
        cout<<movies.starList.at(22)<<endl;
        cout<<movies.starList.at(23)<<endl;
        cout<<endl;
    }

    if(i==8){
        cout<<movies.starList.at(24)<<endl;
        cout<<movies.starList.at(25)<<endl;
        cout<<movies.starList.at(26)<<endl;
        cout<<endl;
    }














    //how the f do I print the list of movie stars out per object on the vector









  }



}
