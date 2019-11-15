//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#define ll  long long
using namespace std;
const int MAX = 1000;//100000
const int MAX_1 = 1000100;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
//void runtime(){cout << "The run time is:" << (double)clock() /CLOCKS_PER_SEC<< "s" << endl;}
ll T,N,M,K,D;

/* --------------------------------------------------------------------------------------------------*/
int a[MAX];
/* --------------------------------------------------------------------------------------------------*/

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> T;
    while(T--)
    {
        cin >> N;
        string s,t;
        cin >> s >> t;
        int diff[10];
        int cnt = 0;
        for(int i = 0;i < N;i++)
        {
            if(s[i] != t[i])
            {
                diff[cnt] = i;
                cnt++;
            }
            if(cnt > 2) break;
        }
        if(cnt == 1 || cnt > 2)
        {
            cout << "No" <<endl;
        }
        else
        {
            if(cnt == 0) cout << "Yes" <<endl;
            else
            {
                if(s[diff[0]] == s[diff[1]] &&
                   t[diff[0]] == t[diff[1]])
                {
                    cout << "Yes" <<endl;
                }
                else cout << "No" <<endl;
            }
        }
    }
    return 0;
}

