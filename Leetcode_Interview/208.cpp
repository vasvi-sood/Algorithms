class Trie
{
    struct Trienode
    {
        bool isterminated = false;
        Trienode *link[26];
        bool containsKey(char c, Trienode *node)
        {
            if (node->link[c - 'a'] != NULL)
                return true;
            return false;
        }
        void insertKey(char c, Trienode *node)
        {
            node->link[c - 'a'] = new Trienode();
        }
    };
    Trienode *root;

public:
    Trie()
    {
        root = new Trienode();
    }

    void insert(string word)
    {
        Trienode *curr = root;
        for (char c : word)
        {

            if (!curr->containsKey(c, curr))
            {
                curr->insertKey(c, curr);
            }
            curr = curr->link[c - 'a'];
        }

        curr->isterminated = true;
    }

    bool search(string word)
    {
        Trienode *curr = root;
        for (char c : word)
        {

            if (curr->containsKey(c, curr))
            {
                curr = curr->link[c - 'a'];
                continue;
            }
            return false;
        }

        if (curr->isterminated)
            return true;
        else
            return false;
    }

    bool startsWith(string prefix)
    {
        Trienode *curr = root;
        for (char c : prefix)
        {

            if (curr->containsKey(c, curr))
            {
                curr = curr->link[c - 'a'];
                continue;
            }
            return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */