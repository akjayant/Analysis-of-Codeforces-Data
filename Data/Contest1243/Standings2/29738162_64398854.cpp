#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#define ll long long int
#define hell 1000000007LL
using namespace std;
ll power(ll x, ll y){ 
    if(y==0)
     return 1;
    else
    {
        ll p=power(x,y/2);
        if(y%2==0)
         return (p*p)%hell;
        else
        return (x*((p*p)%hell))%hell;
    }}
ll gcd(ll x,ll y)
{
    if(y==0)
     return x;
    else
    return gcd(y,x%y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    ll q;
    cin>>q;
    while(q--)
    {
        ll n,f=0;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int a[26],b[26];
        map<int,int>mp;
        for(int i=0;i<26;i++)
        {
            a[i]=0;
            b[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            a[s[i]-'a']++;
            b[t[i]-'a']++;
            if(s[i]==t[i])
             mp[i]=1;
        }
        for(int i=0;i<26;i++)
        {
            if(a[i]%2!=b[i]%2){
             f++;
             break;}
        }
        if(f)
         cout<<"No"<<"\n";
        else
        {
            vector<pair<int,int>>v;
            for(int i=0;i<n;i++)
            {
                if(mp[i]==0)
                {
                    int f=0;
                    for(int j=i+1;j<n;j++)
                    {
                        if(mp[j]==0&&s[j]==s[i])
                        {
                            f++;
                            char x=s[j];
                            s[j]=t[i];
                            t[i]=x;
                            mp[i]=1;
                            v.push_back(make_pair(j,i));
                            if(s[j]==t[j])
                             mp[j]=1;
                            break;
                        }
                    }
                    if(f==0)
                    {
                        for(int j=i+1;j<n;j++)
                        {
                            if(mp[j]==0)
                            {
                                if(t[j]==s[i])
                                {
                                    char x=t[j];
                                    t[j]=s[j];
                                    s[j]=x;
                                    v.push_back(make_pair(j,j));
                                    char y=t[i];
                                    t[i]=s[j];
                                    s[j]=y;
                                    mp[i]=1;
                                    v.push_back(make_pair(j,i));
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            cout<<"Yes"<<"\n"<<v.size()<<"\n";
            for(int i=0;i<v.size();i++)
             cout<<v[i].first+1<<" "<<v[i].second+1<<"\n";
        }
    }}