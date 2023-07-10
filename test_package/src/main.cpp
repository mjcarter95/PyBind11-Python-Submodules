#include <pybind11/pybind11.h>

#include "maths/bindings.hpp"
#include "test/bindings.hpp"

PYBIND11_MODULE(test_package, m) {
    m.doc() = "Test package module";

    pybind11::module maths_module = m.def_submodule("maths", "Maths module");
    maths_module.def("add", &maths_add, "Add two integers");

    pybind11::module test_module = m.def_submodule("test", "Test module");
    test_module.def("add", &test_add, "Add two integers");
}
