#include <cstdlib>
#include <iostream>
#include <string>
#include "song.h"

using namespace std;

//this is the default constructor for the song
Song::Song()
{
    title = "";
    artist = "";
    memSize = 0;
}

//this is the song constructor that initializes the 
//name of the artist,name of the title,and the size
//of the song
Song::Song(string _artist, string _title, int _memSize)
{
    title = _title;
    artist = _artist;
    memSize = _memSize;
}

//returns the title of the song
string Song::getTitle()
{
    return title;
}

//sets the title of the song
void Song::setTitle(string _title)
{
    title = _title;
}

//returns the name of the artist
string Song::getArtist()
{
    return artist;
}

//sets the name of the artist
void Song::setArtist(string _artist)
{
    artist = _artist;
}

//returns the amount of memory of the song
int Song::getSize()
{
    return memSize;
}

//sets the amount of memory of the song
void Song::setSize(int _size)
{
    memSize = _size;
}

//this method overrides the "==" operator to see if 
//2 songs are the same
bool Song::operator ==(Song const &rhs)
{
    if (artist == rhs.artist)
    {
        if (title == rhs.title)
        {
            if (memSize == rhs.memSize)
            {
                return true;
            }
        }
    }
    return false;
}
//returns true or false if the songs are the same

//this method overrides the ">" operator to see if
//one song is greater than another
bool Song::operator >(Song const &rhs)
{
    /*if(artist > rhs.artist)
    {
        return true;
    }

    else if (title > rhs.title)
    {
        return true;
    }

    else if (memSize > rhs.memSize)
    {
        return true;
    }

    return false;
*/
    if(artist > rhs.artist)
    {
        return true;
    }
    else if(artist < rhs.artist)
    {
        return false;
    }
    else{
        if(title > rhs.title)
        {
            return true;
        }
        else if(title < rhs.title)
        {
            return false;
        }
        else{
            if(memSize > rhs.memSize){
                return true;
            }
            else{
                if(memSize <= rhs.memSize){
                    return false;
                }
            }

        }
    }
    return false;

}
//returns true or false if lhs song is greater than the rhs song


//this method overrides the "<" operator to see if a song is less than another
bool Song::operator <(Song const &rhs)
{
    /*if(artist < rhs.artist)
    {
        return true;
    }

    else if (title < rhs.title)
    {
        return true;
    }

    else if (memSize < rhs.memSize)
    {
        return true;
    }

    return false;
*/
    if(artist < rhs.artist){
        return true;
    }
    else{
        if(artist > rhs.artist){
            return false;
        }
        else{
            if(title < rhs.title){
                return true;
            }
            else{
                if(title > rhs.title){
                    return false;
                }
                else{
                    if(memSize < rhs.memSize){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
    }

}
//returns true or false if lhs song is less than rhs song


