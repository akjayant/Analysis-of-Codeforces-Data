#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define fi first
#define se second

ll powe(ll a,ll b)
{
    ll n=1;
    while(b)
    {
        if(b&1)
        {
            n*=a;
        }
        a*=a;
        b/=2;
    }
    return n;
}

bool isVowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return true;
    return false;
}

bool check(string s)
{
    int len = s.length(),c;
    int i=0;
    while(1)
    {
        if(i<len && isVowel(s[i]))
            i++;
        else
        {
            break;
        }
    }
    if(i==len)
        return true;
    while(i<len)
    {
        if(i<len && isVowel(s[i]))
        {
            c=0;
            while(i<len && isVowel(s[i]))
            {
                c++;
                i++;
            }
            if(i<len && c<2)
                return false;
        }
        else if(i==len)
            return true;
        else
        {
            c=0;
            while(i<len && (!isVowel(s[i])))
            {
                c++;
                i++;
            }
            if(c>1)
                return false;
        }
    }
    return true;
}

int main()
{
    boost
    ll t,n,m;
    cin>>t;
    ll i,ii,j,k;
    ll sum;
    ll num=0;
    while(t--)
    {
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n,greater<>());
        ll c=0,mi=0;
        for(i=0;i<n;i++)
        {
            c++;
            if(c>a[i])
            {
                break;
            }
        }
        if(i<n)
            cout<<c-1<<"\n";
            else
                cout<<c<<"\n";
    }
}
