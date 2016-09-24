// Sử dụng C-Free 5
// Thuật toán Quy hoạch động

#include <iostream>
#include <algorithm>

using namespace std;

struct DoVat {
  unsigned khoiluong;
  unsigned giatri;
};

/* CÁC HÀM CẦN XÂY DỰNG */

// Chương trình chính
int main ();

// Hàm nhập
void nhap (DoVat * & mang, unsigned & soluong, unsigned & succhua);
void nhap (DoVat & dovat);

// Hàm xuất
void xuat (DoVat * mang, unsigned soluong);
void xuat (DoVat dovat);

// Hàm Chọn đồ vật
void chondovat (DoVat * & dich, unsigned & soluongdich, unsigned succhua, DoVat * nguon, unsigned soluongnguon);

// Hàm sắp xếp: Tỉ lệ giatri/khoiluong giảm dần (hoặc khoiluong/giatri tăng dần)
void sapxep (DoVat * mang, unsigned soluong);

/* NỘI DUNG */

int main () {
  DoVat * nguon, * dich;
  unsigned soluongnguon, soluongdich, succhua;
  nhap (nguon, soluongnguon, succhua);
  chondovat (dich, soluongdich, succhua, nguon, soluongnguon);
  xuat (dich, soluongdich);
  delete [] nguon;
  delete [] dich;
  return 0;
}

void nhap (DoVat * & mang, unsigned & soluong, unsigned & succhua) {
  cout << "Nhap so luong cac do vat: ";
  cin >> soluong;
  cout << "Nhap suc chua cua tui dung: ";
  cin >> succhua;
  mang = new DoVat[soluong];
  cout << "Nhap lan luot khoi luong va gia tri cua tung do vat: ";
  for (unsigned i = 0; i != soluong; ++i) nhap(mang[i]);
}

void nhap (DoVat & dovat) {
  cin >> dovat.khoiluong >> dovat.giatri;
}

void xuat (DoVat * mang, unsigned soluong) {
  cout << "Cac do vat da chon (GiaTri / KhoiLuong):\n";
  for (unsigned i = 0; i != soluong; ++i) xuat(mang[i]);
}

void xuat (DoVat dovat) {
  cout << " + " << dovat.giatri << " / " << dovat.khoiluong << endl;
}

void chondovat (DoVat * & dich, unsigned & soluongdich, unsigned succhua, DoVat * nguon, unsigned soluongnguon) {
  dich = new DoVat[soluongnguon];
  soluongdich = 0; // Khởi tạo
  // YOUR TEXT HERE...
}
