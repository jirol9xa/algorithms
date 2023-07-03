#include <ctime>
#include <iostream>
#include <list>
#include <random>
#include <string>
#include <string_view>

using List = std::list<int>;

void listDump(const List &lst, std::string_view lst_name = {})
{
    if (!lst_name.empty())
        std::cout << lst_name << ": ";

    for (auto &elem : lst)
        std::cout << elem << ' ';

    std::cout << '\n';
}

List mergeLists(List &first_lst, List &second_lst)
{
    List res;
    int  max_steps = first_lst.size() + second_lst.size();

    for (int i = 0; i < max_steps && !first_lst.empty() && !second_lst.empty(); ++i) {
        auto front1 = first_lst.front(), front2 = second_lst.front();

        if (front2 < front1) {
            res.push_back(front2);
            second_lst.pop_front();
            continue;
        }

        res.push_back(front1);
        first_lst.pop_front();
    }

    bool is_first_empty = first_lst.empty(), is_second_empty = second_lst.empty();
    if (is_first_empty && is_second_empty)
        return res;

    if (is_first_empty)
        res.splice(res.end(), second_lst);
    else
        res.splice(res.end(), first_lst);

    return res;
}

List sortList(List &lst)
{
    if (lst.size() == 1)
        return lst;

    auto iter = lst.begin();
    std::advance(iter, lst.size() / 2);

    List first_half = List(lst.begin(), iter), second_half = List(iter, lst.end());

    List first_sorted = sortList(first_half), second_sorted = sortList(second_half);

    return mergeLists(first_sorted, second_sorted);
}

List generateList(size_t mod_for_up_bnd)
{
    using std::rand;

    List lst;
    auto  upper_bound = rand() % mod_for_up_bnd;
    for (auto i = 0; i < upper_bound; ++i) {
        lst.push_back(rand() % 100);
    }

    return lst;
}

bool isListsEq(const List &first, const List &second)
{
    std::vector<int> first_vec(first.begin(), first.end()),
        second_vec(second.begin(), second.end());

    if (first_vec.size() != second_vec.size())
        return false;

    auto size = first_vec.size();
    for (size_t i = 0; i < size; ++i)
        if (first_vec[i] != second_vec[i])
            return false;

    return true;
}

int main()
{
#if 0
    List first = generateList(10), second = generateList(10);
    listDump(first, "first");
    listDump(second, "second");

    first.sort();
    second.sort();

    List merged = mergeLists(first, second);
    listDump(merged, "merged");

    List third = generateList();
    listDump(third, "third");

    List sorted = sortList(third);
    listDump(sorted, "sorted");

    listDump(third, "third");
#endif

    List lst = generateList(100000000);

    auto start  = std::clock();
    List sorted = sortList(lst);
    auto end    = std::clock();
    std::cout << "My own sort: " << end - start << '\n';

    start = clock();
    lst.sort();
    end = clock();
    std::cout << "Std sort: " << end - start << '\n';

    if (!isListsEq(sorted, lst))
        std::cout << "Wrong sort!!!\n";

    return 0;
}
