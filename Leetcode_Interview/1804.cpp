class Trie
{
    struct TrieNode
    {
        bool terminate = false;
        int count = 0;
        int wordcount = 0;
        TrieNode *links[26];

        bool containsKey(char c, TrieNode *node)
        {
            if (node->links[c - 'a'] == NULL)
                return false;
            return true;
        }
        void insertKey(char c, TrieNode *node)
        {
            node->links[c - 'a'] = new TrieNode();
        }

        TrieNode *getNode(char c, TrieNode *node)
        {
            return node->links[c - 'a'];
        }
        bool isEnd(TrieNode *node)
        {
            return node->terminate;
        }
    };
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        auto node = root;
        for (char c : word)
        {
            if (!node->containsKey(c, node))
            {
                node->insertKey(c, node);
            }
            node = node->getNode(c, node);
            node->count++;
            //            cout<<node->count<<" ";
        }
        //         node->count++;
        //           cout<<node->count<<" ";
        node->wordcount++;
        node->terminate = true;
    }

    int countWordsEqualTo(string &word)
    {
        auto node = root;
        for (char c : word)
        {
            if (!node->containsKey(c, node))
            {
                return 0;
            }

            node = node->getNode(c, node);
        }
        if (!node->isEnd(node))
            return 0;
        return node->wordcount;
    }

    int countWordsStartingWith(string &word)
    {
        auto node = root;
        for (char c : word)
        {
            if (!node->containsKey(c, node))
            {
                return 0;
            }

            node = node->getNode(c, node);
        }
        return node->count;
    }

    void erase(int i, string word, TrieNode *node)
    {
        if (i >= word.size())
        {
            node-> //         cout<<c<<" ";wordcount--;
                return;
        }
        char c = word[i];
        auto nextNode = node->getNode(c, node);
        erase(i + 1, word, nextNode);
        nextNode->count--;
        if (nextNode->count == 0)
            node->links[c - 'a'] = NULL;

        //         if()
    }

    void erase(string &word)
    {

        erase(0, word, root);
        //          auto node=root;
        //        for(char c:word)
        //        {
        //            node=node->getNode(c,node);
        //            node->count--;
        //        }
        //         node->wordcount--;
    }
};
