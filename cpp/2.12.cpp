// Sử dụng C-Free 5
// Giải thuật Quay lui

#include <iostream> // cin, cout
#include <cstdlib> // NULL

using namespace std;

/* CÁC KIỂU DỮ LIỆU */

enum PhepToan {
  CONG, TRU
};

/* CÁC HÀM CẦN XÂY DỰNG */

// Chương trình chính
int main ();

// Hàm nhập
void nhap (int & tong, int * & dayso, unsigned & soluong);

// Hàm xuất
void xuat (bool thanhcong, int * dayso = NULL, PhepToan * pheptoan = NULL, unsigned soluong = 0);
void xuat (int * dayso, PhepToan * pheptoan, unsigned soluong);
char toantu (PhepToan pheptoan);

// Hàm tìm đa thức
void timdathuc (bool & thanhcong, PhepToan * & pheptoan, int tong, int * dayso, unsigned soluong);

/* NỘI DUNG */

int main () {
  int tong, * dayso;
  unsigned soluong;
  PhepToan * pheptoan;
  bool thanhcong;
  nhap(tong, dayso, soluong);
  timdathuc(thanhcong, pheptoan, tong, dayso, soluong);
  xuat(thanhcong, dayso, pheptoan, soluong - 1);
  delete [] dayso;
  delete [] pheptoan;
  return 0;
}

void nhap (int & tong, int * & dayso, unsigned & soluong) {
  cout << "Nhap tong: ";
  cin >> tong;
  cout << "Nhap so luong: ";
  cin >> soluong;
  dayso = new int[soluong];
  cout << "Nhap tung phan tu cua day so: ";
  for (unsigned i = 0; i != soluong; ++i) {
    cin >> dayso[i];
  }
}

void xuat (bool thanhcong, int * dayso, PhepToan * pheptoan, unsigned soluong) {
  if (thanhcong) {
    xuat(dayso, pheptoan, soluong);
  } else {
    cout << "Khong tim thay bieu thuc phu hop\n";
  }
}

void xuat (int * dayso, PhepToan * pheptoan, unsigned soluong) {
  for (unsigned i = 0; i != soluong; ++i) {
    cout << dayso << ' ' << toantu(pheptoan[i]) << ' ';
  }
  cout << dayso[soluong] << endl;
}

char toantu (PhepToan pheptoan) {
  return pheptoan == PhepToan::CONG ? '+' : '-';
}
