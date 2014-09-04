#include<iostream>
using namespace std;
const int SIZE = 100 ;
void print(int *a,int N);
void swap(int &a,int &b){
		int temp = a;
		a=b;
		b=temp;
}
class Heap{
	int heapsize;
	int *array;
	int siz;
  public:
    int accept();
	int heapify();
	int adjust(int I);
	int heapsort();
};
#define _ Heap ::
int _ accept(){
	int n;
	cout << "Enter the number of elements" << endl;
	cin >> n;
	heapsize = siz = n;
	array = new int[n+1];
	array[0]=0;
	cout<<"Enter "<<n<<" Elemets to be sorted : "<<endl;
	for(int i=1;i<n+1;i++)
	{
		cin>>array[i];
	}
	cout<<"Unsorted Sequence : "<<endl;
	print(array,n+1);	
	heapsort();
	cout<<"Sorted Sequence : "<<endl;
	print(array,n+1);
}
int _ heapify(){
	int i=heapsize/2;

	while(i>=1){
			adjust(i);
			i--;
	}
}
int _ adjust(int I){
	int l = 2*I;
	int r = l+1;
	int lar = I;
	int temp;
	if(l<=heapsize &&  array[l]>array[I])
		lar = l;
	if(r<=heapsize && array[r]>array[lar])
		lar =r;
	if(lar != I){
		swap(array[lar] ,  array[I]);
        adjust(lar);

	}
}
int _ heapsort(){
	heapify();
	int Q=heapsize;
	while(Q>=2){
		swap(array[1],array[Q]);
		heapsize--;
		Q--;
		adjust(1);
	}
}
int main(){
	Heap h;
	h.accept();
	return 0;
}

void print(int *a,int N)
{
	for(int i=1;i<N;i++)
	{
		cout<<a[i]<<" : ";
	}
	cout<<endl;
}
