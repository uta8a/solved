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
ll a[300000];
ll b[300000];
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());

  ll n,x;cin>>n>>x;
  REP(i,n){
    cin>>a[i];
    b[i+1]=a[i];
  }
  b[0]=0;// 0,a[1],a[1]+a[2], ...
  for(int i=0;i<n;i++){
    b[i+1]+=b[i];
  }
  ll comp=0;
  ll upr=n;
  // for(int i=0;i<n;i++){
  //   comp+=2*b[i];
  //   // if comp > a*x -> upper
  //   ll cn = (i+2)/2;
  //   // cout<<comp<<" "<<cn*x<<endl;
  //   if(comp > cn * x){
  //     upr=i+3;
  //   }
  // }
  ll ans=n*x;//ごみひろい
  ll cnt=n;
  ll ind=0;
  // untilok
  while(cnt>0){
    for(int i=ind+1;i<=n;i++){
      comp=2*(b[i]-b[ind]);
      P(comp);
      P(x);
      if(comp > x){//cn*x
          upr=i-ind-1;
          break;
      }
    }
    // P(upr);
    if(upr<2)upr=2;
    comp=0;
    // ここ以下は変更なし、うえでuprを毎回決定する
    cnt-=upr;
    ans+=x;//ごみすて
    for(int i=0;i<upr;i++){
      if(i==0){
        ans+=5*a[ind+i];
      }else{
        if(ind+i>=n)continue;
        ans+=(2*i+3)*a[ind+i];
      }
    }
    ind+=upr;
    P(upr);
  }
  P(ans);
  ll desm=0;
  for(int i=0;i<n;i++){
    desm+=a[i]*5;
  }
  P(desm+5*x+10*x);
  return 0;
}
/*
228135383
150710136
*/
