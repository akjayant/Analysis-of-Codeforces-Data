#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[100100];

int main(){
	ll n, k; cin >> n >> k;
	for(ll i=0; i<n; ++i) cin >> arr[i];
	sort(arr, arr+n);
	ll lo=0, hi=n-1, ops=0;
	while(lo<hi && ops<k){
		if(lo+1<n-hi){ //conviene alzare i minimi
			if((arr[lo+1]-arr[lo])*(lo+1)+ops<=k){ //lo uguaglio all'el successivo
				ops+=(arr[lo+1]-arr[lo])*(lo+1);
				++lo;
			}
			else { // non ci arrivo
				arr[lo]+=(k-ops)/(lo+1);
				ops=k;
			}
		}
		else { //conviene abbassare i massimi
			if((arr[hi]-arr[hi-1])*(n-hi)+ops<=k){ //lo uguaglio all'el precedente
				ops+=(arr[hi]-arr[hi-1])*(n-hi);
				--hi;
			}
			else { // non ci arrivo
				arr[hi]-=(k-ops)/(n-hi);
				ops=k;
			}
		}
	}
	cout << max(0ll, arr[hi]-arr[lo]) << endl;
}
