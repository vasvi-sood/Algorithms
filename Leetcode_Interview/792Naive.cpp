class Solution
{
public:
    bool isSubsequence(string s, string word)
    {
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (j >= word.size())
                return true;

            if (s[i] == word[j])
                j++;
        }
        if (j >= word.size())
            return true;
        return false;
    }

    int numMatchingSubseq(string s, vector<string> &words)
    {
        int count = 0;
        for (string word : words)
            if (isSubsequence(s, word))
                count++;

        return count;
    }
};