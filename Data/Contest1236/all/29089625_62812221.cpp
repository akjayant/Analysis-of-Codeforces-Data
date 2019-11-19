///By Stephan Ramirez dsramirezc@unal.edu.co
#include<bits/stdc++.h>
#define ms(a,v) memset(a,v,sizeof a)
#define ll long long
#define N 100015
using namespace std;

priority_queue<int> der[N];
priority_queue<int> izq[N];
priority_queue<int> arr[N];
priority_queue<int> abj[N];
ll n,m,k;
ll tot=0;
ll vis=0;
int main(){
	#ifdef LOCAL
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	scanf("%lld %lld %lld",&n,&m,&k);
	tot=n*m;
	int dir=0;
	int de=m;
	int iz=1;
	int ar=n;
	int ba=1;
	int posi=1;
	int posj=1;
	for(int i=0;i<k;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        der[a].push(-b);
        izq[a].push(b);
        arr[b].push(-a);
        abj[b].push(a);
	}
	int xx=5;
	while(ba<=ar && de>=iz){
        if(dir==0){
            while(der[posi].size()>0 && abs(der[posi].top())<posj)
                der[posi].pop();
            int cor=de;
            if(der[posi].size()>0)
                cor=min(cor,abs(der[posi].top())-1);
            ba++;
            de=cor;
            vis+=cor-posj;
            posj=cor;
        }
        if(dir==1){
            while(arr[posj].size()>0 && abs(arr[posj].top())<posi)
                arr[posj].pop();
            int cor=ar;
            if(arr[posj].size()>0)
                cor=min(cor,abs(arr[posj].top())-1);
            de--;
            ar=cor;
            vis+=cor-posi;
            posi=cor;
        }
        if(dir==2){
            while(izq[posi].size()>0 && abs(izq[posi].top())>posj)
                izq[posi].pop();
            int cor=iz;
            if(izq[posi].size()>0)
                cor=max(cor,abs(izq[posi].top())+1);
            ar--;
            iz=cor;
            vis+=posj-cor;
            posj=cor;
        }
        if(dir==3){
            while(abj[posj].size()>0 && abs(abj[posj].top())>posi)
                abj[posj].pop();
            int cor=ba;
            if(abj[posj].size()>0)
                cor=max(cor,abs(abj[posj].top())+1);
            iz++;
            ba=cor;
            vis+=posi-cor;
            posi=cor;
        }
       // printf("%d %d %d %d %d\n",ar,ba,de,iz,vis);
        //printf("%d %d\n",posi,posj);
        dir=(dir+1)%4;
	}
	//cout<<vis<<" "<<k<<" "<<" "<<tot<<endl;
	if((vis+1+k)==tot)
        printf("Yes\n");
    else
        printf("No\n");
	return 0;
}

