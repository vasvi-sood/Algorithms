class Solution
{
    struct TrieNode
    {
        bool endofWord = false;
        TrieNode *links[26];
        bool containsKey(char c, TrieNode *node)
        {
            if (node->links[c - 'a'] == NULL)
                return false;
            return true;
        }
        void insertNode(char c, TrieNode *node)
        {
            node->links[c - 'a'] = new TrieNode();
        }
        TrieNode *getNode(char c, TrieNode *node)
        {
            return node->links[c - 'a'];
        }
    };

    TrieNode *root;
    void insert(string word)
    {
        auto node = root;
        for (char c : word)
        {
            if (!node->containsKey(c, node))
            {
                node->insertNode(c, node);
            }
            node = node->getNode(c, node);
        }

        node->endofWord = true;
    }
    void constructWords(TrieNode *node, vector<string> &ans, string str)
    {

        if (node->endofWord == true)
        {

            ans.push_back(str);
            // cout<<str<<" "<<ans.size()<<endl;
        }

        for (int i = 0; i < 26; i++)
        {

            char c = i + 'a';
            if (node->containsKey(c, node))
            {
                if (ans.size() < 3)
                {
                    auto newNode = node->getNode(c, node);
                    auto newstr = str + c;

                    constructWords(newNode, ans, newstr);
                }
            }
        }
    }
    void getwords(string prefix, vector<string> &ans)
    {
        auto node = root;
        for (char c : prefix)
        {
            if (!node->containsKey(c, node))
            {
                return;
            }
            node = node->getNode(c, node);
        }
        // node is the checkpoint
        constructWords(node, ans, prefix);
    }

public:
    vector<vector<string>> suggestedProducts(vector<string> &words, string search)
    {
        root = new TrieNode();
        for (string word : words)
            insert(word);

        vector<vector<string>> ans;
        string str = "";
        for (auto c : search)
        {
            str += c;
            vector<string> a;
            getwords(str, a);
            ans.push_back(a);
        }

        return ans;
    }
};