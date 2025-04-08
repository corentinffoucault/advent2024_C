#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_

#include <string>
#include <cctype>

using namespace std;

namespace StringUtils {
    static string& ltrim(string& s) {
        s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !isspace(ch);
            }));
        return s;
    }

    static string& rtrim(string& s) {
        s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !isspace(ch);
            }).base(), s.end());
        return s;
    }

    static string& trim(string& s) {
        return ltrim(rtrim(s));
    }
}
#endif  /* !STRINGUTILS_H_ */