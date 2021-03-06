/*
Andrew Thomas
Project 2 - German-English Dictionary
Due 3/23
*/

#include "DictionaryFunctions.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	
	const int MAX_WORDS = 25;
	const string FILE_NAME = "GtoE_dict.txt";

	showMenu();
	
	int menuChoice = getMenuChoice(1, 9);

	vector<Word> wordList;
	vector<Noun> nounList;
	ifstream inFile;
	ofstream outFile;

	bool wordListCreated = false;

	inFile.open(FILE_NAME);

	if (inFile) {
		wordListCreated = true;
		readWordListFromFile(inFile, wordList, nounList);
	}

	string searchTerm;

	while (true) {
		switch (menuChoice) {
		case 1:
			if (!wordListCreated) {
				outFile.open(FILE_NAME);
				wordListBuilder(wordList, nounList);
				writeWordListToFile(outFile, wordList, nounList);
				wordListCreated = true;
			}
			else {
				cout << "Word list already created." << endl;
				_getch();
			}
			break;
		case 2:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				_getch();
				break;
			}
			findNouns(nounList);
			break;
		case 3:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				_getch();
				break;
			}
			findWordsByPartOfSpeech("Verb", wordList);
			break;
		case 4:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				_getch();
				break;
			}
			findWordsByPartOfSpeech("Preposition", wordList);
			break;
		case 5:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				_getch();
				break;
			}
			findWordsByPartOfSpeech("Adjective", wordList);
			break;
		case 6:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				_getch();
				break;
			}
			findWordsByPartOfSpeech("Adverb", wordList);
			break;
		case 7:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				_getch();
				break;
			}
			findWordsByPartOfSpeech("Cardinal Number", wordList);
			break;
		case 8:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				_getch();
				break;
			}
			cout << "Enter a word: ";
			searchTerm = wordBuilder();
			searchForWord(searchTerm, wordList, nounList);
			break;
		case 9:
			return 0;
		default: // SHOULD NEVER EVER HAPPEN 
			cout << "Oops, you broke it. Try a menu choice between 1 and 9 next time. Exiting..." << endl;
			system("pause");
			return 1;
		}
		system("cls");
		showMenu();
		menuChoice = getMenuChoice(1, 9);
	}
}