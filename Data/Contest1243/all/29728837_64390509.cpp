/// Template
#include<bits/stdc++.h>
using namespace std;
#define read FILE *fp;\
fp=freopen("testcase.txt","r",stdin);
#define ll long long
#define ull unsigned long long
#define sf(n) scanf("%I64d",&n)
#define pf(n) printf("%I64d\n",n)
#define loop for(long long i=0;i<n;i++)
#define tloop for(it=0;it<t;it++)
#define lp(b,n) for(long long i=b;i<n;i++)
#define pb push_back
#define srt(v) sort(v.begin(),v.end())
#define rvs(v) sort(v.begin(), v.end(), greater<long long>());
#define F first
#define S second
#define mp make_pair
#define fio ios::sync_with_stdio(false); cin.tie(),cout.tie();
bool sortbysec(const pair<pair<ll,ll>,ll> &a,
               const pair<pair<ll,ll>,ll> &b)
{
    return (a.second < b.second);
}
void con(ll fl)
{
    if(fl==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
ll mark[5010];
int main()
{
    ll t,it, i,n,fl,i1;
    char ch;
    cin>>t;
    tloop
    {
        string st1,st2;
        cin>>n>>st1>>st2;
        fl=0;
        for(i=0;i<n;i++)
        {
            if(st1[i]!=st2[i])
            {
                fl=1;
                break;
            }
        }
        if(fl==1)
        {
            i1=i;
            i++;
            for(;i<n;i++)
            {
                if(st2[i1]==st2[i]&&st2[i]!=st1[i])
                {
                    ch=st2[i];
                    st2[i]=st1[i1];
                    st1[i1]=ch;
                    break;
                }
            }
            fl=0;
            for(i=0;i<n;i++)
            {
                if(st1[i]!=st2[i])
                {
                    fl=1;
                    break;
                }
            }

        }
        //cout<<st1<<" "<<st2<<endl;
        con(fl);
    }
}
