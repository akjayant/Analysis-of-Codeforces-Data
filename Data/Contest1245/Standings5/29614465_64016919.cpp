/************************************************************************
* File Name : oj.cpp
* Purpose : 
* Creation Date : 2019年05月22日
* Last Modified : 2019年11月01日 星期五 23时26分14秒
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
const int maxn = 1e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const double PI = acos(-1);


ll num[maxn];
int len;
void init()
{
    num[2] = 2; num[3] = 3;
    for(int i=4;i<=len;i++)
    {
        num[i] = (num[i-1] + num[i-2]) % mod;
    }
}

vector<int> v;

int main()
{
    string s;
    cin>>s;
    len = s.length();
    init();
    int flag = 0;
    for(int i=0;i<len;i++)
    {   //cout<<"1111"<<endl;
        if(s[i]=='w' || s[i]=='m')
        {
            flag = 1;break;
        }
        if(s[i]=='u')
        {
            int j=i;
            int cnt=0;
            while(s[j]=='u' && j<len)
            {
                cnt++;j++;
            }
            if(cnt>=2)
                v.push_back(cnt);
            i=j-1;
        }
        else if(s[i]=='n')
        {
            int j=i;
            int cnt=0;
            while(s[j]=='n' && j<len)
            {
                cnt++;j++;
            }
            if(cnt>=2)
                v.push_back(cnt);
            i=j-1;
        }
    }
    if(flag)
    {
        cout<<0<<endl;
    }
    else
    {
        ll ans = 1;
        for(auto x : v)
        {
            //cout<<num[x]<<endl;
            ans = (ans%mod * num[x]%mod) % mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
