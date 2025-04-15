#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int MOD = 1e9 + 7;
const long long INF = 1e18;

// Enable fast I/O
void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int seatCount, studentCount;
vector<int> seatPositions;

// Check if we can place all students with at least 'minDistance' between them
bool canPlaceStudents(int minDistance) {
    int studentsPlaced = 1;
    int lastPlacedPosition = seatPositions[0];

    for (int i = 1; i < seatCount; i++) {
        if (seatPositions[i] - lastPlacedPosition >= minDistance) {
            lastPlacedPosition = seatPositions[i];
            studentsPlaced++;
        }
    }

    return studentsPlaced >= studentCount;
}

void solveTestCase() {
    cin >> seatCount >> studentCount;

    seatPositions.clear();
    seatPositions.resize(seatCount);

    for (int i = 0; i < seatCount; i++) {
        cin >> seatPositions[i];
    }

    sort(seatPositions.begin(), seatPositions.end());

    int low = 0;
    int high = seatPositions[seatCount - 1] - seatPositions[0];
    int maxMinDistance = high + 1;

    // Binary search on the minimum distance
    while (low <= high) {
        int midDistance = low + (high - low) / 2;

        if (canPlaceStudents(midDistance)) {
            maxMinDistance = midDistance;
            low = midDistance + 1;
        } else {
            high = midDistance - 1;
        }
    }

    cout << maxMinDistance << endl;
}

int32_t main() {
    
    fastIO();

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solveTestCase();
    }

    return 0;
}