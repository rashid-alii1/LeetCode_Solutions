class Solution {
public:

    string s;
    int pos = 0;

    // Cartesian product / concatenation
    set<string> multiply(
        const set<string>& A,
        const set<string>& B
    ) {
        set<string> result;

        for (const string& a : A) {
            for (const string& b : B) {
                result.insert(a + b);
            }
        }

        return result;
    }

    // expression = term (',' term)*
    set<string> parseExpression() {

        set<string> result = parseTerm();

        while (pos < s.size() && s[pos] == ',') {

            pos++;  // skip ','

            set<string> next = parseTerm();

            // Union
            result.insert(next.begin(), next.end());
        }

        return result;
    }

    // term = chunk chunk chunk ...
    set<string> parseTerm() {

        set<string> result = {""};

        while (
            pos < s.size() &&
            s[pos] != '}' &&
            s[pos] != ','
        ) {

            set<string> current;

            // chunk = letter
            if (islower(s[pos])) {

                current.insert(
                    string(1, s[pos])
                );

                pos++;
            }

            // chunk = { expression }
            else if (s[pos] == '{') {

                pos++;  // skip '{'

                current = parseExpression();

                pos++;  // skip '}'
            }

            // Concatenate
            result = multiply(result, current);
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        s = expression;
        pos = 0;

        set<string> result = parseExpression();

        return vector<string>(
            result.begin(),
            result.end()
        );
    }
};