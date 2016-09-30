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
void xuat (unsigned giatri);

// Hàm Chọn đồ vật
unsigned chondovat (unsigned succhua, DoVat * nguon, unsigned soluongnguon);

// Hàm sắp xếp: Tỉ lệ giatri/khoiluong giảm dần (hoặc khoiluong/giatri tăng dần)
void sapxep (DoVat * mang, unsigned soluong);

// Hàm tiện ích
float * taomangtile (DoVat * mang, unsigned soluong);

/* NỘI DUNG */

int main () {
  DoVat * nguon;
  unsigned soluongnguon, succhua;
  nhap(nguon, soluongnguon, succhua);
  xuat(chondovat(succhua, nguon, soluongnguon));
  delete [] nguon;
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

void xuat (unsigned giatri) {
  cout << "Dap so: " << giatri << endl;
}

unsigned chondovat (unsigned succhua, DoVat * nguon, unsigned soluongnguon) {
  DoVat * dich = new DoVat[soluongnguon];
  unsigned soluongdich = 0;
  unsigned giatri = 0;
  sapxep(nguon, soluongnguon);
  for (unsigned i = 0; i != soluongnguon; ++i) {
    if (succhua >= nguon[i].khoiluong) {
      dich[soluongdich] = nguon[i];
      succhua -= nguon[i].khoiluong;
      giatri += nguon[i].giatri;
      ++soluongdich;
    }
  }
  return giatri;
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
