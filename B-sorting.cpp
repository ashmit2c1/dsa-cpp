#include<bits/stdc++.h>
using namespace std;
// INSERTION SORT 
void insertionSort(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        int currentElement=arr[i];
        int j=i-1;
        while(j>=0 && arr[j] > currentElement){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=currentElement;
    }
}
// SELECTION SORT 
void selectionSort(vector<int>&arr){
    int minIndex;
    for(int i=0;i<arr.size()-1;i++){
        minIndex=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            swap(arr[minIndex],arr[i]);
        }
    }
}
//BUBBLE SORT 
void bubbleSort(vector<int>&arr){
    for(int i=0;i<=arr.size()-1;i++){
        bool flag=false;
        for(int j=0;j<=arr.size()-2;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=true;
            }
        }
        if(flag==false){
            break;
        }
    }
}
// MERGE SORT 
void merge(vector<int>& arr, int start, int mid, int end) {
    int sizeA = mid - start + 1;
    int sizeB = end - mid;
    vector<int> a(sizeA);
    vector<int> b(sizeB);
    for (int i = 0; i < sizeA; i++) {
        a[i] = arr[start + i];
    }
    for (int i = 0; i < sizeB; i++) {
        b[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, index = start;
    while (i < sizeA && j < sizeB) {
        if (a[i] <= b[j]) {
            arr[index] = a[i];
            i++;
        } else {
            arr[index] = b[j];
            j++;
        }
        index++;
    }
    while (i < sizeA) {
        arr[index] = a[i];
        i++;
        index++;
    }
    while (j < sizeB) {
        arr[index] = b[j];
        j++;
        index++;
    }
}
void mergeSort(vector<int>& arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
//QUICK SORT 
int partition(vector<int>&arr,int start,int end){
    int pivot = arr[end];
    int i=start-1;
    for(int j=start;j<end;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}
void quickSort(vector<int>&arr,int start,int end){
    if(start>=end){
        return;
    }
    int pivot = partition(arr,start,end);
    quickSort(arr,start,pivot-1);
    quickSort(arr,pivot+1,end);
}

int main(){
    int n=5;
    vector<int>arr;
    for(int i = 0; i<n ; i++){
        int x;cin >>x;arr.push_back(x);
    }
    insertionSort(arr);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    
}
