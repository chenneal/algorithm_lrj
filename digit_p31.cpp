/* p31 exercise2-1 */
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("digit.in");
ofstream fout("digit.out");

int main()
{
    int num;
    int count;

    while (fin>>num)
    {
       count = 1;
       while (num / 10 != 0)
       {
           count++;
           num /= 10;
       }

       fout << count << " ";
    }

    return 0;
}
