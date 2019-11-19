// #include<bits/stdc++.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
vector<long long> pr;
int ar[1000005];
int primeGen() {
	memset(ar, 0, sizeof(ar));
	ar[0]=1;
	ar[1]=1;
	for(int i=2;i*i<=1000000;++i) {
		if(ar[i] == 0) {
			for(int j=i+i;j<=1000000;j+=i)
				ar[j]=1;
		}
	}
	for(int i=0;i<1000000;++i) {
		if(ar[i]==0){
			pr.push_back(i);
		}
	}
	return 0;
}

int main() {
	primeGen();
	// printf("%d\n", pr.size());
	long long x;
	memset(ar, 0, sizeof(ar));
	scanf("%lld", &x);
	for(int i=0;i<pr.size();++i) {
		if(x%pr[i] == 0) {
			ar[i]++;
			x/=pr[i];
			--i;
		}
	}
	if(x!=1) {
		pr.push_back(x);
		ar[pr.size()-1]++;
	}
	int cnt = 0, idx = 0;
	for(int i=0;i<pr.size();++i) {
		if(ar[i]!=0) {
			++cnt;
			idx = i;
		}
	}
	if(cnt == 1) {
		printf("%lld\n", pr[idx]);
	} else {
		printf("1\n");
	}
	return 0;
}