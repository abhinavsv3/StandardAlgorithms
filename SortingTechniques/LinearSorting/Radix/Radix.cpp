#include<iostream>
using namespace std;
int maxOf(int array[], int n)
{
    int mx = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > mx)
            mx = array[i];
    return mx;
}
void countSort(int array[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[ (array[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (array[i]/exp)%10 ] - 1] = array[i];
        count[ (array[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        array[i] = output[i];
}
 
void radixsort(int array[], int n)
{
    int m = maxOf(array, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(array, n, exp);
}
void print(int *a,int N)
{
	for(int i=0;i<N;i++)
	{
		cout<<a[i]<<" : ";
	}
	cout<<endl;
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
	cout<<maxOf(a,N)<<endl;
	radixsort(a,N);	
	cout<<"Sorted Sequence : "<<endl;
	print(a,N);	
	delete[] a;
	return 0;	
}
