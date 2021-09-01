//Graph BFS Question, Difficult
#include <vector>
class Solution
{
public:
    vector<int> bfs(vector<string> arr, int start, string beginword)
    {
        vector<int> layer(arr.size(), -1);
        //layer tells us which layer the node belongs with respect to source
        layer[start] = 0;
        queue<int> q;
        q.push(start); //push starting node
        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            string w1 = arr[parent];
            for (int i = 0; i < arr.size(); i++)
            {
                if (layer[i] == -1) //if ith node is -1 then check if its the child of present node
                {
                    int dissimilar = 0;
                    string w2 = arr[i];

                    for (int k = 0; k < beginword.size(); k++)
                    {
                        if (dissimilar > 1)
                            break;
                        if (w1[k] != w2[k])
                            dissimilar++;
                    }

                    if (dissimilar == 1) //exactly k-1 charcters of string match,then they are connected
                    {

                        layer[i] = layer[parent] + 1;
                        q.push(i);
                    }
                }
            }
        }
        return layer;
    }
    int ladderLength(string beginword, string endword, vector<string> &wordlist)
    {
        if (find(wordlist.begin(), wordlist.end(), endword) == wordlist.end()) //endword not found, return 0
        {
            return 0;
        }
        int n = 0; //this will hold the node position

        auto fn = find(wordlist.begin(), wordlist.end(), beginword);
        if (fn == wordlist.end()) //beginword not foundappend to n
        {
            n = wordlist.size(); //begin word is node number n
            wordlist.push_back(beginword);
            //push beginword at end of wordlist
        }
        else
        {
            n = fn - wordlist.begin(); //start node position is what was found
        }

        vector<int> length = bfs(wordlist, n, beginword);
        int pos = find(wordlist.begin(), wordlist.end(), endword) - wordlist.begin(); //position of lastword

        return length[pos] + 1;
    }
};