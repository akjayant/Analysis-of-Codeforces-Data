#include <iostream>
#include <cmath>
using namespace std;

int n;

struct node{
    int x,y;
    long long int k,v;
}a[2020];

int read(){
    char ch=getchar();
    int x=0;
    while(ch>'9'||ch<'0'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

int book[2020];
long long int dis[2020];
int book2[2020];
long long int answ=0;

int getmin(){
    long long int minn=1e9+9;
    int who;
    for(int i=1;i<=n;i++){
        if(book[i]) continue;
        if(dis[i]<minn){
            minn=dis[i];
            who=i;
        }
    }
    return who;
}

int distan(int x,int y){
    return abs(a[x].x-a[y].x)+abs(a[x].y-a[y].y);
}

void update(int x){
    for(int i=1;i<=n;i++){
        if(book[i]) continue;
        if(dis[i]>(distan(i,x)*(a[x].k+a[i].k))){
            dis[i]=(distan(i,x)*(a[x].k+a[i].k));
            book2[i]=x;
        }
//        dis[i]=min(dis[i],);
    }
}

int ge=0;
int xqly[2020];
int dui;
int dxqly[2020][2];

int main(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i].x=read();
        a[i].y=read();
    }
    for(int i=1;i<=n;i++){
        a[i].v=read();
    }
    for(int i=1;i<=n;i++){
        a[i].k=read();
        dis[i]=a[i].v;
    }
    int dd;
    for(int i=1;i<=n;i++){
        dd=getmin();
        book[dd]=1;
        if(book2[dd]==0){
            ge++;
            xqly[ge]=dd;
        }
        else {
            dui++;
            dxqly[dui][0]=dd;
            dxqly[dui][1]=book2[dd];
        }
        answ+=dis[dd];
        update(dd);
    }
    cout<<answ<<endl;
    cout<<ge<<endl;
    for(int i=1;i<=ge;i++){
        cout<<xqly[i]<<" ";
    }
    cout<<endl;
    cout<<dui<<endl;
    for(int i=1;i<=dui;i++){
        cout<<dxqly[i][0]<<" "<<dxqly[i][1]<<endl;
    }
    return 0;
}