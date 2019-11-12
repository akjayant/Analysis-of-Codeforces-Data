/*
 _     _    ___  ___  __ __ 
| |   | |  |__ \|__ \/_ /_ |
| |__ | |__   ) |  ) || || |
| '_ \| '_ \ / /  / / | || |
| |_) | |_) / /_ / /_ | || |
|_.__/|_.__/____|____||_||_|

*/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

#define N  100005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
   cin>>TESTS;
    while(TESTS--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        map<char,ll>lol;
        rep(i,0,n)
        {
            lol[s[i]]++;
            lol[t[i]]++;
        }
        bool f=0;
        for(auto u:lol)
        {
            if(u.S%2==1)
            {
                f=1;
                break;
            }
        }
        if(f==1)
        {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        vector<pii>v;
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i])
                continue;
            bool flag=0;
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==t[j])
                {
                    v.pb({n,j+1});
                        char c=s[n-1];
                        s[n-1]=t[j];
                        t[j]=c;
                        swap(s[n-1],t[i]);
                        v.pb({n,i+1});
                        flag=1;
                        break;

                    // flag=1;
                    // v.pb({i+1,j+1});
                    // swap(t[i],t[j]);
                    // break;
                }
            }
            // cout<<flag<<endl;
            if(flag==0)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(s[j]==s[i])
                    {
                        // cout<<i<<" "<<j<<endl;
                        v.pb({j+1,i+1});
                        swap(s[j],t[i]);
                        break;
                    }
                }
            }

            }
        cout<<v.size()<<endl;
        for(auto u:v)
        {
            cout<<u.F<<" "<<u.S<<endl;
        }    
        
    }
    return 0;
}

/*
1
5
souse
houhe
*/
