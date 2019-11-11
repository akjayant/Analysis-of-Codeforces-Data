/*
* @Author: XiaoBanni
* @Email:  xjc5069@gmail.com
* @Date:   2019-11-01 22:46:28
* @Last Modified by:   Y
* @Last Modified time: 2019-11-01 22:46:28
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

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
	int t;
	in(t);
	while(t--){
		int a,b;
		in(a);in(b);
		if(gcd(a,b)==1){
			printf("Finite\n");
		}
		else{
			printf("Infinite\n");
		}
	}
}