#include "Word.h"
#include <vector>

void showMenu();
int getMenuChoice(int, int);
string wordBuilder();
string makeSortWord(string);
vector<Word> wordListBuilder();
void writeWordListToFile(ofstream&, vector<Word>);
void readWordListFromFile(ifstream&, vector<Word>);
void findWordsByPartOfSpeech(string, vector<Word>);
void sortWords(vector<Word>&);
void searchForWord(string, vector<Word>);
string stringToUpper(string);