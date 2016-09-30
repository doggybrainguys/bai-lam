// Sử dụng C-Free 5
// Thuật toán Tham lam

#include <iostream> // cin, cout
#include <algorithm> // swap

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

// Hàm Chọn đồ vật
void chondovat (DoVat * & dich, unsigned & soluongdich, unsigned succhua, DoVat * nguon, unsigned soluongnguon);

// Hàm sắp xếp: Tỉ lệ giatri/khoiluong giảm dần (hoặc khoiluong/giatri tăng dần)
void sapxep (DoVat * mang, unsigned soluong);

// Hàm tiện ích
float * taomangtile (DoVat * mang, unsigned soluong);

/* NỘI DUNG */

int main () {
  DoVat * nguon, * dich;
  unsigned soluongnguon, soluongdich, succhua;
  nhap(nguon, soluongnguon, succhua);
  chondovat(dich, soluongdich, succhua, nguon, soluongnguon);
  xuat(dich, soluongdich);
  delete [] nguon;
  delete [] dich;
  cin.get();
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
  unsigned tongkhoiluong = 0, tonggiatri = 0;
  cout << "Cac do vat da chon (KhoiLuong : GiaTri):\n";
  for (unsigned i = 0; i != soluong; ++i) {
    DoVat dovat = mang[i];
    cout << " + " << dovat.khoiluong << " : " << dovat.giatri << endl;
    tongkhoiluong += dovat.khoiluong;
    tonggiatri += dovat.giatri;
  }
  cout << "Tong khoi luong: " << tongkhoiluong << endl;
  cout << "Tong gia tri: " << tonggiatri << endl;
}

void chondovat (DoVat * & dich, unsigned & soluongdich, unsigned succhua, DoVat * nguon, unsigned soluongnguon) {
  dich = new DoVat[soluongnguon];
  soluongdich = 0;
  sapxep(nguon, soluongnguon);
  for (unsigned i = 0; i != soluongnguon; ++i) {
    if (succhua >= nguon[i].khoiluong) {
      dich[soluongdich] = nguon[i];
      succhua -= nguon[i].khoiluong;
      ++soluongdich;
    }
  }
}

void sapxep (DoVat * mang, unsigned soluong) {
  float * tile = taomangtile(mang, soluong);
  for (unsigned i = 0; i != soluong; ++i) {
    for (unsigned j = i; j != soluong; ++j) {
      if (tile[i] > tile[j]) {
        swap(mang[i], mang[j]);
        swap(tile[i], tile[j]);
      }
    }
  }
  delete [] tile;
}

float * taomangtile (DoVat * mang, unsigned soluong) {
  float * tile = new float[soluong];
  for (unsigned i = 0; i != soluong; ++i) {
    DoVat dovat = mang[i];
    tile[i] = float(dovat.khoiluong) / dovat.giatri;
  }
  return tile;
}
