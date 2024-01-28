// TC - O(nlogn)
// SC - O(n)
class MedianFinder
{
private:
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    int maxi;
    int mini;

public:
    MedianFinder()
    {
        maxi = 0;
        mini = 0;
    }

    void addNum(int num)
    {
        maxH.push(num);
        maxi++;

        minH.push(maxH.top());
        mini++;
        maxH.pop();
        maxi--;

        if (mini > maxi)
        {
            maxH.push(minH.top());
            maxi++;
            minH.pop();
            mini--;
        }
    }

    double findMedian()
    {
        if (maxi == mini)
        {
            return (maxH.top() + minH.top()) / 2.0;
        }
        else
        {
            return maxH.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */