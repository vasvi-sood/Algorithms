class MinStack
{
public:
    stack<int> stck;
    stack<int> minstck;
    MinStack()
    {
        minstck.push(INT32_MAX);
    }

    void push(int val)
    {
        stck.push(val);
        int minval = min(minstck.top(), val);
        minstck.push(minval);
    }

    void pop()
    {

        stck.pop();
        minstck.pop();
    }

    int top()
    {
        return stck.top();
    }

    int getMin()
    {

        return minstck.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */