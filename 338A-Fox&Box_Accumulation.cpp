/* solution taken from https://titanwolf.org/Network/Articles/Article?AID=51364c9f-a7ce-4d0b-8454-aacbab70fd79#gsc.tab=0 */

#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
		
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int k=1,ans=1;
	int count[102],pile[102];
	for(int i=0;i<102;i++) count[i]=0;
	for(int i=0;i<n;i++) count[arr[i]]+=1;
	for(int i=0;i<102;i++) pile[i]=0;
	int i=0;
	while(n>0){
		k=1;
		while( count[arr[i]]>0 ){
			if( arr[i]<pile[k] ) k+=1;
			pile[k]+=1;
			count[arr[i]]-=1;
			n-=1;
		}
		i+=1;
		ans=max(ans,k);
	}
	cout<<ans;		
}
/* another very simple approach :
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int index[102];
	for(int i=0;i<102;i++) index[i]=0;
	int cnt=0,pile=0;
	vector<int> v;
	while(cnt!=n){
		pile+=1;
		for(int i=0;i<n and cnt<n ;i++){
			int l = v.size();
			if( arr[i]>=l and index[i]==0 ){
				v.push_back(arr[i]);
				cnt+=1;
				index[i]=1;
			}
		}
		v.clear();
	}
	cout<<pile;
*/	
