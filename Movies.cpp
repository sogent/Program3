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
#include <iomanip>
#include <fstream>
using namespace std;

int Movies::readData (){


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
                //tempStars vector<string>;
                //for (int i = 7; i < row.size(); i ++){
                //   tempStars.push_back(row[i]);
                // }


                star1=row[7];

                star2=row[8];

                star3=row[9];

                row[9].clear();

            }
            catch (invalid_argument& e){
                movieErrorList.push_back(inLine);
                movieErrorList.emplace_back(e.what());
                continue;
            }
            //setting all the data members then pushing onto vector that holds Movie objects
            tempMovie.starList.push_back(star1);
            tempMovie.starList.push_back(star2);
            tempMovie.starList.push_back(star3);

            tempMovie.SetTitle(title);
            tempMovie.SetDirector(director);
            tempMovie.SetRating(rating);
            tempMovie.SetGenre(genre);
            tempMovie.SetDuration(duration);
            tempMovie.SetYearReleased(yearReleased);
            //tempMovie.starList = tempStars;
            //tempMovie.addStar(star1, star2, star3);
            //tempMovie.addStar(star2);
            //tempMovie.addStar(star3);
            movieList.push_back(tempMovie);
            //this line ensures that the stars are being pushed on their own vector
            //instead of having the data from the previous loop included
            tempMovie.starList.clear();
            movieCount+=1;

        }

    }
    return 0;
}


void Movies::outputMovieErrorLog(){
    Movies myMovies;
    myMovies.readData();
    //Outputting error(s) to new file
    ofstream outFS;
    outFS.open("MovieListErrorReport.txt");
    if (!outFS.is_open()) {
        cout << "Could not open the file \"MovieListErrorReport.txt\"" << endl;
    }
    while(outFS.is_open()){
        outFS<<"ERROR: ";
        outFS<<movieErrorList.at(0)<<endl;
        outFS<<"Previous record has an "<<movieErrorList.at(1)<<" error"<<endl;
        outFS.close();
    }

}


void Movies::printMovieList () {
    Movie movies;
    cout<<"YOUR MOVIE LIST"<<endl;
    cout<<endl;
    cout<<"#"<<setw(16)<<"TITLE"<<setw(17)<<"YEAR"<<setw(10)<<"RATING"<<endl;
    for (int i = 0; i < movieList.size(); i++) {

        cout <<i+1<<" "<<setw(27)<<left<< movieList.at(i).GetTitle()<<" ";
        cout <<movieList.at(i).GetYearReleased()<<"      ";
        cout << movieList.at(i).GetRating();
        cout << endl;
    }
    cout<<endl;
}

void Movies::listMovieStars() {
    string userInput;
    cout << "Enter the Movie's title: ";
    try {
        getline(cin, userInput);

        vector<int>foundIndex;
        int matchCount=0;
        for(int i=0;i<movieList.size();++i) {
                int found=userInput.find(movieList.at(i).GetTitle());
                if(found==-1){
                    matchCount+=1;
                }
                //if the string is not found, then it will return a -1
                //since each movie is being traversed, it will
                //output a total equivalent to the number of movies

                foundIndex.push_back(found);

        }

            if(matchCount==movieList.size()){
                throw runtime_error("is not found in your movie library");
            }

        cout << "THE STARS OF THE MOVIE \"" << userInput << "\" ARE:" << endl;
        cout << "{";
        cout << setfill('=') << setw(50);
        cout << "}" << endl;
        cout << setfill(' ');

        for (int i = 0; i < movieList.size(); ++i) {
            if (userInput == movieList.at(i).GetTitle()) {
                cout << movieList.at(i).starList.at(0) << endl;
                cout << movieList.at(i).starList.at(1) << endl;
                cout << movieList.at(i).starList.at(2) << endl;
            }
        }

        cout << "{";
        cout << setfill('=') << setw(50);
        cout << "}" << endl;
        cout << setfill(' ');
        cout << endl;
    } catch (runtime_error &inputError) {
            cout<<"Sorry, but the movie: \""<< userInput <<"\" "<<inputError.what()<<endl;
            cout<<endl;
    }
}



void Movies::findMovie(){
    string userInput;
    cout<<"Enter the Star's name: ";
    try {
        getline(cin, userInput);

        int matchCount=0;
        for(int i=0;i<movieList.size();++i) {
            int found1=userInput.find(movieList.at(i).starList.at(0));
            int found2=userInput.find(movieList.at(i).starList.at(1));
            int found3=userInput.find(movieList.at(i).starList.at(2));
            if(found1==-1){
                matchCount+=1;
            }
            if(found2==-1){
                matchCount+=1;
            }
            if(found3==-1){
                matchCount+=1;
            }
            //if the string is not found, then it will return a -1
            //since each movie is being traversed, it will
            //output a total equivalent to the number of movies
        }

            if(matchCount>=19){
                throw runtime_error("is not found in any movies in your movie library");
            }

            cout << endl;
            cout << "{";
            cout << setfill('=') << setw(50);
            cout << "}" << endl;
            cout << setfill(' ');
            cout << userInput << " appears in the following movie(s):" << endl;

            for (int i = 0; i < movieList.size(); ++i) {
                if (userInput == movieList.at(i).starList.at(0)) {

                    cout << movieList.at(i).GetTitle() << endl;

                } else if (userInput == movieList.at(i).starList.at(1)) {

                    cout << movieList.at(i).GetTitle() << endl;

                } else if (userInput == movieList.at(i).starList.at(2)) {

                    cout << movieList.at(i).GetTitle() << endl;
                }

            }
            cout << "{";
            cout << setfill('=') << setw(50);
            cout << "}" << endl;
            cout << setfill(' ');
            cout << endl;
        }catch(runtime_error& inputError){
            cout<<"Sorry, but the star: \""<<userInput<<"\" "<<inputError.what()<<endl;
            cout<<endl;
    }
}


void Movies::printMenuOptions(){
    Movies myMovies;
    myMovies.readData();

    bool run=true;
    while(run) {
        try {
            cout << setw(18) << right << "MENU CHOICES" << endl;
            cout << "M - Print Movie List" << endl;
            cout << "S - Print Stars for a Given Movie" << endl;
            cout << "F - Find the Movie the Star is in" << endl;
            cout << "Q - Quit" << endl;
            cout << endl;
            cout << "Enter your choice: ";
            char userInput;
            char userInput1;

            cin>>userInput1;
            userInput= toupper(userInput1);

            cout << "You have entered: " << userInput << endl;
            cout << endl;
            cin.ignore();

            if (userInput == 'M') {
                myMovies.printMovieList();

            } else if (userInput == 'S') {
                myMovies.listMovieStars();

            } else if (userInput == 'F') {
                myMovies.findMovie();

            } else if (userInput == 'Q') {
                run = false;

            }else{
                throw runtime_error("Invalid input, please try again");
            }


        }catch(runtime_error& inputError){
            cout<<inputError.what()<<endl;
            cout<<endl;
        }
    }
}