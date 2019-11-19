#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll factor[30], f_sz;
const int MAXSIZE = 1E6 + 100;
bool Mark[MAXSIZE]; int ind = 0; //prime[0]起 
int prime[1000000];    //判断是否是一个素数  Mark 标记数组 ind 素数个数
void Prime() { 
    ind = 0;
    for (int i = 2; i < MAXSIZE; i++){
        if (Mark[i])  continue;     //如标记则跳过
        prime[ind++] = i; //否则得到一个素数
        for (int j = i + i; j < MAXSIZE; j += i)  Mark[j] = 1; //标记目前得到的素数的i倍为非素数
    }
} 
void get_factor(ll x) {
    f_sz = 0;
    ll t = sqrt(x + 0.5);
    for (ll i = 0; prime[i] <= t; ++i){ 
    	if (prime[i] > x) break; 
        if (x % prime[i] == 0) {
            factor[f_sz++] = prime[i];
            while (x % prime[i] == 0) x /= prime[i];
        }
    } 
    if (x > 1) factor[f_sz++] = x;
} 

int main() {
    ll n; scanf("%lld",&n);
    Prime();
    get_factor(n);
    if(f_sz>1){
        printf("1\n");
        return 0;
    }else{
        if(n==1){
            printf("1\n"); return 0;
        }
        if(f_sz==1){
            printf("%lld\n",factor[0]); return 0;
        }
    }

    return 0;
}