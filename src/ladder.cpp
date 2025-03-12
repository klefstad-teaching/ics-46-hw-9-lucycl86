#include "ladder.h"

void error(string word1, string word2, string msg)
{
    cout << word1 << ", " << word2 << ": " << msg << endl;
}

void load_words(set<string> & word_list, const string& file_name)
{
    ifstream in(file_name);
    for(string word; (in >> word);)
        word_list.insert(word);
    in.close();
}

void print_word_ladder(const vector<string>& ladder)
{
    int size = ladder.size();
    for(int i = 0; i < size; ++i)
        cout << ladder[i] << " ";
}