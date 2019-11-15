#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
	int T, N;
	int cnt['Z'+1] = {0};
	char str[101];
	char out[101];
	int input[3];
	char care[4] = "SRP";
	char use[4] = "RPS";
	for(cin >> T; T; T--){
		cin >> N;
		for(int i=0; i<3; i++)
			cin >> input[i];
		cin >> str;
		memset(cnt, 0, sizeof(cnt));
		int ans = 0;
		for(int i=0; i<N; i++)
			cnt[str[i]] ++;
		for(int i=0; i<3; i++)
			ans += min(cnt[care[i]], input[i]);
		if(ans >= (N+1)/2){
			memset(out, 0, sizeof(out));
			for(int i=0; i<N; i++)
				for(int j=0; j<3; j++)
					if(str[i] == care[j] && input[j]){
						out[i] = use[j];
						input[j] --;
					}
			for(int i=0; i<N; i++)
				for(int j=0; j<3; j++)
					if(!out[i] && input[j]){
						out[i] = use[j];
						input[j] --;
						break;
					}
			cout << "YES\n" << out << endl;
		}
		else
			cout << "NO\n";
	}
}



