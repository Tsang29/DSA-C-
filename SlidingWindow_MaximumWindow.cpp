//In ra số lớn nhát và nhỏ nhất của mọi mảng con cỡ k của mảng a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k; // Nhập số phần tử của mảng và độ dài của cửa sổ
    int a[n]; // Khai báo mảng chứa dãy số
    for(int i = 0; i < n; i++)
        cin >> a[i]; // Nhập các phần tử của mảng
    multiset<int> se; // Khai báo multiset để lưu cửa sổ
    for(int i = 0; i < k; i++)
        se.insert(a[i]); // Chèn k phần tử đầu tiên vào cửa sổ
    // Xuất ra phần tử nhỏ nhất và lớn nhất trong cửa sổ ban đầu
    cout << *se.begin() << " " << *se.rbegin() << endl;
    for(int i = 1; i <= n - k; i++) {
        auto it = se.find(a[i - 1]); // Tìm vị trí của phần tử bị loại khỏi cửa sổ
        se.erase(it); // Loại bỏ phần tử đầu tiên khỏi cửa sổ
        se.insert(a[i + k - 1]); // Thêm phần tử mới vào cửa sổ
        // Xuất ra phần tử nhỏ nhất và lớn nhất sau khi trượt cửa sổ
        cout << *se.begin() << " " << *se.rbegin() << endl;
    }
    return 0;
}
