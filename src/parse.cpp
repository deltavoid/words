#include "parse.h"
#include <iostream>
using namespace std;


static int idx[Len];
static int idx1[Len];
static int idx_cnt;


bool is_number(char c)  {  return c >= '0' && c <= '9';}

bool is_letter(char c)  {  return c >= 'a' && c <= 'z';}


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

   
    int tmp = idx1[1];
    while (tmp -1 >= 0 && !is_letter(str[tmp - 1]))  tmp = tmp - 1;
    entry.word = string(str, tmp);

    for (int i = 1; i <= idx_cnt; i++)
    {
        Paraphrase p;
        p.first = string(str + idx1[i], idx[i] - idx1[i]);  //[idx1[i], idx[i])
        p.second = string(str + idx[i] + 1, (i == idx_cnt? len : idx1[i + 1]) - (idx[i] + 1));  // [idx[i] + 1, idx1[i + 1] | len]
        entry.paraphrases.push_back(p);
    } 

    return entry;
}