#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int q; cin >> q;
	for(int z=0;z<q;z++){
		int n; cin >> n;
		string s; cin >> s;
		int cnt=0; int cnt1=0;
		int m=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1')m++;
		}
		for(int i=0;i<n;i++){
			if(s[i]=='1')break;
			cnt++;
		}
		for(int i=n-1;i>=0;i--){
			if(s[i]=='1')break;
			cnt1++;
		}
		cout << max(2*n-2*min(cnt,cnt1),n+m) << endl;
	}
}