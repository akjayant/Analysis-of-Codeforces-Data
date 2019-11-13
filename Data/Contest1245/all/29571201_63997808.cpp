#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int a, b, t;
    cin>>t;
    while(t--){
        scanf("%d%d", &a, &b);
        if (__gcd(a, b) == 1) printf("Finite\n");
        else printf("Infinite\n");
    }    
    // system("pause");
}