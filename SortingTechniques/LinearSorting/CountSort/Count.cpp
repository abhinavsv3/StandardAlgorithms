#include<iostream>
using namespace std;
void print(int *a,int N);
void CountSort(int *a,int *b,int k,int N)
{	
	k++;
	int *c =new int[k];
	for(int i=0;i<k;i++)
		c[i]=0;
	for(int j=0;j<N;j++)
		c[a[j]]++;
	for(int i=1;i<k;i++)
		c[i]+=c[i-1];
	for(int j=N-1;j>=0;j--){
		b[c[a[j]]-1] = a[j];
		c[a[j]]--;
	}
	delete[] c;
}
int maxOf(int *a,int N)
{	
	int max = a[0];
	for(int i=1;i<N;i++)
		if(a[i] > max)
			max = a[i];	
    return max;
}
int main()
{
	int N;
	cout<<"Enter the Number of Elemets to be sorted : ";
	cin>>N;
	int *a = new int [N];
	cout<<"Enter "<<N<<" Elemets to be sorted : "<<endl;
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
	}
	cout<<"Unsorted Sequence : "<<endl;
	print(a,N);	
	int *b = new int[N];
	cout<<maxOf(a,N)<<endl;
	CountSort(a,b,maxOf(a,N),N);	
	cout<<"Sorted Sequence : "<<endl;
	print(b,N);
	delete[] a;
	delete[] b;
	return 0;	
}
void print(int *a,int N)
{
	for(int i=0;i<N;i++)
	{
		cout<<a[i]<<" : ";
	}
	cout<<endl;
}
