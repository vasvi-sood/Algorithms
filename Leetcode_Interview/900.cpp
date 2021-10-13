class RLEIterator
{
public:
    int num = 0;
    vector<int> arr;
    RLEIterator(vector<int> &encoding)
    {
        arr = encoding;
    }

    int next(int n)
    {

        while (num < arr.size() && arr[num] < n)
        { //cout<<"here2 "<<" ";
            n -= arr[num];
            arr[num] = 0;
            num += 2;
        }
        if (num >= arr.size())
            return -1;

        if (arr[num] >= n)
        {
            // cout<<"here3 "<<" ";
            arr[num] = arr[num] - n;
            return arr[num + 1];
        }
        // cout<<"here4 "<<" ";
        arr[num] = 0;
        num += 2;
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */