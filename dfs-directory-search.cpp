#include <iostream>
#include <vector>
#include <map>
#include <chrono>

using namespace std;

bool recurse(const string& node, map<string,vector<string>>& adj, map<string, bool>& visited, vector<string>& res, const string& target) {
    visited[node] = true;

    if (node == target) {
        res.insert(res.begin(), node);
        return true;
    }

    for (const auto& neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (recurse(neighbor, adj, visited, res, target)) {
                res.insert(res.begin(), node);
                return true;
            }
        }
    }
    return false;
}

vector<string> dfs(map<string, vector<string>>& adj, const string& target, bool& found) {
    map<string, bool> visited;
    vector<string> res;
    string start = "Folder1";
    found = recurse(start, adj, visited, res, target);
    return res;
}

int main() {
map<string, vector<string>> adj = {
    {"Folder1", {"Folder2", "Folder3", "File1", "File2"}},
    {"Folder2", {"Folder4", "Folder5", "File3", "File4"}},
    {"Folder3", {"Folder6", "File5", "File6"}},
    {"Folder4", {"Folder7", "File7"}},
    {"Folder5", {"File8", "File9", "File10"}},
    {"Folder6", {"Folder8", "Folder9", "File11"}},
    {"Folder7", {"File12", "File13"}},
    {"Folder8", {"File14", "File15"}},
    {"Folder9", {"Folder10", "File16"}},
    {"Folder10", {"File17", "File18", "Folder11"}},
    {"Folder11", {"File19", "Folder12"}},
    {"Folder12", {"File20", "File21", "Folder13"}},
    {"Folder13", {"File22", "File23", "Folder14"}},
    {"Folder14", {"File24", "File25", "Folder15"}},
    {"Folder15", {"File26", "File27", "Folder16"}},
    {"Folder16", {"Folder17", "File28"}},
    {"Folder17", {"File29", "File30", "Folder18"}},
    {"Folder18", {"File31", "File32", "Folder19"}},
    {"Folder19", {"Folder20", "File33"}},
    {"Folder20", {"File34", "File35", "File36", "Folder21"}},
    {"Folder21", {"File37", "File38", "Folder22"}},
    {"Folder22", {"File39", "Folder23"}},
    {"Folder23", {"File40", "File41", "Folder24"}},
    {"Folder24", {"Folder25", "File42"}},
    {"Folder25", {"File43", "File44", "Folder26"}},
    {"Folder26", {"File45", "File46", "Folder27"}},
    {"Folder27", {"Folder28", "File47"}},
    {"Folder28", {"File48", "File49", "Folder29"}},
    {"Folder29", {"File50", "File51", "Folder30"}},
    {"Folder30", {"Folder31", "File52"}},
    {"Folder31", {"File53", "File54", "Folder32"}},
    {"Folder32", {"File55", "File56", "Folder33"}},
    {"Folder33", {"File57", "File58", "Folder34"}},
    {"Folder34", {"File59", "File60", "Folder35"}},
    {"Folder35", {"File61", "File62", "Folder36"}},
    {"Folder36", {"File63", "File64", "Folder37"}},
    {"Folder37", {"File65", "File66", "Folder38"}},
    {"Folder38", {"File67", "File68", "Folder39"}},
    {"Folder39", {"File69", "File70", "Folder40"}},
    {"Folder40", {"File71", "File72", "Folder41"}},
    {"Folder41", {"File73", "File74", "Folder42"}},
    {"Folder42", {"File75", "File76", "Folder43"}},
    {"Folder43", {"File77", "File78", "Folder44"}},
    {"Folder44", {"File79", "File80", "Folder45"}},
    {"Folder45", {"File81", "File82", "Folder46"}},
    {"Folder46", {"File83", "File84", "Folder47"}},
    {"Folder47", {"File85", "File86", "Folder48"}},
    {"Folder48", {"File87", "File88", "Folder49"}},
    {"Folder49", {"File89", "File90", "Folder50"}},
    {"Folder50", {"File91", "File92", "Folder51"}},
    {"Folder51", {"File93", "File94", "Folder52"}},
    {"Folder52", {"File95", "File96", "Folder53"}},
    {"Folder53", {"File97", "File98", "Folder54"}},
    {"Folder54", {"File99", "File100", "Folder55"}},
    {"Folder55", {"File101", "File102", "Folder56"}},
    {"Folder56", {"File103", "File104", "Folder57"}},
    {"Folder57", {"File105", "File106", "Folder58"}},
    {"Folder58", {"File107", "File108", "Folder59"}},
    {"Folder59", {"Folder60"}}, 
    {"Folder60", {}}
};

    string target = "File108";
    bool found = false;
    auto start = chrono::high_resolution_clock::now();
    vector<string> ans = dfs(adj, target, found);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed_seconds = chrono::duration_cast<chrono::nanoseconds>(end - start);
    if (!found) {
        cout << "No path to file found!\n";
        return 0;
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << " => ";
    }
    cout << endl;
    cout << "Elapsed time: " << elapsed_seconds.count() << " ns" << std::endl;
    return 0;
}
