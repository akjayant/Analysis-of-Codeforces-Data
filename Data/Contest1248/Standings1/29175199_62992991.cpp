#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char ch[N];
int n,a[N];
struct node
{
    int num,pos;
}q[1100000];
int head=1,tail=1;
int cal()
{
    int sum=0;
    for(int i=1;i<=n;i++)a[i]=a[i+n]=(ch[i]=='('?1:-1);
    for(int i=1;i<=2*n;i++)a[i]+=a[i-1];
    head=tail=0;
    for(int i=1;i<=2*n-1;i++)
    {
        while(q[head].pos<i-n+1&&head!=tail)head++;
        while(tail&&a[i]<q[tail-1].num&&head!=tail)tail--;
        q[tail].num=a[i],q[tail++].pos=i;
        if(i>=n)
        {
            if(q[head].num>=a[i-n])sum++;
        }
    }
    return sum;
}
int main()
{
    int ans=0,k1,k2,sum=0;scanf("%d",&n);
    if(n%2==1){printf("0\n1 1\n");return 0;}
    scanf("%s",ch+1);
    for(int i=1;i<=n;i++)
    {
        if(ch[i]=='(')sum++;
    }
    if(sum!=n-sum){printf("0\n1 1\n");return 0;}
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            swap(ch[i],ch[j]);
            int x=cal();//cout<<i<<" "<<j<<" "<<x<<endl;
            if(ans<x)ans=x,k1=i,k2=j;
            swap(ch[i],ch[j]);
        }
    printf("%d\n%d %d\n",ans,k1,k2);
}
