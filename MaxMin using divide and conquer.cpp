#include<iostream>
#include<vector>
using namespace std;
void in(int a[],int n){
	for(int i=0;i<n;i++)
		cin>>a[i];
}
void print(int a[],int n){
	for(int i=0;i<n;i++)
		cout<<a[i];
}
int getMax(int a,int b){
	if(a>b)
		return a;
	return b;
}
int getMin(int a,int b){
	if(a<b)
		return a;
	return b;
}
void show(vector<int> a,int n){
	for(int y=0;y<n;y++)
		cout<<a[y]<<"  ";
	cout<<endl;
}
vector<int> MaxMin(int a[],int i,int n){
//	show(a,i,n);
	if(i==n){
		vector<int> h;
		h.push_back(a[i]);
		h.push_back(a[i]);
		return h;
	}
	int mid=(i+n)/2;
	vector<int> jj;
	vector<int> m=MaxMin(a,i,mid);
	vector<int> k=MaxMin(a,mid+1,n);
	jj.push_back(getMax(m[0],k[0]));
	jj.push_back(getMin(m[1],k[1]));
	return jj ;
	
}
int main(void){
	int n;
	cout<<"Size of the array-";
	cin>>n;
	int a[n];
	cout<<"ENTER ELEMENTS-";
	in(a,n);
	vector<int> o=MaxMin(a,0,n-1);
	cout<<"Max "<<o[0]<<endl<<"Min "<<o[1];
}
