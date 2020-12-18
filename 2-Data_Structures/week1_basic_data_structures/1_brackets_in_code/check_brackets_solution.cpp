#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Bracket {
    Bracket(char type, int position) :
            type(type),
            position(position) {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);

    stack<Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        int idx = position + 1;

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next, idx));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.empty()) {
                cout << idx << endl;
                return 0;
            }
            Bracket b = opening_brackets_stack.top();
            opening_brackets_stack.pop();
            if (!b.Matchc(next)){
                cout << idx << endl;
                return 0;
            }
        }
    }

    // Printing answer, write your code here
    if (opening_brackets_stack.empty()) {
        cout << "Success" << endl;
    } else {
        cout << opening_brackets_stack.top().position << endl;
    }

    return 0;
}
