#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
using namespace std;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

template<typename ...Ts>
void show(Ts... ts){
  cout<<"#:";
  auto print=[](auto v){cout<<v<<" ";};
  initializer_list<int>{(void(print(ts)),0)...};
  cout<<endl;
}

ll cnt(ll x){
    vector<int> dp(x+1,0);
    dp[0]=1;dp[1]=1;
    REP(i,1,x){
        dp[i+1]=dp[i]+dp[i-1];
        dp[i+1]%=mod;
    }
    return dp[x];
}

vector<int> subv(vector<int> s,int n,int d){
    vector<int> rt;
    rep(i,d)rt.push_back(s[n+i]);
    return rt;
}

int check(vector<int> s){
    int n=s.size();
    vector<int> ac(1,0);
    rep(i,n*2){
        ac.push_back(ac[i]+s[i%n]);
        //show(ac[i+1],i);
    }
    vector<int> ttt=subv(ac,0,n);
    auto m=min_element(all(ttt));
    int ii=distance(ttt.begin(),m);
    int mm=*m;
    //show("ii,m",ii,mm,ac.size());
    
    int rt=0;
    bool fl=true;
    
    REP(i,ii,ii+n){
        if(ac[i]-mm<0){
            fl=false;
        }
        
        if (ac[i]-mm==0){
            rt++;
        }
    }
    //    show("i",i,ac[i]);
    if(fl==false)rt=-1;
    
    return rt;
}
    

int main(void){
    int n,ans=0;
    string s;
    cin>>n>>s;
    if (n%2==1){
        cout<<0<<endl;
        cout<<1<<' '<<1<<endl;
        return 0;
    }
    
    vector<int> t(n,0);
    rep(i,n){
        if(s[i]=='('){
            t[i]=1;
        }else{
            t[i]=-1;
        }
    }
    
    int l=1,r=1;
    rep(i,n){
        REP(j,i,n){
            vector<int> c=t;
            swap(c[i],c[j]);
            //int tmp=0;
            int tmp=check(c);
            if(tmp>ans){
                ans=tmp;
                l=i+1;
                r=j+1;
            }
            
        }
    }
        /*
        vector<int> a;
        rep(i,n){
            cin>>x;
            a.push_back(x);
        }
    
        sort(all(a),greater<int>());
        sort(all(a));
        */
    //show("check(t)=",check(t));
    cout<<ans<<endl;
    cout<<l<<' '<<r<<endl;
    
}


