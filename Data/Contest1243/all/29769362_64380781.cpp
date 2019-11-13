/**
Code by Nitin1184
**/
# include <bits/stdc++.h>
# define ll long long
# define pi 3.14159265358979323846
# define M 1000000007
# define pb push_back
# define mp make_pair
# define ff first
# define ss second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
                v.pb(i);
        }
        if(v.size()==0)
            cout<<"Yes\n";
        else if(v.size()!=2)
            cout<<"No\n";
        else
        {
            if(s[v[0]]==s[v[1]] && t[v[0]]==t[v[1]])
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}