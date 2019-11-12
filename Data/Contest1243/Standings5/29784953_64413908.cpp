///HELLO EVERYONE! TODAY I FEEL SO GOOD :)
#include <bits/stdc++.h>
using namespace std;
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "599B"
#define maxn 100005
#define MOD 1000000007
#define pii pair<int, int>
int k,n,cnt1[30],cnt2[30];
pii ans[maxn];
string s,t;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen(Task".inp", "r", stdin);
//    freopen(Task".out", "w", stdout);
    cin >> k;
    while(k--)
    {
        cin >> n;
        cin >> s;
        cin >> t;
        int dem=0,ch=0;
        reset(cnt1);
        reset(cnt2);
        for(int i=0; i<n; ++i)
        {
            cnt1[s[i]-'a']++;
            cnt2[t[i]-'a']++;
        }
        for(int i=0; i<26; ++i)
        {
            if((cnt1[i]+cnt2[i])%2)
            {
                ch=1;
                break;
            }
        }
        if(ch)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
            for(int i=0; i<n; ++i)
            {
                 if(s[i]!=t[i])
                 {
                     int che=0;
                     for(int j=i+1; j<n; ++j)
                        if(s[j]==s[i])
                        {
                            ans[++dem]=mp(j+1,i+1),swap(s[j],t[i]);
                            che=1;
                            break;
                        }
                    if(!che)
                    {
                        for(int j=i+1; j<n; ++j)
                           if(t[j]==s[i])
                           {
                               ans[++dem]=mp(i+2,j+1);
                               swap(s[i+1],t[j]);
                               ans[++dem]=mp(i+2,i+1);
                               swap(s[i+1],t[i]);
                               break;
                           }
                    }
                 }
            }
            cout<<dem<<endl;
            for(int i=1; i<=dem; ++i)
                cout<<ans[i].F<<" "<<ans[i].S<<"\n";
        }
    }
}
