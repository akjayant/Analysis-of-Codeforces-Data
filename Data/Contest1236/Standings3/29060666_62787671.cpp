#include <bits/stdc++.h>
using namespace std;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());


int main(){
// 	freopen("input.txt","r",stdin);
	int T;
	cin >> T;
	while(T--){
		int a,b,c;
		cin >> a >> b >> c;
		int ans = 0;
		for(int i = 0;i <= a;i++){
			if(b/2 < i)break;
			int temp = 3*i;
			int want1 = min(b - 2*i,c/2);
			temp+=3*want1;
			ans = max(ans,temp);
		}
		printf("%d\n",ans);
	}
}