#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1.5e7+10
#define ll long long
#define vi vector<int> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

int main() {

    Nkumbo
	
	int n;
    cin >> n;

    map<int, string> mp = {{1, "Sheldon"}, {2, "Leonard"}, {3, "Penny"}, {4, "Rajesh"}, {5, "Howard"}};

    int i = 0;
    while(n - 5 * (1 << i) >= 0){
        n -= (5 * (1 << i));
        i++;
    }

    n = ceil((double)n/(1 << i));

    cout << (n ? mp[n] : mp[5]) << endl;

    return 0;
}