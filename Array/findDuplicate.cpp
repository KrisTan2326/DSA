int findDuplicate(vector<int> &arr) 
{
    // Write your code here
	int size = arr.size();
    int ans  = 0;

    for(int i = 1; i <= size - 1; i++) {
      ans = ans^i;
    }

    for(int i = 0; i < size; i++) {
        ans = ans^arr[i];
    }

    return ans;
}