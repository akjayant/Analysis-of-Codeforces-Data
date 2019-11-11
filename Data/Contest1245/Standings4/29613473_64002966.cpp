#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define ii pair<int,int>
#define mp make_pair
using namespace std;
string s;
int memo[200005];
int mod = 1e9+7;
int n;
int solve(int i)
{
    if(i == n)
    {
        return  1;
    }
    int &ret = memo[i];
    if(ret != -1)
        return ret;
    ret = 0;
    ret = solve(i+1);
    if(s[i] == 'n' && s[i+1] == 'n')
    {
        ret += solve(i+2);
    }
    ret %=mod;
    if(s[i] == 'u'&&s[i+1] == 'u')
    {
        ret+=solve(i+2);
    }
    ret %=mod;
    return ret;
}
int main()
{
    memset(memo,-1,sizeof(memo));
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i] == 'm'|| s[i] == 'w')
        {
            cout<<0;
            return 0;
        }
    }
    n = s.size();
    s+='$';
    cout<<solve(0)<<endl;
    return 0;
}
