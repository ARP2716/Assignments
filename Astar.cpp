#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

// Structure representing a node in the game tree
struct Node {
    int state;
    int cost;
    int heuristic;

    Node(int s, int c, int h) : state(s), cost(c), heuristic(h) {}
};

// Custom comparison function for the priority queue
struct CompareNodes {
    bool operator()(const Node& a, const Node& b) {
        return (a.cost + a.heuristic) > (b.cost + b.heuristic);
    }
};

// Heuristic function (example: Manhattan distance)
int heuristicFunction(int state, int goal) {
    int x1 = state % 3;
    int y1 = state / 3;
    int x2 = goal % 3;
    int y2 = goal / 3;
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

// A* algorithm implementation
int aStarAlgorithm(int start, int goal) {
    std::priority_queue<Node, std::vector<Node>, CompareNodes> openSet;
    std::vector<int> closedSet(9, 0);

    openSet.push(Node(start, 0, heuristicFunction(start, goal)));

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        if (current.state == goal) {
            return current.cost;
        }

        closedSet[current.state] = 1;

        // Generate successors
        for (int i = 0; i < 9; ++i) {
            if (!closedSet[i]) {
                int newCost = current.cost + 1;
                int newHeuristic = heuristicFunction(i, goal);
                openSet.push(Node(i, newCost, newHeuristic));
            }
        }
    }

    // No solution found
    return -1;
}

int main() {
    int startState = 0;  // Starting state of the game
    int goalState = 8;   // Goal state of the game

    int steps = aStarAlgorithm(startState, goalState);

    if (steps != -1) {
        std::cout << "Minimum number of steps: " << steps << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}
