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
                                                while(k --> 0)
                                                {
                                                    ll n; cin>>n;
                                                    string a,b; cin>>a>>b;
                                                    int w = -1;
                                                    bool ok=1;
                                                    rep(i,0,n)
                                                    {
                                                        if(a[i]!=b[i])
                                                        {
                                                            if(w==11111)
                                                            {
                                                                ok = 0;
                                                                break;
                                                            }
                                                            if (w == -1)
                                                            {
                                                                w = i;
                                                            }
                                                            else
                                                            if(a[w] == a[i] && b[w] == b[i])
                                                            {
                                                                w = 11111;
                                                            }
                                                            else
                                                            {
                                                                ok = 0;
                                                                break;
                                                            }
                                                        }
                                                    }
//                                                    error(w,ok);
                                                    cout<<(ok&&w==11111?"YES\n":"NO\n");
                                                }

                                                rt 0;
                                        }



















