#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define f(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
#define vll vector<vector<long long>>
using namespace std;

int main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        int n, flag = 0;
        string s, t;
        cin>>n>>s>>t;
        vi v;
        f(i, 0, n)
        {
        	if(s[i] != t[i]) v.pb(i);
        }
        int nv = v.size();
        if(nv == 2)
        {
        	if(s[v[0]] == s[v[1]] && t[v[0]] == t[v[1]]) {cout<<"Yes\n"; flag++;}
        }
        if(flag == 0) cout<<"No\n";
    }
    return 0;
}