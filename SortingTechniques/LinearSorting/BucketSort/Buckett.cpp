#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucketSort(float array[], int n)
{

    vector<float> buck[n];
    for (int i=0; i<n; i++)
    {
       int bi = n*array[i];
       buck[bi].push_back(array[i]);
    }
    for (int i=0; i<n; i++)
       sort(buck[i].begin(), buck[i].end());
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < buck[i].size(); j++)
          array[index++] = buck[i][j];
}
void print(float *a,int N);
int main()
{
    float array[] = {0.23,0.56,0.2354,0.4856,0.235,0.05,0.99};
    int n = sizeof(array)/sizeof(array[0]);
    cout<<"Unsorted Sequence : "<<endl;
    print(array,n);	
    bucketSort(array, n);
    cout<<"Sorted Sequence : "<<endl;
    print(array,n);	
   return 0;
}
void print(float *a,int N)
{
	for(int i=0;i<N;i++)
	{
		cout<<a[i]<<" : ";
	}
	cout<<endl;
}

