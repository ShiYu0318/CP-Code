// d097
#include<bits/stdc++.h>
using namespace std;

void quicksort(int arr[],int left,int right)
{
	int i=left,j=right;
	int pivot = arr[(left+right)/2];
	while(i <= j)
	{
		while(arr[i] < pivot) i++;
		while(arr[j] > pivot) j--;
		if(i <= j)
		{
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
	}
	if(left < j)
	{
		quicksort(arr,left,j);
	}
	if(i < right)
	{
		quicksort(arr,i,right);
	}
}



int main()
{
	int n;
	while(cin >> n)
	{
		int tmp[n],arr[n-1],output=1;
		for(int i=0;i<n;i++){
			cin >> tmp[i];
		}
		for(int i=0;i<n-1;i++)
		{
			arr[i] = abs(tmp[i+1] - tmp[i]);
		}
		quicksort(arr,0,n-1);
		
		for(int i=0;i<n-1;i++)
		{
			if(arr[i+1] - arr[i] == i+1) 
			{
				cout << arr[i+1] << " " << arr[i] << " " << i+1 << "\n";
				continue;
			}
			else
			{
				output=0;
				break;
			}
		}
		if(output == 1) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
}