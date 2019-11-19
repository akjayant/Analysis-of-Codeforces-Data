/*

Nasha rozpovid pro yizhachka
Pro malenkogo necluhnanogo
Yak spitkala malogo bida
Vzhe ne zhvavogo ne rumanogo
� ����� �� ������ ������
�����, �������, ������, ����
�� ������ ��������� ����
�� ��������� ������������

������! ϳ������, ��������!
������! ����� � ���� ���������!
������! �������� ��������!
������! ������!

��� �� ������������� � ����
� ������� ���� ��� �����
�� ������� ����, �� �����
��� �� ���� � ��� ������

*/

#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio();cin.tie();cout.tie();
#define ops cout<<"ops"<<endl;

#define DIM 100007
#define DIMM 10007
#define INF 100000000000000007.0
#define X 10000
#define MODULO 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pllll;
typedef string str;
typedef char cr;

ll nt,n,m;
ll pa,na,pb,nb;
ll val;

int main()
{
    fast;
    //ll x1,y1,x2,y2;

    cin>>nt;
    while(nt--){
      pa=0;na=0;
      pb=0;nb=0;
      cin>>n;
      for(int i=1;i<=n;i++){
       cin>>val;
       if(val%2==0)pa++;
       else na++;
      }
      cin>>m;
      for(int i=1;i<=m;i++){
       cin>>val;
       if(val%2==0)pb++;
       else nb++;
      }
      cout<<(pa*pb)+(na*nb)<<endl;
    }
    return 0;
}


