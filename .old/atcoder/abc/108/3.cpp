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

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  ll n,k;cin>>n>>k;
  ll ans;
  if(2*n < k){
    ans=0;
  }else if(k%2==1){
    ans=(n/k)*(n/k)*(n/k);
  }else if(k==2){
    if(n%2==0)ans=n*n*n/4;
    if(n%2==1)ans=(n/2 + 1)*(n/2 + 1)*(n/2 + 1) + (n/2)*(n/2)*(n/2);
  }else if(k%2==0){
    ll p=k/2;
    ll s = n/p;
    if(s%2==0)ans=s*s*s/4;
    if(s%2==1)ans=(s/2 + 1)*(s/2 + 1)*(s/2 + 1) + (s/2)*(s/2)*(s/2);
  }
  P(ans);

  return 0;
}
