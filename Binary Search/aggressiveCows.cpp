bool isPossible(vector<int> &stalls, int k, int mid) {

    int cowCount = 1;
    int lastPosition = stalls[0];

    for(int i = 0; i < stalls.size(); i++) {

        if(stalls[i] - lastPosition >= mid) {
            cowCount++ ;

            if(cowCount == k)
                return true;

            lastPosition = stalls[i];
        }

    }

    return false;

}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());

    int stallsCount = stalls.size();
    int ans;

    int mini = 0;
    int maxi = stalls[stallsCount-1] - stalls[0];

    int mid = mini + (maxi-mini)/2;

    while(mini <= maxi) {

        if(isPossible(stalls, k, mid)) {
            ans = mid;
            mini = mid + 1;
        }

        else {
            maxi = mid - 1;
        }

        mid = mini + (maxi-mini)/2;
    }

    return ans;

}