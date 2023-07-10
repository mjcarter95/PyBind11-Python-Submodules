#include <pybind11/pybind11.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

class Maths {
private:
    int add(int i, int j) {
        return i + j;
    }

public:
    static void bind(py::module& module) {
        py::class_<Maths>(module, "Maths")
            .def(py::init<>())
            .def("add", &Maths::add, R"pbdoc(
                Add two numbers

                Some other explanation about the add function.
            )pbdoc");
    }
};

class Test {
private:
    int add(int i, int j) {
        return i + j;
    }

public:
    static void bind(py::module& module) {
        py::class_<Test>(module, "Test")
            .def(py::init<>())
            .def("add", &Test::add, R"pbdoc(
                Add two numbers

                Some other explanation about the add function.
            )pbdoc");
    }
};

PYBIND11_MODULE(test_package, m) {
    py::module maths = m.def_submodule("maths", "A peon is a submodule of 'ork'");
    Maths::bind(maths);
    py::module test = m.def_submodule("test", "A peon is a submodule of 'ork'");
    Test::bind(test);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
