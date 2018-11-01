
#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    
    /*Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    t.showSongList();
          
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();

    cout << endl;

    t.shuffle();

    t.showSongList();

    t.sortSongList();

    cout << endl;

    t.showSongList();

    cout << endl;
    
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    cout << endl << endl << endl;

    UtPod test(-212);

    cout << test.getTotalMemory() << endl;

*/
    Song one("Senteon_Void","Bilal",2);
    Song two("Clayman","InFlames",3);
    Song three("Neverwhere","AttheGates",4);
    Song four("TheSeedofEye","Behemoth",5);
    Song five("BulletRide","InFlames",6);
    Song six("BulletRide","InFlames",500);

    t.addSong(one);
    t.addSong(two);
    t.addSong(three);
    t.addSong(four);
    t.addSong(five);
    t.addSong(six);

    t.showSongList();
    cout << endl << "------------TEST SHOW SONG------------" << endl << endl;

    t.shuffle();
    t.showSongList();
    cout << endl << "------------TEST SHUFFLE--------------" << endl << endl;

    t.sortSongList();
    cout << endl;
    t.showSongList();
    cout << endl << "-------------TEST SORT-------------" << endl << endl;

    t.removeSong(three);
    cout << endl;
    t.showSongList();
    cout << endl << "-------------TEST REMOVE-----------" << endl << endl;
/*
    t.shuffle();

    cout << endl;

    t.showSongList();

    t.sortSongList();

    cout << endl;

    t.showSongList();
*/
    t.addSong(three);
    t.addSong(one);
    t.addSong(two);
    t.addSong(four);
    t.shuffle();
    cout << endl;
    t.showSongList();
    cout << endl <<  "----------TEST SHUFFLE 2----------" << endl << endl;

    t.addSong(six);
    t.showSongList();
    cout << endl;
    cout << "----------TEST CAN'T ADD SONG--------" << endl << endl;
    
    t.sortSongList();
    t.showSongList();
    cout << endl;
    cout << "----------TEST SORT 2---------" << endl << endl;

    t.removeSong(five);
    t.removeSong(three);
    cout << endl;    
    t.showSongList();
    cout << endl << "----------TEST REMOVE SONGS-------" << endl << endl;

    t.removeSong(six);
    t.showSongList();
    cout << endl << "---------REMOVE SONG NOT IN POD--------" << endl << endl;

    Song x("Aerosmith","Dream On",212);
    t.removeSong(x);
    cout << endl;
    t.showSongList();
    cout << endl << "---------REMOVE SONG NOT IN POD 2--------" << endl << endl;

    cout << endl << six.getArtist() << " " << six.getTitle() << " " << six.getSize() << endl;
    cout << endl << "-------------TEST SONG GET FUNCTIONS---------" << endl << endl;

    six.setArtist("Andrew");
    six.setTitle("Brown");
    six.setSize(212);

    cout << six.getArtist() << " " << six.getTitle()<< " " << six.getSize() << endl;
    cout << endl << "-------------TEST SONG SET FUNCTIONS---------" << endl << endl;

    UtPod pod(300);
 
    cout << pod.getTotalMemory() << endl;
    cout << endl << "--------TEST GET TOTAL MEMORY---------" << endl << endl;

    pod.addSong(x);
    pod.showSongList();
    cout << endl << pod.getRemainingMemory() << endl;
    cout << endl << "--------TEST GET REMAIN MEMORY--------" << endl << endl;

    cout << endl << "************ALL FUNCTIONS HAVE BEEN TESTED************" << endl;
}
