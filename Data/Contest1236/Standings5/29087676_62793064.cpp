/**
*    author:  a2954898606
*    created: 2019/10/17 21:25:20
**/
/*
ЗАПУСКАЕМ
░ГУСЯ░▄▀▀▀▄░РАБОТЯГУ░░
▄███▀░◐░░░▌░░░░░░░
░░░░▌░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▌░░░░░▐▄▄░░░░░
░░░░▌░░░░▄▀▒▒▀▀▀▀▄
░░░▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄
░░░▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░░░▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▀▄
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░▄▄▌▌▄▌▌░░░░░
 */
#include<bits/stdc++.h>
#define REP(A,B,I) for(int I=(A);I<=(B);I++)
#define PER(A,B,I) for(int I=(A);I>=(B);I--)
#define LL long long
#define mod 100000007
#define N 1000010
#define M 100
//using namespace std;
//long long quickpow(long long a,long long b){long long ret=1;while(b){if(b&1){ret=ret*a%mod;}}a=a*a%mod;b>>=1;return ret;}
using namespace std;
int n,m,cnt;
int a[400][400];
int main(){
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        int st,v;
        if(i%2==1)st=(i-1)*n+1,v=1;
        else st=i*n,v=-1;
        for(int j=1;j<=n;j++){
            a[i][j]=st;
            st+=v;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",a[j][i]);
        printf("\n");
    }
    return 0;
}
