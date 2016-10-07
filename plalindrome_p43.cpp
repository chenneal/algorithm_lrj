/* 输入一个带空白符的字符行，忽略其中的标点符号以及大小写，输出最大回文子串，最简单的BF法 */

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

bool is_pla(string &s, int left, int right)
{
    bool ok = true;
    int i;
    int j;
    i = left;
    j = right;
    for (; i < j; )
    {
        if (s[i] != s[j])
        {
            ok = false;
            break;
        }
        i++;
        j--;
    }
    return ok;
}

int main()
{
    string s;
    string buf;
    int i;
    int j;
    int length;
    int max;
    int imax, jmax;
    while (getline(cin, buf))
    {
        imax = 0;
        jmax = 1;
        max = 0;
        /* 将字符串所有的字符均转换成小写并去除空白符与标点符号 */
        for (i = 0; i < buf.length(); i++)
        {
            if (isalpha(buf[i]))
            {
                s += tolower(buf[i]);
            }
        }
        length = s.length();
        for (i = 0; i < length; i++)
        {
            for (j = i; j < length; j++)
            {
                if (is_pla(s, i, j) && (j - i + 1) > max)
                {
                    max = j - i + 1;
                    imax = i;
                    jmax = j;
                }
            }
        }
        cout << s.substr(imax, max) << endl;
        /* 复用s */
        s.clear();
    }
}
