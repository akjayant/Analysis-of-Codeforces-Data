// #include<bits/stdc++.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N, cnt[26];
		memset(cnt,0,sizeof(cnt));
		string s,t;
		scanf("%d", &N);
		cin>>s;
		cin>>t;
		for(int i=0;i<N;++i) {
			cnt[s[i]-'a']++;
			cnt[t[i]-'a']++;
		}
		int fl = 0;
		for(int i=0;i<26;++i) {
			if(cnt[i]&1) {
				fl = 1;
				break;
			}
		}
		vector< pair<int, int> > ans;
		ans.clear();
		if(fl) {
			printf("No\n");
		} else {
			printf("Yes\n");
			for(int i=0;i<N-1;++i) {
				if(s[i] == t[i]);
				else {
					int xx = 0;
					for(int j=i+1;j<N;++j) {
						if(s[i] == s[j]) {
							ans.push_back(make_pair(j+1, i+1));
							s[j]=t[i];
							t[i]=s[i];
							xx = 1;
							break;
						}
					}
					if(!xx) {
						for(int j=i+1;j<N;++j) {
							if(s[i] == t[j]) {
								ans.push_back(make_pair(i+2, j+1));
								t[j] = s[i+1];
								s[i+1] = s[i];
								ans.push_back(make_pair(i+2, i+1));
								s[i+1] = t[i];
								t[i] = s[i];
								break;
							}
						}
					}
				}
				// cout<<s<<endl;
				// cout<<t<<endl;
				// printf("\n\n");
			}
			// cout<<s<<endl;
			// cout<<t<<endl;
			// printf("\n\n");
			printf("%d\n", ans.size());
			for(int i=0;i<ans.size();++i) {
				printf("%d %d\n", ans[i].first, ans[i].second);
			}
		}
	}
	return 0;
}