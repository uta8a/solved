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

  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());

  int n;cin>>n;string s;cin>>s;
  int index_k=n,index_d=-1;
  for(int i=0;i<n;i++){
    if(s[i]=='K'){
      index_k=i;
      break;
    }
  }
  for(int i=n-1;i>=0;i--){
    if(s[i]=='D'){
      index_d=i;
      break;
    }
  }
  ll ans=index_k-index_d;
  if(ans<0)ans=0;
  P(ans);
  return 0;
}
