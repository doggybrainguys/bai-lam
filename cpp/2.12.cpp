// Sử dụng C-Free 5
// Giải thuật Quay lui

#include <iostream> // cin, cout, cerr
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
void timdathuc (bool & thanhcong, PhepToan * pheptoan, int tong, int * dayso, unsigned soluong);

/* NỘI DUNG */

int main () {
  int tong, * dayso;
  unsigned soluong;
  bool thanhcong;
  nhap(tong, dayso, soluong);
  PhepToan * pheptoan = new PhepToan[soluong];
  timdathuc(thanhcong, pheptoan, tong, dayso, soluong);
  xuat(thanhcong, dayso, pheptoan, soluong);
  delete [] dayso;
  delete [] pheptoan;
  cin.get();
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
    cout << "Da thuc:";
    xuat(dayso, pheptoan, soluong);
  } else {
    cerr << "Khong tim thay da thuc phu hop\n";
  }
}

void xuat (int * dayso, PhepToan * pheptoan, unsigned soluong) {
  for (unsigned i = 0; i != soluong; ++i) {
    cout << ' ' << toantu(pheptoan[i]) << dayso[i];
  }
  cout << endl;
}

char toantu (PhepToan pheptoan) {
  return pheptoan == PhepToan::CONG ? '+' : '-';
}

void timdathuc (bool & thanhcong, PhepToan * pheptoan, int tong, int * dayso, unsigned soluong) {
  if (soluong) {
    const int sohang = * dayso;
    bool thanhcongmoi;
    timdathuc(thanhcongmoi, pheptoan + 1, tong - sohang, dayso + 1, soluong - 1);
    if (thanhcongmoi) {
      * pheptoan = PhepToan::CONG;
      thanhcong = true;
      return;
    }
    timdathuc(thanhcongmoi, pheptoan + 1, tong + sohang, dayso + 1, soluong - 1);
    if (thanhcongmoi) {
      * pheptoan = PhepToan::TRU;
      thanhcong = true;
      return;
    }
    thanhcong = false;
    return;
  }
  thanhcong = ! tong;
}
