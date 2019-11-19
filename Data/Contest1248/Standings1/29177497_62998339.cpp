#include<cstdio>
#include<algorithm>
using namespace std;

const int mod = 1000000007;

int n, m;
int Fibon[100005];

int main(){
	scanf("%d %d", &n, &m);
	Fibon[0] = 0;
	Fibon[1] = 1;
	for(int i = 2; i <= max(n, m) + 1; i++){
		Fibon[i] = Fibon[i-1] + Fibon[i-2];
		Fibon[i] %= mod;
	}
	int score = Fibon[n+1] + Fibon[m+1] - 1;
	score %= mod;
	score *= 2;
	score %= mod;
	printf("%d", score);
	return 0;
}