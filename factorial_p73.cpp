// 大数阶乘算法，这个算法有个关键之处就是无论乘数是否超过10均可以使用普通的位乘法法则，进位carry很有可能超过10
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> result(3000, 0);
    while (cin >> n) {
        int i;
        result[0] = 1;
        for (i = 2; i <= n; i++) {
            //这里做了个小优化，当跳过所有的前导零之后再遇到multi为零的情形直接停止
            int meet_zero = 0;
            int carry = 0;
            for (int j = 0; j < result.size(); j++) {
                int multi = i*result[j] + carry;
                if (multi == 0 && meet_zero == 0)
                    continue;
                if (!multi && meet_zero == 1)
                    meet_zero == 1;
                if (multi == 0 && meet_zero == 1)
                    break;
                result[j] = multi%10;
                carry = multi/10;
            }
        }
        int j;
        for (j = result.size()-1; result[j] == 0; j--)    ;
        //cout << j << endl;
        for (int k = j; k >= 0; k--) {
            cout << result[k];
        }
        cout << endl;
        result.assign(result.size(), 0);
    }
    return 0;
}
