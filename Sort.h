#ifndef SORT_H
#define SORT_H

template <class T>
void merge(T arr[],int left, int mid, int right, bool (*compare)(const T&, const T&)){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    T* L = new T[n1];
    T* R = new T[n2];

    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2){
        if(compare(L[i], R[j])) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
    delete[] L;
    delete[] R;
}

template <class T>
void mergeSort(T arr[], int left, int right, bool (*compare)(const T&, const T&)){
    if(left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid, compare);
    mergeSort(arr, mid + 1, right, compare);
    merge(arr, left, mid, right, compare);
}

#endif

