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
int a[555][555];

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  int h,w;cin>>h>>w;
  REP(i,h){
    REP(j,w){
      cin>>a[i][j];
    }
  }
  vector<int> x,y,z,zz;
  REP(i,h){
    REP(j,w){
      if(j==w-1)continue;
      if(a[i][j]%2==1){
        // cout<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+2<<endl;
        x.push_back(i+1);
        y.push_back(j+1);
        z.push_back(i+1);
        zz.push_back(j+2);
        a[i][j+1]++;
      }
    }
  }
  REP(i,h){
    if(i==h-1)continue;
    if(a[i][w-1]%2==1){
      // cout<<i+1<<" "<<w<<" "<<i+2<<" "<<w<<endl;
      x.push_back(i+1);
      y.push_back(w);
      z.push_back(i+2);
      zz.push_back(w);
      a[i+1][w-1]++;
    }
  }
  P(x.size());
  REP(i, (int)x.size()){
    cout<<x[i]<<" "<<y[i]<<" "<<z[i]<<" "<<zz[i]<<endl;
  }
  return 0;
}
