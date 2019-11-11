#include <bits/stdc++.h>
using namespace std;
#define idfc ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define ll long long
#define pb push_back
#define mp make_pair
#define nt _int128
#define ld long double
long double PI =3.14159265358979323846;


const ll modo=1e9+7;
const ll inf=1e15;
const ll ms=(1e5) +5;
ll ar[ms];

int main()
{
    idfc;
    string s;
    cin>>s;
    int n=s.length();
    int i;
    char e;
    for(i=0;i<n;i++)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            cout<<0;
            return 0;
        }
    }
    ll ans=1;
    ll t=2;
    ar[0]=1;
    ar[1]=1;
    for(i=2;i<=n;i++)
    {
        ar[i]=(ar[i-1]+ar[i-2])%modo;
    }
    char pr=s[0];
    ll f=1;
    for(i=1;i<n;i++)
    {
       if(s[i]==pr)
       {
           f++;
       } else{
           if(pr=='n'||pr=='u')
           {
               ans*=ar[f];
               ans%=modo;
           }
           f=1;
       }
       pr=s[i];
    }
    if(pr=='n'||pr=='u')
    {
        ans*=ar[f];
        ans%=modo;
    }
    cout<<ans;
    return 0;
}