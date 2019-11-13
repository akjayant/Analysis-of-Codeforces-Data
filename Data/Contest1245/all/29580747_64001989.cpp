#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <string> 
using namespace std;
int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}
int main(){
	int a, b, t;
	scanf("%d", &t);
	while(t--){ 
		scanf("%d%d", &a, &b);
		if(gcd(a, b) == 1){
			printf("Finite\n");
		}
		else{
			printf("Infinite\n"); 
		}
	}
	return 0;
} 