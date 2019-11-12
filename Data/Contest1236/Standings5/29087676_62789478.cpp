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
using namespace std;
long long quickpow(long long a,long long b){long long ret=1;while(b){if(b&1){ret=ret*a%mod;}}a=a*a%mod;b>>=1;return ret;}
int q,n,m;
int a,b,c;
int main(){
    //read(1)
    //write(1)
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    REP(1,q,qq){
        cin>>a>>b>>c;
        if(b==0){
            cout<<b<<endl;
            continue;
        }
        int ans=0;
        while(c){
            if(b>=1&&c>=2){
                ans+=3;
            }
            else{
                break;
            }
            b--;
            c-=2;
        }
        while(a){
            if(b>=2&&a>=1){
                ans+=3;
            }
            else{
                break;
            }
            b-=2;
            a--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
