#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

int n;
int changes[505];

int maximum = 0;
pair<int, int> best_swap = make_pair(1, 1);

int main(){
	scanf("%d\n", &n);
	if(n%2 != 0){
		printf("0\n1 1");
		return 0;
	}
	for(int i = 1; i <= n; i++){
		char x;
		scanf("%c", &x);
		if(x == '(') changes[i] = 1;
		else changes[i] = -1;
	}
	changes[n+1] = changes[1];
	int state = 0;
	for(int i = 1; i <= n; i++){
		state += changes[i];
	}
	if(state != 0){
		printf("0\n1 1");
		return 0;
	}
	int num_shifts = 0;
	state = 0;
	int minimum = 0;
	for(int i = 1; i <= n; i++){
		state += changes[i];
		minimum = min(minimum, state);
	}
	state = 0;
	for(int i = 1; i <= n; i++){
		state += changes[i];
		if(state == minimum) num_shifts++;
	}
	maximum = max(maximum, num_shifts);
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(changes[i] == changes[j]) continue;
//			printf("%d %d\n", i, j);
			num_shifts = 0;
			state = 0;
			minimum = 0;
			swap(changes[i], changes[j]);
			changes[n+1] = changes[1];
			for(int k = 1; k <= n; k++){
				state += changes[k];
				minimum = min(minimum, state);
			}
//			printf("%d\n", minimum);
			state = 0;
			for(int k = 1; k <= n; k++){
				state += changes[k];
				if(state == minimum) num_shifts++;
			}
//			printf("%d\n", num_shifts);
			maximum = max(maximum, num_shifts);
			if(maximum == num_shifts) best_swap = make_pair(i, j);
			swap(changes[i], changes[j]);
			changes[n+1] = changes[1];
		}
	}
	printf("%d\n", maximum);
	printf("%d %d", best_swap.first, best_swap.second);
	return 0;
}