#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
#define FF first
#define SS second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
#define INF 1e18
#define MOD 1000000007
#define pi pair<ll,ll>
#define sc(x) scanf("%lld",&x)
#define pf(x) printf("%lld\n",x)
#define PI 3.14159265
typedef long long int lli;
typedef vector< lli > vlli;
typedef pair<lli,lli> plli;
typedef unordered_set<lli> slli;
typedef unordered_map<lli,lli> mlli;
 
ll pwr(ll base, ll p, ll mod){
    ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll cost[100005][3];
ll indeg[100005];
vector <int> v[100005];
vector <int> xx;
int final[100005];


void func(int pos, int p){
    xx.push_back(pos);
    for(int i=0; i<v[pos].size(); i++){
        if(v[pos][i]!=p){
            func(v[pos][i], pos);
        }
    }
    return;
}

int main(){
    int n,a , b, st;
    ll temp, ind;
    cin>>n;
    for(int i=0; i<3; i++){
        for(int j=0; j<n; j++){
            cin>>cost[j][i];
        }
    }
    bool chk=true;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        a--;
        b--;
        indeg[a]++;
        indeg[b]++;
        if(indeg[a]>2 || indeg[b]>2){
            chk=false;
        }
        v[a].push_back(b);
        v[b].push_back(a);
    }
    st=-1;
    for(int i=0; i<n; i++){
        if(indeg[i]==1 && st==-1){
            st=i;
            break;
        }
    }

    if(chk==false){
        cout<<"-1"<<endl;
    }
    else{
        func(st, -1);
        ll ans[7];
        ll mn, x;
        for(int i=1; i<=6; i++){
            ans[i]=0;
        }
        for(int i=0; i<xx.size(); i++){
            if(i%3==0){
                ans[1]+=cost[xx[i]][0];
                ans[2]+=cost[xx[i]][0];
                ans[3]+=cost[xx[i]][1];
                ans[4]+=cost[xx[i]][1];
                ans[5]+=cost[xx[i]][2];
                ans[6]+=cost[xx[i]][2];
            }
            if(i%3==1){
                ans[1]+=cost[xx[i]][1];
                ans[2]+=cost[xx[i]][2];
                ans[3]+=cost[xx[i]][0];
                ans[4]+=cost[xx[i]][2];
                ans[5]+=cost[xx[i]][0];
                ans[6]+=cost[xx[i]][1];
            }
            if(i%3==2){
                ans[1]+=cost[xx[i]][2];
                ans[2]+=cost[xx[i]][1];
                ans[3]+=cost[xx[i]][2];
                ans[4]+=cost[xx[i]][0];
                ans[5]+=cost[xx[i]][1];
                ans[6]+=cost[xx[i]][0];
            }
        }
        mn=ans[1];
        x=1;
        for(int i=2; i<=6; i++){
            if(ans[i]<mn){
                mn=ans[i];
                x=i;
            }
            
        }
        if(x==1){
            for(int i=0; i<xx.size(); i++){
                if(i%3==0){
                    final[xx[i]]=1;
                }
                if(i%3==1){
                    final[xx[i]]=2;
                    
                }
                if(i%3==2){
                    final[xx[i]]=3;
                   
                }
            }
        }
        else if(x==2){
            for(int i=0; i<xx.size(); i++){
                if(i%3==0){
                    final[xx[i]]=1;
                }
                if(i%3==1){
                    final[xx[i]]=3;
                    
                }
                if(i%3==2){
                    final[xx[i]]=2;
                   
                }
            }
        }
        else if(x==3){
            for(int i=0; i<xx.size(); i++){
                if(i%3==0){
                    final[xx[i]]=2;
                }
                if(i%3==1){
                    final[xx[i]]=1;
                    
                }
                if(i%3==2){
                    final[xx[i]]=3;
                   
                }
            }
        }
        else if(x==4){
            for(int i=0; i<xx.size(); i++){
                if(i%3==0){
                    final[xx[i]]=2;
                }
                if(i%3==1){
                    final[xx[i]]=3;
                    
                }
                if(i%3==2){
                    final[xx[i]]=1;
                   
                }
            }
        }
        else if(x==5){
            for(int i=0; i<xx.size(); i++){
                if(i%3==0){
                    final[xx[i]]=3;
                }
                if(i%3==1){
                    final[xx[i]]=1;
                    
                }
                if(i%3==2){
                    final[xx[i]]=2;
                   
                }
            }
        }
        else if(x==6){
            for(int i=0; i<xx.size(); i++){
                if(i%3==0){
                    final[xx[i]]=3;
                }
                if(i%3==1){
                    final[xx[i]]=2;
                    
                }
                if(i%3==2){
                    final[xx[i]]=1;
                   
                }
            }
        }
        cout<<mn<<endl;
        for(int i=0; i<n; i++){
            cout<<final[i]<<" ";
        }
        cout<<endl;


        
    }
    



       

}