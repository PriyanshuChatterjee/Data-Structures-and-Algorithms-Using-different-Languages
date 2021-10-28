#include<bits/stdc++.h>
#define list vector<int>
using namespace std;
class nqueen{
	vector<list> sol;
	int n;
	bool **b;
	public:
	nqueen(int v){
		n=v;
		b=(bool**)malloc(n*sizeof(bool*));
		for(int i=0;i<n;i++){
			bool *f=(bool*)malloc(n*sizeof(bool));
			for(int j=0;j<n;j++)
				*(f+j)=false;
			*(b+i)=f;
		}
	}
	bool issafe(int i,int j){
		for(int k=0;k>=0 and k<n;k++){
			if(b[k][j])
				return false;
		}
		for(int k=0;k>=0 and k<n;k++){
			if(b[i][k])
				return false;
		}	
		for(int k=i,l=j;k>=0 and l>=0;k--,l--){
			if(b[k][l])
				return false;
		}
		for(int k=i,l=j;k<n and l>=0;k++,l--){
			if(b[k][l])
				return false;
		}
		return true;			
	}
	bool rec(int r,int c){
		if(c==n){
			list v;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(b[i][j]){
						v.push_back(j);
						
					}
						
				}
			}
			sol.push_back(v);
			return true;
		}
		bool f=false;
		for(int i=0;i<n;i++){
	
			if(issafe(i,c)){
				b[i][c]=1;
				f=rec(r,c+1);
				b[i][c]=0;
			}
		}
		return f;
	}
	void soln(){
		rec(0,0);
		if(sol.size()){
			sort(sol.begin(),sol.end());
			cout<<"total solution "<<sol.size()<<endl;
			for(int i=0;i<sol.size();i++){
				for(int j=0;j<sol[i].size();j++)
					cout<<sol[i][j]<<" ";
				cout<<endl;
			}
		}
		else
			cout<<"NO OP";
	}
};
int main(void){
	int n;
	cout<<"Enter number of queens ";
	cin>>n; 
	nqueen q=nqueen(n);
	q.soln();
}
