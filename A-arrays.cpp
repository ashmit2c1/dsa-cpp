#include<bits/stdc++.h>
using namespace std;


// LINEAR SEARCH 
bool linearSearch(vector<int>&arr,int target){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==target){return true;}
    }
    return false;
}
// FIND THE LAST OCCURENCE OF ELEMENT 
int findLast(vector<int>&arr,int target){
    int index=-1;
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]==target){
            index=i;break;
        }
    }
    return index;
}
// FIND THE TOTAL NUMBER OF PAIRS WHOSE SUM IS X IN ARRAY 
int countPairs(vector<int>&arr,int target){
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            int sum=arr[i]+arr[j];
            if(sum==target){cnt++;}
        }
    }
    return cnt;
}
// FIND THE ELEMENT IN ARRAY  THAT DOES NOT HAVE DUPLICATE 
int findElement(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]==arr[j]){
                arr[i]=-1;arr[j]=-1;
            }
        }
    }
    int element=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=-1){element=arr[i];}
    }
    return element;
}
// FIND THE ELEMENT IN ARRAY THAT DOES HAVE DUPLICATE USING MAP 
int findElement(vector<int>&arr){
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    int element=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        int freq=it->second;
        if(freq==1){element=it->first;}
    }
    return element;
}
// FIND THE SECOND LARGEST ELEMENT IN ARRAY 
int secondLargest(vector<int>&arr){
    int maxElement=INT_MIN;
    int maxIndex=-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>maxElement){
            maxElement=arr[i];maxIndex=i;
        }
    }
    arr[maxIndex]=-1;
    int secMax=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>secMax && arr[i]!=maxElement && i!=maxIndex){
            secMax=arr[i];
        }
    }
    return secMax;
}
// ROTATE ARRAY BY K STEPS
void rotateK(vector<int>&arr,int k){
    int n=arr.size();
    k=k%n;
    int index=0;
    vector<int>newArr(n);
    for(int i=n-k;i<n;i++){
        newArr[index]=arr[i];
        index++;
    }
    for(int i=0;i<n-k;i++){
        newArr[index]=arr[i];
        index++;
    }
    int index2=0;
    for(int i=0;i<newArr.size();i++){
        arr[index2]=newArr[i];
        index2++;
    }
}
// SORT AN ARRAY CONSISTING 1 AND 0 WITHOUT SORTING 
void sort01(vector<int>&arr){
    int oneCnt=0;
    int zeroCnt=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){zeroCnt++;}
        if(arr[i]==1){oneCnt++;}
    }
    int index=0;
    while(zeroCnt--){
        arr[index]=0;
    }
    while(oneCnt--){
        arr[index]=1;
    }
}
// TWO POINTER APPROACH TO SOLVE THE ABOVE QUESTIONS 
void sort01(vector<int>&arr){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        if(arr[start]==1 && arr[end]==0){
            swap(arr[start],arr[end]);
            start++;end--;
        }
        if(arr[start]==0){start++;}
        if(arr[end]==1){end--;}
    }
}
// GIVEN AN ARRAY PLACE ALL THE EVEN INTEGERS IN FRONT THE ARRAY 
void sortEvenOdd(vector<int>&arr){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        if(arr[start]%2==1 && arr[end]%2==0){
            swap(arr[start],arr[end]);
            start++;end--;
        }
        if(arr[start]%2==0){start++;}
        if(arr[end]%2==1){end--;}
    }
}
// GIVEN AN ARRAY RETURN THE SORTED SQUARE 
vector<int>sortedSquared(vector<int>&arr){
    int start=0;
    int end=arr.size()-1;
    int index=arr.size()-1;
    vector<int>ans(arr.size());
    while(start<=end){
        if(abs(arr[start])<abs(arr[end])){
            ans[index]=arr[start]*arr[start];
            start++;index--;
        }
        else{
            ans[index]=arr[end]*arr[end];
            end--;index--;
        }
    }
    return ans;
}
// GIVEN AN ARRAY, RETURN THE PREFIX SUM ARAY 
void prefixSum(vector<int>&arr){
    for(int i=1;i<arr.size();i++){
        arr[i]=arr[i]+arr[i-1];
    }
}
// GIVEN AN ARRAY CHECK IF WE CAN PARTITION THE ARRAY INTO TWO HALVES
bool checkForPartition(vector<int>&arr){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    int prefix=0;
    for(int i=0;i<arr.size();i++){
        int suffix=sum-prefix;
        if(suffix==prefix){return true;}
        prefix+=arr[i];
    }
    return false;
}
// FIND THE MAX SUM OF THE SUBARRAY OF SIZE K 
int maxSubArraySum(vector<int>&arr,int k){
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    int maxSum=sum;
    for(int i=k;i<arr.size();i++){
        sum+=arr[i];
        sum-=arr[i-k];
        maxSum=max(maxSum,sum);
    }
    return maxSum;
}

