// RUN: not llvm-mc -triple aarch64 -filetype asm -o - %s 2>&1 | FileCheck %s

.arch armv9-a+sve2
.arch armv9-a+nosve2
tbx z0.b, z1.b, z2.b
// CHECK: error: instruction requires: sve2
// CHECK-NEXT: tbx z0.b, z1.b, z2.b

.arch armv9-a+sve2-aes
.arch armv9-a+nosve2-aes
aesd z23.b, z23.b, z13.b
// CHECK: error: instruction requires: sve2-aes
// CHECK-NEXT: aesd z23.b, z23.b, z13.b

.arch armv9-a+sve2-sm4
.arch armv9-a+nosve2-sm4
sm4e z0.s, z0.s, z0.s
// CHECK: error: instruction requires: sve2-sm4
// CHECK-NEXT: sm4e z0.s, z0.s, z0.s

.arch armv9-a+sve2-sha3
.arch armv9-a+nosve2-sha3
rax1 z0.d, z0.d, z0.d
// CHECK: error: instruction requires: sve2-sha3
// CHECK-NEXT: rax1 z0.d, z0.d, z0.d

.arch armv9-a+sve2-bitperm
.arch armv9-a+nosve2-bitperm
bgrp z21.s, z10.s, z21.s
// CHECK: error: instruction requires: sve2-bitperm
// CHECK-NEXT: bgrp z21.s, z10.s, z21.s
