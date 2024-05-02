#include <bits/stdc++.h>
using namespace std;

// Hàm tìm dãy con lớn nhất bằng cách duyệt thường
void cachthongthuong() {
    int n, k;
    cin >> n >> k; // Nhập số phần tử của mảng và độ dài dãy con
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i]; // Nhập các phần tử của mảng
    int maxsum = 0; // Khởi tạo biến lưu tổng lớn nhất
    for (int i = 0; i <= n - k; i++) { // Duyệt qua các vị trí bắt đầu của dãy con
        int tong = 0; // Khởi tạo biến tổng cho mỗi dãy con
        for (int j = 0; j < k; j++)
            tong += a[i + j]; // Tính tổng của dãy con
        if (tong > maxsum)
            maxsum = tong; // Cập nhật tổng lớn nhất
    }
    cout << maxsum; // Xuất tổng lớn nhất của dãy con
}

int main() { // Giải thuật cửa sổ trượt
    int n, k;
    cin >> n >> k; // Nhập số phần tử của mảng và độ dài cửa sổ
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i]; // Nhập các phần tử của mảng
    int maxsum = 0, tong = 0;
    for (int i = 0; i < k; i++)
        tong += a[i]; // Tính tổng các phần tử đầu tiên để khởi tạo cửa sổ ban đầu
    maxsum = tong; // Gán tổng lớn nhất bằng tổng cửa sổ ban đầu
    for (int i = 1; i <= n - k; i++) {
        tong = tong - a[i - 1] + a[i + k - 1]; // Cập nhật tổng khi trượt cửa sổ
        if (tong > maxsum)
            maxsum = tong; // Cập nhật tổng lớn nhất
    }
    cout << maxsum; // Xuất tổng lớn nhất của cửa sổ trượt
    return 0;
}

