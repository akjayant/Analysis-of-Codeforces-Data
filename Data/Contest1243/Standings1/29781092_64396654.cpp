#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define double long double
#define f(i, a, b) for(int i=(a);i<=(b);++i)
#define rf(i, a, b) for(int i=(a);i>=(b);--i)
#define Cl(a) memset(a,0,sizeof(a))
#define Cln(a) memset(a,0xff,sizeof(a))
#define cp(a, b) memcpy(a,b,sizeof(b))
#define sz(a) ((int)((a).size()))
#define pb emplace_back
#define sqr(x) ((x)*(x))
#define all(a) (a).begin(),(a).end()
#define mpr make_pair
#define x first
#define y second
#define Debug(a) cout<<"---"<<a<<"---"<<endl;
#define endl '\n'

using namespace std;
const int INF = ~(1 << 31);
const int N = 50+ 5;
const int mod = 1e9 + 7;
int a[N];
int n, m;
int get(char*s,char ch,int x){
    f(i,x,n-1)if(s[i]==ch)return i;
    return -1;
}
char s[N],t[N];
vector<pair<int,int>>an;
void swap1(int x,int y){
    char tmp=s[x];
    s[x]=t[y];
    t[y]=tmp;
}
int main() {
//    freopen("../../%s/data.in", "r", stdin);
   // ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        an.clear();
        cin>>n>>s>>t;
        Cl(a);
        f(i,0,n-1)a[s[i]-'a']++;
        f(i,0,n-1)a[t[i]-'a']++;
        bool is=true;
        f(i,0,25)if(a[i]&1)is=false;
        if(!is){
            cout<<"No\n";
            continue;
        }
        f(i,0,n-1){
            if(s[i]==t[i])continue;
            int p=get(s,s[i],i+1);
            if(p!=-1){
                swap1(p,i);
                an.push_back(make_pair(p,i));
            }else{
                int q=get(t,s[i],i);
                an.push_back(make_pair(i+1,q));
                an.push_back(make_pair(i+1,i));
                swap1(i+1,q),swap1(i+1,i);
            }
        }
        cout<<"Yes\n";
        if(sz(an)==0){
            cout<<"1\n1 1\n";
            continue;
        }
        cout<<sz(an)<<endl;
        for(auto p:an)cout<<p.first+1<<' '<<p.second+1<<endl;
    }
    return 0;
}
