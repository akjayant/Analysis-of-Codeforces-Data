#include<bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
long long k;
cin>>n>>k;
long long *arr=new long long[n];
for(int i=0;i<n;i++)
cin>>arr[i];
sort(arr, arr+n);
long long x=arr[0],y=arr[n-1];
int i=0,j=n-1;
long long ctr=1;
bool success1,success2;
while(k>=ctr){
success1=false;
success2=false;
if(i>=j)
break;

if(ctr*(arr[i+1]-arr[i])<=k){
k-=ctr*(arr[i+1]-arr[i]);
i++;
x=arr[i];
success1=true;
}
else {
    x+= k/ctr;
    k%=ctr;
}
if(ctr*(arr[j]-arr[j-1])<=k){
k-=ctr*(arr[j]-arr[j-1]);
j--;
y=arr[j];
success2=true;
}
else {
    y-= k/ctr;
    k%=ctr;
}
if(success1&&success2)
ctr++;


}
if(i>=j)
cout<<0;
else 
cout<<y-x;

}