#include "Word.h"
#include <vector>
#include <memory>

void showMenu();
int getMenuChoice(int, int);
string wordBuilder();
string makeSortWord(string);
vector<unique_ptr<Word>> wordListBuilder();
void writeWordListToFile(ofstream&, vector<unique_ptr<Word>>);
void readWordListFromFile(ifstream&, vector<unique_ptr<Word>>);
void findWordsByPartOfSpeech(string, vector<unique_ptr<Word>>);
void sortWords(vector<unique_ptr<Word>>);
void searchForWord(string, vector<unique_ptr<Word>>);
string stringToUpper(string);