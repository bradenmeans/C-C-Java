// Braden Means
// Project 3
// 10/19/18

#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H
#include <iostream>
#include <string>
using namespace std;


class PlaylistNode {
public:
	PlaylistNode();
	PlaylistNode(string ID, string song, string artist, int length);
	void InsertAfter(PlaylistNode* newNode);
	void SetNext(PlaylistNode *next) { nextNodePtr = next; };
	string GetID() const { return uniqueID; };
	string GetSongName() const { return songName; };
	string GetArtistName() const {return artistName;};
	int GetSongLength() const { return songLength; };
	PlaylistNode* GetNext() const { return nextNodePtr; };
	void PrintPlaylistNode();
private:
	string uniqueID;
	string songName;
	string artistName;
	int songLength;
	PlaylistNode* nextNodePtr;
};

#endif 