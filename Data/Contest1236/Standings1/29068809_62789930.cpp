#include <stdio.h>
#include <iostream>
using namespace std;


typedef long long ll;
ll bp(ll a, ll b, ll m=1e9+7){
	ll ans = 1;
	while(b > 0){
		if(b & 1){
			ans = ans * a % m;
		}
		a = a * a % m;
		b >>= 1;
	}
	return ans;
}




int main()
{
    int n,m;scanf("%d%d",&n,&m);
    long long tmp=bp(2,m);
    --tmp;
    tmp=bp(tmp,n);
    cout << tmp;


}
