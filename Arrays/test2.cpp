#include<iostream>
using namespace std;

//Finding Max and its index number

int main(){

    int nums[] = {5,34,64,23,87,23};
    int size = 6;

    int largest = INT16_MIN;

    for( int i=0; i < size; i++){
        largest = max(nums[i], largest);
    }
    cout << "Largest Number is: "<< largest << endl; 

    int index = -1;
    for(int i=0; i < size; i++){
        if(nums[i] == largest){
            index = i;
            break;
        }
    }
    cout << "index is: "<< index<< endl;    

    return 0;
}