#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <future>

template <typename SrcIter, typename DstIter, typename Func>
auto par_transform(SrcIter first, SrcIter last, DstIter dst, Func f) {

    auto n = static_cast<size_t>(std::distance(first, last));
    auto num_tasks = size_t(std::max(std::thread::hardware_concurrency(), 1u));
    auto chunk_sz = std::max(size_t(n / num_tasks), 1ul);
    auto futures = std::vector<std::future<void>>{};
    futures.reserve(num_tasks);

    for (size_t task_idx = 0; task_idx < num_tasks; ++task_idx) {
        auto start_idx = chunk_sz * task_idx;
        auto stop_idx = std::min(chunk_sz * (task_idx + 1), n);
        auto fut = std::async([first, dst, start_idx, stop_idx, &f](){
            std::transform(first + start_idx, first + stop_idx, dst + start_idx, f);
        });
        futures.emplace_back(std::move(fut));
    }   

    for (auto& fut : futures) {
        fut.wait();
    }
}

int main() {
    
}