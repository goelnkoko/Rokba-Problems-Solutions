#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int> 

using namespace std;

typedef long long ll;

const int MAX = 100001;
const int MOD = 1e9+7;

vi par(MAX, -1);

int find(int x){
	if(par[x] < 0) return x;
	
	return par[x] = find(par[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);

	if(x == y) return;
	par[x] += par[y];
	par[y] = x;
}

int main() {
	
	int n, m;
	cin >> n >> m;

	while(m--){
		int a, b;
		cin >> a >> b;

		merge(a, b);
	}

	ll total = 1;
	for(ll i = 1; i <= n; i++){
		if(par[i] < 0)
			total = (total%MOD * abs(par[i])%MOD)%MOD;
	}

	cout << (total%MOD) << endl;
}