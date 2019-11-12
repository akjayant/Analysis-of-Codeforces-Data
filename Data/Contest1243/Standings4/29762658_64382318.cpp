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
    string s1,s2;
    int main()
    {
        cin>>T;
        FOR(k,0,T)
        {
            cin>>N;
            cin>>s1>>s2;
            bool unamal=false;
            char a,b;
            bool dosmal=false;
            bool cambio=false;
            FOR(i,0,N)
            {
                if(!unamal)
                {
                    if(s1[i]!=s2[i])
                    {
                        a=s1[i];
                        b=s2[i];
                        unamal=true;
                    }
                } else{
                    if(s1[i]!=s2[i])
                    {
                        if(s2[i]==b&&s1[i]==a)
                        {   if(cambio==false)
                            {cambio=true;}
                            else{
                                dosmal=true;
                            }
                        }
                        else
                        {
                            dosmal=true;
                        }
                    }
                }
            }
            if(dosmal) cout<<"No"<<endl;
            else if(unamal&&!cambio) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }


    }