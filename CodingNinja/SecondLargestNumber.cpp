vector<int> getSecondOrderElements(int n, vector<int> a)
{
    int min = INT_MAX;
    int max = INT_MIN;
    int second_min = -1;
    int second_max = -1;

    for (int i = 0; i < n; i++)
    {
        if (max <= a[i])
        {
            second_max = max;
            max = a[i];
        }

        if (a[i] > second_max && a[i] < max)
            second_max = a[i];

        if (min >= a[i])
        {
            second_min = min;
            min = a[i];
        }

        if (a[i] < second_min && a[i] > min)
            second_min = a[i];
    }
    return {second_max, second_min};
}
