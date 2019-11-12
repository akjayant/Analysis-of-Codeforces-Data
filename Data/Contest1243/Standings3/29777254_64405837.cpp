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
                                                    int n; cin>>n;
                                                    string a,b; cin>>a>>b;
                                                    vector<int> bi(26,0);
                                                    for(auto x: a)
                                                        bi[x-'a']^=1;
                                                    for(auto x: b)
                                                        bi[x-'a']^=1;
                                                    int ok = 1;
                                                    for(auto x: bi)
                                                        ok &= !x;

                                                    if(!ok)
                                                    {
                                                        cout<<"No\n";
                                                    }
                                                    else
                                                    {
                                                        vector<pair<int,int>> v;
                                                        rep(i,0,n)
                                                        {
                                                            if(a[i] == b[i]) continue;
                                                            int done = 0;
                                                            rep(j,i+1,n)
                                                            {
                                                                if(a[i] == a[j])
                                                                {
                                                                    swap(b[i], a[j]);
                                                                    done = 1;
                                                                    v.push_back({j, i});
                                                                    break;
                                                                }
                                                            }
                                                            if(!done)
                                                            rep(j,i+1,n)
                                                            {
                                                                if(a[i] == b[j])
                                                                {
                                                                    swap(b[j], a[i + 1]);
                                                                    v.push_back({i + 1, j});
                                                                    swap(b[i], a[i + 1]);
                                                                    v.push_back({i + 1, i});
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                        cout<<"Yes\n";
                                                        cout<<v.size()<<endl;

                                                        for(auto x: v)
                                                            cout<<x.F+1<<' '<<x.S+1<<'\n';
                                                    }
                                                }

                                                rt 0;
                                        }



















