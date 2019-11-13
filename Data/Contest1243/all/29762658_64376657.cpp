    #include <bits/stdc++.h>

    #define MAX 10e15+1
    #define MIN 0
    #define MOD 998244353
    #define FOR(i, a, b)    for(int i=a;i<b;i++)
    using namespace std;
    typedef long long ll;
    typedef vector<ll> vll;
    typedef vector<int> vi;
    typedef pair<ll,ll> pll;
    typedef pair<double,double> ii;
    typedef vector<pll> vpll;
    ll N; ll M; ll Q; ll T;
    vll vl;
    int main()
    {
        cin>>T;
        FOR(k,0,T)
        {  
            cin>>N;
            
            vl.resize(N);
            FOR(i,0,N)
            {
                cin>>vl[i];
            }
            sort(vl.begin(),vl.end());
            for(int i=1;i<=N;i++)
            {
                if(vl[N-i]<i) {cout<<i-1<<endl; break;}
                if(i==N) cout<<N<<endl;
            }
            vl.clear();
        }

    }