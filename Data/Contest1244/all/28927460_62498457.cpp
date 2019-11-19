#include<bits/stdc++.h>
using namespace std;

#define int long long

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}

void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

#define pii pair<int,int >
#define vec vector<int >

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 1e6+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int a[maxn],n,k,tot,ans;

signed main() {
    read(n),read(k);
    for(int i=1;i<=n;i++) read(a[i]);
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<=r){
        int x=a[l+1]-a[l],y=a[r]-a[r-1];tot++;
        if((x+y)*tot>k) {ans=a[r]-a[l]-k/tot;break;}
        k-=(x+y)*tot,l++,r--;
    }
    write(max(ans,0ll));
    return 0;
}
