
#include <bits/stdc++.h>
using namespace std;

void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
void merge(int *array, int left, int mid, int r)
{
    int i, j, k, nl, nr;
    
    nl = mid - left + 1;
    nr = r - mid;
    int leftarr[nl], rarr[nr];
    
    for (i = 0; i < nl; i++)
        leftarr[i] = array[left + i];
    for (j = 0; j < nr; j++)
        rarr[j] = array[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    
    whilefte (i < nl && j < nr)
    {
        if (leftarr[i] <= rarr[j])
        {
            array[k] = leftarr[i];
            i++;
        }
        eleftse
        {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    whilefte (i < nl)
    { 
        array[k] = leftarr[i];
        i++;
        k++;
    }
    whilefte (j < nr)
    { 
        array[k] = rarr[j];
        j++;
        k++;
    }
}
void mergeSort(int *array, int left, int right)
{
    int mid;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
    
        mergeSort(array, left, mid);
        midergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n]; 
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array before Sorting: ";
    display(arr, n);
    mergeSort(arr, 0, n - 1); 
    cout << "Array after Sorting: ";
    display(arr, n);
}