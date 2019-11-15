#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string>vst;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef map<int,int> dct;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
#define all(ct) ct.begin() , ct.end()
#define endl "\n"
#define fr(i,a) for(auto i:a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define in(d,v) d.find(v)!=d.end()
#define mp make_pair

bool compare(pair<int,pii> a, pair<int,pii> b){
    if(a.first!=b.first)return a.first>b.first;
    return a.second<b.second;
}

const int mod = 1e9 + 7;
const ll inf = ll(1e18);

ll modexp(ll x,ll n,ll k){
    if(n==0)return k;
    if(n%2==0)return modexp((x*x)%mod,n/2,k);
    return (x*modexp((x*x)%mod,n/2,k))%mod;
}


int main(){
    fastio;
    //clock_t tm = clock();
    ll n,k,t,x,y;char  *s1=(char *)malloc(50),*s2=(char *)malloc(50);
    cin>>t;
    while(t--){
        cin>>n;cin>>s1;cin>>s2;
        vi ch(26,0),srtd(n,0);
        f(i,0,n){
            if(s1[i]==s2[i]){
                srtd[i]=1;
                continue;
            }
            ch[s1[i]-'a']++;
            ch[s2[i]-'a']++;
        }
        int flag=1;
        f(i,0,26){
            if(ch[i]%2==1){
                cout<<"No"<<endl;
                flag=0;break;
            }
        }
        if(flag){
            int op=0; vii opns;
            for(char i='a';i<='z';i++){
                if(ch[i-'a']==0)continue;
                vi up,lw;
                f(j,0,n){
                    if(s1[j]==i and s2[j]==i)continue;
                    if(s1[j]==i)up.pb(j);
                    if(s2[j]==i)lw.pb(j);
                }
                x=-1;y=-1;
                if(!up.empty()){
                    for(int j=0;j<int(up.size())-1;j+=2){
                        op++;
                        opns.pb({up[j+1]+1,up[j]+1});
                        s1[up[j+1]]=s2[up[j]];
                        s2[up[j]]=i;
                        srtd[up[j]]=1;
                    }
                    if(int(up.size())%2==1)x=up[int(up.size())-1];
                }
                if(!lw.empty()){
                    for(int j=0;j<int(lw.size())-1;j+=2){
                        op++;
                        opns.pb({lw[j]+1,lw[j+1]+1});
                        s2[lw[j+1]]=s1[lw[j]];
                        s1[lw[j]]=i;
                        srtd[lw[j]]=1;
                    }
                    if(int(lw.size())%2==1)y=lw[int(lw.size())-1];
                }
                if(x!=-1){
                    op+=2;
                    opns.pb({y+1,y+1});
                    opns.pb({y+1,x+1});
                    srtd[x]=1;s2[y]=s1[y];s1[y]=s2[x];s2[x]=i;
                }
            }
            if(op<=2*n) {
                cout<<"Yes"<<endl;
                cout << op << endl;
                fr(i, opns)cout << i.first << " " << i.second << endl;
            }
        }
    }
    //cout<<((clock()-tm)*1.0)/CLOCKS_PER_SEC<<endl;
}