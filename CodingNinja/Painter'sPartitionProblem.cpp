// Time Complexity: O(log(n))
// Space Complexity: O(1)

int allocatePainter(const vector<int> &arr, int block)
{
    int painters = 1;
    long long subArraySum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (subArraySum + arr[i] <= block)
        {
            subArraySum += arr[i];
        }
        else
        {
            painters++;
            subArraySum = arr[i];
        }
    }
    return painters;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    if (k > n)
        return -1;
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (allocatePainter(boards, mid) > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}