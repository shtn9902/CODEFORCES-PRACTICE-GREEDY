/*
I have written explaination in notes
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long int n,m;
	cin>>n>>m;
	long long int d[m],h[m];
	for(long long int i=0;i<m;i++)
		cin>>d[i]>>h[i];
	bool poss=true;
	long long int maxh =  max( (h[0]-1)+d[0], (n-d[m-1])+h[m-1] );
	for(long long int i=0;i<m-1;i++){
		if( fabs(h[i]-h[i+1]) > (d[i+1]-d[i]) ){
			poss=false;
			break;
		} 
		
		maxh=max( maxh,  (h[i]+h[i+1]+(d[i+1]-d[i]))/2  );
	}
	if(!poss) cout<<"IMPOSSIBLE";
	else cout<<maxh; 
}
