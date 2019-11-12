#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        string s,t;
        ll n,c=0;
        cin >> n;
        cin >> s >> t;
        set<char>s1,s2;
        for(ll i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                s1.insert(s[i]);
                s2.insert(t[i]);
                c++;
            }
        }
        if(c==2 && s1.size()<=1 && s2.size()<=1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}