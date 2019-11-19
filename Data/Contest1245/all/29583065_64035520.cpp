/* ****revpro**** */
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define endl	   '\n'
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b-1;i>=a;i--)    
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mii	    map<ll,ll>
using namespace std;

#define N  
ll  num[2][35]; // two numbers num[0]>=num[1]
ll DP[35][2][2][2][2][2];
ll call(ll pos,ll f1,ll f2,ll f3,ll f4,ll f5){
    if(pos == 35){
      return 1;
    }
    if(DP[pos][f1][f2][f3][f4][f5] != -1) return DP[pos][f1][f2][f3][f4][f5];
    ll res = 0;
    ll LMT = f1?1:num[0][pos];
    ll ST = f2?0:num[1][pos];
    ll LMT1=f3?1:num[0][pos];
    ll ST1=	f4?0:num[1][pos];
    rep(dgt,ST,LMT+1){ 
    	rep(dgt1,ST1,LMT1+1)
    		if(dgt1!=dgt)
            res = (res+call(pos+1,f1||(dgt<LMT),f2||(dgt>ST),f3||(dgt1<LMT1),f4||(dgt1>ST1),1LL));
        	else if((dgt==dgt1)&&(dgt1==0))
        	res=(res+call(pos+1,f1||(dgt<LMT),f2||(dgt>ST),f3||(dgt1<LMT1),f4||(dgt1>ST1),f5));

    }
    return DP[pos][f1][f2][f3][f4][f5] = res;
}
ll solve(){
	 ll a[2]; 
	cin>>a[1]>>a[0];
    rep(i,0,2){	
        rep(j,0,35){
            num[i][j]=a[i]%2;
            a[i]/=2;
        }
        reverse(num[i],num[i]+35);
    }
    memset(DP, -1, sizeof(DP));
    return call(0, 0, 0,0 , 0,0);
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
	cin>>TESTS;
	while(TESTS--)
	{
		cout<<solve()<<endl;
	}
	return 0;
}