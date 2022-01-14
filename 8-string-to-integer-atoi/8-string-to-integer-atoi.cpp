class Solution {
public:
    int myAtoi(string s) {
                long val = 0;
        int positive = 0; 
        bool exist = false;

        for (int i = 0; i < s.size(); i++) {
            if (val > INT_MAX)
                break;

            if (exist && !isdigit(s[i]))
                break;

            if (s[i] == ' ') {
                if (positive)
                    return 0;
                continue;
            } else if (s[i] == '+' || s[i] == '-') {
                if (positive)
                    return 0;
                positive = s[i] == '-' ? -1 : 1;
                continue;
            } else if (!isdigit(s[i]))
                    return 0;

            val = val * 10 + s[i] - '0';

            if (!exist)
                exist = true;
        }
        val = positive ? val * positive : val;

        if (val > INT_MAX)
            return INT_MAX;
        else if (val < INT_MIN)
            return INT_MIN;
        else
            return (int) val;
    }
};