// Braden Means
// Project 3
// 10/19/18

#include <iostream>
#include <string>
#include "PlaylistNode.h"
using namespace std;

void PrintMenu(string playlistName) {
	string ID, song, artist;
	int length;
	int totalTime = 0;
	int songPos;
	int newPos = 0;
	int numNodes = 0;
	char choice = '1';
	PlaylistNode *newNode = NULL;
	PlaylistNode *curr = NULL;
	PlaylistNode *head = NULL;
	PlaylistNode *prev = NULL;
	PlaylistNode *tail = NULL;
	PlaylistNode *newPosNode = NULL;


	
	while (choice != 'q') {
		cout << playlistName << " PLAYLIST MENU" << endl;
		cout << "a - Add song" << endl;
		cout << "d - Remove song" << endl;
		cout << "c - Change position of song" << endl;
		cout << "s - Output songs by specific artist" << endl;
		cout << "t - Output total time of playlist (in seconds)" << endl;
		cout << "o - Output full playlist" << endl;
		cout << "q - Quit" << endl << endl;
		cout << "Choose an option:" << endl;
		cin >> choice;

		if (choice == 'a') {
			cout << "ADD SONG" << endl;
			cout << "Enter song's unique ID:" << endl;
			cin >> ID;
			cin.ignore();
			cout << "Enter song's name:" << endl;
			getline(cin, song);
			cout << "Enter artist's name:" << endl;
			getline(cin, artist);
			cout << "Enter song's length (in seconds):" << endl;
			cin >> length;
			cout << endl;

			newNode = new PlaylistNode(ID, song, artist, length);
			
			if (head == NULL) {
				head = newNode;
				tail = newNode;
			}
			else {
				tail->InsertAfter(newNode);
				tail = tail->GetNext();
			}
		}
		if (choice == 'd') {
			cout << "REMOVE SONG" << endl;
			cout << "Enter song's unique ID:" << endl;
			cin >> ID;

			curr = head;
			prev = head;

			while (curr) {
				if (curr->GetID() == ID) {
					cout << '"' << curr->GetSongName() << '"' << " removed." << endl << endl;
					if (curr == head) {
						head = head->GetNext();

						if (curr == tail) {
							tail = NULL;
						}
					}
					else if (tail == curr) {
						tail = prev;
						tail->SetNext(NULL);
					}
					else {
						prev->SetNext(curr->GetNext());
					}
				}
				prev = curr;
				curr = curr->GetNext();
			} 
		}
		if (choice == 't') {
			cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
			curr = head;

			while (curr) {
				totalTime = totalTime + curr->GetSongLength();
				curr = curr->GetNext();
			}
			cout << "Total time: " << totalTime << " seconds" << endl << endl;
		}

		if (choice == 's') {
			cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
			cout << "Enter artist's name:" << endl;
			cin.ignore();
			getline(cin, artist);
			cout << endl;

			numNodes = 1;
			curr = head;

			while (curr) {
				if (artist == curr->GetArtistName()) {
					cout << numNodes << "." << endl;
					curr->PrintPlaylistNode();
					cout << endl;
				}
				curr = curr->GetNext();
				numNodes++;
			}
		}
		
		if (choice == 'o') {
			numNodes = 1;

			cout << playlistName << " - OUTPUT FULL PLAYLIST" << endl;
			curr = head;
		
			if (head == NULL) {
				cout << "Playlist is empty" << endl << endl;
			}
			else {
				while (curr) {
					cout << numNodes << "." << endl;
					curr->PrintPlaylistNode();
					cout << endl;
					curr = curr->GetNext();
					numNodes++;
				}
			}
		}
		if (choice == 'c') {
			cout << "CHANGE POSITION OF SONG" << endl;
			cout << "Enter song's current position:" << endl;
			cin >> songPos;
			cout << "Enter new position for song:" << endl;
			cin >> newPos;

			curr = head;

			numNodes = 0;

			while ((curr != NULL) && (numNodes < (songPos - 1))) {
				numNodes++;
				curr = curr->GetNext();
			}
			if (curr == head) {
				head = curr->GetNext();
			}
			else {
				prev = head;
				while (prev->GetNext() != curr) {
					prev = prev->GetNext();
				}
				prev->SetNext(curr->GetNext());
				if (curr == tail) {
					tail = prev;
				}
			}
			if (newPos <= 1) {
				curr->SetNext(head);
				head = curr;

				cout << '"' << curr->GetSongName() << '"' << " moved to position 1" << endl << endl;

			}
			else {
				newPosNode = head;
				numNodes = 0;

				while ((newPosNode != NULL) && ((numNodes + 2) < newPos)) {
					newPosNode = newPosNode->GetNext();
					numNodes++;
				}
				if (newPosNode == NULL) {
					tail->InsertAfter(curr);
					tail = curr;
					newPos = numNodes + 1;
				}
				else {
					newPosNode->InsertAfter(curr);
					newPos = numNodes + 2;
				}

				if (tail == newPosNode) {
					tail = curr;
				}
				cout << '"' << curr->GetSongName() << '"' << " moved to position " << newPos << endl << endl;
			}
			while (choice != 'c' && choice != 'd' && choice != 'i' && choice != 'o' && choice != 'a' && choice != 'q') {
				cout << "Choose an option:" << endl;
				cin >> choice;
			}
		}
	}

}

int main(void) {
	string playlistName;

	cout << "Enter playlist's title:" << endl << endl;
	getline(cin, playlistName);
	PrintMenu(playlistName);

}