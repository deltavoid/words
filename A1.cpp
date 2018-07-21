#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

const int N = 1000;
char str[N];
//int n;
int idx[N];
int idx_cnt;

bool is_number(char c)
{
    return c >= '0' && c <= '9';
}

bool is_letter(char c)
{
    return c >= 'a' && c <= 'z';
}

void output_char(char* str, int l, int r)
{
    for (int i = l; i < r; i++)
        std::cout << str[i];
}

void operate(char* str, int len)
{
    if  (len <= 0)  return ;

    idx_cnt = 0;
    for (int i = 0; i < len; i++)
        if  (str[i] == '.')
            idx[++idx_cnt] = i;
    
    for (int i = idx_cnt; i >= 1; i--)
    {
        int& x = idx[i];
        while (x-1 >= 0 && is_letter(str[x-1]))  x = x - 1;
    }

    output_char(str, idx[0], idx[1]);
    std::cout << std::endl;
    for (int i = 1; i <= idx_cnt; i++)
    {   std::cout << "    ";
        output_char(str, idx[i], i < idx_cnt? idx[i + 1] : len);
        std::cout << std::endl;
    }

}

int main()
{

    while (std::cin.getline(str, N))
    {
        operate(str, strlen(str));
    }

    return 0;
}