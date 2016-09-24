// Dùng C-Free 5
// Giải thuật Tham lam

#include <iostream> // cin, cout, endl
#include <algorithm> // swap

using namespace std;

/* CÁC HÀM CẦN XÂY DỰNG */

// Chương trình chính
int main ();

// Nhập, xuất
void nhap (unsigned & sotien, unsigned * & menhgia, unsigned & soloai);
void xuat (unsigned * menhgia, unsigned * soto, unsigned soloai);
void xuat ();

// Chia tiền
bool chiatien (unsigned * & soto, unsigned * menhgia, unsigned soloai, unsigned sotien);

// Tiện ích
void sapxep (unsigned * menhgia, unsigned soluong);

/* NỘI DUNG */

int main () {
  unsigned sotien, soloai, * menhgia, * soto;
  nhap (sotien, menhgia, soloai);
  if (chiatien (soto, menhgia, soloai, sotien)) {
    xuat(menhgia, soto, soloai);
  } else {
    xuat();
  }
  delete [] menhgia;
  delete [] soto;
  return 0;
}

void nhap (unsigned & sotien, unsigned * & menhgia, unsigned & soloai) {
  cout << "Nhap so tien: ";
  cin >> sotien;
  cout << "Nhap so menh gia: ";
  cin >> soloai;
  cout << "Nhap tung menh gia: ";
  menhgia = new unsigned[soloai];
  for (unsigned i = 0; i != soloai; ++i) {
    cin >> menhgia[i];
  }
}

void xuat (unsigned * menhgia, unsigned * soto, unsigned soloai) {
  unsigned tongsoto = 0;
  cout << "Danh sach cac to can doi (MenhGia x SoTo):\n";
  for (unsigned i = 0; i != soloai; ++i) {
    unsigned & mg = menhgia[i], & st = soto[i];
    cout << " + " << mg << " x " << st << " = " << (mg * st) << endl;
    tongsoto += st;
  }
  cout << "Tong so to: " << tongsoto << endl;
}

void xuat () {
  cout << "Het tien le!\n";
}

bool chiatien (unsigned * & soto, unsigned * menhgia, unsigned soloai, unsigned sotien) {
  unsigned i = 0;
  soto = new unsigned[soloai];
  sapxep(menhgia, soloai);
  while (sotien && i != soloai) {
    soto[i] = sotien % menhgia[i];
    sotien /= menhgia[i];
    ++i;
  }
  return i != soloai;
}

void sapxep (unsigned * menhgia, unsigned soloai) {
  for (unsigned i = 0; i != soloai; ++i)
    for (unsigned j = i; j != soloai; ++j)
      if (menhgia[i] < menhgia[j])
        swap(menhgia[i], menhgia[j])
}
