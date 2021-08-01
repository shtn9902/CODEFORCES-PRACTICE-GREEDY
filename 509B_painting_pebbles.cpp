/*
code 1: first approach, less optimised, Self thought and self implementation
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n,k;
   cin>>n>>k;
   int m=INT_MAX;
   int arr[n];
   for(int i=0;i<n;i++){
   	cin>>arr[i];
   	m=min(m,arr[i]);
   }	
  // cout<<m<<" ";
   int colors[k];
   for(int i=0;i<k;i++) colors[i]=i+1;
   //int allowed = m-1+k;
   bool poss=true;
   //cout<<allowed<<"\n";
   for(int i=0;i<n;i++){
   	if(arr[i]>m+k) poss=false;
   }
   if(!poss){
   	cout<<"NO";
   }
   else{
   	int ans[n][102];
   	for(int i=0;i<n;i++){
   		for(int j=0;j<102;j++) ans[i][j]=-1;
	   }
   	priority_queue<pair<int,int>, vector<pair<int,int> > ,greater<pair<int,int>> >p;
   	
	for(int i=0;i<n;i++){
		while(!p.empty()) p.pop();
		for(int i=1;i<k;i++){
   		p.push( {0,i+1} );
		}		
		for(int j=0;j<arr[i];j++){
			if(j<=m) ans[i][j]=colors[0];
			else{
				ans[i][j] = p.top().second;
				pair<int,int> q=p.top();
				p.pop();
				int x=q.first; int y=q.second;
				p.push( {x+1,y} );
			}
		}
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<arr[i];j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
   }
   
}
/*
code 2: optimised solution. Also self implementation
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n,k;
   cin>>n>>k;
   int m=INT_MAX;
   int arr[n];
   for(int i=0;i<n;i++){
   	cin>>arr[i];
   	m=min(m,arr[i]);
   }	
  // cout<<m<<" ";
   int colors[k];
   for(int i=0;i<k;i++) colors[i]=i+1;
   //int allowed = m-1+k;
   bool poss=true;
   //cout<<allowed<<"\n";
   for(int i=0;i<n;i++){
   	if(arr[i]>m+k) poss=false;
   }
   if(!poss){
   	cout<<"NO";
   }
   else{
   	int ans[n][102];
   	for(int i=0;i<n;i++){
   		for(int j=0;j<102;j++) ans[i][j]=-1;
	   }
   	priority_queue<pair<int,int>, vector<pair<int,int> > ,greater<pair<int,int>> >p;
   	
	for(int i=0;i<n;i++){
		while(!p.empty()) p.pop();
		for(int i=1;i<k;i++){
   		p.push( {0,i+1} );
		}		
		for(int j=0;j<arr[i];j++){
			if(j<=m) ans[i][j]=colors[0];
			else{
				ans[i][j] = p.top().second;
				pair<int,int> q=p.top();
				p.pop();
				int x=q.first; int y=q.second;
				p.push( {x+1,y} );
			}
		}
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<arr[i];j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
   }
   
}

