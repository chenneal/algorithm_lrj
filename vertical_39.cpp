/*
 *  这里用的C++的string去实现的，大家可以发现，C++去格式化字符串非常地坑人，特别是这个字符串流对象的
 *  clear()方法真是坑死人不偿命，所以不太建议用C++刷字符串的题目，非常悲剧 T T
 */
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

int main()
{
    int abc, de;
    int i;
    int count = 0;
    stringstream ss;
    string s;
    string buf;
    int x, y, z;
    bool ok;
    while (cin >> s)
    {
        for (abc = 111; abc < 999; abc++)
        {
            for (de = 11; de < 99; de++)
            {
                ok = true;
                x = abc*(de%10);
                y = abc*(de/10);
                z = abc*de;
                ss << abc << de << x << y << z;
                buf = ss.str();
                ss.str("");
                ss.clear();
                for (i = 0; i < buf.length(); i++)
                {
                    if (s.find(buf[i]) > s.length())
                        ok = false; 
                }
                if (ok)
                {
                    printf("<%d>\n", ++count);
                    printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n", abc, de, x, y, z);
                }
            }
        }
        cout << "the number of solutions is " << count << endl;
    }
    return 0;
}
