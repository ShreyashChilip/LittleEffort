#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <map>
using namespace std;

struct Node {
    string name;
    string type;
    vector<pair<Node*, int>> children;
};

map<Node*, int> bestCost;
map<Node*, vector<Node*>> chosenChildren;

int computeCost(Node* node) {
    if (node->children.empty()) {
        bestCost[node] = 0;
        chosenChildren[node] = {};
        return 0;
    }

    if (node->type == "OR") {
        int best = numeric_limits<int>::max();
        Node* bestChild = nullptr;
        for (auto &child : node->children) {
            int c = child.second + computeCost(child.first);
            if (c < best) {
                best = c;
                bestChild = child.first;
            }
        }
        bestCost[node] = best;
        chosenChildren[node] = {bestChild};
    } else { // AND node
        int total = 0;
        vector<Node*> chosen;
        for (auto &child : node->children) {
            total += child.second + computeCost(child.first);
            chosen.push_back(child.first);
        }
        bestCost[node] = total;
        chosenChildren[node] = chosen;
    }
    return bestCost[node];
}

void printPlan(Node* node, int depth = 0) {
    for (int i = 0; i < depth; i++) cout << "   ";
    cout << "- " << node->name << endl;

    for (Node* c : chosenChildren[node]) {
        printPlan(c, depth + 1);
    }
}

int main() {
    Node hire{"Hire Freelancer", "OR"};
    Node internal{"Internal Team", "OR"};
    Node featureA{"Develop Feature A", "OR", {{&hire, 100}, {&internal, 50}}};

    Node openSource{"Use Open Source", "OR"};
    Node custom{"Build Custom", "OR"};
    Node featureB{"Develop Feature B", "OR", {{&openSource, 30}, {&custom, 60}}};

    Node develop{"Develop", "AND", {{&featureA, 0}, {&featureB, 0}}};

    Node buy{"Buy Off-The-Shelf", "OR"};
    Node launch{"Launch Product", "OR", {{&buy, 70}, {&develop, 0}}};

    int best = computeCost(&launch);
    cout << "Minimum cost to launch product: " << best << "\n\n";
    cout << "Chosen plan:\n";
    printPlan(&launch);
    return 0;
}
