#include<bits/stdc++.h>
using namespace std;


int main()
{
    int min_value , curr_index , loc ,temp;
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the array : "<<endl; 
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        min_value = arr[i];
        loc=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<min_value )
            {
                min_value = arr[j];
                loc = j;
            }
        }
            // temp = arr[i];
            // arr[i]= arr[loc];
            // arr[loc]=temp;
            swap(arr[i],arr[loc]);

    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}