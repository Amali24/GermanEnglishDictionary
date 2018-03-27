#include "Word.h"
#include "DictionaryFunctions.h"
#include <iostream>

Word::Word() {

}

Word::Word(string german, string english, string partOfSpeech) {
	this->german = german;
	this->english = english;
	this->partOfSpeech = partOfSpeech;
	this->sortWord = makeSortWord(german);
}

ostream& operator<<(ostream& os, const Word& w){
	os << w.german << " " << w.english << " " << w.partOfSpeech << " ";
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

Noun::Noun(string german, string english, string definiteArticle) {
	this->german = german;
	this->english = english;
	this->partOfSpeech = "Noun";
	this->sortWord = makeSortWord(german);
	this->definiteArticle = definiteArticle;
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
	os << w.german << " "  << w.english << " " << w.partOfSpeech << " " << w.definiteArticle;
	return os;
}

istream& operator>>(istream& is, Noun& w) {
	is >> w.german >> w.english >> w.partOfSpeech >> w.definiteArticle;
	return is;
}