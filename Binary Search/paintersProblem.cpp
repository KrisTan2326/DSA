bool isPossible(vector<int> &boards, int k, int mid) {

    int painters = 1, sum = 0;

    for(int i = 0; i < boards.size(); i++) {

        if(boards[i] + sum <= mid)
            sum += boards[i];

        else {
            painters++ ;
            if(painters > k || boards[i] > mid)
                return false;
            
            else {
                sum = boards[i];
            }
        }

    }

    return true;

}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int ans;
    int sum = 0;

    for (int i = 0; i < boards.size(); i++) {
      sum += boards[i];
    }

    int start = 0, end = sum;
    int mid = start + (end-start)/2;

    while(start <= end) {

        if(isPossible(boards, k, mid)) {
            ans = mid;
            end = mid - 1;
        }

        else {
            start = mid + 1;
        }

        mid = start + (end-start)/2;
    }

    return ans;
}