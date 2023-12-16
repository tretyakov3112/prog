enum class CellState {A, B};

struct Cell {
    virtual void flip() = 0;
    virtual CellState current() const = 0;
    virtual ~Cell() { }
};


void bulk_flip(Cell **begin_cells, Cell **end_cells) {
    for (auto it = begin_cells; it != end_cells; ++begin_cells)
        (*it)->flip();
}

class ABLoopCell : public Cell {
public:
    ABLoopCell(CellState initial_state) : state(initial_state) {}
    void flip() override {
        state = (state == CellState::A) ? CellState::B : CellState::A;
    }
    
    CellState current() const override {
        return state;
    }
    
private:
    CellState state;
};

class ABDeadCell : public Cell {
public:
    ABDeadCell(CellState initial_state) : state(initial_state) {}
    void flip() override {
        state = CellState::B;
    }
    
    CellState current() const override { 
        return state;
    }
    
private:
    CellState state;
};

class BADeadCell : public Cell {
public:
    BADeadCell(CellState initial_state) : state(initial_state) {}
    void flip() override {
        state = CellState::A;
    }
    
    CellState current() const override {
        return state;
    }
    
private:
    CellState state;
};
