#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 5;
const long long mod = 1e9 + 7;

int n;
string s;

long long memo[MAXN];

long long calcState(int index)
{
    if(index==n) return 1;
    if(memo[index]!=-1) return memo[index];

    if(s[index]!='u' && s[index]!='n')
    {
        memo[index] = calcState(index+1);
        return memo[index];
    }

    memo[index] = calcState(index+1);
    if(index<n-1 && s[index]==s[index+1])
    {
        memo[index] += calcState(index+2);
    }

    memo[index] %= mod;
    return memo[index];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    n = s.size();

    for(int i = 0;i<n;i++)
    {
        if(s[i]=='m' || s[i]=='w')
        {
            cout << "0" << '\n';
            return 0;
        }
    }

    memset(memo, -1, sizeof(memo));
    cout << calcState(0) << "\n";
}
