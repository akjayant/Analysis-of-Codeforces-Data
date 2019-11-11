/*
* @Author: XiaoBanni
* @Email:  xjc5069@gmail.com
* @Date:   2019-11-01 22:57:28
* @Last Modified by:   Y
* @Last Modified time: 2019-11-01 22:57:28
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

int main(){
	IOS
	int t;
	cin>>t;
	while(t--){
		int n,a,b,c;
		cin>>n>>a>>b>>c;
		string mess;
		cin>>mess;
		string res;
		int cnt=0;
		fin2(i,0,n-1){
			if(mess[i]=='R'){
				if(b>0){
					res+='P';
					cnt++;
					b--;
				}
				else{
					res+='.';
				}
			}else if(mess[i]=='P'){
				if(c>0){
					res+='S';
					cnt++;
					c--;
				}else res+='.';
			}else{
				if(a>0){
					res+='R';
					cnt++;
					a--;
				}else res+='.';
			}
		}
		if(cnt<(n+1)/2){
			cout<<"NO"<<endl;
			continue;
		}
		fin2(i,0,n-1){
			if(res[i]=='.'){
				if(a>0){
					res[i]='R';
					a--;
				}else if(b>0){
					res[i]='P';
					b--;
				}else{
					res[i]='S';
					c--;
				}
			}
		}
		cout<<"YES"<<endl;
		cout<<res<<endl;
	}
}