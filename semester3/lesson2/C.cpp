#include<iostream>

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() = default;
};

struct Number : Expression
{
public:    
    Number(double value)
        : value(value)
    {}
    double evaluate() const override
    {
        return value;
    }

    ~Number() {}
private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    { }

    double evaluate() const override
    {
        if (left != nullptr and right != nullptr)
        {
                if (op == '+')
            {
                return (left->evaluate() + right->evaluate());
            } else if (op == '-')
            {
                return (left->evaluate() - right->evaluate());
            } else if (op == '/' and right->evaluate() != 0)
            {
                return (left->evaluate() / right->evaluate());
            } else
            {
                return (left->evaluate() * right->evaluate());
            } 
        
        } else return 0;
    }

    ~BinaryOperation() 
    {
        delete left;
        delete right;
    }

private:
    Expression const * left;
    char op;
    Expression const * right;
};

int main() 
{
    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    // потом используем его в выражении для +
    Expression * expr = new BinaryOperation(new Number(3), '+', sube);

    // вычисляем и выводим результат: 25.5
    std::cout << expr->evaluate() << std::endl;

    // тут освобождаются *все* выделенные объекты
    // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;
    return 0;
}