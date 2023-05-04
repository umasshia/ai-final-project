#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_valid(vector<int>& board, int row, int col) {
    for (int r = 0; r < row; ++r) {
        if (board[r] == col || r - board[r] == row - col || r + board[r] == row + col) {
            return false;
        }
    }
    return true;
}

void print_board(vector<int>& board){
    for (int r = 0; r < board.size(); ++r) {
        for (int c = 0; c < board.size(); ++c) {
            if (board[r] == c) {
                printf("Q ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool solve(vector<int>& board, int row) {
    if (row == board.size()) {
        print_board(board);
        return true;
    }
    
    bool found = false;
    for (int col = 0; col < board.size(); ++col) {
        if (is_valid(board, row, col)) {
            board[row] = col;
            found = solve(board, row + 1);
            if (found) {
                return true;
            }
            board[row] = -1;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    
    int num_runs;
    cout << "Enter the number of runs: ";
    cin >> num_runs;
    int num_solutions = 0;

    vector<long long> durations(num_runs);

    for (int i = 0; i < num_runs; i++) {
        vector<int> board(n, -1);
        auto start = chrono::high_resolution_clock::now();
        printf("Run %d:\n", i + 1);
        if(solve(board, 0)){
            num_solutions++;
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        durations[i] = duration;
    }

    long long min_duration = *min_element(durations.begin(), durations.end());
    long long max_duration = *max_element(durations.begin(), durations.end());
    double avg_duration = accumulate(durations.begin(), durations.end(), 0.0) / num_runs;
    double std_dev = 0.0;
    for (int i = 0; i < num_runs; i++) {
        std_dev += pow(durations[i] - avg_duration, 2);
    }
    std_dev = sqrt(std_dev / (num_runs - 1));

    printf("\nExecution time statistics:\n");
    printf("--------------------------\n");
    printf("Minimum time taken: %.2f %s\n", min_duration < 1000 ? min_duration : min_duration < 1000000 ? min_duration / 1000.0 : min_duration / 1000000, min_duration < 1000 ? "\u00B5s" : min_duration < 1000000 ? "ms" : "s");
    printf("Maximum time taken: %.2f %s\n", max_duration < 1000 ? max_duration : max_duration < 1000000 ? max_duration/ 1000.0 : max_duration / 1000000.0, max_duration < 1000 ? "\u00B5s" : max_duration < 1000000 ? "ms" : "s");
    printf("Average time taken: %.2f %s\n", avg_duration < 1000 ? avg_duration : avg_duration < 1000000 ? avg_duration / 1000.0 : avg_duration / 1000000.0, avg_duration < 1000 ? "\u00B5s" : avg_duration < 1000000 ? "ms" : "s");
    printf("Standard deviation of time taken: %.2f %s\n", std_dev == 0 ? 0 : std_dev < 1000 ? std_dev : std_dev < 1000000 ? std_dev / 1000.0 : std_dev / 1000000.0, std_dev < 1000 ? "\u00B5s" : std_dev < 1000000 ? "ms" : "s");
    printf("Number of solutions: %d\n", num_solutions);
    printf("Number of runs: %d\n", num_runs);
    printf("--------------------------\n");

    return 0;
}
