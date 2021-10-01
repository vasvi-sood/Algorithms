class Solution
{

    void reverse(stack<int> &st, vector<int> &ans)
    {
        if (st.empty())
        {

            return;
        }
        int a = st.top();
        st.pop();
        reverse(st, ans);
        ans.push_back(a);
    }

public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;
        stack<int> st;
        for (int elem : asteroids)
        {
            if (st.empty())
            {

                st.push(elem);
                // cout<<"pushed0 "<<st.top()<<endl;
                continue;
            }

            int prev = st.top();
            st.push(elem);
            // cout<<"pushed1 "<<st.top()<<endl;

            while ((st.size() >= 2) && st.top() < 0 && prev > 0)
            {
                int tp = st.top();
                st.pop();
                int sec = st.top();
                st.pop();

                if (abs(tp) > sec)
                    st.push(tp);
                else if (sec > abs(tp))
                    st.push(sec);

                if (st.size() <= 1)
                    break;
                // cout<<"pushed2 "<<st.top()<<endl;
                tp = st.top();
                st.pop();
                prev = st.top();
                st.push(tp);
            }
        }

        reverse(st, ans);
        return ans;
    }
};