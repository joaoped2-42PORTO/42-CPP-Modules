//
// Created by joaoped2 on 3/21/24.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(std::vector<int> vector) : _vec(vector), _deq(vector.begin(), vector.end()) {
    std::cout << "Before: ";
    std::vector<int>::iterator it;
    for (it = _vec.begin(); it != _vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    sortCont();
}

PmergeMe::PmergeMe(const PmergeMe &cpy) : _vec(cpy._vec), _deq(cpy._deq) {

}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy) {
    if (this == &cpy)
        return (*this);
    this->_vec = cpy._vec;
    this->_deq = cpy._deq;
    return (*this);
}

PmergeMe::~PmergeMe() {

}

void	PmergeMe::printVec(void)
{
    std::vector<int>::iterator it;
    std::cout << "After: ";
    for(it = _vec.begin(); it < _vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::sortCont() {
    clock_t startV = clock();
    mergeVec(_vec);//algorithm for vector
    clock_t endV = clock();
    double timeV = 1000.0 * (endV - startV) / CLOCKS_PER_SEC;  // Convert to microseconds
    printVec();
    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector: " << timeV << " us";
    std::cout << std::endl;
    clock_t startD = clock();
    mergeDec(_deq);
    clock_t endD = clock();
    double timeD = 1000.0 * (endD - startD) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << timeD << " us" << std::endl;
}


void PmergeMe::mergeVec(std::vector<int>& vec)
{
    if (vec.size() == 1)
        return ;

    int middle = vec.size() / 2;

    std::vector<int> left = std::vector<int>(vec.begin(), vec.begin() + middle);
    std::vector<int> right = std::vector<int>(vec.begin() + middle, vec.end());

    mergeVec(left);
    mergeVec(right);
    sortMergeVec(left, right, vec);
}

void PmergeMe::sortMergeVec(std::vector<int>& left, std::vector<int>& right, std::vector<int>& vec)
{
    size_t l = 0, r = 0, i = 0;

    while (l < left.size() && r < right.size())
    {
        if (left[l] < right[r])
        {
            vec[i] = left[l];
            i++;
            l++;
        }
        else
        {
            vec[i] = right[r];
            i++;
            r++;
        }
    }

    while (l < left.size())
    {
        vec[i] = left[l];
        i++;
        l++;
    }
    while (r < right.size())
    {
        vec[i] = right[r];
        i++;
        r++;
    }
}

void PmergeMe::mergeDec(std::deque<int> &vector) {
    if (vector.size() == 1)
        return ;

    int middle = vector.size() / 2;

    std::deque<int> left = std::deque<int>(vector.begin(), vector.begin() + middle);
    std::deque<int> right = std::deque<int>(vector.begin() + middle, vector.end());

    mergeDec(left);
    mergeDec(right);
    sortMergeDec(left, right, vector);
}

void PmergeMe::sortMergeDec(std::deque<int>& left, std::deque<int>& right, std::deque<int> &vector) {
    size_t l = 0, r = 0, i = 0;

    while (l < left.size() && r < right.size()) {
        if (left[l] < right[r]) {
            vector[i] = left[l];
            i++;
            l++;
        }
        else {
            vector[i] = right[r];
            i++;
            r++;
        }
    }

    while (l < left.size()) {
        vector[i] = left[l];
        i++;
        l++;
    }
    while (r < right.size()) {
        vector[i] = right[r];
        i++;
        r++;
    }
}