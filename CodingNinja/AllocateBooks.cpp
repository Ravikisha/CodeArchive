// Time Complexity: O(log(n))
// Space Complexity: O(1)

int allocateStudent(const vector<int> &arr, int pages)
{
    int students = 1;
    long long pageStudent = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (pageStudent + arr[i] <= pages)
        {
            pageStudent += arr[i];
        }
        else
        {
            students++;
            pageStudent = arr[i];
        }
    }
    return students;
}
int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (allocateStudent(arr, mid) > m)
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