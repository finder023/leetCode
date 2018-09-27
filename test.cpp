#include "llist.h"

int main(int argc, char const *argv[])
{
    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);
    l.push_front(2);
    l.push_front(1);
    List<int>::iterator it;
    for(it = l.begin(); it != l.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << l.front() << std::endl;
    std::cout << l.back() << std::endl;

    l.pop_back();
    l.pop_front();

    for(it = l.begin(); it != l.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    it = l.begin();
    l.insert(it, -1);
    it = l.erase(it);

    for(it = l.begin(); it != l.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;


}
