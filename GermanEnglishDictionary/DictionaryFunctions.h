#include "Word.h"
#include <vector>

void showMenu();
int getMenuChoice(int, int);
string wordBuilder();
string makeSortWord(string);
void wordListBuilder(vector<Word>&, vector<Noun>&);
void writeWordListToFile(ofstream&, vector<Word>, vector<Noun>);
void readWordListFromFile(ifstream&, vector<Word>&, vector<Noun>&);
void findWordsByPartOfSpeech(string, vector<Word>);
void findNouns(vector<Noun>);
void sortWords(vector<Word>&);
void sortWords(vector<Noun>&);
void searchForWord(string, vector<Word>, vector<Noun>);
string stringToUpper(string);