#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

//1.Find Score of Balanced Parentheses Problem

int scoreOfParentheses(string s)
{
    stack<int> st;

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(-1);
        }
        else
        {
            int sum = 0;
            while (st.top() != -1)
            {
                sum += st.top();
                st.pop();
            }
            st.pop();
            if (sum == 0)
            {
                st.push(1);
            }
            else
            {
                st.push(2 * sum);
            }
        }
    }

    int totalScore = 0;
    while (!st.empty())
    {
        totalScore += st.top();
        st.pop();
    }

    return totalScore;
}


//2.Span of Stocks Problem......................

vector<int> stockSpan(vector<int> price){ //vector function

    vector<int> ans(price.size(), 0);
    stack<int> s;

    for (int i = 0; i < price.size(); i++){
        while(!s.empty() && price[s.top()] <= price[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = i + 1;
        }else{
            ans[i] = i - s.top();
        }

        s.push(i);
    }

    return ans;
}


//3.Next Greater Element in an Array

vector<long int> nextGreater(int arr[], int size){
    vector<long int> v;
    stack<int> s;

    s.push(arr[size - 1]);
    v.push_back(INT64_MIN);

    for(int i = size - 2; i >= 0; i--){
        while(!s.empty() && s.top() <= arr[i])
            s.pop();
        
            long int res = s.empty() ? INT64_MIN : s.top();
            v.push_back(res);
            s.push(arr[i]);
    }

    reverse(v.begin(), v.end());
    return v;
    
}

//4.Practice Question 2: Find number of days of till the next day(Next Greater Elem Approach)

vector<int> nextGreaterIndex(int arr[], int size){
    stack<int> s;
    vector<int> ans;

    s.push(size - 1);
    ans.push_back(-1);
    
    for(int i = size - 2; i>=0; i--){
        while(!s.empty() && arr[s.top()] <= arr[i]){
            s.pop();
        }

        int res = s.empty() ? -1 : s.top();

        ans.push_back(res - i);
        s.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


//5.Largest Area of a Rectangle in Histogram

int largestRect(int arr[], int size){

    stack<int> s;
    int maxArea = 0;
    int nextSmaller=0;
    int prevSmaller=0;

    for(int i = 0; i <= size-1; i++){
        while(!s.empty() && arr[i] < arr[s.top()]){
            int element = s.top();
            s.pop();
            nextSmaller = arr[i];
            prevSmaller = s.empty() ? -1 : s.top();
            maxArea = max(maxArea, (nextSmaller - prevSmaller - 1)* arr[element]);
        }
        s.push(i);
    }

    while(!s.empty()){
        int element = s.top();
        s.pop();
        nextSmaller = size;
        prevSmaller = s.empty() ? -1 : s.top();
        maxArea = max(maxArea, (nextSmaller - prevSmaller - 1)* arr[element]);
    }
    
    return maxArea;
}


//6.Custom Stack with getMin()

class SpecialStack {
    vector<int> vec;
    vector<int> minStack;
public:
    void push(int x){
        vec.push_back(x);

        if(minStack.empty() || x <= minStack.back()){
            minStack.push_back(x);
        }

    }
    void pop(){
        if(vec.empty()){
            cout<<"Stack Underflow\n";
            return;
        }
        if(minStack.back() == vec.back()){
            minStack.pop_back();
        }
        vec.pop_back();
    }
    bool isEmpty(){
        return vec.empty();
    }

    int getMin(){
        if(minStack.empty()){
            cout<<"Stack is Empty\n";
            return -1;
        }
        return minStack.back();
    }
};

//7.Largest Rectangle with all 1's

int maxAreaOfRect(int arr[4][4], int n, int m){
    int maxArea = 0;
    vector<int> height(m, 0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 1) height[j]++;

            else height[j]=0;
        }
        int area = largestRect(height.data(), m);
        maxArea = max(area, maxArea);
    }
    return maxArea;
}


//8.Infix to Postfix

class wrapperClass{
    public:

    bool isOperand(char ch){
        return isalpha(ch);
    }

    int precedence(char op){
        if(op == '+' || op == '-') return 1;
        if(op == '*' || op == '/') return 2;
        if(op == '^') return 3;
        return -1;
    }

    string infixToPostfix(const string& infix){
        stack<char> st;
        string postfix;

        for(char ch : infix){
            if(isOperand(ch)){
                postfix += ch;
            }
            else if(ch == '('){
                st.push(ch);
            }
            else if(ch == ')'){
                while(!st.empty() && st.top() != '('){
                    postfix += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            else{
                while(!st.empty() && precedence(ch) <= precedence(st.top())){
                    postfix += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while(!st.empty()){
            postfix += st.top();
            st.pop();
        }
        return postfix;
    }

};


//9.Trapping Rain Water Problem

int countTotal(int arr[], int n){
    int leftMax=0;
    int rightMax=0;
    int total=0;
    int l = 0;
    int r = n-1;

    while(l < r){
        if(arr[l] <= arr[r]){
            if(leftMax > arr[l]){
                total += leftMax - arr[l];
            }
            else {
                leftMax = arr[l];
            }
            l++;
        }
        else {
            if(rightMax > arr[r]){
                total += rightMax - arr[r];
            }
            else {
                rightMax = arr[r];
            }
            r--;
        }
    }
    return total;
}

int main()
{
    /*
    //Score of the Balanced Parentheses
    string input;
    cout<<"Enter a string of balanced Parentheses: ";
    cin>>input;

    int result = scoreOfParentheses(input);
    cout<<"Score: "<<result<< endl;
    */



    // //Span of Stock
    // vector<int> vec = {100, 30, 60, 80, 50, 90, 55, 10};
    // vector<int> result = stockSpan(vec);

    // for(int val : result){
    //     cout<<val << " ";
    // }
    // cout<< endl;

    /*
    int arr[] = {30, 60, 50, 98, 20, 67};
    int size = sizeof(arr)/sizeof(arr[0]);


    for(long int x : nextGreater(arr, size)){
        if(x == INT64_MIN){
            cout<<"- ";
        }else{
            cout<<x<<" ";
        }
    }
*/

/*
    int arr[] = {67, 79, 70, 81, 60, 70, 82};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int x : nextGreaterIndex(arr, size)){
        cout<< x<<" ";
    }
    cout<< endl;
*/

/*

    int arr[] = {3,2,5,6,2,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<< largestRect(arr, size)<<endl;
*/

/*

    SpecialStack st;

    st.push(40);
    st.push(13);
    st.push(76);
    st.push(34);
    st.push(10);

    cout<<"Current Min: "<<st.getMin()<<endl;

    st.pop();
    st.pop();

    cout<<"After pop Min is: "<<st.getMin()<<endl;

*/

/*

    int arr[4][4] = {
        {1,0,0,1},
        {1,1,0,1},
        {1,0,1,1},
        {1,0,0,1}
    };

    cout<<"Max Area is: "<<maxAreaOfRect(arr, 4, 4)<<endl;                
*/

/*
    wrapperClass obj;
    string expression = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = obj.infixToPostfix(expression);
    cout<<"Postfix Expression: "<< postfix<<endl;
*/

    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Total is: "<<countTotal(arr, size)<<endl;

    return 0;
}