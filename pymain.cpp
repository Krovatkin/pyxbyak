#include <pybind11/pybind11.h>
#include <xbyak/xbyak.h>

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(pyxbyak, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    pybind11::enum_<Xbyak::Operand::Kind>(m, "OperandKind")
        .value("NONE", Xbyak::Operand::Kind::NONE)
        .value("MEM", Xbyak::Operand::Kind::MEM)
        .value("REG", Xbyak::Operand::Kind::REG)
        .value("MMX", Xbyak::Operand::Kind::MMX)
        .value("FPU", Xbyak::Operand::Kind::FPU)
        .value("XMM", Xbyak::Operand::Kind::XMM)
        .value("YMM", Xbyak::Operand::Kind::YMM)
        .value("ZMM", Xbyak::Operand::Kind::ZMM)
        .export_values();

    pybind11::class_<Xbyak::Operand>(m, "Operand");
    pybind11::class_<Xbyak::Reg64, Xbyak::Operand>(m, "Reg64");

    pybind11::class_<Xbyak::CodeGenerator>(m, "CodeGenerator")
        .def(pybind11::init<>())
        .def("ret", &Xbyak::CodeGenerator::ret)
        .def_readonly("rax", &Xbyak::CodeGenerator::rax)
        // .def("rax2", [](Xbyak::CodeGenerator& cg) -> const Xbyak::Operand {
        //     return cg.rax;
        // })
        .def("xor", pybind11::overload_cast<const Xbyak::Operand&, const Xbyak::Operand&>(&Xbyak::CodeGenerator::xor_))
        .def("getCode", [](Xbyak::CodeGenerator& cg) {
            return cg.getCode();
        });
}