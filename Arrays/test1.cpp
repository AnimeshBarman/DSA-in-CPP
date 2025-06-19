#include<iostream>
using namespace std;

//Finding the smallest number in the array

int main(){

    int nums[] = {5,15,21,14,19};
    int size = 5;
    int index = 0;

    int smallest = INT16_MAX;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] < smallest) //alt method: smallest = min(nums[i], smallest);
        {
            smallest = nums[i];
            index++;
        }
        
    }
    
    cout << "Smallest number is: "<<smallest << endl;
    cout<< "index is: "<< index<<endl;

    return 0;
}