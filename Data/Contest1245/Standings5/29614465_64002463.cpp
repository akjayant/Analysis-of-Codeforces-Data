/************************************************************************
* File Name : oj.cpp
* Purpose : 
* Creation Date : 2019年05月22日
* Last Modified : 2019年11月01日 星期五 22时52分17秒
* Created By : Elite
************************************************************************/
//#include<iostream>
//#include<string>
//#include<cmath>
//#include<vector>
//#include<set>
//#include<algorithm>
//#include<stdio.h>
//#include<stdlib.h>
//#include<queue>
//#include<stack>
//#include<string.h>


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int maxn = 1e6+5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const double PI = acos(-1);


int f[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(f, 0, sizeof(f));
        int n;
        string s;
        int a, b, c;
        cin>>n;
        cin>>a>>b>>c;
        cin>>s;
        int ans = 0;
        int len = s.length();
        string t="";
        for(int i=0;i<len;i++)
        {
            if(s[i]=='R')
            {
                if(b)
                {
                    b--;ans++;f[i]=1;
                }
            }
            else if(s[i]=='P')
            {
                if(c)
                {
                    c--;
                    ans++;
                    f[i] = 1;
                }
            }
            else
            {
                if(a)
                {
                    a--;ans++;f[i]=1;
                }
            }
        }
        if(ans >= ((n>>1)+(n&1)))
        {
            cout<<"YES"<<endl;
            for(int i=0;i<len;i++)
            {
                if(f[i])
                {
                    if(s[i]=='R')
                        t+='P';
                    else if(s[i]=='P')
                        t+='S';
                    else
                        t+='R';
                }
                else
                {
                    if(a)
                    {
                        t+='R';a--;
                    }
                    else if(b)
                    {
                        t+='P';b--;
                    }
                    else
                    {
                        c--;
                        t+='S';
                    }
                }
            }
            cout<<t<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
