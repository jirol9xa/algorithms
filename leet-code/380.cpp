#include <iterator>
#include <unordered_map>

using namespace std;

class RandomizedSet {
    unordered_map<int, int> map;
    int                     idx = 0;

  public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (!map[val]) {
            map[val]++;
            return true;
        }

        return false;
    }

    bool remove(int val)
    {
        if (map[val]) {
            map[val]--;
            return true;
        }

        return false;
    }

    int getRandom()
    {
        auto iter = map.begin();
        std::advance(iter, idx++ % map.size());
        return iter->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
