#include <bits/stdc++.h>

#define int long long int
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define mii map<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, diff;
    pii index;
    string s, t;
    cin>>k;
    while (k--)
    {
        cin>>n;
        cin>>s>>t;
        diff=0;
        index=mp(-1,-1);
        for (i=0; i<n; i++)
        {
            if (s[i]!=t[i])
            {
                diff++;
                if (diff==1)
                    index.ff=i;
                else if (diff==2)
                    index.ss=i;
                else
                    break;
            }
        }
        if (diff==0)
            cout<<"Yes\n";
        else if (diff>2 || diff==1)
            cout<<"No\n";
        else if (s[index.ff]==s[index.ss] && t[index.ff]==t[index.ss])
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
