#include <string>
class Solution {
public:

    string encode(vector<string>& strs) {
        // size of vector, length of 1st string, 1st string,
        // length of second string, second string ..

        string encodedString = to_string(strs.size()) + ',';
        for(const auto str:strs)
        {
            encodedString += to_string(str.length()) + ',' + str + ',';
        }

        return encodedString;
    }

    vector<string> decode(string s) {

        cout << s <<"/n";
        // read encoded string and decode
        int start = 0;
        int com = s.find(',', start);
        int size = stoi(s.substr(0, com-start));
        start = com+1;

        vector<string> decoded;
        for(int i = 0 ; i<size; i++)
        {
            int comma = s.find(',', start);
            int length = stoi(s.substr(start, comma-start));
            //int length = 5;
            decoded.push_back(s.substr(comma+1, length));
            start = comma+length+2;
        }
        return decoded;
    }
};
