template <typename state_t>
ListPair<state_t>* copy(ListPair<state_t> const *src){
    if(!src) return nullptr;
    
    ListPair<state_t>* head = nullptr;
    ListPair<state_t>* tail = nullptr;
    
    try{
        while(src){
            state_t const& state = src->state;
            ListPair<state_t>* node = new ListPair<state_t>{state, nullptr};
            
            if(!head){
                head = node;
                tail = node;
            }
            else{
                tail->next_state = node;
                tail = node;
            }
            
            src = src->next_state;
        }
    }
    catch(...){
        while(head){
            ListPair<state_t>* next = head->next_state;
            delete head;
            head = next;
        }
        throw;
    }
    
    return head;
}
