#include <algorithm>
#include <iostream>
#include <list>
#include <utility>

using namespace std;

class LRUCache {
    using type = pair<int, int>;

    list<type> lst;
    int        capacity;

  public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        auto key_iter =
            std::find_if(lst.begin(), lst.end(),
                         [=](std::pair<int, int> elem) { return elem.first == key; });

        if (key_iter == lst.end())
            return -1;

        auto res = key_iter->second;
        std::rotate(key_iter, std::next(key_iter), lst.end());

        return res;
    }

    void put(int key, int value)
    {
        auto key_iter =
            std::find_if(lst.begin(), lst.end(),
                         [=](std::pair<int, int> elem) { return elem.first == key; });

        if (key_iter == lst.end()) {
            if (!lst.empty() && lst.size() == capacity)
                lst.pop_front();
            lst.emplace_back(key, value);
            return;
        }

        key_iter->second = value;
        std::rotate(key_iter, std::next(key_iter), lst.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << '\n';
    cache.put(3, 3);
    std::cout << cache.get(2) << '\n';

    return 0;
}
