#include <iostream>
#include <vector>
//в данной реализации индексация с 1


template<typename T>
class Segment_Tree {
    std::vector<T> tree;
    std::vector<T> arr;
    void build (int w, int left, int right) {
        //w - номер вершины в графе
        if (left + 1 == right) {
            tree[w] = arr[left];
            return;
        }
        int m = (left+right) / 2;
        build(2 * w, left, m);
        build(2 * w + 1, m, right);
        tree[w] = tree[2*w] + tree[2*w + 1];
    }

public:
    Segment_Tree(const std::vector<T>& v) {
        this->arr = arr;
        int k = 1;
        while (this->arr.size() > k) {
            k *= 2;
        }
        while (this->arr.size() < k) {
            this->arr.emplace_back(0);
        }
        tree.assign(4 * arr.size(), 0);
    }
};

int main() {
    std::vector<int> v = {3, -1, 2, 3, -2, 5, 1, 4};
};