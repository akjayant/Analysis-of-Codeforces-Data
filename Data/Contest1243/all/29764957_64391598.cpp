/*enjoy karo yaar*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

#define     int          long long int
#define     fast()       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)       x.begin(),x.end()
#define     mem(a,b)     memset(a,b,sizeof(a))
#define     gcd(a,b)     (__gcd((a),(b)))
#define     lcm(a,b)     (((a)*(b))/gcd((a),(b)))
#define     pb           push_back
#define     ins          insert
#define     F            first
#define     S            second

const int inf=1e18,M=1e9+7;
const int N=1;

void solve()
{
    int n;
    cin>>n;

    string s,t;
    cin>>s>>t;

    string str1="",str2="";
    int cnt=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]!=t[i])
        {
            ++cnt;

            if(cnt==3)
            {
                cout<<"No\n";
                return;
            }

            str1+=s[i];
            str2+=t[i];
        }
    }

    if(cnt==1)
    {
        cout<<"No\n";
        return;
    }

    if(str1[0]==str1[1] && str2[0]==str2[1])
        cout<<"Yes\n";
    else
        cout<<"No\n";
}

int32_t main()
{
    fast();

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}

