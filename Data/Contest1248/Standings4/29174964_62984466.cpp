#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005];
int n;
ll s1,s2;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    s1=s2=0;
    for (int i=1;i<=n/2;i++)s1+=a[i];
    for (int i=n/2+1;i<=n;i++)s2+=a[i];
    cout<<s1*s1+s2*s2<<endl;
    return 0;
}