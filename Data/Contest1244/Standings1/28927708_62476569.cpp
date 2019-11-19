#include<bits/stdc++.h>
using namespace std;
vector<int> *graph;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
ios_base::sync_with_stdio(false);
cin.tie(NULL);
long long n,p,w,d;
cin>>n>>p>>w>>d;
bool found=false;
long long sum;
long long x,y;
for(long long i=0;i<=100005 ;i++){
    if((p-i*d)%w==0&&p>=i*d){
        found=true;
        sum=i+(p-i*d)/w;
        x=(p-i*d)/w;
        y=i;
        break;
    }
}
if(!found)
cout<<-1;
else {
    if(sum<=n)
    cout<<x<<" "<<y<<" "<<n-sum;
    else 
    cout<<-1;
}

}