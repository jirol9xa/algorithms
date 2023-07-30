#include <stack>
#include <string>

using string = std::string;

class Solution {
    enum Braces_ {
        ROUND  = ')',
        SQUARE = ']',
        CURLY  = '}',
    };

  public:
    bool isValid(string s)
    {
        std::stack<Braces_> braces;

        for (auto sym : s) {
            switch (sym) {
            case '(':
                braces.push(ROUND);
                break;
            case '{':
                braces.push(CURLY);
                break;
            case '[':
                braces.push(SQUARE);
                break;
            default:
                if (braces.empty() || braces.top() != sym)
                    return false;
                braces.pop();
            }
        }

        return braces.empty();
    }
};
