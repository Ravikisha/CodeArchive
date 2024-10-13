class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();

        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++)
        {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end());

        double maxTime = 0.0;
        int result = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            double time = cars[i].second;
            if (time > maxTime)
            {
                maxTime = time;
                result++;
            }
        }

        return result;
    }
};


// Using Stack
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        
        // Calculate the time each car will take to reach the target
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        
        // Sort the cars based on their position (farthest first)
        sort(cars.begin(), cars.end());

        stack<double> fleetTimes; // Stack to store the fleet times
        
        // Process cars from the farthest to the closest
        for (int i = n - 1; i >= 0; i--) {
            double time = cars[i].second;
            
            // If the current car's time is greater than the top of the stack, it forms a new fleet
            if (fleetTimes.empty() || time > fleetTimes.top()) {
                fleetTimes.push(time);
            }
        }
        
        // The size of the stack is the number of car fleets
        return fleetTimes.size();
    }
};
