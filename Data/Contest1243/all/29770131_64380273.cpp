// #include<bits/stdc++.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main() {
	int K;
	scanf("%d", &K);
	while(K--) {
		int N;
		string s,t;
		scanf("%d", &N);
		cin>>s;
		cin>>t;
		int diff=0,idx,idy;
		for(int i=0;i<N;++i) {
			if(s[i]==t[i]);
			else {
				++diff;
				if(diff == 1) {
					idx=i;
				} else if(diff == 2) {
					idy=i;
				} else {
					break;
				}
			}
		}
		// printf("%d %d %d\n", diff, idx, idy);
		if(diff == 2) {
			if(s[idx]==s[idy] && t[idy] == t[idx]) {
				cout<<"Yes"<<endl;
			} else {
				printf("No\n");
			}
		} else if(diff == 0) {
			printf("Yes\n");
		} else {
			cout<<"No"<<endl;
		}
	}
	return 0;
}