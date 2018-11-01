#include <cstdlib>
#include <iostream>
#include <string>

#ifndef SONG_H
#define SONG_H

using namespace std;

class Song
{
    private:

    string title;
    string artist;
    int memSize;

public:

    Song();
    Song(string _artist, string _title, int _memSize);

    string getTitle();
    void setTitle(string _title);

    string getArtist();
    void setArtist(string _artist);

    int getSize();
    void setSize(int _size);

    bool operator ==(Song const &rhs);
    bool operator >(Song const &rhs);
    bool operator <(Song const &rhs);



};

#endif