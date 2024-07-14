#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "MultivariablePolynomial.h"

namespace py = pybind11;

PYBIND11_MODULE(polymodule, m) {
    py::class_<Monomial>(m, "Monomial")
        .def(py::init<double, const std::vector<int>&>())
        .def("print", &Monomial::print);

    py::class_<MultivariablePolynomial>(m, "MultivariablePolynomial")
        .def(py::init<>())
        .def("addMonomial", (void (MultivariablePolynomial::*)(double, const std::vector<int>&)) &MultivariablePolynomial::addMonomial)
        .def("operator+", &MultivariablePolynomial::operator+)
        .def("operator-", &MultivariablePolynomial::operator-)
        .def("operator*", &MultivariablePolynomial::operator*)
        .def("operator/", &MultivariablePolynomial::operator/)
        .def("print", &MultivariablePolynomial::print);

    m.def("create_polynomial", []() {
        return MultivariablePolynomial();
    });
}