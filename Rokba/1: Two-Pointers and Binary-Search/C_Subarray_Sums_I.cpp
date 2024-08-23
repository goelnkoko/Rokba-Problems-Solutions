#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long
#define endl '\n'

using namespace std;

int main(){

    Nkumbo

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i=0; i < n; i++)
        cin >> a[i];

    ll l = 0, r = 0, sum = a[0], c = 0;

    while(l != n-1){
        if(sum == k) c++;

        if(sum < k && r < n-1){
            r++;
            sum += a[r];
        } else {
            sum -= a[l];
            l++;

            if(l > r && l < n){
                r = l;
                sum = a[l];
            }
        }
    }

    if(sum == k) c++;

    cout << c << endl;

    
}