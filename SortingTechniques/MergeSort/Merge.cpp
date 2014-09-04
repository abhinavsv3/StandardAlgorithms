#include <iostream>
using namespace std;

int Merge(int a[],int p,int q,int r)
{
	int i=p,j=q+1,k=0;
	int *t = new int[r-p+1];
	while(i<=q && j<=r)
	{
		if(a[i]<=a[j])
		{
			t[k]=a[i];
			i++;
		}
		else
		{
			t[k]=a[j];
			j++;
		}
	   k++;
	}
	while(i<=q){ 
		t[k]=a[i];
		k++;i++;
	}
	while(j<=r){
		t[k]=a[j];
		k++;j++;
	}
	for(int l=p,e=0;e<k;l++,e++)
	{
		a[l] = t[e];
	}

	delete[] t;	
	return 1;
}
int MergeSort(int *a,int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		MergeSort(a,p,q);
		MergeSort(a,q+1,r);
		Merge(a,p,q,r);
	}
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
	MergeSort(a,0,N-1);
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
