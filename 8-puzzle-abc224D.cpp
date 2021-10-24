#include <bits/stdc++.h>
#define pb push_back
#define PQ priority_queue<int>
#define ff first
#define all(v) v.begin(), v.end()
#define ss second
#define pii pair<int,int>
#define v1d vector<int>
#define vpi vector<pair<int,int>>
#define int long long
#define nl '\n'
#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++) 
using namespace std;
template<typename T> void read(vector<T> &a){ for(T &e: a) cin>>e; } 
template<typename T> void print(vector<T> &a){ for(T &e: a) cout<<e<<" "; } 

void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

void IOS(){ios::sync_with_stdio(false); cout.precision(10); cout << fixed;}

#define INF (1LL<<60)
int i, j, k;
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
const int mx = 1e5 + 10;
const int MOD = 1e9 + 7;

vector<vector<int>>adj(10);
void edge(int &x, int &y){
	adj[x].pb(y);
	adj[y].pb(x);
}
vector<int>fact(mx),inv_fact(mx);
int modinv(int x, int m=MOD){
	if(x==1)return 1;
	return modinv(m%x,m)*(m-m/x)%m;
}
void factorial(){
	fact[0] = inv_fact[0] = 1;
	for(int i=1; i<mx; i++){
		fact[i] = fact[i-1]*i%MOD;
		inv_fact[i] = inv_fact[i-1]*modinv(i,MOD)%MOD;
	}
}
int bin(int a, int b){
	a%=MOD;
	int res = 1;
	while(b){
		if(b&1)res = res*a%MOD;
		a = a*a%MOD;
		b >>=1;
	}
	return res;
}	

void test_cases(){
	
	int n;
	cin>>n;
	rep(i,n){
		int x,y;
		cin>>x>>y;
		edge(x,y);
	}
	string s(9,'9');
	
	for(int i=1; i<=8; i++){
		int x; cin>>x;
		s[x-1] = i + '0';
	}
	queue<string>q;
	q.push(s);
	map<string,int>mp;
	mp[s] = 0;
	int v;
	while(q.size()){
		string s= q.front(); q.pop();
		for(int i=1; i<=9; i++)if(s[i-1]=='9')v=i;
		for(auto u:adj[v]){
			string t = s;
			swap(t[u-1], t[v-1]);
			if(mp.count(t))continue;
			mp[t] = mp[s] + 1;
			q.push(t);
		}
	}
	dbg(s);
	if(mp.count("123456789")==0)cout<<-1<<nl;
	else cout<<mp["123456789"]<<nl;
}

int32_t main(){
	IOS();
	int nr=1;
      //cin>>nr;
      for(int i=1; i<=nr; i++){
            test_cases();
      }
	
	return 0;
}





