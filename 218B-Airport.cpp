						// https://codeforces.com/problemset/problem/218/B//	
	/*
		218 B : Airport
		Data structure used: MinHeap and MaxHeap
		My own unique approach of the question
	*/
// My Unique Approach //
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int> q;
	priority_queue<int, vector<int>,greater<int> > p;
	int n,m,x;
	cin>>n>>m;
	while(m--){
		cin>>x;
		q.push(x);
		p.push(x);
	}
	int max_ans=0,pass_max=0;
	while(pass_max<n and !q.empty()){
		int amt = q.top(); q.pop();
		if(!q.empty()){
			int needed = n - pass_max;
			if(needed<=amt and ( (amt-needed)>=q.top() ) ){
				pass_max+=needed;
				int j = amt-needed;
				if(j!=0)
					q.push(j);
				max_ans+= ( (((amt)*(amt+1))/2) - ( ((j)*(j+1))/2 )  );
			}
			else if(needed<=amt and ( (amt-needed)<q.top() ) ){
				pass_max+= amt-q.top()+1;
				int j = q.top()-1;
				if(j!=0)
					q.push(j);
				max_ans+= ( (((amt)*(amt+1))/2) - ( ((j)*(j+1))/2 ) );	
			}
			else if(needed>amt){
				pass_max+=amt-q.top()+1;
				int j = q.top()-1;
				if(j!=0) q.push(j);
				max_ans+= ( (((amt)*(amt+1))/2) - ( ((j)*(j+1))/2 ) );
			}
		}
		else{
			int needed = n-pass_max;
			int j = amt-needed;
			pass_max+= needed;
			max_ans+= ( (((amt)*(amt+1))/2) - ( ((j)*(j+1))/2 ) );
		}
		
	}
	int min_ans=0;
	pass_max=0;
	
	while(pass_max<n and !p.empty()){
		int needed = n-pass_max;
		int amt = p.top();
		if(needed>=amt){
			pass_max+=amt;
			min_ans+=( ( ((amt)*(amt+1))/2 )  );			
			p.pop();
		}
		else{
			int l = amt - needed;
			min_ans+=( ( ((amt)*(amt+1))/2 ) - ((l)*(l+1))/2 );
			pass_max+=needed;
			p.pop();
			
		}
	}
	
	cout<<max_ans<<" "<<min_ans;
}

// Very short approach using MaxHeap and MinHeap//
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int> q;
	priority_queue<int, vector<int>,greater<int> > p;
	int n,m,x;
	cin>>n>>m;
	while(m--){
		cin>>x;
		q.push(x);
		p.push(x);
	}
	int max_ans=0,min_ans=0;
	for(int i=0;i<n;i++){
		int x = q.top();
		q.pop();
		max_ans+=x;
		x-=1;
		if(x!=0) q.push(x);
	}
	for(int i=0;i<n;i++){
		int x = p.top();
		p.pop();
		min_ans+=x;
		x-=1;
		if(x!=0) p.push(x);
	}
	cout<<max_ans<<" "<<min_ans;
}

