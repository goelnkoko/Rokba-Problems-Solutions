#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1010
#define ll long long
#define vi vector<int> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

bool isPrime(int n){
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

int main() {

    Nkumbo

    int n;
    cin >> n;

    if (isPrime(n)) {
        cout << 1 << endl;
    } else if(n % 2 == 0 && n != 2 || isPrime(n-2)){
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }

    return 0;
}