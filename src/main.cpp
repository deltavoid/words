#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include "parse.h"
using namespace std;

char str[Len];
int n;

vector<Entry> entries;

typedef map<string, vector<Entry> > Dictionary;
Dictionary dic;


void output_entry(Entry entry)
{
    cout << entry.word <<  endl;
        for (int i = 0; i < entry.paraphrases.size(); i++)
            cout << "    " << entry.paraphrases[i].first << "." << entry.paraphrases[i].second << endl;
}

void output_entry1(Entry entry)
{
    cout << entry.word;
    int tab = 14;
    int l = tab - (entry.word.size()) % tab;
    for (int i = 0; i < l; i++)
        cout << " ";
    
        for (int i = 0; i < entry.paraphrases.size(); i++)
            cout << "  " << entry.paraphrases[i].first << "." << entry.paraphrases[i].second;
    cout << endl;
}


int main()
{

    while (cin.getline(str, Len))
    {
        if  ((n = strlen(str)) <= 0)  continue;

        Entry entry = parse(str, strlen(str));

        entries.push_back(entry);
    }

    for (int i = 0; i < entries.size(); i++)
    {
        for (int j = 0; j < entries[i].paraphrases.size(); j++)
        {
            Entry en;
            en.word = entries[i].word;
            en.paraphrases.push_back(entries[i].paraphrases[j]);
            if  (en.paraphrases[0].second == string("/"))
                en.paraphrases[0].second = entries[i].paraphrases[j + 1].second;
            dic[en.paraphrases[0].first].push_back(en);
        }
    }

    Dictionary::iterator it;
    for (it = dic.begin(); it != dic.end(); it++)
        cout << it->first << endl;
    cout << endl << endl;

    //Dictionary::iterator it;
    for (it = dic.begin(); it != dic.end(); it++)
    {
        cout << it->first << endl;
        for (int i = 0; i < it->second.size(); i++)
            output_entry1(it->second[i]);
        cout << endl << endl;
    }

    return 0;
}