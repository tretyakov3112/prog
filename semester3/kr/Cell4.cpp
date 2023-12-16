#include <utility>

template <typename state_t>
std::unique_ptr<ListPair<state_t>> reverse_list(std::unique_ptr<ListPair<state_t>> head) {
    std::unique_ptr<ListPair<state_t>> prev = nullptr;
    std::unique_ptr<ListPair<state_t>> curr = std::move(head);
    while (curr) {
        std::unique_ptr<ListPair<state_t>> next = std::move(curr->next_state);
        curr->next_state = std::move(prev);
        prev = std::move(curr);
        curr = std::move(next);
    }
    return std::move(prev);
}

