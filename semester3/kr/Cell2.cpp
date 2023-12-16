#include <utility>
#include <ostream>

template <typename state_t>
struct Cell {
    virtual void flip() = 0;
    virtual state_t current() const = 0;
    virtual ~Cell() { }
};

template <typename state_t>
class LoggerCell : public Cell<state_t> {
public:
    LoggerCell(std::ostream &output, std::unique_ptr<Cell<state_t>> cell)
        : output_(output), cell_(std::move(cell)), current_state_(cell_->current()) {}

    void flip() override {
        cell_->flip();
        state_t new_state = cell_->current();
        output_ << "[" << current_state_ << " > " << cell_->current() << "]";
        current_state_ = new_state;
    }
    

    state_t current() const override {
        return cell_->current();
    }
    

private:
    std::ostream &output_;
    std::unique_ptr<Cell<state_t>> cell_;
    state_t current_state_;
};

template <typename state_t>
std::unique_ptr<Cell<state_t>> wrap_into_logger(std::ostream &output, std::unique_ptr<Cell<state_t>> cell) {
    return std::make_unique<LoggerCell<state_t>>(output, std::move(cell));
}