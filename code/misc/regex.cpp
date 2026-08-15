#include <bits/stdc++.h>
using namespace std;

// First occurrence of pattern in s, or "" if there is none.
string findFirst(string s, string pattern) {
    smatch m;
    if (regex_search(s, m, regex(pattern))) return m.str();
    return "";
}

// All occurrences of pattern in s.
// Note: sregex_iterator requires a named regex; a temporary is a compile error in C++20+.
vector<string> findAll(string s, string pattern) {
    vector<string> results;
    regex re(pattern);
    sregex_iterator it(s.begin(), s.end(), re);
    sregex_iterator end;
    while (it != end) {
        results.push_back(it->str());
        it++;
    }
    return results;
}

/*
Common patterns:

Integer validation:
  regex_match(s, regex(R"(^-?\d+$)"))           // integer (possibly negative)
  regex_match(s, regex(R"(^\d+$)"))             // non-negative integer
  regex_match(s, regex(R"(^[1-9]\d*$)"))        // integer without leading zeros

Decimal number:
  regex_match(s, regex(R"(^-?\d+(\.\d+)?$)"))   // integer or decimal
  regex_match(s, regex(R"(^-?\d+\.\d+$)"))      // strictly decimal (has dot)

Subscript/superscript (e.g. Bad Latex):
  regex_match(s, regex(R"([a-zA-Z0-9]+_\{\d+\})"))      // X_{Y} where Y is integer
  regex_match(s, regex(R"([a-zA-Z0-9]+\^\{\d+\})"))     // X^{Y} where Y is integer
  findAll(s, R"([a-zA-Z0-9]+[_^]\{\d+\})")              // all sub/superscripts

Extract numbers:
  findAll(s, R"(\d+)")                          // sequences of digits
  findAll(s, R"(-?\d+(\.\d+)?)")                // integers and decimals

Other:
  regex_match(s, regex(R"(^[a-zA-Z]+$)"))       // only letters
  regex_match(s, regex(R"(^[a-zA-Z0-9]+$)"))    // alphanumeric
  regex_match(s, regex(R"(^[a-zA-Z0-9 ]+$)"))   // alphanumeric with spaces
*/
