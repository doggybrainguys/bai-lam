// Sử dụng C-Free 5
// Giải thuật Quay lui

#include <iostream> // cin, cout, endl
#include <cstdlib> // srand, rand
#include <ctime> // time

using namespace std;

/* CÁC HẰNG SỐ */

const unsigned SOHAUCANDAT = 8;
const unsigned TRONGSOTOIDA = 10;

/* KIỂU DỮ LIỆU */

struct QuanCo;
struct BanCo;
struct DauVet;
struct CSDL;
struct ToaDo;

struct QuanCo {
  bool chiem;
  unsigned trongso;
};

struct BanCo {
  static const unsigned KICHTHUOC = 8;
  static const unsigned SOQUANCO = KICHTHUOC * KICHTHUOC;
  union {
    QuanCo luoi[KICHTHUOC][KICHTHUOC];
    QuanCo day[SOQUANCO];
  } quanco; // 'luoi' và 'day' thực ra là một, cùng chiếm 1 vùng nhớ, chỉ khác về số chiều
};

struct DauVet {
  static const unsigned KICHTHUOC = BanCo::KICHTHUOC;
  typedef bool Mang[KICHTHUOC];
  Mang ngang, doc, cheothuan, cheongich;
};

struct CSDL {
  BanCo banco;
  DauVet dauvet;
};

struct ToaDo {
  unsigned x, y;
  ToaDo (unsigned _x = 0, unsigned _y = 0): x(_x), y(_y) {}
};

/* CÁC HÀM CẦN XÂY DỰNG */

// Chương trình chính
int main ();

// Các hàm khởi tạo
void khoitao (CSDL & csdl);
void khoitao (BanCo & banco);
void khoitao (DauVet & dauvet);

// Các hàm xuất
void xuat (CSDL csdl);
void xuat (BanCo banco);

// Các hàm tính toán
void giaibaitoan (CSDL & csdl, unsigned soluong);
void datquanhau (CSDL & csdl, unsigned & trongso, unsigned soluong);
bool kiemtra (DauVet dauvet, ToaDo taodo);

// Các hàm tiện ích
unsigned ngaunhien (unsigned max);
template <typename GiaTri> void xoamang (GiaTri * mang, unsigned dodai, GiaTri giatri);

/* NỘI DUNG */

int main () {
  CSDL csdl;
  srand(time(NULL));
  khoitao(csdl);
  giaibaitoan(csdl, SOHAUCANDAT);
  xuat(csdl);
  return 0;
}

void khoitao (CSDL & csdl) {
  khoitao(csdl.banco);
  khoitao(csdl.dauvet);
}

void khoitao (BanCo & banco) {
  for (QuanCo * i = banco.quanco.day, * e = i + BanCo::SOQUANCO; i != e; ++i) {
    i->chiem = false;
    i->trongso = ngaunhien(TRONGSOTOIDA);
  }
}

void khoitao (DauVet & dauvet) {
  xoamang(dauvet.ngang, DauVet::KICHTHUOC, false);
  xoamang(dauvet.doc, DauVet::KICHTHUOC, false);
  xoamang(dauvet.cheothuan, DauVet::KICHTHUOC, false);
  xoamang(dauvet.cheongich, DauVet::KICHTHUOC, false);
}

void xuat (CSDL csdl) {
  xuat(csdl.banco);
}

void xuat (BanCo banco) {
  unsigned tongtrongso = 0;
  cout << "Ban co:\n";
  for (unsigned i = 0; i != BanCo::KICHTHUOC; ++i) {
    for (unsigned j = 0; j != BanCo::KICHTHUOC; ++j) {
      const QuanCo * const quanco = & banco.quanco.luoi[i][j];
      cout << ' ';
      if (quanco->chiem) {
        cout << '*';
        tongtrongso += quanco->trongso;
      } else {
        cout << '.';
      }
      cout << quanco->trongso;
    }
    cout << endl;
  }
  cout << "Tong trong so (n): " << tongtrongso << endl;
  cout <<
    "Chu thich:\n"
    " - Con trong:  .n\n"
    " - Co hau:     *n\n"
  ;
}

void giaibaitoan (CSDL & csdl, unsigned soluong) {
  unsigned trongso = 0;
  datquanhau(csdl, trongso, soluong);
}

void datquanhau (CSDL & csdl, unsigned & trongso, unsigned soluong) {
  CSDL csdlmoi = csdl;
  unsigned trongsothem = 0;
  for (unsigned x = 0; x != BanCo::KICHTHUOC; ++x) {
    for (unsigned y = 0; y != BanCo::KICHTHUOC; ++y) {
      const ToaDo toado(x, y);
      CSDL csdlss = csdl;

    }
  }
  csdl = csdlmoi;
  trongso += trongsothem;
}

unsigned ngaunhien (unsigned max) {
  return max * rand() / RAND_MAX;
}

template <typename GiaTri>
void xoamang (GiaTri * mang, unsigned dodai, GiaTri giatri) {
  for (GiaTri * i = mang, * e = mang + dodai; i != e; ++i) {
    * i = giatri;
  }
}
