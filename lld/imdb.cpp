#include <bits/stdc++.h>
#include <stdexcept>

int uuidGen=0;

using namespace std;

int getUUID(){
    return uuidGen++;
}

enum Status {BOOKED, AVAILABLE, PENDING};

class Seat{
    int seatNo;
    int status;

};

class CinemaHall{
    public:
    string name;
    int seatingCapacity;
    string desc;
};

class Cinema{
    public:
    string name;
    string city;
    vector<CinemaHall> cinemaHalls;
    vector<Show> shows;
};


class Movie{
    public:
    string title;
    string language;
    string genre;
    string rating;
    string releaseDate;
    int duration;
};


class Show{
    
    string movieId;
    string cinemaHallId;
    string dateTime;
    string duration;
    vector<Seat> seats;


};

class Booking{
    int bookingId;
    Status bookingStatus;
    vector<Seat> seats;
    string time;
};

class Search{
    public:
    virtual vector<Movie> searchByTitle(string title)=0;
    virtual vector<Movie> searchByLanguage(string language)=0;
    virtual vector<Movie> searchByGenre(string genre)=0;
};

class Catalog : public Search{
    public: 
    map<int, Movie> movies;
    map<string, vector<int>> movieTitles;
    map<string, vector<int>> movieLanguages;
    map<string, vector<int>> movieGenre;

    vector<Movie> searchByTitle(string title) override {
        vector<Movie> movieResults;
        for(auto movieId:movieTitles[title])
            movieResults.push_back(movies[movieId]);
        return movieResults;    
    }

    vector<Movie> searchByLanguage(string language) override {
        vector<Movie> movieResults;
        for(auto movieId:movieLanguages[language])
            movieResults.push_back(movies[movieId]);
        return movieResults;    
    }

    vector<Movie> searchByGenre(string genre) override {
        vector<Movie> movieResults;
        for(auto movieId:movieGenre[genre])
            movieResults.push_back(movies[movieId]);
        return movieResults;    
    }    

    void addMovie(Movie movie){
        int uuid = getUUID();
        movies[uuid] = movie;
        movieTitles[movie.title].push_back(uuid);
        movieLanguages[movie.language].push_back(uuid);
    }

};

class MTBS{
    public: 
    string name;
    string desc;

    map<string, Cinema> cinemas;
    map<string, Show> shows;
    Catalog movieCatalog;
    vector<Booking> bookings;
    vector<Movie> searchMovie;
};


int main(){
    MTBS mtbs = MTBS();
    return 0;
}