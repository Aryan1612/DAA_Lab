#include<bits/stdc++.h>
using namespace std;


vector<int>arr;
 int n;
bool check1(int mid){
  if(arr[mid]>arr[n-1]){
    return 1;
  }
  return 0;
}
void solve(){
 
  cin>>n;
  int target;
  cin>>target;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    arr.push_back(a);
  }
  int lo=0;
  int hi=n-1;
  int peaki=n-1;

  while(lo<=hi){
    int mid=(lo+hi)/2;
    if(check1(mid)){
      peaki=mid;
      lo=mid+1;
    }
    else{
      hi=mid-1;
    }
  }
  if(target>arr[peaki]){
    cout<<-1<<endl;
    return;
  }
  int lo1=0;
  int hi1=peaki;
  int ans =-1;
  int lo2=peaki+1;
  int hi2=n-1;
  while(lo1<=hi1){
    int mid=(lo1+hi1)/2;
    if(arr[mid]>target){
      hi1=mid-1;
    }
    else if(arr[mid]<target){
      lo1=mid+1;
    }
    else{
      ans=mid;
      break;
    }
   
  }
  if(ans!=-1){cout<<ans<<endl;return;}
    while(lo2<=hi2){
    int mid=(lo2+hi2)/2;
    if(arr[mid]>target){
      hi2=mid-1;
    }
    else if(arr[mid]<target){
      lo2=mid+1;
    }
    else{
      ans=mid;
      break;
    }
   
  }
 
   if(ans!=-1){cout<<ans<<endl;return;}
 

}

int main(){
  solve();
}
