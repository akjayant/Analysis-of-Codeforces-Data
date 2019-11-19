#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

long long k;
vector<int> czyn;

int main(){
	scanf("%I64d", &k);
	long long kc = k;
	for(int i = 2; (long long)i*(long long)i <= k; i++){
		while(kc%i == 0){
			czyn.push_back(i);
			kc /= i;
		}
	}
	if(czyn.empty()){
		printf("%I64d", k);
		return 0;
	}
//	for(int i = 0; i < czyn.size(); i++){
//		printf("%d ", czyn[i]);
//	}
	if(czyn[0] != czyn[czyn.size() - 1]){
		printf("1");
		return 0;
	}
	if(kc != 1){
		printf("1");
	}
	else printf("%d", czyn[0]);
	return 0;
}