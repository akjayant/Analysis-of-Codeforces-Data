    // Siddhant Gautam
    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define ull unsigned long long ll
    #define all(x) x.begin(),x.end()
    #define ff first
    #define ss second
    #define bitcount __builtin_popcountll
    #define INF 1e18+9
    #define eb emplace_back
    #define pb push_back
    #define mp make_pair
    #define FIO ios_base::sync_with_stdio(false)
    #define mod 1000000007
    ll power(ll a,ll b,ll m)
    {
        a%=m;
        ll ret=1;
        while(b)
        {
            if(b&1)
                ret=((ret%m)*(a%m))%m;
            a=((a%m)*(a%m))%m;
            b>>=1;
        }
        return ret;
    }
     
    int main()
    {
        FIO;
        
        int t;
        cin >> t;
     
        while(t--){
            int n;
            cin >> n;
     
            string s,t;
            cin >> s >> t;
     
            vector < int > v;
     
            for(int i=0;i<n;i++){
                if(s[i] != t[i]){
                    v.pb(i);
                }
            }
     
            if(v.size() != 2 & v.size() != 0){
                cout << "No" << endl;
            }
            else{
                if(v.size() == 0){
                    cout << "Yes" << endl;
                }
                else{
                    if(s[v[0]] != s[v[1]] || t[v[0]] != t[v[1]]){
                        cout << "No" << endl;
                    }
                    else{
                        cout << "Yes" << endl;
                    }
                }
            }
        }   
        return 0;
    }