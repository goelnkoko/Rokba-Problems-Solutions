#include <bits/stdc++.h>

#define endl '\n'
#define vi vector<int> 

typedef long long ll;

using namespace std;

const int MAX = 100001;
const int MOD = 1e9+7;

vi par(MAX);

int find(int x){
	if(par[x] < 0) return x;

	return par[x] = find(par[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);

	if(x == y) return;
	par[x] = min(par[x], par[y]);
	par[y] = x;
}

int main() {
	
	int n, m;
	cin >> n >> m;

	for(int i=1; i < MAX; i++)
		par[i] = -1*i;

	while(m--){
		int a, b;
		cin >> a >> b;

		merge(a, b);
	}

	int q; 
	cin >> q;


	while(q--){
		int a, b;
		cin >> a >> b;

        int x = find(a);
        int y = find(b);

		if(par[x] == par[y]) cout << "TIE" << endl;
		else if(par[x] < par[y])
			cout << a << endl;
		else 
			cout << b << endl;
	}
}