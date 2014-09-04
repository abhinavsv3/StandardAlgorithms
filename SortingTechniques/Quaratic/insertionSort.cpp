#include<iostream>
using namespace std;
int insertionSort(int a[], int N)
{
   int key,i;
	for(int j=1;j<N;j++)
	{
		key=a[j];
		i=j-1;
		while(i>=0 && a[i]>key)
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
        }
   return 1;
}
void print(int *a,int N);
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
	insertionSort(a,N);
	cout<<"Sorted Sequence : "<<endl;
	print(a,N);
	delete[] a;
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
