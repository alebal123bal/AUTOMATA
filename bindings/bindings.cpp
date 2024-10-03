#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Monomial.h"
#include "MathConstants.h"
#include "MultivariablePolynomial.h"

namespace py = pybind11;

PYBIND11_MODULE(automata_bindings, m) {
    m.doc() = "pybind11 automata plugin"; // optional module docstring

    py::class_<Monomial>(m, "Monomial")
        .def(py::init<>())
        .def(py::init<double, const std::vector<int>&>())
        .def_readwrite("coefficient", &Monomial::coefficient)
        .def_readwrite("exponents", &Monomial::exponents)
        .def("__add__", &Monomial::operator+)
        .def("__sub__", &Monomial::operator-)
        //.def("__mul__", &Monomial::operator*)
        .def("__truediv__", &Monomial::operator/)
        .def("pow", &Monomial::pow)
        .def("__mul__", static_cast<Monomial (Monomial::*)(double) const>(&Monomial::operator*))
        .def("__eq__", &Monomial::operator==)
        .def("hasEqualExponents", &Monomial::hasEqualExponents)
        .def("isPureCoefficient", &Monomial::isPureCoefficient)
        .def("eval", &Monomial::eval)
        .def("print", &Monomial::print);

    py::class_<MultivariablePolynomial>(m, "MultivariablePolynomial")
        .def(py::init<>())
        .def(py::init<const std::vector<Monomial>&>())
        .def_readwrite("monomialVec", &MultivariablePolynomial::monomialVec)
        .def("addMonomial", static_cast<void (MultivariablePolynomial::*)(double, const std::vector<int>&)>(&MultivariablePolynomial::addMonomial))
        .def("addMonomial", static_cast<void (MultivariablePolynomial::*)(const Monomial&)>(&MultivariablePolynomial::addMonomial))
        .def("__add__", &MultivariablePolynomial::operator+)
        .def("__sub__", &MultivariablePolynomial::operator-)
        .def("__mul__", &MultivariablePolynomial::operator*)
        .def("__truediv__", &MultivariablePolynomial::operator/)
        .def("pow", &MultivariablePolynomial::pow)
        .def("__eq__", &MultivariablePolynomial::operator==)
        .def("cleanup", &MultivariablePolynomial::cleanup)
        .def("eval", &MultivariablePolynomial::eval)
        .def("print", &MultivariablePolynomial::print)
        .def("isPureCoefficientPoly", &MultivariablePolynomial::isPureCoefficientPoly);
}