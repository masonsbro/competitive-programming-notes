#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

// line = pair<slope, y-intercept>
// line is max when intersect(prev, cur) <= x <= intersect(cur, next)
vector<pair<ll, ll> > lines;

// x-coordinate of intersection of line1 and line2
double intersect(pair<ll, ll> line1, pair<ll, ll> line2) {
    return (double) (line2.second - line1.second)/(line1.first - line2.first);
}

// get y value of line at some x
ll evaluate(pair<ll, ll> line, ll x) {
    return line.first * x + line.second;
}

// remove irrelevant lines and then add this one
void add_line(pair<ll, ll> line) {
    // in this case, adding increasing slopes from left to right
    while (lines.size() >= 2 && intersect(lines[lines.size()-2], line)
                              > intersect(lines[lines.size()-2], lines[lines.size()-1]))
        lines.pop_back();
    lines.push_back(line);
}

// get value of highest line at x
ll query(ll x) {
    // if only one line (rightmost), evaluate it
    if (lines.size() == 1)
        return evaluate(lines[0], x);
    // if x is at an extreme (left of intersection of leftmost and almost-leftmost lines)
    if (x < intersect(lines[lines.size()-1], lines[lines.size()-2]))
        return evaluate(lines[lines.size()-1], x);
    // binary search on lines (sorted in order of increasing slope)
    // l is the index of the visually right line, but left in array
    int l = -1, r = lines.size()-2, m;
    while (r - l > 1) {
        m = (l + r) / 2;
        // check intersection of m and m + 1
        if (x >= intersect(lines[m], lines[m+1]))
            r = m;
        else
            l = m;
    }
    return evaluate(lines[r], x);
}

int main() {

    add_line(make_pair(5, 10));
    add_line(make_pair(10, 3));
    query(3); // will return the value of the highest added line at x = 3

    return 0;

}
