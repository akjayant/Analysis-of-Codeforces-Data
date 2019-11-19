/*
1 2 3 4
1 3 
2 4
n的所有因子
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 1000006
ll n;

bool vis[N];
ll prime[N],m;
void init(){
	for(int i=2;i<=1000000;i++){
		if(!vis[i])prime[++m]=i;
		for(int j=1;j<=m;j++){
			if(prime[j]*i>1000000)break;
			vis[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
}

ll p[N],mm;
void divide(ll x){
	mm=0;
	for(int i=1;i<=m;i++)if(x%prime[i]==0){
		p[++mm]=prime[i];
		while(x%prime[i]==0)
			x/=prime[i];
	}/*
	puts("1");
	cout<<x<<'\n';
	*/if(x>1)
		p[++mm]=x;
}

int main(){
	init();
	cin>>n;
	
	divide(n);
	if(mm==1 && p[1]==n){
		cout<<n<<'\n';
	} 
	else if(mm==1 && p[1]!=n){
		cout<<p[1]<<'\n';
	}
	else cout<<1<<'\n';
	
}

/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
1 4 7 10 13 16 19 
2 5 8 11 14 17 20
3 6 9 12 15 18 21

1 6 11 16 21 26 31
2 7 12
3 8 13
4 9 14
5 10 15

*/