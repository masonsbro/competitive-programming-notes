// FFT implementation from Stanford ICPC notebook
// https://web.stanford.edu/~liszt90/acm/notebook.html#file16

#include <iostream>
#include <cmath>

using namespace std;

struct cpx {
    cpx() {}
    cpx(double aa):a(aa),b(0) {}
    cpx(double aa, double bb):a(aa),b(bb) {}
    double a;
    double b;
    double modsq(void) const {
        return a * a + b * b;
    }
    cpx bar(void) const {
        return cpx(a, -b);
    }
};

cpx operator +(cpx a, cpx b) {
    return cpx(a.a + b.a, a.b + b.b);
}

cpx operator *(cpx a, cpx b) {
    return cpx(a.a * b.a - a.b * b.b, a.a * b.b + a.b * b.a);
}

cpx operator /(cpx a, cpx b) {
    cpx r = a * b.bar();
    return cpx(r.a / b.modsq(), r.b / b.modsq());
}

cpx EXP(double theta) {
    return cpx(cos(theta),sin(theta));
}

const double two_pi = 4 * acos(0);

void FFT(cpx *in, cpx *out, int step, int size, int dir) {
    if (size < 1) return;
    if (size == 1) {
        out[0] = in[0];
        return;
    }
    FFT(in, out, step * 2, size / 2, dir);
    FFT(in + step, out + size / 2, step * 2, size / 2, dir);
    for (int i = 0 ; i < size / 2 ; i++) {
        cpx even = out[i];
        cpx odd = out[i + size / 2];
        out[i] = even + EXP(dir * two_pi * i / size) * odd;
        out[i + size / 2] = even + EXP(dir * two_pi * (i + size / 2) / size) * odd;
    }
}

cpx arr1[1 << 21];
cpx arr2[1 << 21];

int main() {

    FFT(arr1, arr2, 1, 1 << 21, 1);
    FFT(arr2, arr1, 1, 1 << 21, -1);

    return 0;

}
