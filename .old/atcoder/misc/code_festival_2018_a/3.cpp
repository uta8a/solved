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
ll cnt[55];
ll dp[55][3333][2];

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  ll n,kk;cin>>n>>kk;
  ll sm=0;
  REP(i,n){
    ll a,b=0;cin>>a;
    while(a!=0){
      a/=2;
      b++;
    }
    cnt[i]=b;
    sm+=b;
  }
  kk=min(kk, sm); // でかい数だけど実際は0を2に割るが起こるので、minとってOK
  ll k;
  dp[0][0][0]=1;
  for(ll i=0;i<n;i++){
    for(ll j=0;j<=sm;j++){
      for(k=0;k<cnt[i];k++){
        dp[i+1][j+k][1] += dp[i][j][1]; dp[i+1][j+k][1]%=MOD;
        dp[i+1][j+k][0]+=dp[i][j][0]; dp[i+1][j+k][0]%=MOD;
      }
      k=cnt[i];
      dp[i+1][j+k][1] += dp[i][j][1]; dp[i+1][j+k][1]%=MOD;
      dp[i+1][j+k][1]+=dp[i][j][0]; dp[i+1][j+k][1]%=MOD;
    }
  }
  ll ans=0;
  ans+=dp[n][kk][0];
  for(ll i=0;i<=kk;i++){
    ans+=dp[n][i][1]; ans%=MOD;
  }
  P(ans);

  return 0;
}
