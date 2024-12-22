#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Include this header for std::accumulate

using namespace std;

// Helper function for backtracking
bool canAssign(vector<int> &jobs, vector<int> &workers, int idx, int limit)
{
    if (idx == jobs.size())
        return true;

    int job = jobs[idx];
    for (int i = 0; i < workers.size(); ++i)
    {
        if (workers[i] + job <= limit)
        {
            workers[i] += job;

            if (canAssign(jobs, workers, idx + 1, limit))
                return true;

            workers[i] -= job;
        }

        // Prune branches where current worker is not used
        if (workers[i] == 0)
            break;
    }

    return false;
}

int minimumWorkingTime(vector<int> &jobs, int k)
{
    // Sort jobs in descending order (heuristic for pruning)
    sort(jobs.rbegin(), jobs.rend());

    int left = *max_element(jobs.begin(), jobs.end());   // Minimum possible max time
    int right = accumulate(jobs.begin(), jobs.end(), 0); // Maximum possible max time

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        vector<int> workers(k, 0);

        if (canAssign(jobs, workers, 0, mid))
        {
            right = mid; // Try for a smaller maximum
        }
        else
        {
            left = mid + 1; // Increase the maximum limit
        }
    }

    return left;
}

int main()
{
    vector<int> jobs = {3, 2, 3};
    int k = 3;

    cout << "Minimum possible maximum working time: " << minimumWorkingTime(jobs, k) << endl;
    return 0;
}
