#include<bits/stdc++.h>
using namespace std;

int interativeMemoization(int n) {
    vector<int> f;
    f.push_back(0);
    f.push_back(1);

    int count = 2;
    for (int i = 2; i < n; i++) {
        count++;
        f.push_back(f[i - 1] + f[i - 2]);
    }
    return n;
}

int noofrecursiveSteps = 0;

int recursiveSteps(int n) {
    noofrecursiveSteps++;
    if (n < 0) {
        return 0;
    }
    if (n==1 || n==0) {
        return 1;
    }
    return recursiveSteps(n - 1) + recursiveSteps(n - 2);
}

int main() {
    int n;
    cout << "Enter the number : ";
    cin >> n;
    cout << "Fibbonacci Value : " << recursiveSteps(n) << endl;
    cout << interativeMemoization(n) << " " << noofrecursiveSteps << endl;
}
