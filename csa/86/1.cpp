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
int row[2000];
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  int n,p,t;cin>>n>>p>>t;
  int th=t/9, la=t%9;
  int ste;
  if(la<=4){
    ste=0;
  }else if(la==5){
    ste=1;
  }else if(la==6){
    ste=0;
  }else{
    ste=la-6;
  }
  for(int i=1;i<=n;i++){
    row[i+th*3+ste]=i; // 1-indexed
  }
  int ans=-1;
  if(row[p]>0){
    ans=row[p];
  }
  P(ans);
  return 0;
}
