/*   Author : Rshs
 *   Data : 2019-11-01-22.38
 */
#include<bits/stdc++.h>
using namespace std;
#define FI first
#define SE second
#define LL long long
#define MP make_pair
#define PII pair<int,int>
#define SZ(a) (int)a.size()
const double pai = acos(-1);
const double eps = 1e-10;
const LL mod = 1e9+7;
const int MXN = 1e6+5;

void Main(int avg){
    int a,b;cin>>a>>b;
    for(int i=2;i<=1e4;i++){
        if(a%i==0&&b%i==0) {puts("Infinite");return ;}
    }
    puts("Finite");

}
int main(){
    int cas;cin>>cas;for(int i=1;i<=cas;i++)Main(i);
    return 0;
}
