#ifndef WORD
#define WORD

#include <string>

using namespace std;

struct Word {
	string german;
	string english;
	string partOfSpeech;
	string sortWord;

	Word();
	Word(string, string, string);
	
	friend ostream& operator<<(ostream&, const Word&);
	friend istream& operator>>(istream&, Word&);

	static Word wordFactory(string);

};

#endif // !Word

#ifndef NOUN
#define NOUN



struct Noun : Word {
	string definiteArticle;

	Noun();
	Noun(string, string, string);

	friend ostream& operator<<(ostream&, const Noun&);
	friend istream& operator>>(istream&, Noun&);

	static Noun nounFactory();
};

#endif // !Noun