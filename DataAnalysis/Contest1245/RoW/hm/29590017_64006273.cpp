using namespace std;
typedef long long ll;

ll multi(ll a, ll b){
    return (a * b)%1000000007;
}

ll addi(ll a, ll b){
    return (a + b)%1000000007;
}

ll resp;
ll fibo[100010];

void calculate(ll qtd, ll tipo){
    if(tipo == -1)return;
    resp = multi(resp, fibo[qtd]);
}

int main() {
    string s;
    cin >> s;
    resp = 1;
    fibo[0] = fibo[1] = 1;
    fibo[2] = 2;
    for(int i=0; (i)<int(100010); (i)++) {if(i < 3)continue;else fibo[i] = addi(fibo[i - 1], fibo[i - 2]);}
    ll qtd = 0;
    ll tipo = -1;
    for(int i=0; (i)<int(int(s.size())); (i)++){
        if(s[i] == 'm' || s[i] == 'w')resp *= 0;
        else if(s[i] == 'n'){
            if(tipo == 1){
                qtd++;
            }else{
                calculate(qtd, tipo);
                tipo = 1;
                qtd = 1;
            }
        }else if(s[i] == 'u'){
            if(tipo == 2){
                qtd++;
            }else{
                calculate(qtd, tipo);
                tipo = 2;
                qtd = 1;
            }
        }else{
            calculate(qtd, tipo);
            tipo = -1;
            qtd = 0;
        }
    }
    calculate(qtd, tipo);
    printf("%lld\n", resp);
    return 0;
}
