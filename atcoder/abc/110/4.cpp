#include <bits/stdc++.h>
//---------------------------
using namespace std;
//---------------------------
#define REP(i,n) for(int i = 0; i < (n); i++)
#define P(x) cout << (x) << "\n"
#define fcout cout << fixed << setprecision(18)

#define MOD 1000000007 // 1e9+7
#define PI 3.1415926535
/*
3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
*/
#define ll long long int // 10^18
#define INF 1000000001 // 1e9+1
#define LINF 1000000000000000001 // 1e18+1

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
//---------------------------
typedef tuple<long long, long long> Pair;
Pair factor_sub(long long n, long long m){
  long long i=0;
  while(n%m==0){
    i++;
    n/=m;
  }
  return make_tuple(i,n);
}

vector<Pair> factorization(long long n){
  vector<Pair> a;
  long long c,m;
  tie(c, m) = factor_sub(n, 2);
  if(c>0)a.push_back(make_tuple(2, c));
  for(long long i=3;i*i<=m;i+=2){
    tie(c,m)=factor_sub(m, i);
    if(c>0)a.push_back(make_tuple(i,c));
  }
  if(m>1)a.push_back(make_tuple(m,1));
  return a;
}
class ModuloCombination {
private:
  vector<ll> fact, fact_inv;

  static ll mod_pow(ll a, ll n){
    if(n == 0) return 1;
    if(n%2 == 0) return mod_pow((a * a) % MOD, n / 2);
    return (a * mod_pow(a, n - 1)) % MOD;
  }

public:
  ModuloCombination(ll N): fact(N + 1), fact_inv(N + 1) {
    fact[0]=1;
    for(ll i = 1; i < N + 1; i++) {
      fact[i] = (i * fact[i - 1]) % MOD;
    }
    for(ll i = 0; i < N + 1; i++) {
      fact_inv[i] = mod_pow(fact[i], MOD - 2);
    }
  }

  ll operator()(ll n, ll r) {
    return (((fact[n] * fact_inv[r]) % MOD) * fact_inv[n - r]) % MOD;
  }
};

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  ll n,m, sm=0;cin>>n>>m;
  vector<Pair> f = factorization(m);
  // P(get<1>(f[0]));
  for(auto x:f){
    // cout<<get<0>(x)<<" "<<get<1>(x)<<endl;
    sm+=get<1>(x);
  }
  ll ans=1;
  ModuloCombination C(200000);
  for(auto x:f){
    ans*=C(get<1>(x) + n-1, get<1>(x));
    ans%=MOD;
  }
  P(ans);
  return 0;
}
