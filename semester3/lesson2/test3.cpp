#include <iostream>
#include <iomanip>
// omega * omega - 1 - k * k = 0;
double implicit_dispersion_relation_A(double omega, double k) {
    return omega * omega - k * k - 1;
}

// omega^2 - k^2 - a * k^3 - 1 = 0;
double implicit_dispersion_relation_B(double omega, double k, double alpha) {
    return omega * omega - k * k - alpha * k * k * k - 1;
}

// здесь идёт ваш код ...
struct DispersionRelation {
  virtual double operator()(double omega) const = 0;
  virtual ~DispersionRelation() { }
};

double dichotomy_solver(double a, double b, DispersionRelation const &dr, double tolerance);

class DispersionRelationA : public DispersionRelation {
public:
    DispersionRelationA(double k) : k(k) {}
    double operator()(double omega) const override {
        return implicit_dispersion_relation_A(omega, k);
    }
private:
    double k;
};

class DispersionRelationB : public DispersionRelation {
public:
    DispersionRelationB(double k, double alpha) : k(k), alpha(alpha) {}
    double operator()(double omega) const override {
        return implicit_dispersion_relation_B(omega, k, alpha);
    }
private:
    double k;
    double alpha;
};

DispersionRelation const * construct_dispersion_relation_A(double k) {
    return new DispersionRelationA(k);
}
DispersionRelation const * construct_dispersion_relation_B(double k, double alpha) {
    return new DispersionRelationB(k, alpha);
}

int main() {
  DispersionRelation const *dr1 = construct_dispersion_relation_A(1.0);
  DispersionRelation const *dr2 = construct_dispersion_relation_B(1.0, 2.0);
  auto dr1_actual = dichotomy_solver(0., 2.0, *dr1, 1.0e-5);
  auto dr2_actual = dichotomy_solver(1., 3.0, *dr2, 1.0e-5); 
  delete dr1; delete dr2;
  std::cout << std::setprecision(2) << std::fixed << dr1_actual << ' ' << dr2_actual;
  return 0;
}