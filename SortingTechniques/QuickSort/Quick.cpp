#include <iostream>
using namespace std;
int partition(int a[],int p,int r)
{
		int x,t;
		x=a[r];
		int i=p-1;
		for(int j=p;j<r-1;j++)
		{
				if(a[j] <= x){
					i++;
					t=a[i];
					a[i]=a[j];
					a[j] =t;
				}
		}
		t=a[i+1];
		a[i+1]=a[r];
		a[r] =t;
		return i+1;
}
void quicksort(int a[],int p,int r)
{
		int q;
		if(p<r)
		{
				q=partition(a,p,r);
				quicksort(a,p,q-1);
				quicksort(a,q+1,r);			
		}
			

}
void print(int a[],int N)
{
		for(int i=0;i<N;i++)
		{
				cout<<a[i]<<"|";
		}
		cout<<endl;
}
int main()
{
	int a[] = {5,3,6,7,9,8,1,36,58,6,5,4,21,-1},N=14;
	print(a,N);
	quicksort(a,0,N);
	print(a,N);
	return 0;
}
