#include <iostream>
#include <string>
#include <cassert>

class MediaItem {
public:
    MediaItem(const std::string& title) {
        this->title = title;
    }

    std::string getTitle() const {
        return title;
    }

private:
    std::string title;
};

class Song : public MediaItem {
public:


    Song(const std::string& title, const std::string& artist);


    void stream() {

        nbStrems++;

    };

    std::string getArtist() const {

        return artist;

    };

    int getStreamCount() {
    
        return nbStrems;
    
    };




private:

    std::string artist;
    int nbStrems;

};


Song::Song( const std::string& title, const std::string& artist) : MediaItem(title) {

    this -> artist = artist;
    nbStrems = 0;
};

void runTests() {
    // Title and artist are set correctly
    Song s1("Copacabanana", "Sean Banan");
    assert(s1.getTitle() == "Copacabanana");
    assert(s1.getArtist() == "Sean Banan");

    // Stream count starts at 0
    Song s2("Copacabanana", "Sean Banan");
    assert(s2.getStreamCount() == 0);

    // One stream counted correctly
    Song s3("Copacabanana", "Sean Banan");
    s3.stream();
    assert(s3.getStreamCount() == 1);

    // Multiple streams counted correctly
    Song s4("Copacabanana", "Sean Banan");
    s4.stream();
    s4.stream();
    assert(s4.getStreamCount() == 2);

    // Streaming one song doesn't affect another
    Song s5("Copacabanana", "Sean Banan");
    Song s6("Gangnam Style", "PSY");
    s5.stream();
    s5.stream();
    s5.stream();
    assert(s5.getStreamCount() == 3);
    assert(s6.getStreamCount() == 0);

    // Different songs have correct titles and artists
    Song s7("Gangnam Style", "PSY");
    assert(s7.getTitle() == "Gangnam Style");
    assert(s7.getArtist() == "PSY");

    std::cout << "All tests passed!" << std::endl;
}


int main()
{
    Song s("Copacabanana", "Sean Banan");
    s.stream();
    s.stream();
    s.stream();
    std::cout << s.getTitle() << " of " << s.getArtist() << " has been streamed "
        << s.getStreamCount() << " times." << std::endl;

    runTests();
}
