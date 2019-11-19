#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define N 100007
#define M 1e16

int n;
ll k;

int main()
{
//    freopen("f.txt","r",stdin);
//    freopen("g.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    ll arr[n],mx=0,mn=1e10;
    set<ll>s;
    set<ll>::iterator it,jt,kt,lt;
    map<ll,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mx=max(mx,arr[i]);
        mn=min(mn,arr[i]);
        s.insert(arr[i]);
        mp[arr[i]]++;
    }
    ll x,y,z,dif,need,p,q,a,b,c,d,e,f,need1,dif1;
    kt=s.end();
    kt--;
    lt=kt;
    lt--;
    //cout<<*kt<<" "<<*lt<<endl;
    jt=s.begin();
    jt++;
    if(mx==mn)
    {
        cout<<0<<endl;
        return 0;
    }
    for(it=s.begin();;)
    {
        a=*kt;
        b=mp[a];
        c=*lt;
        x=*it;
        y=mp[x];
        z=*jt;
//        cout<<a<<" "<<b<<" "<<c<<endl;
//        cout<<x<<" "<<y<<" "<<z<<endl;
        if(y<b)
        {
            dif=z-x;
            need=dif*y;
            if(need<=k)
            {
                k-=need;
                mp[z]+=y;
                mn=z;
            }
            else if(y<=k)
            {
                p=k/y;
                mn=x+p;
                break;
            }
            else
                break;
            it++;
            jt++;
        }
        else
        {
            dif=a-c;
            need=dif*b;
            if(need<=k)
            {
                k-=need;
                mp[c]+=b;
                mx=c;
            }
            else if(b<=k)
            {
                p=k/b;
                mx=a-p;
                break;
            }
            else
                break;
            kt--;
            lt--;
        }
        if(z==a)
        {
            break;
        }
    }
    //cout<<mx<<" "<<mn<<endl;
    cout<<abs(mx-mn)<<endl;
    return 0;
}

