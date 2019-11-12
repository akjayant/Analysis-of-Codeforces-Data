#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define PII pair<int,int>
#define PII2 pair<int,pair<int,int> >
#define PII3 pair<pair<int,int>,int >
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); }
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
int cnts[100],cntt[100],ok[100],n;
void solve()
{
   string s,t;
   cin>>n;
   cin>>s>>t;
   for(int i=0;i<=26;i++)
   {
       cnts[i]=0;
       cntt[i]=0;
   }
   for(auto it:s)cnts[it-'a']++;
   for(auto it:t)cntt[it-'a']++;
   for(int i=0;i<=26;i++)
       if((cnts[i]+cntt[i])%2){cout<<"No"<<'\n';return;}
   cout<<"Yes"<<'\n';
   vector<PII> ans;
   for(int i=0;i<n;i++)
   {
       if(s[i]!=t[i])
         for(int j=i+1;j<n;j++)
         {
             if(s[i]==t[j])
             {
                 swap(s[j],t[j]);
                 //cout<<j+1<<" "<<j+1<<'\n';
                 ans.push_back({j+1,j+1});
                 swap(s[j],t[i]);
                 //cout<<j+1<<" "<<i+1<<'\n';
                 ans.push_back({j+1,i+1});
                 break;
             }
             if(s[i]==s[j])
             {
                 swap(s[j],t[i]);
                 //cout<<j+1<<" "<<i+1<<'\n';
                 ans.push_back({j+1,i+1});
                 break;
             }
         }
   }
   cout<<ans.size()<<'\n';
   for(auto it:ans)cout<<it.fi<<" "<<it.se<<'\n';
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    //freopen("flash.inp", "r", stdin);
    //freopen("flash.out", "w", stdout);

    int t;cin>>t;while(t--)

    solve();
}
