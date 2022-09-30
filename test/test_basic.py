import sys
sys.path.append("build")
import pyxbyak

def test_import_codegen():
    cg = pyxbyak.CodeGenerator()
    assert cg is not None
    assert type(cg).__name__ == "CodeGenerator"