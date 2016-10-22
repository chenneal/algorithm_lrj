#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <climits>
#include <cctype>

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>

#define push_back pb;
//#define FILE_JUDGE

using namespace std;

typedef long long ll;
typedef double D;
typedef vector<int> VI;
typedef map<int, int> MII;
typedef set<int> SI;

void build(string& pre, string& mid, int pleft, int pright, int mleft, int mright, string& result) {
    if (pleft > pright)
        return;
    int root = mid.find(pre[pleft], mleft);
    int length = root-mleft;
    build(pre, mid, pleft+1, pleft+length, mleft, root-1, result);
    build(pre, mid, pleft+length+1, pright, root+1, mright, result);
    result += pre[pleft];
}
int main(int argc, char* argv[]) {
    #ifdef FILE_JUDGE
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    string pre, mid;
    while (cin >> pre >> mid) {
        string result;
        build(pre, mid, 0, pre.size()-1, 0, pre.size()-1, result);
        cout << result << endl;
    }
    return 0;
}
