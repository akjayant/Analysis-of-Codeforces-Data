#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <stack>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iomanip>
#define int long long
#define double long double
using namespace std;

// const int MAXN =
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-5;

int n, a, b, c;

inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

signed main()
{
    int T = read();
    while (T--)
    {
        n = read(), a = read(), b = read(), c = read();
        string str;
        cin >> str;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'R')
                cnt1++;
            else if (str[i] == 'P')
                cnt2++;
            else
                cnt3++;
        }
        int ans = min(cnt1, b) + min(cnt2, c) + min(cnt3, a);
        int over1 = max(0ll, a - cnt3), over2 = max(0ll, b - cnt1), over3 = max(0ll, c - cnt2);
        if (ans >= (int)ceil(n * 1.0 / 2))
        {
            cout << "YES" << endl;
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == 'R')
                {
                    if (b)
                    {
                        cout << "P";
                        b--;
                    }
                    else
                    {
                        if (over1)
                        {
                            cout << "R";
                            over1--;
                        }
                        else if (over3)
                        {
                            cout << "S";
                            over3--;
                        }
                    }
                }
                else if (str[i] == 'P')
                {
                    if(c){
                        cout << "S";
                        c--;
                    }
                    else{
                        if(over1){
                            cout << "R";
                            over1--;
                        }
                        else if(over2){
                            cout << "P";
                            over2--;
                        }
                    }
                }
                else
                {
                    if(a){
                        cout << "R";
                        a--;
                    }
                    else{
                        if(over2){
                            cout << "P";
                            over2--;
                        }
                        else if(over3){
                            cout << "S";
                            over3--;
                        }
                    }
                }
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
