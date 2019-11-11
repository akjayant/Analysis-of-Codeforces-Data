#include<bits/stdc++.h>
using namespace std;

#define repi(i, a, b) for(int i = a; i <= b; i++)
#define repd(i, a, b) for(int i = a; i >= b; i--)
#define _end printf("\n")
#define dg(x) cout << #x << '=' << x << ' '
#define mem(a, b) memset(a, b, sizeof(a))

void _in(long long *a, ...){

    va_list arg_ptr;

    scanf("%I64d", a);
    long long *temp;

    va_start(arg_ptr, a);
    temp = va_arg(arg_ptr, long long*);

    while(temp){
        scanf("%I64d", temp);
        temp = va_arg(arg_ptr, long long*);
    }

    va_end(arg_ptr);
}

void _in(int *a, ...){
    va_list arg_ptr;

    scanf("%d", a);
    int *temp;

    va_start(arg_ptr, a);
    temp = va_arg(arg_ptr, int*);
    while(temp){
        scanf("%d", temp);
        temp = va_arg(arg_ptr, int*);
    }

    va_end(arg_ptr);
}

#define in(...) _in(__VA_ARGS__, 0)
typedef long long ll;

int gcd(int a, int b){
    return b? gcd(b, a % b) : a;
}

int main(){

    int t; in(&t);
    while(t--){
        int a, b;
        in(&a, &b);
        if(gcd(a, b) == 1){
            printf("Finite\n");
        }
        else{
            printf("Infinite\n");
        }
    }

    return 0;
}