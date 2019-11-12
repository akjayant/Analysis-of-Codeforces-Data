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
    ll q,n,m;
    cin>>q;
    ll i,ii,j,k;
    ll sum;
    ll num=0;
    string s,t;
    ll x,y;
    while(q--)
    {
        cin>>n;
        cin>>ws;
        cin>>s;
        cin>>ws;
        cin>>t;
        ll c=0;
        ll hash[26]={0};
        for(i=0;i<n;i++)
        {
            hash[s[i]-'a']++;
            hash[t[i]-'a']++;
        }
        for(i=0;i<26;i++)
        {
            if(hash[i]&1)
                break;
        }
        if(i<26)
        {
            cout<<"No\n";
            continue;
        }
        ll d=0;
        char ch;
        vector< pair<int,int> >v;
        for(i=0;i<n;i++)
        {
            if(s[i]==t[i])
                continue;
            d=0;
            for(j=i+1;j<n;j++)
            {
                if(s[j]==s[i])
                {
                    ch=s[j];
                    s[j]=t[i];
                    t[i]=ch;
                    c++;
                    d++;
                    v.pb(mp(j,i));
                    break;
                }
            }
            if(d>0)
                continue;
            for(j=i+1;j<n;j++)
            {
                if(s[i]==t[j])
                {
                    ch=s[j];
                    s[j]=t[j];
                    t[j]=ch;
                    c++;
                    v.pb(mp(j,j));
                    ch=t[i];
                    t[i]=s[j];
                    s[j]=ch;
                    c++;
                    v.pb(mp(j,i));
                    break;
                }
            }
        }
        cout<<"Yes\n";
        cout<<c<<"\n";
        for(i=0;i<c;i++)
        {
            cout<<v[i].fi+1<<" "<<v[i].se+1<<"\n";
        }
    }
}
