#include <iterator>
#include <unordered_set>

using namespace std;

class RandomizedSet {
    unordered_set<int> set;
    int                idx = 0;

  public:
    RandomizedSet() {}

    bool insert(int val) { return set.insert(val).second; }

    bool remove(int val)
    {
        if (auto iter = set.find(val); iter != set.end()) {
            set.erase(iter);
            return true;
        }

        return false;
    }

    int getRandom()
    {
        auto iter = set.begin();
        std::advance(iter, std::rand() % set.size());
        return *iter;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
