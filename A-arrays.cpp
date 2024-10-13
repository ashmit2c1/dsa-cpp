#include<bits/stdc++.h>
using namespace std;


// LINEAR SEARCH 
bool linearSearch(vector<int>arr,int target){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==target){return true;}
    }
    return false;
}
// FIND THE LAST OCCURENCE OF AN ELEMENT 
int findLast(vector<int>arr,int target){
    int index=0;
    for(int i=arr.size()-1;i>=0;i++){
        if(arr[i]==target){
            index=i;break;
        }
    }
    return index;
}
// FIND THE TOTAL NUMBER OF PAIRS WHOSE SUM IS EQUAL TO X 
int findPairs(vector<int>arr,int target){
    int cnt=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum = arr[j]+arr[i];
            if(sum==target){cnt++;}
        }
    }
    return cnt;
}
// FIND THE ELEMENT THAT DOES NOT HAVE A DUPLICATE 
// given an array in which each element has a duplicate we need to
// find the element that does not have a duplicate 
int findElement(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]==arr[j]){
                arr[i]=-1;arr[j]=-1;
            }
        }
    }
    int element;
    for(int i = 0; i<arr.size() ; i++){
        if(arr[i]!=-1){element=arr[i];}
    }
    return element;
}
// using map
int findElementUsingMap(vector<int>arr){
    unordered_map<int,int>mp;int n=arr.size();
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    int element;
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second==1){element = it->first;}
    }
    return element;
}
// FIND THE SECOND LARGEST ELEMENT IN THE ARRAY 
int findSecondLargest(vector<int>arr){
    int maxElement=INT_MIN;
    int maxIndex=-1;
    int n=arr.size();
    for(int i = 0; i<n ; i++){
        if(arr[i]>maxElement){
            maxElement=arr[i];
            maxIndex=i;
        }
    }
    arr[maxIndex]=-1;
    int secondMax=INT_MIN;
    for(int i = 0; i<n ; i++){
        if(arr[i]>secondMax && arr[i]!=maxElement && i!=maxIndex){
            secondMax=arr[i];
        }
    }
    return secondMax;
}
// ROTATE AN ARRAY BY K STEPS 
void rotateByK(vector<int>&arr,int k){
    vector<int>arr2(arr.size());
    k=k%arr.size();int j=0;
    for(int i=arr.size()-k;i<arr.size();i++){
        arr2[j]=arr[i];j++;
    }
    for(int i=0;i<=k;i++){
        arr2[j]=arr[i];j++;
    }
    int w=0;
    for(int i=0;i<arr2.size();i++){
        arr[w]=arr2[i];k++;
    }
}
// SORT AN ARRAY WITH ZEROES AND ONES 
void sort01(vector<int>&arr){
    int zerocnt=0;
    int onecnt=0;
    for(int i = 0; i<arr.size() ; i++){
        if(arr[i]==0){zerocnt++;}
        if(arr[i]==1){onecnt++;}
    }
    int k=0;
    while(zerocnt--){
        arr[k]=0;k++;
    }
    while(onecnt--){
        arr[k]=1;k++;
    }
}
// SORT USING TWO POINTER APPROACH FOR THE ABOVE PROBLEM
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
// GIVEN AN ARRAY PLACE ALL THE EVEN INTEGERS IN FRONT OF THE ARRAY 
void placeEvenFirst(vector<int>&arr){
    int n=arr.size();
    int start=0;
    int end=n-1;
    while(start<=end){
        if(arr[start]%2==1 && arr[end]%2==0){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
        if(arr[start]%2==0){start++;}
        if(arr[end]%2==1){end--;}
    }
}
// GIVEN AN ARRAY RETURN THE SQUARES IN SORTED ORDER
vector<int>returnSquareSorted(vector<int>arr){
    int n=arr.size();
    int start=0;
    int end=n-1;
    vector<int>ans(n);
    int index=n-1;
    while(start<=end){
        if(abs(arr[start])<abs(arr[end])){
            arr[index]=arr[end]*arr[end];
            end--;index--;
        }
        else{
            arr[index]=arr[start]*arr[start];
            start++;index--;
        }
    }
    return ans;
}
// GIVEN AN ARRAY ,RETURN AN ARRAY WITH THE PREFIX SUM OF ALL EELEMNTS
void prefixSum(vector<int>&arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        arr[i]=arr[i]+arr[i-1];
    }
}
// GIVEN AN ARRAY CHECK IF WE CAN PARTITION THE ARRAY INTO TWO EQUAL HALVES
bool checkPartition(vector<int>arr){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int prefix=0;
    for(int i=0;i<n;i++){
        int suffix=sum-prefix;
        if(suffix==prefix){return true;}
        prefix+=arr[i];
    }
    return false;
}
// FIND THE MAX SUM OF THE SUBARRAY OF SIZE K 
int maxSubarraySum(vector<int>arr,int k){
    int sum=0;int n=arr.size();
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    int maxsum=sum;
    for(int i=k;i<n;i++){
        sum+=arr[i];
        sum-=arr[i-k];
        maxsum=max(maxsum,sum);
    }
    return maxsum;
}
// FIND THE INDEX OF SUBARRAY WITH THE GIVEN SUM 
vector<int>findIndex(vector<int>arr,int k){
    int n=arr.size();
    int start=0;
    int end=n-1;
    vector<int>ans;
    int currentSum=0;
    for(int i=0;i<n;i++){
        currentSum+=arr[i];
        if(currentSum>=k){
            end=i;
            while(currentSum>k && start<=end){
                currentSum-=arr[start];
                start++;
            }
            if(currentSum==k){
                ans.push_back(start+1);
                ans.push_back(end+1);
                break;
            }
        }
    }
    return ans;
}
// FIND THE MINIMUM NUMBER OF OPERATIONS TO CHANGE ALL THE ELEMENTS IN THE ARRAY 
int findOps(vector<int>arr){
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    int maxFreq=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        int freq=it->second;
        maxFreq = max(maxFreq,freq);
    }
    return arr.size()-maxFreq;
}
// REVERSE A GIVEN ARRAY 
void reverseArray(vector<int>arr){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
// FIND THE UNION OF TWO SORTED ARRAYS
vector<int>findUnion(vector<int>arr1,vector<int>arr2){
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
        if(arr1[i]>arr2[j]){
            if(ans.size()==0||ans.back()!=arr2[j]){
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
vector<int>findIntersection(vector<int>arr1,vector<int>arr2){
    vector<int>ans;
    int i=0;int j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){i++;}
        else if(arr1[i]>arr2[j]){j++;}
        else{
            if(ans.size()==0 || ans.back()!=arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;j++;
        }
    }
    return ans;
}
// FIND AN ELEMENT IN SORTED ARRAY IN 0(LOG N) TIME 
int binarySearch(vector<int>arr, int target){
    int n=arr.size();
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==target){return mid;}
        if(target>arr[mid]){start=mid+1;}
        if(target<arr[mid]){end=mid-1;}
    }
    return -1;
}
// FIND THE MISSING ELEMENT IN SORTED ARRAY 
int findElement(vector<int>arr){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int tot=0;
    for(int i=1;i<=n;i++){
        tot+=i;
    }
    return tot-sum; 
}
// FIND THE MAX ONES BY HAVING M ZEROES 
int findMaxOnes(vector<int>arr,int m){
    int j=0;int n=arr.size();int zero=0;int maxlen=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]==0){zero++;}
        if(zero>m){
            if(arr[j]==0){zero--;}
            j++;
        }
        maxlen=max(maxlen,i-j+1);
    }
    return maxlen;
}
// FIND THE LONGEST SUBARRAY WITH THE SUM K 
int lenOfLongestSubarray(vector<int>arr,int k){
    int n=arr.size();
    int left=0;
    int right=0;
    int sum=0;
    int maxlen=INT_MIN;
    while(right<arr.size()){
        sum+=arr[right];
        while(left<=right && sum>=k){
            if(sum==k){
                maxlen=max(maxlen,right-left+1);
                right++;
            }
            sum-=arr[left];
            left++;
        }
        right++;

    }
}
// SEARCH FOR AN ELEMENT IN 2D MATRIX
bool findElement(vector<vector<int>>&matrix,int element){
    int r=matrix.size();
    int c=matrix[0].size();
    for(int i=0;i<r;i++){
        int start=0;
        int end=c-1;
        while(start<=end){
            int mid=start +(end-start)/2;
            if(matrix[i][mid]==element){return true;}
            if(element > matrix[i][mid]){start=mid+1;}
            if(element < matrix[i][mid]){end=mid-1;}
        }
    }
    return false;
}
// FIND THE MAX PROFIT FROM STOCK BUY AND SELL 
int stockBuySell(vector<int>arr){
    int n=arr.size();
    int maxProfit=0;
    for(int i=1;i<arr.size()-1;i++){
        if(arr[i]>arr[i-1]){
            int diff=abs(arr[i]-arr[i-1]);
            maxProfit+=diff;
        }
    }
    return maxProfit;
}
// TWO SUM WITH TWO ARRAYS
vector<pair<int,int>>findPairs2(vector<int>arr,vector<int>arr2,int sum){
    int n=arr.size();
    vector<pair<int,int>>ans;
    unordered_set<int>st;
    for(int i=0;i<arr.size();i++){
        st.insert(arr[i]);
    }
    for(int i=0;i<arr2.size();i++){
        if(st.find(sum-arr2[i])!=st.end()){
            ans.push_back(make_pair(sum-arr2[i],arr2[i]));
        }
    }
    return ans;
}
// TWO SUM LEET CODE FIRST QUESTION
vector<int>findPairs1(vector<int>arr,int sum){
    int n =arr.size();
    unordered_map<int,int>mp;
    vector<int>ans;
    for(int i=0;i<n;i++){
        int complement=sum-arr[i];
        if(mp.find(complement)!=mp.end()){
            ans.push_back(mp[complement]);
            ans.push_back(i);
        }
        mp[arr[i]]=i;
    }
    return ans;
}
// FIND THE MAJORITY ELEMENT IN A GIVEN ARRAY 
int findMajority(vector<int>&arr){
    int n=arr.size();
    unordered_map<int,int>mp;
    for(int i = 0; i<n ; i++){
        mp[arr[i]]++;
    }
    int majority=0;
    int maxFreq=INT_MIN;
    for(auto it=mp.begin();it!=mp.end();it++){
        int freq=it->second;
        if(freq>maxFreq){
            maxFreq=freq;
            majority=it->first;
        }
    }
    if(maxFreq>n/2){
        return majority;
    }
    else{
        return -1;
    }
}
// FIND THE MAJORITY ELEMENT USING MOORE VOTING CONCEPT 
int majorityElementMooreVoting(vector<int>&arr){
    int cnt=0;int element;int n=arr.size();
    for(int i = 0; i<n ; i++){
        if(cnt==0){element=arr[i];cnt=1;}
        else{
            if(arr[i]==element){cnt++;}
            else{cnt--;}
        }
    }
    int cnt2=0;
    for(int i = 0; i<n ; i++){
        if(arr[i]==element){cnt2++;}
    }
    if(cnt2>n/2){return element;}else{return -1;}
}
// RE-ARRANGE THE POSITIVE AND NEGATIVE ELEMENTS IN THE ARRAY 
vector<int>reArrange(vector<int>&arr){
    vector<int>positive;
    vector<int>negative;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>=0){positive.push_back(arr[i]);}
        else{negative.push_back(arr[i]);}
    }
    int index=0;
    int positiveIndex=0;
    int negativeIndex=0;
    while(positiveIndex<positive.size() && negativeIndex<negative.size()){
        if(index%2==0){
            arr[index]=positive[positiveIndex];
            positiveIndex++;index++;
        }
        else{
            arr[index]=negative[negativeIndex];
            negativeIndex++;index++;
        }
    }
    while(positiveIndex<positive.size()){
        arr[index]=positive[positiveIndex];
        positiveIndex++;index++;
    }
    while(negativeIndex<negative.size()){
        arr[index]=negative[negativeIndex];
        negativeIndex++;index++;
    }
    return arr;
}
// MERGE TWO SORTED ARRAYS WITHOUT USING EXTRA SPACE 
// using two pointer approach, this approach is similar to union of two arrays
vector<int> mergeTwoArrays(vector<int>arr1,vector<int>arr2){
    vector<int>arr3(arr1.size()+arr2.size());
    int left=0;
    int right=0;
    int index=0;
    while(left<arr1.size() && right<arr2.size()){
        if(arr1[left]<=arr1[right]){
            arr3[index]=arr1[left];
            index++;
            left++;
        }
        else{
            arr3[index]=arr2[right];
            right++;
            index++;
        }
    }
    while(left<arr1.size()){
        arr3[index]=arr1[left];
        index++;left++;
    }
    while(right<arr2.size()){
        arr3[index]=arr2[right];
        right++;index++;
    }
    return arr3;
}
// optimised approach 
void merge(vector<int>arr1,vector<int>arr2){
    int n=arr1.size();
    int left=n-1;
    int right=0;
    while(left>=0 && right<arr2.size()){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;right++;
        }
        else{break;}
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    for(int i=0;i<arr1.size();i++){
        cout << arr1[i] << " ";
    }
    for(int i=0;i<arr2.size();i++){
        cout << arr2[i] << " ";
    }
}
// REMOVE DUPLICATES FROM A SORTED ARRAY 
void removeDuplicates(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return; 
    int index = 1; 
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[index] = arr[i]; 
            index++;
        }
    }
    arr.resize(index);
}
// MINIMUM JUMPS TO REACH THE END OF THE ARRAY 
int minJumps(int arr[], int n) {
    int jump = 0;
    int pos = 0;
    int des = 0;
    for(int i = 0; i < n-1; i++) {
        des = max(des, arr[i] + i);
        if(pos == i) {
            if(des == pos)
                return -1;
            pos = des;
            jump++;
        }
    }
    return jump;
}

