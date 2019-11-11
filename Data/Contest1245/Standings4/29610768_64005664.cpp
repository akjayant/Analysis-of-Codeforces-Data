#include "bits/stdc++.h"
using namespace std;
#define int int64_t
#define mp make_pair
#define f first
#define s second
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a,b,c;cin>>a>>b>>c;
        map<char,int> m;
        string ss;cin>>ss;
        int count=0;
        set<int> index;
        for(int i=0;i<n;i++)
        {
            if(ss[i]=='R')
            {
                if(b>0)
                {
                    index.insert(i);
                    b--;
                    count++;
                    ss[i]='P';
                }
            }
            else if(ss[i]=='P')
            {
                if(c>0)
                {
                    index.insert(i);
                    c--;
                    count++;
                    ss[i]='S';
                }
            }
            else
            {
                if(a>0)
                {
                    index.insert(i);
                    a--;
                    count++;
                    ss[i]='R';
                }
            }
        }
        int ans=(n+1)/2;
        if(count>=ans)
        {
            for(int i=0;i<n;i++)
            {
                if(index.find(i)==index.end())
                {
                    if(a>0)
                    {
                        a--;
                        ss[i]='R';
                    }
                    else if(b>0)
                    {
                        b--;
                        ss[i]='P';
                    }
                    else if(c>0)
                    {
                        c--;
                        ss[i]='S';
                    }
                }
            }
            cout<<"YES\n";
            cout<<ss<<"\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
