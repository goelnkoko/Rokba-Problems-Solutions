#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define MOD 100000000
#define ll long long
#define vll vector<ll> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

int main() {
	
	ll n, k;
	cin >> n >> k;
	vll cnt(k);

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		cnt[x % k]++;
	}

	int ans = cnt[0] / 2;

	if (k % 2 == 0) ans += cnt[k / 2] / 2;

	for (int i = 1; i < (k + 1) / 2; ++i) {
		int j = k - i;
		ans += min(cnt[i], cnt[j]);
	}
	
	cout << ans * 2 << endl;
	
	return 0;
}