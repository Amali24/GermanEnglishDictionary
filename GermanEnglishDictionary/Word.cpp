#include "Word.h"
#include "DictionaryFunctions.h"
#include <iostream>
#include <iomanip>

Word::Word() {

}

ostream& operator<<(ostream& os, const Word& w){
	os << setw(20) << w.german << setw(20) << w.english << setw(20) << w.partOfSpeech;
	return os;
}

istream& operator>>(istream& is, Word& w){
	is >> w.german >> w.english >> w.partOfSpeech;
	return is;
}

Word Word::wordFactory(string partOfSpeech) {
	Word word;

	cout << "Enter German Word: ";
	word.german = wordBuilder();

	cout << "\nEnter English Meaning: ";
	getline(cin, word.english);

	word.partOfSpeech = partOfSpeech;
	word.sortWord = makeSortWord(word.german);

	return word;
}

Noun::Noun() {
	partOfSpeech = "Noun";
}

Noun Noun::nounFactory(){
	Noun noun;

	cout << "Enter definite article: ";
	cin >> noun.definiteArticle;
	cin.ignore(80, '\n');

	cout << "Enter German Word: ";
	noun.german = wordBuilder();

	cout << "\nEnter English Meaning: ";
	cin >> noun.english;
	cin.ignore(80, '\n');

	noun.sortWord = makeSortWord(noun.german);

	return noun;
}

ostream& operator<<(ostream& os, const Noun& w) {
	os << setw(20) << w.definiteArticle << setw(20) << w.german << setw(20) << w.english << setw(20) << w.partOfSpeech;
	return os;
}

istream& operator>>(istream& is, Noun& w) {
	is >> w.definiteArticle >> w.german >> w.english >> w.partOfSpeech;
	return is;
}