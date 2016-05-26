// RUN: %clang_cc1 -triple x86_64-unk-unk -o - -emit-llvm -debug-info-kind=limited %s | FileCheck %s

namespace std { class A; }
using std::A; using ::A;


// CHECK: [[CompileUnit:![0-9]+]] = distinct !DICompileUnit({{.+}} imports: [[Imports:![0-9]+]])
// CHECK: [[Imports]] = !{[[ImportedEntity:![0-9]+]]}
// CHECK: [[ImportedEntity]] = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: [[CompileUnit]], entity: !"_ZTSSt1A", line: 4)

