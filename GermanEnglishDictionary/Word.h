#ifndef WORD_H
#define Word_H

#include <string>

using namespace std;

struct Word {
	string german;
	string english;
	string partOfSpeech;
	string sortWord;

	Word();
	Word(string, string, string, string);
};

struct Noun : Word {
	string definiteArticle;

	Noun(string, string, string, string, string);
};



#endif // !Word

