                                        #include <bits/stdc++.h>

                                        typedef long long ll;
                                        typedef long double ld;
                                        #define rep(i,a,n) for(ll i=(a); i<(n); i++)
                                        #define per(i,a,n) for(ll i=(n-1); i>=(a); i--)
                                        #define F first
                                        #define S second
                                        #define maxx(a,b) a=max(a,b)
                                        #define minn(a,b) a=min(a,b)
                                        #define db(x) cerr<<#x<<" = "<<x<<endl
                                        #define N 1111111
                                        #define mod 1000000007
                                        #define rt return
                                        #define inf 123456789123456789ll

                                        using namespace std;

                                        #define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

                                        void err(istream_iterator<string> it) {}
                                        template<typename T, typename... Args>
                                        void err(istream_iterator<string> it, T a, Args... args)
                                        {
                                                cerr << *it << " = " << a << endl;
                                                err(++it, args...);
                                        }

                                        int main()
                                        {

                                                ios_base::sync_with_stdio(0);
                                                cin.tie(0);
                                                cout.tie(0);

                                                int k; cin>>k;
                                                while(k--)
                                                {
                                                    ll n; cin>>n;
                                                    vector<ll>v(n);
                                                    for(auto &x: v)
                                                        cin>>x;
                                                    sort(begin(v),end(v));
                                                    ll ans = 0;
                                                    rep(i,0,n)
                                                    {
                                                        maxx(ans, minn(v[i],n-i));
                                                    }
                                                    cout<<ans<<endl;
                                                }

                                                rt 0;
                                        }



















