//#include <cstdio>
//#include <cstdlib>
#include <cstring>
//#include <cmath>
#include <iostream>
//#include <algorithm>
#include "parse.h"

char str[Len];
int n;

int main()
{

    while (std::cin.getline(str, Len))
    {
        if  ((n = strlen(str)) <= 0)  continue;

        Entry entry = parse(str, strlen(str));

        std::cout << entry.word /*<< entry.paraphrases.size()*/ <<  std::endl;
        for (int i = 0; i < entry.paraphrases.size(); i++)
            std::cout << "    " << entry.paraphrases[i].first << "." << entry.paraphrases[i].second << std::endl;
    }

    Classes::iterator it;
    for (it = classes.begin(); it != classes.end(); it++)
        std::cout << *it << std::endl;

    return 0;
}