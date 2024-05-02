//Xác định xem trong mảng có tồn tại 2 phần tử a[i], a[j] sao cho
// a[i] = a[j] và abs(i-j)<= k
#include <bits/stdc++.h>
using namespace std;
int d[10000];
int main (){
    int n, k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++){
        if(d[a[i]] != 0){  //Nếu đã tồn tại a[i]
            cout << "YES\n"; //in ra yes
            return 0;
        }
        d[a[i]]++; //nếu không thì tăng thêm vào cửa sổ
    }
    for(int i = k; i < n; i++){ //tách ra do abs(i-j) <= k
        if(d[a[i]] != 0){
            cout << "YES\n";
            return 0;
        }
        d[a[i]]++;
        d[a[i-k]]--; //bỏ đi giá trị tại vị trí i-k
    }
    cout << "NO";
    return 0;
}
