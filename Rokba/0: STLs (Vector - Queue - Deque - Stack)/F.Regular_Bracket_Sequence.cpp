#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

int main(){
  fast;
  //freopen("F.out", "w", stdout);
  int t;
  string s;int i = 0;

  cin>>t;

    while(t--){
  
        cin>>s;
        stack<char> p;

        for(i = 0; i < s.size(); ++i){
            if(s[i] == '?'){
                if(p.empty()) p.push('(');
                else if(p.top() == ')')
                else p.push(')');
            } else if (s[i] == '(') {
                p.push('(');
            } else if(p.empty()) {
                break;
            }
            else 
                p.pop();
        }

        if(i == s.size() && p.empty())
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }

  return 0;
}