// MERGE INTERVALS 
vector<vector<int>> merge(vector<vector<int>> intervals){
    vector<vector<int>> ans;
    if(intervals.size()==0){
        return ans;
    }
    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];
    for(auto it: intervals){
        if(it[0]<=tempInterval[1]){
            tempInterval[1]=max(it[1], tempInterval[1]);
        }
        else{
            ans.push_back(tempInterval);
            tempInterval=it;
        }
    }
    ans.push_back(tempInterval);
    return ans;
}

// MAX PRODUCT SUBARRAY IN ARRAY ( BRUTE FORCE APPROACH )
int maxProduct(vector<int>arr){
    int n=arr.size();
    int maxProduct=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int product=1;
            for(int k=i;k<=j;k++){
                product*=arr[k];
                maxProduct=max(maxProduct,product);
            }
        }
    }
    return maxProduct;
}
 // MAX PRODUCT SUBARRAY IN ARRAY ( OPTIMISED APPROACH )
int maxProduct(vector<int>arr){
    int n=arr.size();
    int maxProduct=INT_MIN;
    int leftProduct=1;
    int rightProduct=1;
    for(int i=0;i<n;i++){
        if(leftProduct==0){leftProduct=1;}
        if(rightProduct==0){rightProduct=1;}
        leftProduct*=arr[i];
        rightProduct*=arr[n-1-i];
        maxProduct = max(maxProduct,max(leftProduct,rightProduct));
    }
    return maxProduct;
}
// MAX SUBARRAY KADANE ALGORITHMS 
int maxSubArraySum(vector<int>arr){
    int maxHere=0;
    int maxSoFar=INT_MIN;
    int n=arr.size();
    for(int i=0;i<n;i++){
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
