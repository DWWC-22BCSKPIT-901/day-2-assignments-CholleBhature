#include <iostream>
#include <vector>
#include <string>
#include <numeric> // For std::accumulate
using namespace std;

int calPoints(vector<string> &ops)
{
    vector<int> record;
    for (const string &op : ops)
    {
        if (op == "+")
        {
            record.push_back(record.back() + record[record.size() - 2]);
        }
        else if (op == "D")
        {
            record.push_back(2 * record.back());
        }
        else if (op == "C")
        {
            record.pop_back();
        }
        else
        {
            record.push_back(stoi(op));
        }
    }
    return accumulate(record.begin(), record.end(), 0);
}

int main()
{
    vector<string> ops = {"5", "2", "C", "D", "+"};
    cout << calPoints(ops) << endl; // Output: 30
    return 0;
}
