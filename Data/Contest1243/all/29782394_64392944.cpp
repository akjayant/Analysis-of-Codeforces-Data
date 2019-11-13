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
struct ANS
{
    int x,y;
};
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
        map<char,int> ch;
        vector<ANS> ans;
        for(int i = 0;i < N;i++)
        {
            ch[s[i]]++;
            ch[t[i]]++;
        }
        auto it = ch.begin();
        bool flag = true;
        for(;it != ch.end();it++)
        {
            if(it->second % 2)
            {
                flag = false;
                break;
            }
        }
        if(flag == false)
        {
            cout << "No" <<endl;
            continue;
        }
        else
        {
            cout << "Yes" <<endl;
            ANS temp;
            for(int i = 0;i < N;i++)
            {
                if(s[i] != t[i])
                {
                    int f = -1;
                    for(int j = i+1;j < N;j++)
                    {
                        if(s[j] == s[i])
                        {
                            f = j;
                            break;
                        }
                    }
                    if(f != -1)
                    {
                        temp.x = f;
                        temp.y = i;
                        char c = s[f];
                        s[f] = t[i];
                        t[i] = c;
                        ans.push_back(temp);
                    }
                    else
                    {
                        int f = -1;
                        for(int j = i+1;j < N;j++)
                        {
                            if(s[i] == t[j])
                            {
                                f = j;
                                break;
                            }
                        }
                        //1
                        temp.x = i+1;
                        temp.y = f;
                        char c = s[i+1];
                        s[i+1] = t[f];
                        t[f] = c;
                        ans.push_back(temp);
                        //2
                        temp.x = i+1;
                        temp.y = i;
                        c = s[i+1];
                        s[i+1] = t[i];
                        t[i] = c;
                        ans.push_back(temp);
                    }
                }
                else continue;
            }
            cout << ans.size() <<endl;
            int n = ans.size();
            for(int i = 0;i < n;i++)
            {
                cout << ans[i].x+1 << " " << ans[i].y + 1<<endl;
            }
        }
    }
    return 0;
}

