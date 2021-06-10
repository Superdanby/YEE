using namespace std;

int main() {

    string inp;
    while (cin >> inp) {
        stack<char> st;

        for (int i = 0; i < inp.size(); ++i) {
            if (!st.empty() && ((st.top() == '(' && inp[i] == ')') || (st.top() == '[' && inp[i] == ']') || (st.top() == '{' && inp[i] == '}')))
                st.pop();
            else
                st.push(inp[i]);
        }
        if (st.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}