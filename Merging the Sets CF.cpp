#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n,m; cin>>n>>m;
  
  vector<set<int>> arr;
  unordered_map<int,int>mp;
  for(int i=0;i<n;i++){
    int sz; cin>>sz;
    set<int>st;
    for(int i=0;i<sz;i++){
      int a; cin>>a;
      st.insert(a);
      mp[a]++;
    }
    arr.push_back(st);
  }
  if(mp.size()!=m){
    cout<<"NO"<<endl;
    return;
  }
  
  int count=0;
  for(auto st:arr){
    for(auto si:st){
      mp[si]--;
      if(mp[si]==0) mp.erase(si);
    }
    if(mp.size()==m) count++;
    
    for(auto si:st){
      mp[si]++;
    }
  }
  
  if(count<2){
    cout<<"NO"<<endl;
    return;
  }
  
  cout<<"YES"<<endl;
  return;
  
}

int32_t main() 
{
    int t; cin>>t;
    while(t--){
      solve();
    }
}
