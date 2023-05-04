#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <chrono>
#include <cmath>

using namespace std;

class NQueensProblem {
    private:
        int n;
        vector<int> initial_state;
    public:
        NQueensProblem(int n) : n(n), initial_state(n) {
            for (int i = 0; i < n; i++) {
                initial_state[i] = rand() % n;
            }
        }

        vector<int> get_initial_state(){
            return this->initial_state;
        }

        int value(vector<int>& state) {
            int attacks = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    if (state[i] == state[j] || abs(state[i] - state[j]) == j - i) {
                        attacks++;
                    }
                }
            }
            return -attacks;
        }

    vector<int> get_highest_valued_successor(vector<int>& state) {
        vector<int> best_state = state;
        int best_value = value(state);
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                if (state[row] != col) {
                    vector<int> successor = state;
                    successor[row] = col;
                    int successor_value = value(successor);
                    if (successor_value > best_value) {
                        best_state = successor;
                        best_value = successor_value;
                    }
                }
            }
        }
        return best_state;
    }
};

void print_state(vector<int>& state) {
    int n = state.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (state[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

vector<int> hill_climbing(NQueensProblem& problem) {
    vector<int> current = problem.get_initial_state();
    while (true){
        vector<int> neighbor = problem.get_highest_valued_successor(current);
        if (problem.value(neighbor) <= problem.value(current)) {
            return current;
        }
        current = neighbor;
    }
}

bool solve_n_queens(int n, int attempt) {
    NQueensProblem problem(n);
    vector<int> solution = hill_climbing(problem);
    if(problem.value(solution) == 0){
        printf("Solution found on attempt %d:\n", attempt);
        print_state(solution);
        return true;
    }
    return problem.value(solution) == 0;
}

int main() {
    srand(time(0));
    int attempts = 100, solves = 0;
    vector<int> durations;
    for(int attempt = 0; attempt < attempts; attempt++) {
        auto start = chrono::high_resolution_clock::now();
        bool solution = solve_n_queens(10, attempt);
        clock_t end_time = clock();
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        if(solution){
            durations.push_back(duration);
        }
        solves += solution;
    }
    printf("Solved %d out of %d\n", solves, attempts);
    printf("Success rate: %.2f%%\n", (float)solves / attempts * 100);
    long long min_duration = *min_element(durations.begin(), durations.end());
    long long max_duration = *max_element(durations.begin(), durations.end());
    double avg_duration = accumulate(durations.begin(), durations.end(), 0.0) / attempts;
    double std_dev = 0.0;
    for (int i = 0; i < attempts; i++) {
        std_dev += pow(durations[i] - avg_duration, 2);
    }
    std_dev = sqrt(std_dev / (attempts - 1));
    printf("\nExecution time statistics:\n");
    printf("--------------------------\n");
    printf("Minimum time taken: %.2f %s\n", min_duration < 1000 ? min_duration : min_duration < 1000000 ? min_duration / 1000.0 : min_duration / 1000000, min_duration < 1000 ? "\u00B5s" : min_duration < 1000000 ? "ms" : "s");
    printf("Maximum time taken: %.2f %s\n", max_duration < 1000 ? max_duration : max_duration < 1000000 ? max_duration/ 1000.0 : max_duration / 1000000.0, max_duration < 1000 ? "\u00B5s" : max_duration < 1000000 ? "ms" : "s");
    printf("Average time taken: %.2f %s\n", avg_duration < 1000 ? avg_duration : avg_duration < 1000000 ? avg_duration / 1000.0 : avg_duration / 1000000.0, avg_duration < 1000 ? "\u00B5s" : avg_duration < 1000000 ? "ms" : "s");
    printf("Standard deviation of time taken: %.2f %s\n", std_dev == 0 ? 0 : std_dev < 1000 ? std_dev : std_dev < 1000000 ? std_dev / 1000.0 : std_dev / 1000000.0, std_dev < 1000 ? "\u00B5s" : std_dev < 1000000 ? "ms" : "s");

    return 0;
}

