#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int psb1 = n + n - 1;
    int psb2 = k + k - 1;
    int psb3 = n + k;

    cout << std::max(psb1, std::max(psb2, psb3)) << endl;

    return 0;
}