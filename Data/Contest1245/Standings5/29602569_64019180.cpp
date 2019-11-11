/*
* @Author: XiaoBanni
* @Email:  xjc5069@gmail.com
* @Date:   2019-11-01 23:14:37
* @Last Modified by:   Y
* @Last Modified time: 2019-11-01 23:14:37
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
typedef priority_queue<int> maxpque;
typedef priority_queue<int,vector<int>,greater<int> > minpque;
const int MAXN = 1e5+5;
const int INF=INT_MAX/2;
const ll LLINF=9223372036854775807/2;
#define in(a) scanf("%d",&a)
#define inll(a) scanf("%lld",&a)
#define out(a) printf("%d",a)
#define outll(a) printf("%lld",a)
#define outln(a) printf("%d\n",a)
#define outllln(a) printf("%lld\n",a)
#define fin(i,st,n) for(int i=st;i<n;i++)
#define fin2(i,st,n) for(int i=st;i<=n;i++)
#define c(a) cout<<"***"<<a<<endl;
#define mk make_pair
#define pb push_back
#define f first
#define s second
#define maxpque(type) priority_queue<type>
#define minpque(type) priority_queue<type,vector<type>,greater<type> > //pay attention that no ',' in type
#define gcd __gcd
#define IOS ios::sync_with_stdio(false);cin.tie(0); cout.tie(0); 

const ll MOD=1e9+7;
ll dp[MAXN][2];
//dp[i][0]以u为结尾
//dp[i][1]以w为结尾
int main(){
	IOS
	dp[1][0]=1;
	dp[1][1]=0;
	fin2(i,2,MAXN-1){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
		dp[i][1]=dp[i-1][0];
	}
	string s;
	cin>>s;
	int len=s.size();
	fin2(i,0,len-1){
		if(s[i]=='w'||s[i]=='m'){
			cout<<0<<endl;
			return 0;
		}
	}
	s+="#";
	char ch='u';
	ll res=1;
	fin2(i,0,len-1){
		if(s[i]==ch){
			int cnt=0;
			while(s[i]==ch){
				cnt++;
				i++;
			}
			res=(res*((dp[cnt][0]+dp[cnt][1])%MOD))%MOD;
			i--;
		}
	}
	ch='n';
	fin2(i,0,len-1){
		if(s[i]==ch){
			int cnt=0;
			while(s[i]==ch){
				cnt++;
				i++;
			}
			res=(res*((dp[cnt][0]+dp[cnt][1])%MOD))%MOD;
			i--;
		}
	}
	cout<<res<<endl;	
}