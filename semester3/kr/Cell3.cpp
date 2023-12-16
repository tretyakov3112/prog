template<typename state_t>
        struct ListPair final {
            state_t const state;
            ListPair<state_t> *next_state;
        };


template <typename state_t, typename... Args>
ListPair<state_t>* make_list_from_arguments(Args&&... states){
    ListPair<state_t>* head = nullptr;
    
    auto add_state = [&](const state_t& state) {
        head = push_list(head, state);
    };
    
    (void)std::initializer_list<int>{(add_state(std::forward<Args>(states)), 0)...};
    
    return reverse_list(head);
}

