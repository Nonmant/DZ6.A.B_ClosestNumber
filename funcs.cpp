//https://contest.yandex.ru/contest/27844/problems/B/

#include "funcs.h"
#include <bits/stdc++.h>

//! @brief Index of last less. If everything is more return 0
size_t binSearchLowerBound(std::vector<int> & vector, int value){
    if(vector.empty())
        return 0;
    size_t left = 0,
        right = vector.size()-1;
    while (left<right){
        size_t cur = (left + right + 1)/2;
        if(vector[cur]<value){
            left = cur;
        } else {
            right = cur-1;
        }
    }
    return right;
}

void parseFile(std::istream & input, std::ostream & output){

    int n, k;
    input >> n >> k;
    std::vector<int> source(n), search(k);

    std::copy_n(std::istream_iterator<int>(input), n, source.begin());
    std::copy_n(std::istream_iterator<int>(input), k, search.begin());

    long long int diff1,diff2;
    int ans;
    for(auto a: search){
        auto index = binSearchLowerBound(source,a);
        if(index == source.size()-1){
            if(source.size()>1){
                diff1 = (long long int)(a) - (long long int)(source[index-1]);
                diff2 = (long long int)(a) - (long long int)(source[index]);
                if(std::abs(diff1) <= std::abs(diff2)){
                    ans = source[index-1];
                } else {
                    ans = source[index];
                }
            } else {
                ans = source[index];
            }
        } else {
            diff1 = (long long int)(a) - (long long int)(source[index]);
            diff2 = (long long int)(a) - (long long int)(source[index+1]);
            if(std::abs(diff1) <= std::abs(diff2)){
                ans = source[index];
            } else {
                ans = source[index+1];
            }
        }
        output << ans << '\n';
    }
}
