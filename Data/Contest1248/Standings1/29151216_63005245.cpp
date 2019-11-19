#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#ifndef ONLINE_JUDGE
    #include<lol.h>
#endif

#define all(c) (c).begin(),(c).end()
#define endl "\n"
#define ff first
#define ss second
#define allr(c) (c).rbegin(),(c).rend()
#define ifr(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pof pop_front
#define pob pop_back
#define pb emplace_back
#define pf emplace_front
#define fstm(m,n,r) m.reserve(n);m.max_load_factor(r)
#define mp make_pair
#define mt make_tuple
#define inf LLONG_MAX
#define os tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
typedef long long ll;
ll gcd(){return 0ll;} template<typename T,typename... Args> T gcd(T a,Args... args) { return __gcd(a,(__typeof(a))gcd(args...)); }
typedef map<ll,ll> mll;
typedef map<string,ll> msll;
typedef unordered_map<ll,ll> umap;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("/home/srinivas/Desktop/cp/input.txt","r",stdin);
        // freopen("/home/srinivas/Desktop/output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=0,l=-1,r=-1,t,o=0,c=0;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            if(i!=j && s[i]==s[j]) continue;
            stack< pair<char,int> > st;
            swap(s[i],s[j]);
            for(int k=0;k<n;k++) {
                if(!st.empty() && st.top().ff=='(' && s[k]==')') st.pop();
                else st.push(mp(s[k],k));
            }
            // if(i==4 && j==8) cout<<s<<endl;
            if(st.empty()) {
                t=0;
                for(int k=0;k<n;k++) {
                    if(!st.empty() && st.top().ff=='(' && s[k]==')') st.pop();
                    else st.push(mp(s[k],k));
                    if(st.empty()) t++;
                }
                if(t>ans) {
                    ans=t;
                    l=i;r=j;
                }
            }else{
                int ind;
                while(!st.empty()) {
                    // if(i==4 && j==8) cout<<st.top().ff<<" ";
                    if(st.top().ff==')') c++;
                    else  {
                        o++;
                        ind=st.top().ss;
                    }
                    st.pop();
                }
                // cout<<endl;
                if(o==c) {
                    t=0;
                    for(int k=0;k<n;k++) {
                        if(!st.empty() && st.top().ff=='(' && s[(k+ind)%n]==')') st.pop();
                        else st.push(mp(s[(k+ind)%n],(k+ind)%n));
                        if(st.empty()) t++;
                    }
                    if(t>ans) {
                        ans=t;
                        l=i;r=j;
                    }
                }
            }
            swap(s[i],s[j]);
        }
    }
    if(l==-1)
        cout<<"0\n1 1\n";
    else cout<<ans<<endl<<l+1<<" "<<r+1<<endl;
    return 0;
}