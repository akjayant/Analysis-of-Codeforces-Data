/*   Author : Rshs
 *   Data : 2019-11-01-22.41
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
    int n;cin>>n;
    int a,b,c;cin>>a>>b>>c;
    string s;cin>>s;
    int cr=0,cp=0,cs=0;
    int le=s.length();
    for(int i=0;i<le;i++) {
        if(s[i]=='R') cr++;
        if(s[i]=='P') cp++;
        if(s[i]=='S') cs++;
    }
    int can=min(a,cs)+min(b,cr)+min(c,cp);
    int need=n/2+(n%2!=0);
    if(can<need) {puts("NO");return ;}
    puts("YES");
    int ya=min(a,cs),yb=min(b,cr),yc=min(c,cp);
    vector<char>v;
    for(int i=1;i<=a-ya;i++)v.push_back('R');
    for(int i=1;i<=b-yb;i++)v.push_back('P');
    for(int i=1;i<=c-yc;i++)v.push_back('S');
    for(int i=0;i<le;i++){
        if(s[i]=='R') {
            if(yb) yb--,cout<<"P";
            else cout<<v.back(),v.pop_back();
        }
        if(s[i]=='P') {
            if(yc) yc--,cout<<"S";
            else cout<<v.back(),v.pop_back();
        }
        if(s[i]=='S') {
            if(ya) ya--,cout<<"R";
            else cout<<v.back(),v.pop_back();
        }
    }
    puts("");
}
int main(){
    int cas;cin>>cas;for(int i=1;i<=cas;i++)Main(i);
    return 0;
}
