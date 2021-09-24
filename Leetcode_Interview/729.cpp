class MyCalendar
{
public:
    map<int, int> mp;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (auto pr : mp)
        {
            int num1 = pr.first;
            int num2 = pr.second;
            if (num1 <= start && num2 > start)
                return false;
            else if (num1 > start)
            {
                if (end <= num1)
                {
                    mp[start] = end;
                    return true;
                }
                else
                    return false;
            }
        }
        mp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */