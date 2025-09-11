#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sadUsers;
        for(auto& friends : friendships) {
            int u = friends[0] - 1;
            int v = friends[1] - 1;
            unordered_set<int> langSet(begin(languages[u]), end(languages[u]));
            bool canTalk = false;
            for(auto& lang : languages[v]) {
                if(langSet.count(lang)) {
                    canTalk = true;
                    break;
                }
            }
            if(!canTalk) {
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }

        vector<int> language(n + 1, 0);
        int mostTalklanguage = 0;
        for(int users : sadUsers) {
            for(int lang : languages[users]) {
                language[lang]++;
                mostTalklanguage = max(mostTalklanguage, language[lang]);
            }
        }
        return sadUsers.size() - mostTalklanguage;
    }
};
int main() {
    int n = 2;
    vector<vector<int>> languages = {{1}, {2}, {1, 2}};
    vector<vector<int>> friendships = {{1, 2}, {1, 3}, {2, 3}};
    Solution s;
    int ans = s.minimumTeachings(n, languages, friendships);
    cout << ans << endl;
    return 0;
}