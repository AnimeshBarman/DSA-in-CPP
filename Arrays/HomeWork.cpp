#include<iostream>
using namespace std;

//calculate sum & product of numbers in an array

int sum(int arr[], int size){
    int total= 0;
    for(int i=0; i<size; i++){
        total = total + arr[i];
    }
    return total;
}
int product(int arr[], int size){
    int prod = 1;
    for(int i = 0; i<size; i++){
        prod *= arr[i];
    }
    return prod;
}

//swap min & max value in an array

void swapMinMax(int arr[], int size){
    int small = arr[0];
    int large = arr[0];
    for(int i = 1; i< size; i++){
        small = min(arr[i], small);
        large = max(arr[i], large);
    }
    
    int smallIndex, largeIndex;
    for(int i=0; i< size; i++){
        if(arr[i] == small){
            smallIndex = i;
        }
        if(arr[i] == large){
            largeIndex = i;
        }
    }
    swap(arr[largeIndex], arr[smallIndex]);
}

//Print all the unique values in an array

void uniqueValue(int arr[], int size){

    for(int i = 0; i< size; i++){
        bool isUniue = true;  

        for(int j = 0; j < size; j++){
            if(i != j && arr[i] == arr[j]){
                isUniue = false;
                break;
            }
        }
        if(isUniue){
            cout<< arr[i] << " ";
        }
    }
    cout<<endl;
}


//Print Intersection of two array

void findIntersec(int arr[], int arr2[], int size){

    for(int i = 0; i< size; i++){
        bool isSame = false;
        for(int j = 0; j<size; j++){
            if(arr[i] == arr2[j]){
                isSame = true;
                break;
            }
        }
        if(isSame){
            cout<< arr[i]<< " ";
        }
    }
    cout<< endl;
}

int main(){

    int arr[] = {3,4,6,9,2,7};
    int arr2[] = {5,3,5,6,9,2};
    int size = 6;

    // int total_sum = sum(arr, size);
    // int total_prod = product(arr, size);
    // cout<<"Sum of the array is: "<< total_sum << endl;
    // cout<<"Product of the array is: " << total_prod << endl;


    // swapMinMax(arr, size);
    // for(int i =0; i< size; i++){
    //     cout << arr[i] << " ";
    // }
    // cout<<endl;


    // uniqueValue(arr, size);


    findIntersec(arr, arr2, size);

    return 0;
}
//DONE