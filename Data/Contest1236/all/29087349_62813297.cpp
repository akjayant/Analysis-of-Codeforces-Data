#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define IOS cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
vector<int>x[100025];
vector<int>y[100025];
int x0,y0,x1,y1;
int xx=1,yy=0,kk=1;
int n,m,k;
int sum=0;
int iff(){
    return x1>=x0&&y1>=y0;
}

void operator_1(){
    auto it=lower_bound(x[xx].begin(),x[xx].end(),yy);
    int a,b;
    if(it==x[xx].end()){
        a=xx;
        b=y1;
    }
    else{
        a=xx;
        b=min(y1,(*it)-1);
    }
    x0=x0+1;
    y0=y0;
    x1=x1;
    y1=b;
    sum+=b-yy;
    xx=a,yy=b;
}

void operator_2(){
    auto it=lower_bound(y[yy].begin(),y[yy].end(),xx);
    int a,b;
    if(it==y[yy].end()){
        a=x1;
        b=yy;
    }
    else{
        a=min((*it)-1,x1);
        b=yy;
    }
    x0=x0;
    y0=y0;
    x1=a;
    y1=y1-1;
    sum+=a-xx;
    xx=a,yy=b;
}

void operator_3(){
    auto it=lower_bound(x[xx].begin(),x[xx].end(),yy);
    int a,b;
    if(x[xx].empty()){
        a=xx;
        b=y0;
    }
    else if(it==x[xx].begin()){
        a=xx;
        b=y0;
    }
    else{
        it--;
        a=xx;
        b=max((*it)+1,y0);
    }
    x0=x0;
    y0=b;
    x1=x1-1;
    y1=y1;
    sum+=yy-b;
    xx=a,yy=b;
}

void operator_4(){
    auto it=lower_bound(y[yy].begin(),y[yy].end(),xx);
    int a,b;
    if(y[yy].empty()){
        a=x0;
        b=yy;
    }
    else if(it==y[yy].begin()){
        a=x0;
        b=yy;
    }
    else{
        it--;
        a=max((*it)+1,x0);
        b=yy;
    }
    x0=a;
    y0=y0+1;
    x1=x1;
    y1=y1;
    sum+=xx-a;
    xx=a,yy=b;
}
signed main()
{IOS;
    cin>>n>>m>>k;
    x0=1,y0=1,x1=n,y1=m;
    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        x[a].push_back(b);
        y[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(x[i].begin(),x[i].end());
        sort(y[i].begin(),y[i].end());
    }
    while(iff()){
        if(kk==1){
            operator_1();
        }
        else if(kk==2){
            operator_2();
        }
        else if(kk==3){
            operator_3();
        }
        else if(kk==4){
            operator_4();
        }
        //cout<<xx<<" "<<yy<<" "<<sum<<" "<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<endl;
        ++kk;
        if(kk==5){
            kk-=4;
        }
    }
    //cout<<sum<<endl;
    if(sum+k==n*m){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}

/*
*/

