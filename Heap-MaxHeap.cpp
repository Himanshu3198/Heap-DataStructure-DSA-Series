#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[largest])
	{
		largest=l;
	}
	if(r<n && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		
		heapify(arr,n,largest);
	}

}
void BuildHeapify(int a[],int n){
	int startIndex=n/2-1;
	for(int i=startIndex;i>=0;i--){

		heapify(a,n,i);

	}
}

void printHeap(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
int main(){
	int a[]={1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
	int n=sizeof(a)/sizeof(a[0]);
	BuildHeapify(a,n);
	printHeap(a,n);
}