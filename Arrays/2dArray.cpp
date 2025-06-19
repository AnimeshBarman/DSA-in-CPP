#include <iostream>
#include <utility>
using namespace std;

//Finding index of a given input using PAIR..2D Array

pair<int, int> findIdx(int arr[3][3], int row, int col, int key)
{
    pair<int, int> index = {-1, -1};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == key)
            {
                index.first = i;
                index.second = j;
                return index;
            }
        }
    }

    return index;
}

// HomeWork: Maximum sum of Column

int maxSum(int arr[3][3], int col, int row){
    int maxColSum = INT8_MIN;
    for(int i = 0; i<col; i++){
        int colSum = 0;
        for(int j = 0; j< row; j++){
            colSum = colSum + arr[i][j];
        }
        maxColSum = max(maxColSum, colSum);
    }

    return maxColSum;
}

int main()
{

    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {9, 8, 7}};
    int row = 3;
    int col = 3;

    /*pair<int, int> result = findIdx(arr, row, col, 0);

    if(result.first != -1 && result.second != -1){
        cout<<"The Index are: "<<result.first<<", "<< result.second<<endl;
    } else {
        cout<<"Element not found :"<<result.first<<", "<<result.second<<endl;
    }*/
    
   cout<<maxSum(arr, row, col)<<endl;


    return 0;
}