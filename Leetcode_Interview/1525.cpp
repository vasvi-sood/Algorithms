class Solution
{
public:
    int numSplits(string s)
    {
        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);
        int count = 0;
        int sum1 = 0, sum2 = 0;
        int index = s[0] - 'a';
        arr1[index] = 1;
        sum1 = 1;
        for (int i = 1; i < s.size(); i++)
        {
            index = s[i] - 'a';
            arr2[index]++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (arr2[i] != 0)
                sum2++;
        }

        for (int i = 1; i < s.size(); i++)
        {
            if (sum1 == sum2)
                count++;

            index = s[i] - 'a';
            arr1[index]++;
            if (arr1[index] == 1)
                sum1++;
            arr2[index]--;
            if (arr2[index] == 0)
                sum2--;
        }
        return count;
    }
};