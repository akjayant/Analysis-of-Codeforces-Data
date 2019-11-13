/**
*
* Author: MARS
* Lang: GNU C++14
*
**/

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >
#define LS pair < ll , string >

typedef unsigned long long ull;
typedef long double ldbl;
typedef long long ll;
typedef double dbl;

const ldbl E = 2.71828182845904523536;
const ldbl pi = acos(-1);
const dbl eps = 1e-9;
const ll mod = 1e9+7;
const ll inf = 1LL<<30;

/** /////////// ** Code ** /////////// **/

const int N=333;
int a[N][N];

int main()
{
    int n;
    scanf("%d",&n);

    int cnt=1;

    for(int j=0 ; j<n ; j++){
        if(j%2 == 0){
            for(int i=0 ; i<n ; i++)
                a[i][j]=cnt++;
        }
        else{
            for(int i=n-1 ; i>=0 ; i--)
                a[i][j]=cnt++;
        }
    }


    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++)
            printf("%d ",a[i][j]);

        printf("\n");
    }

    return 0;
}
