class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

private:
    void backtrack(string &s, int start, vector<string> &path, vector<string> &result) {
        if (path.size() == 4) {
            if (start == s.size()) {
                result.push_back(join(path));
            }
            return;
        }

        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.size()) break;
            string part = s.substr(start, len);
            if (isValid(part)) {
                path.push_back(part);
                backtrack(s, start + len, path, result);
                path.pop_back();
            }
        }
    }

    bool isValid(string &part) {
        if (part.size() > 1 && part[0] == '0') return false;
        int num = stoi(part);
        return num >= 0 && num <= 255;
    }

    string join(vector<string> &parts) {
        string ip = parts[0];
        for (int i = 1; i < parts.size(); i++) {
            ip += "." + parts[i];
        }
        return ip;
    }
};
