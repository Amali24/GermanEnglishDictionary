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
	ifstream inFile;
	ofstream outFile("GtoE_dict.txt");

	bool wordListCreated = false;

	inFile.open(FILE_NAME);

	string searchTerm;

	if (inFile) {
		wordListCreated = true;
		readWordListFromFile(inFile, wordList);
	}

	while (true) {
		switch (menuChoice) {
		case 1:
			inFile.open("GtoE_dict.txt");
			if (!inFile) {
				wordList = wordListBuilder();
				writeWordListToFile(outFile, wordList);
				wordListCreated = true;
			}
			else {
				cout << "Word list already created." << endl;
			}
			break;
		case 2:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				break;
			}
			findWordsByPartOfSpeech("Noun", wordList);
			break;
		case 3:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				break;
			}
			findWordsByPartOfSpeech("Verb", wordList);
			break;
		case 4:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				break;
			}
			findWordsByPartOfSpeech("Preposition", wordList);
			break;
		case 5:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				break;
			}
			findWordsByPartOfSpeech("Cardinal Number", wordList);
			break;
		case 6:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				break;
			}
			findWordsByPartOfSpeech("Adverb", wordList);
			break;
		case 7:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				break;
			}
			findWordsByPartOfSpeech("Adjective", wordList);
			break;
		case 8:
			if (!wordListCreated) {
				cout << "Word list must be created first." << endl;
				break;
			}
			cout << "Enter a word: ";
			searchTerm = wordBuilder();
			searchForWord(searchTerm, wordList);
			break;
		case 9:
			return 0;
		default: // SHOULD NEVER EVER HAPPEN 
			cout << "Oops, you broke it. Try a menu choice between 1 and 9 next time. Exiting..." << endl;
			system("pause");
			return 1;
		}
	}
}