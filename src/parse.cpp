#include "parse.h"
#include <iostream>
using namespace std;


static int idx[Len];
static int idx1[Len];
static int idx_cnt;

Classes classes;

bool is_number(char c)  {  return c >= '0' && c <= '9';}

bool is_letter(char c)  {  return c >= 'a' && c <= 'z';}

/*
void output_char(char* str, int l, int r)
{
    for (int i = l; i < r; i++)
        std::cout << str[i];
}*/

Entry parse(char* str, int len)
{
    Entry entry;

    idx_cnt = 0;
    for (int i = 0; i < len; i++)
        if  (str[i] == '.')
            idx[++idx_cnt] = i;
    
    for (int i = idx_cnt; i >= 1; i--)
    {
        int& x = idx1[i] = idx[i];
        while (x-1 >= 0 && is_letter(str[x-1]))  x = x - 1;
    }


    /*
    output_char(str, idx[0], idx[1]);
    std::cout << std::endl;
    for (int i = 1; i <= idx_cnt; i++)
    {   std::cout << "    ";
        output_char(str, idx[i], i < idx_cnt? idx[i + 1] : len);
        std::cout << std::endl;
    }
    */
   
    int tmp = idx1[1];
    while (tmp -1 >= 0 && !is_letter(str[tmp - 1]))  tmp = tmp - 1;
    entry.word = string(str, tmp);

    for (int i = 1; i <= idx_cnt; i++)
    {
        Paraphrase p;
        p.first = string(str + idx1[i], idx[i] - idx1[i]);  //[idx1[i], idx[i])
        p.second = string(str + idx[i] + 1, (i == idx_cnt? len : idx1[i + 1]) - (idx[i] + 1));  // [idx[i] + 1, idx1[i + 1] | len]
        entry.paraphrases.push_back(p);

        classes.insert(p.first);
    } 

    return entry;
}