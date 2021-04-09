// First thing to do:
// - Tokenize text using lexical analysis
//   into '{', 'name', ':', 'value', '}'
//
// 

#include <map>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std; // less typing; remove afterwards though

std::map<string, string> parseKeyValues(const string& s);

struct Node
{
    Node(const map<string, string>& keyVals, const vector<Node*>& children = {});
    Node(const string& s);
};

Node* parse(const std::string& text)
{
    string s = text; // copy
    stack<unsigned> braces;
    vector<Node> children;

    int currPos = -1;
    for (auto& c : s)
    {
        ++currPos;

        if (c == '{')
            braces.push(currPos);
        else if (c == '}')
        {
            if (braces.empty())
                return nullptr; // opening/closing braces do not match

            auto startPos = braces.top();
            braces.pop();


        }        
    }           
}