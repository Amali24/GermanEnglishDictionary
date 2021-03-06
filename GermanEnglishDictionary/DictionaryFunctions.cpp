#include "DictionaryFunctions.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <iomanip>
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
	cout << "F1 = �, F2 = �, F3 = �, F4 = �,  F5 = �, F6 = �, F7 = �, F8 = �" << endl;
	while (1) {
		char char1, char2;

		while (1) {
			char1 = _getch();

			if (char1 == 0 || char1 == -32) {
				char2 = _getch();
				if (char2 == 59) { // F1 = �
					cout << (char)132;
					word += (char)132;
				}
				else if (char2 == 60) { // F2 = �
					cout << (char)137;
					word += (char)137;
				}
				else if (char2 == 61) { // F3 = �
					cout << (char)139;
					word += (char)139;
				}
				else if (char2 == 62) { // F4 = �
					cout << (char)148;
					word += (char)148;
				}
				else if (char2 == 63) { // F5 = �
					cout << (char)129;
					word += (char)129;
				}
				else if (char2 == 64) { // F6 = �
					cout << (char)142;
					word += (char)142;
				}
				else if (char2 == 65) { // F7 = �
					cout << (char)153;
					word += (char)153;
				}
				else if (char2 == 66) { // F8 = �
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

void wordListBuilder(vector<Word> &wordList, vector<Noun> &nounList){

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

		Noun noun;
		switch (menuChoice) {
		case 1:
			noun = Noun::nounFactory();
			wordList.push_back(noun);
			nounList.push_back(noun);
			break;
		case 2:
			cout << "Do not include \'to\' in the infinitive" << endl;
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
			return;
		}
	}

}

void writeWordListToFile(ofstream& out, vector<Word> wordList, vector<Noun> nounList) {
	for (Word word : wordList) {
		out << word << endl;
	}
	for (Noun noun : nounList) {
		out << noun << endl;
	}
}

void readWordListFromFile(ifstream& in, vector<Word> &wordList, vector<Noun> &nounList) {
	string line;
	while (getline(in, line)) {
		stringstream iss(line);
		if (line.find("Noun") != string::npos) {
			Noun noun;
			iss >> noun;
			nounList.push_back(noun);
		}
		else {
			Word word;
			iss >> word;
			word.sortWord = makeSortWord(word.german);
			wordList.push_back(word);
		}
	}
}

void findWordsByPartOfSpeech(string partOfSpeech, vector<Word> wordList) {
	vector<Word> words;

	for (Word word : wordList) {
		if (word.partOfSpeech == partOfSpeech) {
			words.push_back(word);
		}
	}
	
	system("cls");
	
	if (words.size() == 0){
		cout << "No " << partOfSpeech << "s found.";
		_getch();
		return;
	}
		
	sortWords(words);

	cout << setw(20) << "German" << setw(20) << "English" << setw(20) << "Part of Speech" << endl;

	for (Word w : words) {
		cout << w << endl;
	}
	_getch();
}


void findNouns(vector<Noun> nounList) {
	sortWords(nounList);

	system("cls");
	cout << setw(20) << "Definite Article" << setw(20) << "German" << setw(20) << "English" << setw(20) << "Part of Speech" << endl;

	for (Noun n : nounList) {
		cout << n << endl;
	}
	_getch();
}

void sortWords(vector<Word>& unsortedWords) {
	unsigned i, j;
	for (i = 0; i < unsortedWords.size() - 1; i++) {
		for (j = 0; j < unsortedWords.size() - i - 1; j++) {
			if (unsortedWords[j].sortWord > unsortedWords[j + 1].sortWord) {
				Word temp = unsortedWords[j];
				unsortedWords[j] = unsortedWords[j + 1];
				unsortedWords[j + 1] = temp;
			}
		}
	 }
}

void sortWords(vector<Noun>& unsortedWords) {
	unsigned i, j;
	for (i = 0; i < unsortedWords.size() - 1; i++) {
		for (j = 0; j < unsortedWords.size() - i - 1; j++) {
			if (unsortedWords[j].sortWord > unsortedWords[j + 1].sortWord) {
				Noun temp = unsortedWords[j];
				unsortedWords[j] = unsortedWords[j + 1];
				unsortedWords[j + 1] = temp;
			}
		}
	}
}

void searchForWord(string searchTerm, vector<Word> wordList, vector<Noun> nounList) {
	system("cls");

	cout << setw(20) << "Definite Article" << setw(20) << "German" << setw(20) << "English" << setw(20) << "Part of Speech" << endl;

	for (Word w : wordList) {
		if (stringToUpper(w.german).find(stringToUpper(searchTerm)) != string::npos || stringToUpper(w.english).find(stringToUpper(searchTerm)) != string::npos){
			cout << setw(20) << " " << w << endl;
		}
	}

	for (Noun w : nounList) {
		if (stringToUpper(w.german).find(stringToUpper(searchTerm)) != string::npos || stringToUpper(w.english).find(stringToUpper(searchTerm)) != string::npos){
			cout << w << endl;
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