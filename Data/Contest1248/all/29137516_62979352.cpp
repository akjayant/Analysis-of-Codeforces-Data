#include <bits/stdc++.h>
    using namespace std;

    /*
                      __       ____      __  __      __  _____   __      __       __ __         __         
                     /  \     |    \    |  ||  |    |  ||  __ \ |  |    |  |     /  \  \      /  /                  
                    /    \    |     \   |  ||  |    |  || |_/  ||  |    |  |    /    \  \    /  /                   
                   /  /\  \   |  |\  \  |  ||  |    |  ||  _  / |  |____|  |   /  /\  \  \  /  /                   
                  /  /__\  \  |  | \  \ |  ||  |    |  || | \ \ |   ____   |  /  /__\  \  \/  /                      
                 /  ______  \ |  |  \  \|  | \  \__/  / | |_/  ||  |    |  | /  ______  \    /                       
                /__/      \__\|__|   \_____|  \______/  |_____/ |__|    |__|/__/      \__\__/
                                                         
    */



    typedef long long ll;
    typedef long double ld;
    typedef string str;
    typedef vector<int> vi;
    typedef vector<long long> vll;
    typedef vector<str> vs;
    typedef map<long long,long long> mll;
    typedef map<int,int> mii;
    typedef map<string,int> msi;
    typedef map<char,int> mci;
    typedef pair<int,int> pii;
    typedef pair<long long,long long> pll;
    

    #define pb                 push_back
    #define mp                 make_pair
    #define F                 first
    #define S                 second
    #define forn(i, n)         for(ll i = 0; i < n; i++)
    #define fori(i,a,b)        for(ll i = a; i < b; i++)
    #define ford(i,a,b)        for(ll i = a; i >=b; i--)
    #define input(vec)         for(ll i=0;i<vec.size();cin>>vec[i++]);
    #define output(vec)        for(ll i=0;i<vec.size();cout<<vec[i++]);cout<<endl;
    #define sort(vec)       sort(vec.begin(),vec.end());
    #define sz(vec)         vec.size();
    #define ln(s)           s.length();
    #define mx(vec)         *max(vec.begin(),vec.end())
    #define mn(vec)         *min(vec.begin(),vec.end())
    #define sm(vec,k)         accumulate(vec.begin(),vec.end(),k)

    #define mem(x)          memset(x,0,sizeof(x));
    #define test int t;     cin >> t; while(t--)
    #define debug(x)        cout << "-->" << #x << ':' << x << "<--"<<endl;
    #define deathnote()     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define maxx            1000007
    #define mod             1000000007
    #define mod1            998244353
    #define PI              3.1415926535897932384626433832795l
    #define sp(n)           cout<<fixed<<setprecision(n);

    
    ll power(ll x, ll y, ll p){
        ll res = 1;
        x = x % p;
        while (y > 0){
            if (y & 1)
                res = (res*x) % p;
            y = y>>1;
            x = (x*x) % p;
        }
        return res;
    }

    int main(){
        deathnote();
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            vll p(n);
            input(p);
            ll m;
            cin>>m;
            vll q(m);
            input(q);
            ll x1=0,x2=0,y1=0,y2=0;
            for(ll i=0;i<n;i++){
                // cout<<p[i]<<" ";
                if(p[i]%2){
                    y1++;
                }
                else{
                    x1++;
                }
            }
            // cout<<endl;
            for(ll i=0;i<m;i++){
                // cout<<q[i]<<" ";
                if(q[i]%2){
                    y2++;
                }
                else{
                    x2++;
                }
            }
            // cout<<endl;
            // cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<" ";
            cout<<x1*x2+y1*y2<<endl;
        }
        return 0;
    }