#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> Point;

double Dist(const Point& x, const Point& y) {
    return sqrt((x.first - y.first) * (x.first - y.first) +
                (x.second - y.second) * (x.second - y.second));
}

double FindMinDist(Point* points, int n) {
    double min_dist = DBL_MAX;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            min_dist = min(min_dist, Dist(points[i], points[j]));

    return min_dist;
}

double StripClosest(Point* strip, int size, double max_dist) {
    double min_dist = max_dist;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1;
             j < size && (strip[j].second - strip[i].second) < min_dist;
             j++)
            min_dist = min(min_dist, Dist(strip[i], strip[j]));
    }

    return min_dist;
}

double ClosestUtil(Point* px, Point* py, int n) {
    if (n <= 3)
        return FindMinDist(px, n);

    int mid = n / 2;
    Point mid_point = px[mid];

    Point py_left[mid + 1];
    Point py_right[n - mid - 1];
    int left_idx = 0, right_idx = 0;

    for (int i = 0; i < n; i++) {
        if (py[i].first <= mid_point.first)
            py_left[left_idx++] = py[i];
        else
            py_right[right_idx++] = py[i];
    }

    double left_dist = ClosestUtil(px, py_left, mid);
    double right_dist = ClosestUtil(px + mid, py_right, n - mid);

    double min_left_right = min(left_dist, right_dist);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(py[i].first - mid_point.first) < min_left_right) {
            strip[j] = py[i];
            j++;
        }
    }

    return min(min_left_right, StripClosest(strip, j, min_left_right));
}

double Closest(Point* points, int n) {
    Point px[n];
    Point py[n];
    for (int i = 0; i < n; i++) {
        px[i] = points[i];
        py[i] = points[i];
    }

    sort(px, px + n, [](const Point& p, const Point& q) {
        return p.first < q.first;
    });

    sort(py, py + n, [](const Point& p, const Point& q) {
        return p.second < q.second;
    });

    return ClosestUtil(px, py, n);
}

int main() {
    vector<Point> vp;
    vp.push_back(make_pair(2, 3));
    vp.push_back(make_pair(12, 30));
    vp.push_back(make_pair(40, 50));
    vp.push_back(make_pair(5, 1));
    vp.push_back(make_pair(12, 10));
    vp.push_back(make_pair(3, 4));

    Point p[vp.size()];
    copy(vp.begin(), vp.end(), p);
    int n = sizeof(p) / sizeof(p[0]);

    cout << Closest(p, n) << endl;

    return 0;
}
