#include "headers/sortingAlgos.h"


void selectionSort(std::vector<int> &vect)
{
    for (int i = 0; i < vect.size()-1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i+1; j < vect.size(); j++)
        {
            if (vect[j] < vect[min_idx])
            {
                min_idx = j;
            }
            displayArray(vect,j);
            displayArray(vect,min_idx-1);
        }
        displayArray(vect,min_idx-1);
        std::swap(vect[min_idx], vect[i]);
        displayArray(vect,i-1);
    }
}

void insertionSort(std::vector<int> &vect)
{
    for (int i = 1; i < vect.size() ; i++)
    {
        int key = vect[i];
        int j = i - 1;
        while (vect[j] > key && j >= 0)
        {
            vect[j + 1] = vect[j];
            j--;
            displayArray(vect,j);
        }
        vect[j + 1] = key;
    }
}

//We find the smallest element in the unsorted array and we put in the end of the sorted array
void bubbleSort(std::vector<int> &vect)
{
    for (int i = 0; i < vect.size()-1; i++)
        // Last i elements are already in place
        for (int j = 0; j < vect.size()-i-1; j++)
        {
            if (vect[j] > vect[j+1])
                std::swap(vect[j], vect[j+1]);
            displayArray(vect,j);
        }
};

void CocktailSort(std::vector<int> &vect)
{
    bool swapped = true;
    int start = 0;
    int end = vect.size() - 1;
    while (swapped)
    {
        swapped = false;
//From left to right
        for (int i = start; i < end; ++i)
        {
            if (vect[i] > vect[i + 1])
            {
                std::swap(vect[i], vect[i + 1]);
                swapped = true;
            }
            displayArray(vect,i);
        }

        if (!swapped)
            break;
        swapped = false;
        --end;
//From right to left
        for (int i = end - 1; i >= start; --i)
        {
            if (vect[i] > vect[i + 1])
            {
                std::swap(vect[i], vect[i + 1]);
                swapped = true;
            }
            displayArray(vect,i);
        }
        ++start;
    }
}
//--------merge sort----------------------------------
void merge(std::vector<int> &vect, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = vect[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = vect[m + 1 + j];

    // Merge the temp arrays back into vect[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vect[k] = L[i];
            i++;
        }
        else {
            vect[k] = R[j];
            j++;
        }
        displayArray(vect,k);
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        vect[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        vect[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of vect to be sorted */
void mergeSort(std::vector<int> &vect,int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(vect,l,m);
    mergeSort(vect,m+1,r);
    merge(vect,l,m,r);
}


