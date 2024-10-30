class Solution
{
    // Time Complexity: O(log n)
    // Space Complexity: O(log n)
public:
    vector<int> pathInZigZagTree(int label)
    {
        int level = int(log2(label)); // Calculate the level of the input node,
                                      // with indexing starting at 0
        vector<int> path;
        int node;
        int index;             // Represents the node's index within its level (starting
                               // from 0, left to right)
        path.push_back(label); // Start the path with the input label

        node = label;
        while (node != 1)
        {
            if (level % 2 == 0)
            {
                // For even levels (left-to-right labeling):
                index = node - pow(2, level); // Calculate the index of 'node'
                                              // within the level
                index /= 2;                   // Determine the parent's index in the previous
                                              // level (half the current index)

                // Calculate the parent's label:
                // (pow(2, level) - 1) - index reverses the index to
                // right-to-left for odd level above
                node = (pow(2, level) - 1) - index;
            }
            else
            {
                // For odd levels (right-to-left labeling):
                index =
                    (pow(2, level) - 1) -
                    (node - pow(2, level)); // Reverse index to left-to-right
                index /=
                    2;                            // Calculate parent's index in left-to-right ordering
                node = pow(2, level - 1) + index; // Determine parent's label by
                                                  // offsetting from level start
            }
            path.insert(path.begin(),
                        node); // Add current node to the front of the path
            level--;           // Move to the previous level
        }

        return path;
    }
};