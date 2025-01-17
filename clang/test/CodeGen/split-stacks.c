// Start Fujitsu Extension: 3-D-003
// RUN: %clang -ffj-no-line -target x86_64-linux-gnu -fsplit-stack -S %s -emit-llvm -o - | FileCheck -check-prefix=CHECK-SEGSTK %s
// RUN: %clang -ffj-no-line -target x86_64-linux-gnu -S %s -emit-llvm -o - | FileCheck -check-prefix=CHECK-NOSEGSTK %s
// End Fujitsu Extension: 3-D-003

int foo() {
  return 0;
}

__attribute__((no_split_stack))
int nosplit() {
  return 0;
}

int main() {
  return foo();
}

// CHECK-SEGSTK: define dso_local i32 @foo() [[SS:#[0-9]+]] {
// CHECK-SEGSTK: define dso_local i32 @nosplit() [[NSS:#[0-9]+]] {
// CHECK-SEGSTK: define dso_local i32 @main() [[SS]] {
// CHECK-SEGSTK-NOT: [[NSS]] = { {{.*}} "split-stack" {{.*}} }
// CHECK-SEGSTK: [[SS]] = { {{.*}} "split-stack" {{.*}} }
// CHECK-SEGSTK-NOT: [[NSS]] = { {{.*}} "split-stack" {{.*}} }

// CHECK-NOSEGSTK: define dso_local i32 @foo() #0 {
// CHECK-NOSEGSTK: define dso_local i32 @main() #0 {
// CHECK-NOSEGSTK-NOT: #0 = { {{.*}} "split-stack" {{.*}} }
