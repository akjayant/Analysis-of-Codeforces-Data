#include <bits/stdc++.h>
using namespace std;

int n,a[100010];
long long k;
int poz1, poz2;

int cautbin1(int x)
{
    int st=1,dr=n,mid;
    while (st<=dr)
    {
        mid=(st+dr)/2;
        if(a[mid] <= x) st=mid+1;
        else dr=mid-1;
    }
    if(a[dr]==x) return dr;
    return -1;
}

int cautbin2(int x)
{
    int st=1,dr=n,mid;
    while(st<=dr)
    {
        mid=(st+dr)/2;
        if(a[mid]<x) st=mid+1;
        else dr=mid-1;
    }
    return st;
}

int main(){

    cin>>n>>k;
    long long st, fn;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1, a+1+n);
    st = a[1];
    fn = a[n];
    while(k && st < fn){
        poz1 = cautbin1(st);
        poz2 = cautbin2(fn);
        if(poz1 < (n - poz2+1)){
            if(k >= (a[poz1+1] - st)*poz1 ){
                k-=(a[poz1+1] - st)*poz1 ;
                st = a[poz1+1];
            }
            else
            {

                st +=k/poz1;
                k = 0;
            }
        }
        else {
            if( k >= (fn - a[poz2-1])*(n - poz2+1) ){
                k -= (fn - a[poz2-1])*(n - poz2+1);
                fn = a[poz2-1];
            }
            else {

                fn -= k/(n - poz2+1);
                k =0;
            }
        }
    }
    cout<<fn - st;

    return 0;
}


