#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 2010;
const int mod = 998244353;
long long int n;

int num[maxn];


// long long int prv[maxn];
// long long int nxt[maxn];
// long long int tot[maxn];
// The following codes is equal to the codes above.
// (The change is maintaining memory order in different system.)
long long int *p = new long long int[3 * maxn]();
long long int *prv = p;
long long int *nxt = p + maxn;
long long int *tot = p + 2 * maxn;

void solve(){
    int idx = 0;
    for(int i = 1; i <=n; ++i){
        if(i & 1){
            int t = i;
            while(t <= n){
                num[idx++] = t;
                t = (t << 1);
            }
        }
    }
    int cumsum = 0;
    for(int i = 0; i < n; ++i){
        if(num[i] & 1){
            cumsum = num[i];
        }
        else{
            cumsum += num[i];
        }
        for(int j = 0; j < cumsum; ++j){
            nxt[j] = 0;
        }
        nxt[cumsum] = 1;
        for(int j = cumsum + 1; j <= n; ++j){
            if(num[i] & 1){
                nxt[j] = (nxt[j - num[i]] + tot[j - num[i]]) % mod;
            }
            else{
                nxt[j] = (nxt[j - num[i]] + prv[j - num[i]]) % mod;
            }
        }
        for(int j = cumsum; j <= n; ++j){
            tot[j] = (tot[j] + nxt[j]) % mod;
        }
        long long int *tmp = prv;
        prv = nxt;
        nxt = tmp;
    }
    printf("%lld", tot[n]);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    printf("Please input your student id:\n");
    scanf("%lld", &n);
    n = n % 900 + 1100;
    solve();
    delete [] p;
    return 0;
}