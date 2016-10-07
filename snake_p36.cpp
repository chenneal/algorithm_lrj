#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

const int maxsize = 1000;
int a[maxsize][maxsize];

int main()
{
    int tot;
    int n;
    int i, j;
    while (cin >> n)
    {
        i = 0;
        j = n-1;
        tot = 1;
        memset(a, 0, sizeof(a));
        a[i][j] = tot;
        while (tot < n*n)
        {
            while (i+1 < n && !a[i+1][j])    a[++i][j] = ++tot;
            while (j-1 >= 0 && !a[i][j-1])   a[i][--j] = ++tot;
            while (i-1 >= 0 && !a[i-1][j])   a[--i][j] = ++tot;
            while (j+1 < n && !a[i][j+1])    a[i][++j] = ++tot;
        } 
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << setw(3) << a[i][j];
            }
            cout << endl;  
        }
    }
    return 0;
}
