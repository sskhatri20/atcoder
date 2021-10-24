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

vector<vector<int>>adj;
void edge(int &x, int &y){
	--x, --y;
	adj[x].pb(y);
}

int n, m;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))return 1;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return 1;
        }
    }
    color[v] = 2;
    return 0;
}

bool find_cycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }
	if(cycle_start!=-1){
		return true;
	}
	return false;
    
}
vector<int>ans;

void test_cases(){
	cin>>n>>m;
	adj.resize(n);
	vector<int>ind(n);
	rep(i,m){
		int x, y;
		cin>>x>>y;
		ind[y-1]++;
		edge(x,y);
	}
	if(find_cycle()){
		cout<<-1<<nl;
		return ;
	}
	priority_queue<int, v1d, greater<int>>heap;

	rep(i,n)if(ind[i]==0)heap.push(i);
	ans.reserve(n);
	while(!heap.empty()){
		int x= heap.top();
		heap.pop();
		ans.pb(x+1);
		for(auto j : adj[x]){
			--ind[j];
			if(ind[j]==0)heap.push(j);
		}
	}
	print(ans);
	

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





