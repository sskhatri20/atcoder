#pragma GCC optimize("O3")
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

int n;
string s;

void test_cases(){

	cin>>n>>s;
	vector<vector<v1d>>adj(3, vector<v1d>(3));
	rep(i,3*n){
		adj[i/n][s[i]-'A'].pb(i);
	}

	dbg(adj);
	v1d z = {0,1,2};
	int type = 0;
	do{
		type++;
		dbg(type, z);
		while(!adj[0][z[0]].empty() && !adj[1][z[1]].empty() && !adj[2][z[2]].empty()){

			rep(j,3){
				int x = adj[j][z[j]].back();
				adj[j][z[j]].pop_back();
				s[x] = '0' + type;
			}
			dbg(s);
		}
	}while(next_permutation(all(z)));
	cout<<s<<nl;
}


int32_t main(){

	IOS();
	int nr=1;
	//cin>>nr;
	for(int t=1; t<=nr; t++)test_cases();

	return 0;
}





