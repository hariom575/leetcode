class Solution {
    public:
    int max_x, max_y, min_x, min_y;
    int x, y;
    bool is_vertical;
    bool is_positive;

    void update() {
        max_x = max(max_x, x);
        min_x = min(min_x, x);
        max_y = max(max_y, y);
        min_y = min(min_y, y);
    }
    void traverse(const string &s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'G') {
                if (is_vertical)
                    (is_positive) ? y++ : y--;
                else
                    (is_positive) ? x++ : x--;
                update();
            } else if (s[i] == 'L') {
                if (is_vertical)
                    (is_positive) ? (is_vertical = is_positive = false)
                    : (is_vertical = false, is_positive = true);
                else
                    (is_positive) ? (is_vertical = is_positive = true)
                    : (is_vertical = true, is_positive = false);

            } else {
                if (is_vertical)
                    (is_positive) ? (is_vertical = false, is_positive = true)
                    : (is_vertical = false, is_positive = false);
                else
                    (is_positive) ? (is_vertical = true, is_positive = false)
                    : (is_vertical = true, is_positive = true);
            }
        }
    }
    bool isRobotBounded(string s) {
        max_x = INT_MIN, max_y = INT_MIN, min_x = INT_MAX, min_y = INT_MAX;
        x = 0, y = 0;
        is_vertical = false;
        is_positive = true;

        for (int i = 0; i <= s.size(); i++)
            traverse(s);

        int curr_max_x = max_x, curr_mx_y = max_y;
        int curr_min_x = min_x, curr_mn_y = min_y;

        for (int i = 0; i < s.size(); i++)
            traverse(s);

        return (curr_max_x == max_x and curr_mx_y == max_y and
                curr_min_x == min_x and curr_mn_y == min_y)
            ? true
            : false;
    }
} ob;