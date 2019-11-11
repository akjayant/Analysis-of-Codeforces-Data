#include<bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll mod=1e9+7;
//0>1
//1>2
//2>0
int a[105];
int times[10];
int cnt[10],rem[10];
char talkc(int id)
{
    if(id==0)
        return 'R';
    if(id==1)
        return 'S';
    return 'P';
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        mset(times,0);
        int n;
        cin>>n>>cnt[0]>>cnt[2]>>cnt[1];
        string s;
        cin>>s;
        for(int i=0; i<n; ++i)
        {
            if(s[i]=='R')
                a[i+1]=0;
            if(s[i]=='P')
                a[i+1]=2;
            if(s[i]=='S')
                a[i+1]=1;
            times[a[i+1]]++;
        }
        int tot=0;
        for(int i=0; i<3; ++i)
        {

            tot+=min(cnt[i],times[(i+1)%3]);
            int w=min(cnt[i],times[(i+1)%3]);
            rem[i]=cnt[i]-w;
            cnt[i]=w;
        }
        if(tot>=(n+1)/2)
        {
            cout<<"YES"<<endl;
            string pt="";
            for(int i=1; i<=n; ++i)
            {
                int id=(a[i]+2)%3;
                if(cnt[id] > 0)
                {
                    pt+=talkc(id);
                    cnt[id]--;
                }
                else
                {
                    for(int i=0; i<3; ++i)
                    {
                        if(rem[i] > 0)
                        {
                            pt+=talkc(i);
                            rem[i]--;
                            break;
                        }
                    }
                }
            }
            cout<<pt<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}
/*
5
2 2 1
PPRRS

*/
