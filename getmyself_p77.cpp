/* 测试样例为一个整数，要求是用其所有的位组成一个最大的数和最小的数（不包含0），
   得到新数后循环这个过程知道出现重复的数字为止，输出这个数 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

void swap(char&a, char& b) {
    char temp;
    temp = a;
    a = b;
    b = temp;
}
void reverse(char *s) {
    int length = strlen(s);
    for (int i = 0; i < length/2; i++) {
        swap(s[i], s[length-1-i]);
    }
}

int main()
{
    int n;
    char s[10];
    while (cin >> n) {
        set<int> num_set;
        int num = n;
        memset(s, 0, sizeof(s));
        while (num_set.count(num) == 0) {
            int num_next;  
            int big;
            int small;
            num_set.insert(num);
            sprintf(s, "%d", num);
            int length_s = strlen(s);
            for (int i = 0; i < length_s-1; i++) 
                for (int j = i+1; j < length_s; j++) {
                    if (s[j] > s[i]) {
                        swap(s[j], s[i]);
                    }
                }
            sscanf(s, "%d", &big);
            reverse(s);
            sscanf(s, "%d", &small);
            num_next = big-small;
            num = num_next;
        }
        cout << num << endl;
    }
}
