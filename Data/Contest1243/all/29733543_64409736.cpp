#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef map<ll,ll> mll;
#define MOD 1000000007
template<typename T> void prllList(std::initializer_list<T> li) { 
    for (const auto & value: li) 
        std::cout << value << " "; } 

#define ifr(i,n) for(ll i=0;i<n;++i)
#define dfr(i,n) for(ll i=n-1;i>=0;--i)
#define ifrd(i,s,n,d) for(ll i=s;i<n;i+=d)
#define dfrd(i,n,d) for(ll i=n-1;i>=0;i-=d)

ll find(string t,ll i,ll n,char x)
{
    ifrd(j,i+1,n,1){
        if(x==t[j])
        return j;
    }
    return -1;
}
main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
    ll te=1;
    cin>>te;
    while(te--)
    {
        ll n;
        cin>>n;
        string s ,t;
        cin>>s>>t;
        ll h[26]={0};
        ifr(i,n)
        {
            h[s[i]-'a']++;
            h[t[i]-'a']++;
        }
        bool f= true;
        ll op = 2*n;
        ifr(i,26)
        {
            if(h[i]%2!=0)
                f=false;
        }
        if(!f)
        {
            cout<<"No"<<endl;
            continue;
        }
        else{
            vector<pair<ll,ll> > v;
            ifr(i,n)
            {
                if(s[i]!=t[i])
                {
                    ll x1= find(t,i,n,t[i]);
                    ll x2= find(s,i,n , t[i]);
                    if(x1!=-1 && op>0){
                        op--;
                        v.push_back({i,x1});
                        char x =s[i];
                        s[i] = t[x1];
                        t[x1] = x;
                    }
                    else if(x2!=-1 && op>0)
                    {
                        op-=2;
                        v.push_back({x2, i+1});
                        char x= s[x2];
                        s[x2] = t[i+1];
                        t[i+1] = x;
                        v.push_back({i,i+1});
                        x = s[i];
                        s[i] = t[i+1];
                        t[i+1] = x;
                    }
                    else{
                        f=false;
                    }
                    
                }
            }
            if(!f){
                cout<<"No"<<endl;
                continue;
            }
            else{
                cout<<"Yes"<<endl;
                cout<<v.size()<<endl;
                ifr(i,v.size())
                    cout<<v[i].first+1<<" "<<v[i].second+1<<endl;
            }
        }
    }
}
