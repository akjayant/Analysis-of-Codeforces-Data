#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int A[1010][1000];
int main(){
    int i,j,n,a;
    cin>>n;
    a=n*n;

    for(i=1;i<=n;i++){
        if(i%2) for(j=1;j<=n;j++) A[j][i]=a--;
        else for(j=n;j;j--) A[j][i]=a--;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++) cout<<A[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
