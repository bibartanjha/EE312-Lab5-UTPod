#include <cstdlib>
#include <iostream>
#include <string>
#include "UtPod.h"

using namespace std;

//This is my default constructor for the UtPod
UtPod::UtPod()
{
    songs = NULL;
    memSize = MAX_MEMORY;

}


//This is my constructor for a UtPod that 
//wants to set a certain memory size
UtPod::UtPod(int size)
{
    int temp_Size = size;
    if ((size > 512) || (size <= 0))
    {
        temp_Size = 512;
    }
    songs = NULL;
    memSize = temp_Size;
}


//This is to check if the UtPod
//can add another song.It traverses
//through the linked list to check
int UtPod::getRemainingMemory()
{
    int memoryUsed = 0;
    SongNode* ptr = songs;

    while (ptr != NULL)
    {
        memoryUsed = memoryUsed + ptr -> s.getSize();
        ptr = ptr -> next;
    }

    return (memSize - memoryUsed);

}
//Post-condition:Returns how much
//memory is left if it adds the song

//This is the method to add a song
//at the head of the linked list
int UtPod::addSong(Song const &s)
{
    Song temp = s;

    //If the song has too much memory,it won't add
    //it
    if (getRemainingMemory() - temp.getSize() >= 0)
    {

        SongNode *x = new SongNode;
        x -> s = s;
        x -> next = songs;
        songs = x;
        return SUCCESS;
    }
    return NO_MEMORY;
}
//Post-condition:song is added at
//head of linked list


//This is the function to remove a song
//from the linked list
int UtPod::removeSong(Song const &s)
{
    //If the UtPod is empty,then
    //there aren't any songs
    if(songs == NULL){
       return NOT_FOUND;
    }
    
    SongNode* ptr = songs;
    SongNode* trail = NULL;

    while ((ptr != NULL) && !(ptr->s == s))
    {
        trail = ptr;
        ptr = ptr -> next;
    }

    //if the song isn't there,
    //then return -2
    if(ptr == NULL)
    {
        return NOT_FOUND;
    }

    //This is if the song to remove
    //is at the head of the linked list
    if(songs->s == s)
    {
        songs = songs->next;
        delete ptr;

    }

    else
    {

        trail -> next = ptr -> next;
        delete ptr;


    }
    return SUCCESS;
}
//Post-condition:the song is successfully deleted from the Linked List

//this randomizes the songs in the linked list
void UtPod::shuffle ()
{
    int totalSongs = 0;
    SongNode* ptr = songs;

    while (ptr != NULL)
    {
        totalSongs ++;
        ptr = ptr -> next;
    }
    
    //no point in shuffling if you have
    //1 or 0 songs
    if ((totalSongs == 0) || (totalSongs == 1))
    {
        return;
    }

    int shuffleLoop = 0;

    //I randomize the songs by how many songs
    //are in the UtPod
    for(shuffleLoop = 0; shuffleLoop < totalSongs; shuffleLoop++)
    {
        int rand1 = 0;
        int rand2 = 0;
        //Want to make sure rand1 and rand2 are different
        while(rand1 == rand2)
        {

            rand1 = rand() % totalSongs;
            rand2 = rand() % totalSongs;
        }

        SongNode* ptr1 = songs;
        SongNode* ptr2 = songs;
        int i = 0;
        for (i = 0; i < rand1; i ++)
        {
            ptr1 = ptr1 -> next;
        }

        for (i = 0; i < rand2; i ++)
        {
            ptr2 = ptr2 -> next;
        }

        //this is how I interchange the songs
        Song temp = ptr1->s;
        ptr1->s = ptr2->s;
        ptr2->s = temp;


    }
}
//Post-condition:the songs in the UtPod are
//randomized

//this method basically prints out the linked list
void UtPod::showSongList()
{
    SongNode *ptr = songs;
    while(ptr != NULL)
    {
        cout << ptr->s.getTitle() << ", " << ptr->s.getArtist() << ", " << ptr->s.getSize() << endl;
        ptr = ptr->next;

    }
}


//this method sorts the songs by artist,title,then 
//memory size
void UtPod::sortSongList()
{
    int totalSongs = 0;
    SongNode* ptr = songs;

    while (ptr != NULL)
    {
        totalSongs ++;
        ptr = ptr -> next;
    }


    //****** I SORT THE LINKED LIST VERY SIMILAR TO HOW I WOULD SORT AN ARRAY ******

    int i;
    int j;

    for (i = 0; i < totalSongs; i ++) {
        int smallestIndex = i;

        for (j = i; j < totalSongs; j++) {
            SongNode *ptr1 = songs; //will point to SongNode at index j
            int k = 0;
            for (k = 0; k < j; k++) {
                ptr1 = ptr1->next;
            }

            SongNode *ptr2 = songs; //will point to SongNode at index smallestIndex
            int l = 0;
            for (l = 0; l < smallestIndex; l++) {
                ptr2 = ptr2->next;
            }

            if (ptr1->s < ptr2->s) //if Song at index j is less than song at index smallestIndex
            {
                smallestIndex = j;
            }
        }

        //swap Song at index i with Song at index smallestIndex
        SongNode *ptr3 = songs; //will point to SongNode at index i
        int k = 0;
        for (k = 0; k < i; k++) {
            ptr3 = ptr3->next;
        }

        SongNode *ptr4 = songs; //will point to SongNode at index smallestIndex
        int l = 0;
        for (l = 0; l < smallestIndex; l++) {
            ptr4 = ptr4->next;
        }

        //this is when I swap
        Song temp = ptr3->s;
        ptr3->s = ptr4->s;
        ptr4->s = temp;

    }













     /*
        for (int j = i; j < totalSongs; j ++)
        {
            if (array[j] < array[smallestIndex])
            {
                smallestIndex = j;
            }
        }

        int temp = array [i];
        array [i] = array [smallestIndex];
        array [smallestIndex] = temp;
    }

    */

    /*
     *
     *  SongNode* ptr1 = songs; //will point to Song at index i
        int k = 0;
        for (k = 0; k < i; k ++)
        {
            ptr1 = ptr1 -> next;
        }
     *
     *
     *
     *
     *
     *
     *
    for(i = 0; i < totalSongs; i ++)
    {
        SongNode* ptr1 = songs; //will point to Song at index i
        int k = 0;
        for (k = 0; k < i; k ++)
        {
            ptr1 = ptr1 -> next;
        }

        int smallestIndex = i;

        for (j = i; j < totalSongs; j ++)
        {
            SongNode* ptr2 = songs; //will point to Song at index j
            int l = 0;
            for (l = 0; l < j; l ++)
            {
                ptr2 = ptr2 -> next;
            }




        }
    }

     */
}
//Post-Condition:the songs are successfully sorted

void UtPod::clearMemory()
{  if(songs == NULL)
   {
      delete songs;
   }
  else{ 
   SongNode *temp1 = songs->next;
   while(temp1 != NULL)
   {
      songs->next = temp1->next;
      temp1->next = NULL;
      delete temp1;
      temp1 = songs->next;
    }
   delete songs;
  }
}

//in the destructor,I delete the linked list
UtPod::~UtPod()
{
   /* SongNode *temp1 = songs->next;
    while(temp1 != NULL){
        songs->next = temp1->next;
        temp1->next = NULL;
        delete temp1;
        temp1 = songs->next;
    }
    delete songs;
*/
    clearMemory();
}
//Post-condition:no memory leaks

