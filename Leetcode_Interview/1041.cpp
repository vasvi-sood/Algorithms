class Solution
{
    pair<pair<int, int>, char> getlastpos(string &s)
    {
        char dir = 'N';
        int x = 0;
        int y = 0;
        map<char, char> left;
        left['N'] = 'W';
        left['W'] = 'S';
        left['S'] = 'E';
        left['E'] = 'N';

        map<char, char> right;
        right['N'] = 'E';
        right['E'] = 'S';
        right['S'] = 'W';
        right['W'] = 'N';

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'G')
            {
                switch (dir)
                {
                case 'N':
                    y = y + 1;
                    break;
                case 'E':
                    x = x + 1;
                    break;

                case 'S':
                    y -= 1;
                    break;

                case 'W':
                    x -= 1;
                }
            }

            else if (s[i] == 'L')
                dir = left[dir];
            else
                dir = right[dir];
        }
        return make_pair(make_pair(x, y), dir);
    }

    char getfirstdir(string &s)
    {
        return 'N';
    }

public:
    bool isRobotBounded(string instructions)
    {
        auto a = getlastpos(instructions);
        int x = a.first.first;
        int y = a.first.second;
        char dir = a.second;
        if (x == 0 && y == 0)
            return true;

        char first = getfirstdir(instructions);
        if (dir == first)
            return false;

        return true;
    }
};