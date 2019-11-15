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

    int n, k, i, j;
    char temp;
    string s, t;
    cin>>k;
    while (k--)
    {
        cin>>n;
        cin>>s>>t;
        mii m;
        vii oper;
        for (i=0; i<n; i++)
            m[s[i]]++;
        for (i=0; i<n; i++)
            m[t[i]]++;
        for (i=0; i<26; i++)
            if (m['a'+i]%2)
                break;
        if (i<26)
        {
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\n";
        for (i=0; i<n; i++)
        {
            if (s[i]==t[i])
                continue;
            for (j=i+1; j<n; j++)
                if (s[j]==s[i])
                    break;
            if (j<n)
            {
                oper.pb(mp(j+1, i+1));
                temp=s[j];
                s[j]=t[i];
                t[i]=temp;
            }
            else
            {
                for (j=i+1; j<n; j++)
                    if (t[j]==s[i])
                        break;
                oper.pb(mp(j+1, j+1));
                oper.pb(mp(j+1, i+1));
                temp=s[j];
                s[j]=t[j];
                t[j]=temp;
                temp=s[j];
                s[j]=t[i];
                t[i]=temp;
            }
        }
        cout<<oper.size()<<'\n';
        for (i=0; i<oper.size(); i++)
            cout<<oper[i].ff<<' '<<oper[i].ss<<'\n';
    }
}
