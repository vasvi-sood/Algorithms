class Solution
{
public:
    int minPartitions(string n)
    {
        char a = '0';
        for (char num : n)
        {
            a = max(a, num);
        }

        return a - '0';
    }
};