#include <iostream>

using namespace std;

long long mod = (5 << 25) + 1;
long long gen = 243;
long long temp[1 << 23];
int levels = 21;

unsigned int bitReverse(unsigned int x, int log2n) {
    int n = 0;
    for (int i=0; i < log2n; i++) {
        n <<= 1;
        n |= (x & 1);
        x >>= 1;
    }
    return n;
}

void setupNTT() {
    int ww = 25;
    while (ww-- > levels) {
        gen = gen * gen % mod;
    }
}

void transform(long long *b, long long *a, int l, long long gen) {
    int len = 1 << l;
    for (int i = 0; i < len; i++) a[i] = b[i];
    for (unsigned int i = 0; i < len; i++) {
        unsigned int j = bitReverse(i, l);
        if (j < i) {
            a[i] ^= a[j];
            a[j] ^= a[i];
            a[i] ^= a[j];
        }
    }
    long long roots[32];
    roots[levels] = gen;
    for (int i = levels-1; i >= 0; i--) {
        roots[i] = roots[i+1] * roots[i+1] % mod;
    }
    for (int i = 1, hs = 1; (1 << i) <= len; i++, hs <<= 1) {
        temp[0] = 1;
        for (int j = 1; j < hs; j++) temp[j] = temp[j-1] * roots[i] % mod;
        for (int j = 0; j < len; j += (1 << i)) {
            for (int k = j; k < j + hs; k++) {
                long long tre = a[k + hs] * temp[k-j] % mod;
                a[k + hs] = a[k] + mod - tre;
                if (a[k + hs] >= mod) a[k + hs] -= mod;
                a[k] += tre;
                if (a[k] >= mod) a[k] -= mod;
            }
        }
    }
}

long long inv(long long N, long long M) {
    long long x = 0;
    long long lastx = 1;
    long long y = 1;
    long long lasty = 0;
    long long q, t;
    long long a = N;
    long long b = M;
    while (b != 0) {
        q = a / b;
        t = a % b;
        a = b;
        b = t;
        t = x;
        x = lastx - q * x;
        lastx = t;
        t = y;
        y = lasty - q * y;
        lasty = t;
    }
    return (lastx + M) % M;
}

int arr1[1 << 21];
int arr2[1 << 21];

int main() {

    transform(arr1, arr2, gen);
    transform(arr2, arr1, inv(gen, mod));
    // result of inverse scaled by N... multiply by inv(N, mod) (and mod) to fix

    return 0;

}
