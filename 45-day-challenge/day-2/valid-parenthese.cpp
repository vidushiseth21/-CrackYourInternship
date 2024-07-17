
class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                s1.push(ch);
            } else {
                if (s1.empty()) {
                    return false;
                }
                char top = s1.top();
                s1.pop();
                if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return s1.empty(); 
    }
};