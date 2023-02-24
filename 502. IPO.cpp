class Solution
{
    public:
        int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &cap)
        {

            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> minHeap;
            priority_queue<pair<int, int>, vector< pair<int, int>>> maxHeap;
            for (int i = 0; i < profits.size(); i++)
                minHeap.push({ cap[i],profits[i] });
            

            while (k>0)
            {

                while (!minHeap.empty() && w >= minHeap.top().first)
                {

                    maxHeap.push({ minHeap.top().second,minHeap.top().first });
                    minHeap.pop();
                }
                if (k > 0 && !maxHeap.empty())
                {

                    w += maxHeap.top().first;
                    maxHeap.pop();
                    k--;
                }else break;
            }
            return w;
        }
};
