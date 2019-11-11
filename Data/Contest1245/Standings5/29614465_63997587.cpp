/************************************************************************
* File Name : oj.cpp
* Purpose : 
* Creation Date : 2019年05月22日
* Last Modified : 2019年11月01日 星期五 22时41分25秒
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


int n, m;
int a[maxn];
int gcd(int a, int b)
{
    return b==0 ? a : gcd(b, a%b);
}
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        int g = gcd(a, b);
        if(g==1)cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
    }


    return 0;
}
