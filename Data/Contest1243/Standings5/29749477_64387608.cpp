#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        string str1, str2;
        cin >> str1 >> str2;
        int ch = 0;
        char f = '0', s = '0', fb = '0', sb = '0';
        for (int i = 0; i < n; ++i) {
            if (str1[i] != str2[i]) {
                ++ch;
                if (f == '0') {
                    f = str1[i];
                    fb = str2[i];
                }
                else {
                    s = str1[i];
                    sb = str2[i];
                }
            }
        }
        if (ch == 2 && f == s && fb == sb)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}