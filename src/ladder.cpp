#include "ladder.h"

void error(string word1, string word2, string msg)
{
    cout << word1 << ", " << word2 << ": " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    int str1_len = str1.length();
    int str2_len = str2.length();
    int length_dif = abs(str1_len - str2_len);
    if (length_dif > d) return false;
    if (length_dif == 0)
    {
        int diff_count = 0;
        for(int i = 0; i < str1_len; ++i)
        {
            if (str1[i] != str2[i])
                ++diff_count;
            if (diff_count > d) return false;
        }
        return true;
    }
    if (length_dif <= d && length_dif > 0)
    {
        string shorter_str = str1_len < str2_len ? str1 : str2;
        string longer_str = str1_len > str2_len ? str1 : str2;
        // for (size_t i = 0; i <= shorter_str.length(); ++i)
        // {
        //     string modified = shorter_str.substr(0,i) + longer_str[i] + shorter_str.substr(i);
        //     if (modified == longer_str) return true;
        // }
        // return false;
        int s_len = shorter_str.length();
        int l_len = longer_str.length();
        int i = 0, j = 0;
        while(i < s_len && j < l_len)
        {
            if(shorter_str[i] == longer_str[j])
            {
                ++i;
                ++j;
            }
            else
            {
                ++j;
                if(j - i > d) return false;
            }
        }
        return true;
    }
    return false;
}

bool is_adjacent(const string& word1, const string& word2)
{
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list)
{
    queue<vector<string>> ladder_queue; 
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while(!ladder_queue.empty())
    {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for(const string& word: word_list)
        {
            if(is_adjacent(last_word, word))
            {
                if(visited.find(word) == visited.end())
                {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if(word == end_word)
                        return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return {};
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
    if(size == 0)
    {
        cout << "No word ladder found." << endl;
        return;
    }
    cout << "Word ladder found: ";
    for(int i = 0; i < size; ++i)
        cout << ladder[i] << " ";
    cout << "\n";
}

# define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder()
{
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}