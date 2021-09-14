// Braden Means
// Project 3
// 10/19/18

#include <iostream>
#include <string>
#include "PlaylistNode.h"
using namespace std;

PlaylistNode::PlaylistNode() {
	uniqueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
	nextNodePtr = NULL;
}

PlaylistNode::PlaylistNode(string ID, string song, string artist, int length) {
	uniqueID = ID;
	songName = song;
	artistName = artist;
	songLength = length;
	nextNodePtr = NULL;
}

void PlaylistNode::InsertAfter(PlaylistNode* newNode) {
	PlaylistNode* temp = 0;
	
	temp = nextNodePtr;
	nextNodePtr = newNode;
	newNode->nextNodePtr = temp;
}



void PlaylistNode::PrintPlaylistNode() {
	cout << "Unique ID: " << GetID() << endl;
	cout << "Song Name: " << GetSongName() << endl;
	cout << "Artist Name: " << GetArtistName() << endl;
	cout << "Song Length (in seconds): " << GetSongLength() << endl;
}
