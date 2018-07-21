#ifndef PARSE_H
#define PARSE_H
#include <string>
#include <vector>
#include <set>


typedef std::pair<std::string, std::string> Paraphrase;

struct Entry
{
    std::string word;
    std::string pronunciation;
    std::vector<Paraphrase> paraphrases; 
};

const int Len = 1000;

Entry parse(char* str, int len);


#endif