// FIND THE INDEX OF THE SUB ARRAY WITH THE SUM K 
vector<int>findIndex(vector<int>&arr,int k){
    int start=0;
    int end=arr.size()-1;
    int currentSum=0;
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        currentSum+=arr[i];
        if(currentSum>=k){
            end=i;
            while(currentSum>k && start <=end){
                currentSum-=arr[start];
                start++;
            }
            if(currentSum==k){
                ans.push_back(start+1);
                ans.push_back(end+1);
            }
        }
    }
    return ans;
}
// FIND THE MINIMUM NUMBER OF OPERATIONS NEEDED TO CHANGE ALL THE ELEMENT SIN THE ARRAY 
int findOps(vector<int>&arr){
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    int maxFreq=INT_MIN;
    for(auto it=mp.begin();it!=mp.end();it++){
        int freq=it->second;
        maxFreq=max(maxFreq,freq);
    }
    return arr.size()-maxFreq;
}
// REVERSE A GIVEN ARRAY 
void reverseArray(vector<int>&arr){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
// FIND THE UNION OF TWO SORTED ARRAYS
vector<int>findUnion(vector<int>&arr1,vector<int>&arr2){
    int i=0;
    int j=0;
    vector<int>ans;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<=arr2[j]){
            if(ans.size()==0 || ans.back()!=arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(ans.size()==0 || ans.back()!=arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<arr1.size()){
        if(ans.size()==0 || ans.back()!=arr1[i]){
            ans.push_back(arr1[i]);
        }
        i++;
    }
    while(j<arr2.size()){
        if(ans.size()==0 || ans.back()!=arr2[j]){
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}
// FIND THE INTERSECTION OF TWO SORTED ARRAYS
vector<int>findIntersection(vector<int>&arr1,vector<int>&arr2){
    vector<int>ans;
    int i=0;int j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){i++;}
        else if(arr2[i]>arr2[j]){j++;}
        else{
            if(ans.size()==0 || ans.back()!=arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;j++;
        }
    }
    return ans;
}
// FIND AN ELEMENT IN SORTED ARRAY IN LOGN TIME 
int findElement(vector<int>&arr,int target){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(target==arr[mid]){return mid;}
        if(target> arr[mid]){start=mid+1;}
        if(target< arr[mid]){end=mid-1;}
    }
    return -1;
}
// FIND THE MISSING ELEMENT IN ARRAY 
int findMissing(vector<int>&arr){
    int sum=0;
    for(int i=1;i<=arr.size();i++){
        sum+=i;
    }
    int sum2=0;
    for(int i=0;i<arr.size();i++){
        sum2+=arr[i];
    }
    return (sum-sum2);
}
// FIND THE MAX ONES WE CAN GET BY FLIPPING AT MOST M EROES
int findOnes(vector<int>&arr,int m){
    int zero=0;
    int index=0;
    int maxOnes=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){zero++;}
        if(zero>m){
            if(arr[index]==0){zero--;}
            index++;
        }
        maxOnes=max(maxOnes,i-index+1);
    }
    return maxOnes;
}
// FIND THE LONGEST SUBARRAY WITH THE SIZE K 
int longestSubArray(vector<int>&arr,int k){
    int n=arr.size();
    int left=0;
    int right=0;
    int sum=0;
    int maxLen=INT_MIN;
    while(right<arr.size()){
        sum+=arr[right];
        while(left<=right && sum>=k){
            if(sum==k){
                maxLen=max(maxLen,right-left+1);
            }
            sum-=arr[left];
            left++;
        }
        right++;
    }
}
// SEARCH FOR AN ELEMENT IN 2D MATRIX
bool findElement2(vector<vector<int>>&matrix,int element){
    int r=matrix.size();
    int c=matrix[0].size();
    for(int i=0;i<r;i++){
        int start=0;
        int end=c-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(element=matrix[i][mid]){return true;}
            if(element > matrix[i][mid]){start = mid+1;}
            else{end=mid-1;}
        }
    }
    return false;
}
// FIND THE MAX PROFIT FROM SELLING STOCKS 
int stockBuySell(vector<int>&arr){
    int n=arr.size();
    int maxProfit=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>arr[i-1]){
            int diff=arr[i]-arr[i-1];
            maxProfit+=diff;
        }
    }
    return maxProfit;
}
// GIVEN TWO ARRAYS RETURN THE PAIR OF ELEMENTS THAT FORM A SUM 
vector<pair<int,int>>twoSum2(vector<int>&arr1,vector<int>&arr2,int sum){
    vector<pair<int,int>>ans;
    unordered_set<int>st;
    for(int i=0;i<arr1.size();i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<arr2.size();i++){
        if(st.find(sum-arr2[i])!=st.end()){
            ans.push_back(make_pair(sum-arr2[i],arr2[i]));
        }
    }
    return ans;
}
// TWO SUM LEETCODE
vector<int>findPairs(vector<int>&arr,int sum){
    unordered_map<int,int>mp;
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        int complement = sum=-arr[i];
        if(mp.find(complement)!=mp.end()){
            ans.push_back(mp[complement]);
            ans.push_back(i);
        }
        mp[arr[i]]=i;
    }
    return ans;
}
// FIND THE MAJORITY ELEMENT IN ARRAY 
int findMajorityMapApproach(vector<int>&arr){
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    int element=0;
    int maxFreq=INT_MIN;
    for(auto it=mp.begin();it!=mp.end();it++){
        int freq=it->second;
        if(freq>maxFreq){
            maxFreq=freq;
            element = it->first;
        }
    }
    if(maxFreq>arr.size()/2){
        return element;
    }
    else{
        return -1;
    }
}
// FIND THE MAJORITY ELEMENT USING MOORE VOTING 
int mooreVoting(vector<int>&arr){
    int cnt=0;
    int element=0;
    for(int i=0;i<arr.size();i++){
        if(cnt==0){
            element=arr[i];
            cnt=1;
        }
        else{
            if(element==arr[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
    }
    int cnt2=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==element){
            cnt2++;
        }
    }
    if(cnt2 > arr.size()/2){
        return element;
    }
    else{
        return -1;
    }
}
// MERGE TWO SORTED ARRAY USING EXTRA SPACE
vector<int>mergeTwoArrays(vector<int>&arr1,vector<int>&arr2){
    vector<int>ans;
    int left=0;
    int right=0;
    int index=0;
    vector<int>ans(arr1.size()+arr2.size());
    while(left<arr1.size() && right < arr2.size()){
        if(arr1[left]<=arr2[right]){
            ans[index]=arr1[left];
            left++;index++;
        }
        else{
            ans[index]=arr2[right];
            index++;right++;
        }
    }
    while(left<arr1.size()){
        ans[index]=arr1[left];
        index++;
        left++;
    }
    while(right<arr2.size()){
        ans[index]=arr2[right];
        index++;right++;
    }
}
// MERGE TWO SORTED ARRAYS WIHOUT SUING SPACE 
void mergeWithoutSpace(vector<int>&arr1,vector<int>&arr2){
    int n=arr1.size();
    int left=n-1;
    int right=0;
    while(left>=0 && right<arr2.size()){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            right++;
            left--;
        }
        else{
            break;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}
// REMOVE DUPLICATES FROM SORTED ARRAY
void removeDuplicates(vector<int>&arr){
    int n=arr.size();
    int index=1;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            arr[index]=arr[i];
        }
    }
    arr.resize(index);
}
// MINIMUM JUMPS TO REACH THE END OF THE ARRAY 
int minJumps(vector<int>&arr,int n){
    int jumps=0;
    int pos=0;
    int des=0;
    for(int i=0;i<n-1;i++){
        des=max(des,arr[i]+i);
        if(pos==i){
            if(des==pos){
                return -1;
            }
            pos=des;
            jumps++;
        }
    }
    return jumps++;
}
// MERGE INTERVALS IN ARRAY 
vector<vector<int>>mergeIntervals(vector<vector<int>>intervals){
    vector<vector<int>>ans;
    if(intervals.size()==0){
        return ans;
    }
    sort(intervals.begin(),intervals.end());
    vector<int>tempInterval=intervals[0];
    for(auto it:intervals){
        if(it[0] <= tempInterval[1]){
            tempInterval[1]=max(it[1],tempInterval[1]);
        }
        else{
            ans.push_back(tempInterval);
            tempInterval=it;
        }
    }
    ans.push_back(tempInterval);
    return ans;
}
// MAX PRODUCT SUB ARRAY 
int maxProduct(vector<int>&arr){
    int maxProduct=INT_MIN;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            int product=1;
            for(int k=i;k<=j;k++){
                product*=arr[k];
                maxProduct=max(maxProduct,product);
            }
        }
    }
    return maxProduct;
}
// MAX PRODUCT IN ARRAY OPTIMISED APPROACH 
int maxProduct(vector<int>&arr){
    int maxProduct=INT_MIN;
    int leftProduct=1;
    int rightProduct=1;
    for(int i=0;i<arr.size();i++){
        if(leftProduct==0){leftProduct=1;}
        if(rightProduct==0){rightProduct=1;}
        leftProduct*=arr[i];
        rightProduct*=arr[arr.size()-i-1];
        maxProduct=max(maxProduct,max(leftProduct,rightProduct));
    }
    return maxProduct;
}
// KADANES ALGORITHMS 
int maxSubArraySum(vector<int>&arr){
    int maxHere=0;
    int maxSoFar=INT_MIN;
    for(int i=0;i<arr.size();i++){
        maxHere+=arr[i];
        if(maxHere<arr[i]){
            maxHere=arr[i];
        }
        if(maxSoFar<maxHere){
            maxSoFar=maxHere;
        }
    }
    return maxSoFar;
}
