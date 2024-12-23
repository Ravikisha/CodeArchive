class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    bool isPathCrossing(string path)
    {
        set<pair<int, int>> visited;
        int x = 0, y = 0;
        visited.insert({x, y});

        for (char direction : path)
        {
            if (direction == 'N')
                y++;
            else if (direction == 'S')
                y--;
            else if (direction == 'E')
                x++;
            else if (direction == 'W')
                x--;

            if (!visited.insert({x, y}).second)
            {
                // If the coordinate already exists in the set, path crosses
                return true;
            }
        }
        return false;
    }
};