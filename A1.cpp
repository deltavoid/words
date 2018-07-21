#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

const int N = 1000;
char str[N];
int n;


bool isNumber(char c)
{
    return c >= '0' && c <= '9';
}

bool isLetter(char c)
{
    return c >= 'a' && c <= 'z';
}

void operate(char* str, int len)
{
    if  (len <= 0)  return ;

    char* str1 = str;
    while (isNumber(*str1))  str1++;
    std::cout << str1 << std::endl;
}

int main()
{

    while (std::cin.getline(str, N))
    {
        operate(str, strlen(str));
    }

    return 0;
}