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

/*
 *Pre-condition:
 * There must be a csv file already indicated to open
 * Post-condition:
 * vector data member "movieList" of the Movies class is loaded with objects of the class Movie
 * vector data member "movieErrorList" of the Movies class is loaded with any errors from input file
 */

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

/*
 * Pre-condition:
 * vector data member "movieErrorList" must be loaded with input file errors
 * Post-condition:
 * data in "movieErrorList" vector has been output to new file
 */
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

/*
 * Pre-condition:
 * vector data member "movieList" of class Movies must be loaded with data from input file, which are
 * now objects of the class Movie
 * Post-condition:
 * specific data members (title, yearReleased, rating) of each object of the Movie class are output
 */
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

/*
 * Pre-condition:
 * 1.vector data member "movieList" of class Movies must be loaded with data from input file, which are
 * now objects of the class Movie
 * 2.user must provide title of movie
 * Post-condition:
 * specific data members (elements from Movie data member, starList vector) of each object of the
 * Movie class are output
 */
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

/*
 * Pre-condition:
 * 1. vector data member "movieList" of class Movies must be loaded with data from input file, which are
 * now objects of the class Movie
 * 2. user must provide name of movie star
 * Post-condition:
 * specific data member (title) of each object of the
 * Movie class are output which name of movie star input is present in
 */

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

/*
 * Pre-condition:
 * 1. object of the class Movies must be declared
 * 2. object previously declared must call readData() function
 * Post-condition:
 * menu options are printed for user to select
 */
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