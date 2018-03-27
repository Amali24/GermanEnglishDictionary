#include "DictionaryFunctions.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <sstream>
using namespace std;

void showMenu() {
	string germanToEnglish = "German to English";
	cout << "Please make a selection:" << endl
		<< "1. Create the word list" << endl
		<< "2. " << germanToEnglish << " nouns" << endl
		<< "3. " << germanToEnglish << " verbs" << endl
		<< "4. " << germanToEnglish << " prepositions" << endl
		<< "5. " << germanToEnglish << " adjectives" << endl
		<< "6. " << germanToEnglish << " adverbs" << endl
		<< "7. " << germanToEnglish << " cardinal numbers" << endl
		<< "8. Search for a word" << endl
		<< "9. Quit" << endl;
}

int getMenuChoice(int lo, int hi) {
	int input = _getch() - '0';
	while (input > hi || input < lo) {
		cout << "Please select a valid menu option" << endl;
		input = _getch() - '0';
	}
	return input;
}

string wordBuilder() {
	string word;
	while (1) {
		char char1, char2;

		while (1) {
			char1 = _getch();

			if (char1 == 0 || char1 == -32) {
				char2 = _getch();
				if (char2 == 59) { // F1 = ä
					cout << (char)132;
					word += (char)132;
				}
				else if (char2 == 60) { // F2 = ë
					cout << (char)137;
					word += (char)137;
				}
				else if (char2 == 61) { // F3 = ï
					cout << (char)139;
					word += (char)139;
				}
				else if (char2 == 62) { // F4 = ö
					cout << (char)148;
					word += (char)148;
				}
				else if (char2 == 63) { // F5 = ü
					cout << (char)129;
					word += (char)129;
				}
				else if (char2 == 64) { // F6 = Ä
					cout << (char)142;
					word += (char)142;
				}
				else if (char2 == 65) { // F7 = Ö
					cout << (char)153;
					word += (char)153;
				}
				else if (char2 == 66) { // F8 = Ü
					cout << (char)154;
					word += (char)154;
				}
			}
			else if (char1 == 13) {
				return word;
			}
			else {
				cout << char1;
				word += char1;
			}
		}
	}
}

string makeSortWord(string unsorted) {
	string sortWord;
	for (char c : unsorted) {
		if (c == (char)132) {
			sortWord += 'a';
		}
		else if (c == (char)137) {
			sortWord += 'e';
		}
		else if (c == (char)139) {
			sortWord += 'i';
		}
		else if (c == (char)148) {
			sortWord += 'o';
		}
		else if (c == (char)129) {
			sortWord += 'u';
		}
		else if (c == (char)142) {
			sortWord += 'A';
		}
		else if (c == (char)153) {
			sortWord += 'O';
		}
		else if (c == (char)154) {
			sortWord += 'U';
		}
		else {
			sortWord += c;
		}
	}
	return sortWord;
}

vector<Word> wordListBuilder(){
	vector<Word> wordList;

	while (true) {

		cout << "Select part of speech:" << endl
			<< "1 - Noun" << endl
			<< "2 - Verb" << endl
			<< "3 - Preposition" << endl
			<< "4 - Cardinal Number" << endl
			<< "5 - Adverb" << endl
			<< "6 - Adjective" << endl
			<< "7 - Finished Entering Words" << endl;

		int menuChoice = getMenuChoice(1, 7);

		switch (menuChoice) {
		case 1:
			wordList.push_back(Noun::nounFactory());
			break;
		case 2:
			wordList.push_back(Word::wordFactory("Verb"));
			break;
		case 3:
			wordList.push_back(Word::wordFactory("Preposition"));
			break;
		case 4:
			wordList.push_back(Word::wordFactory("Cardinal Number"));
			break;
		case 5:
			wordList.push_back(Word::wordFactory("Adverb"));
			break;
		case 6:
			wordList.push_back(Word::wordFactory("Adjective"));
			break;
		case 7:
			return wordList;
			break;
		}
	}

}

void writeWordListToFile(ofstream& out, vector<Word> wordList) {
	for (Word word : wordList) {
		out << word << endl;
	}
}

void readWordListFromFile(ifstream& in, vector<Word> wordList) {
	string line;
	while (getline(in, line)) {
		stringstream iss(line);
		if (line.find("Noun") != string::npos) {
			Noun noun;
			iss >> noun;
			wordList.push_back(noun);
		}
		else {
			Word word;
			iss >> word;
			wordList.push_back(word);
		}
	}
}

void findWordsByPartOfSpeech(string partOfSpeech, vector<Word> wordList) {
	

	
	
	if (partOfSpeech != "Noun") {
		vector<Word> subset;
		for (Word word : wordList) {
			if (word.partOfSpeech == partOfSpeech) {
				subset.push_back(word);
			}
		}
		sortWords(subset);
		system("cls");
		for (Word w : subset) {
			cout << w << endl;
		}
	}

	else {
		vector<Noun> subset;
		for (unsigned int i = 0; i < (wordList.size() - 1); i++) {
			
		}
		for (Noun w : subset) {
			cout << w << endl;
		}
	}
	_getch();
}

void sortWords(vector<Word>& unsortedWords) {
	for (unsigned int i = 0; i < unsortedWords.size() - 1; i++) {
		if (unsortedWords[i].sortWord > unsortedWords[i+1].sortWord) {
			Word temp = unsortedWords[i];
			unsortedWords[i] = unsortedWords[i + 1];
			unsortedWords[i + 1] = temp;
		}
	 }
}

void searchForWord(string searchTerm, vector<Word> wordList) {
	for (Word w : wordList) {
		if (stringToUpper(w.german) == stringToUpper(searchTerm) || stringToUpper(w.english) == stringToUpper(searchTerm)) {
			cout << w;
		}
	}
	_getch();
}

string stringToUpper(string str) {
	for (char c : str){
		c = toupper(c);
	}
	return str;
}