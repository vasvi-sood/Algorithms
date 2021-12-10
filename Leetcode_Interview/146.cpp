class LRUCache
{
public:
    int cap;
    unordered_map<int, int> mp;
    map<int, int> pnokey;
    unordered_map<int, int> keypno;
    int c = 0;

    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        int pno = keypno[key];
        keypno.erase(key);
        pnokey.erase(pno);
        keypno[key] = c;
        pnokey[c] = key;
        c++;
        // cout<<"get : ";
        //  for(auto i=pnokey.begin();i!=pnokey.end();i++)
        // {
        //     cout<<i->second<<" ";
        // }
        // cout<<endl;

        return mp[key];
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end())
        {

            if (mp.size() == cap)
            {
                auto itr = pnokey.begin();
                int pno = itr->first;
                int ky = itr->second;
                mp.erase(ky);
                pnokey.erase(pno);
                keypno.erase(ky);
            }

            mp[key] = value;
            pnokey[c] = key;
            keypno[key] = c;
            c++;
        }

        //if key is already present
        else
        {
            int pno = keypno[key];
            keypno.erase(key);
            pnokey.erase(pno);
            keypno[key] = c;
            pnokey[c] = key;
            mp[key] = value;
            c++;
        }
        //   cout<<"put : ";
        // for(auto i=pnokey.begin();i!=pnokey.end();i++)
        // {
        //     cout<<i->second<<" ";
        // }
        // cout<<endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */