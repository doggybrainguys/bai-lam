// Sử dụng C-Free 5

#include <iostream> // cin, cout, endl
#include <cmath> // sqrt

using namespace std;

/* HẰNG SỐ */

const unsigned SO_CHU_SO_NGUYEN_TO = 3;
const unsigned CHU_SO_NGUYEN_TO[SO_CHU_SO_NGUYEN_TO] = {3, 5, 7};
const unsigned SO_LUONG_TOI_DA = 256;

/* CÁC HÀM CẦN XÂY DỰNG */

// Chương trình chính
int main ();

// Hàm nhập
unsigned nhap ();

// Hàm xuất
void xuat (unsigned * danhsach, unsigned soluong);

// Hàm tách và xuất các siêu nguyên tố
void xuat (unsigned sieunguyento);

// Hàm kiểm tra siêu nguyên tố
void sieunguyento (unsigned * danhsach, unsigned & soluong, unsigned sochuso, unsigned batdau = 0);

// Hàm kiểm tra số nguyên tố
bool nguyentole (unsigned songuyenle);

/* NỘI DUNG */

int main () {
  unsigned sochuso = nhap();
  unsigned danhsach[SO_LUONG_TOI_DA];
  unsigned soluong;
  sieunguyento(danhsach, soluong, sochuso, 0);
  xuat(danhsach, soluong);
  return 0;
}

unsigned nhap () {
  unsigned n;
  cout << "Nhap so chu so (n > 1): ";
  cin >> n;
  if (n > 1) {
    return n;
  }
  cout << "Nhap sai. Nhap lai.\n";
  return nhap();
}

void xuat (unsigned * danhsach, unsigned soluong) {
  cout << "Co tong cong " << soluong << " sieu nguyen to co n chu so.\n";
  for (unsigned i = 0; i != soluong; ++i) {
    xuat(danhsach[i]);
  }
}

void xuat (unsigned sieunguyento) {
  while (sieunguyento) {
    cout << sieunguyento << ' ';
    sieunguyento /= 10;
  }
  cout << endl;
}

void sieunguyento (unsigned * danhsach, unsigned & soluong, unsigned sochuso, unsigned batdau) {
  if (sochuso) {
    soluong = 0;
    for (unsigned i = 0; i != SO_CHU_SO_NGUYEN_TO; ++i) {
      const unsigned batdaumoi = 10 * batdau + CHU_SO_NGUYEN_TO[i];
      if (nguyentole(batdaumoi)) {
        unsigned soluongthem;
        sieunguyento(danhsach + soluong, soluongthem, sochuso - 1, batdaumoi);
        soluong += soluongthem;
      }
    }
  } else {
    * danhsach = batdau;
    soluong = 1;
  }
}

bool nguyentole (unsigned songuyenle) {
  unsigned i = 3, e = sqrt(songuyenle);
  while (songuyenle % i && i < e) ++i;
  return i >= e;
}
