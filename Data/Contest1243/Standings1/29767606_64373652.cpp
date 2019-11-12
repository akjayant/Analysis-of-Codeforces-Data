#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
int A[100100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		for(int i = n; i >= 1; i--){
			int ct = 0;
			for(int j = 0; j < n; j++){
				if(A[j] >= i){
					ct++;
				}
			}
			if(ct >= i){
				cout << i << '\n';
				break;
			}
		}
	}

}