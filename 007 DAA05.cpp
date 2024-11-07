#include<bits/stdc++.h>
using namespace std;

int comparisons = 0;
vector<int> deterministicQuickSort(vector<int> num){
    if(num.size()<=1) return num;
    int pivot = num[0];
    vector<int>leftP, rightP;
    for(int i=1;i<num.size();i++){
        comparisons ++;
        if(num[i]<pivot){
            leftP.push_back(num[i]);
        }
        else{
            rightP.push_back(num[i]);
        }
    }

    vector<int> sorted = deterministicQuickSort(leftP);
    sorted.push_back(pivot);
    vector<int>rightSorted = deterministicQuickSort(rightP);
    sorted.insert(sorted.end(), rightSorted.begin(), rightSorted.end());
    return sorted;

}

vector<int> randomizedQuickSort(vector<int>num){
    if(num.size()<=1){
        return num;
    }
    int pivotIdx = rand() %num.size();
    int pivot = num[pivotIdx];
    vector<int> leftP,rightP;
    for(int i=0;i<num.size();i++){
            comparisons++;
            if(i==pivotIdx){
                continue;
            }
        
            comparisons++;
            if (num[i] < pivot)
            {
                leftP.push_back(num[i]);
            }
            else
            {
                rightP.push_back(num[i]);
            }
        
    }

    vector<int> sorted = randomizedQuickSort(leftP);
    sorted.push_back(pivot);
    vector<int> rightSorted = randomizedQuickSort(rightP);
    sorted.insert(sorted.end(), rightSorted.begin(), rightSorted.end());
    return sorted;
}
int main(){

    cout<<"Enter number of elements present in the Array: ";
    int n;
    cin>>n;
    cout<<"Enter elemnents in the array: "<<endl;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>nums[i];
    }

    cout<<"Using deterministic Quick sort: "<<endl;
    cout<<"The sorted array is: "<<endl;
    vector<int> ans = deterministicQuickSort(nums);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<"The number of comparisons performed are: "<<comparisons<<endl;
    comparisons = 0;
    cout << "Using Randomized Quick sort: " << endl;
    cout << "The sorted array is: " << endl;
    ans = randomizedQuickSort(nums);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout << "The number of comparisons performed are: " << comparisons << endl;

    return 0;
}
