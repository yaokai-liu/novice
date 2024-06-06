# x64-64 assembly script

.globl      getSum
.type       getSum, @function
.text
# @returns: $rax
# @params: _dest=$rdi, _count=$rsi
getSum:
    .cfi_startproc
    testq   %rsi, %rsi
    jz      getSum.L1
    salq    $3, %rsi
    add     %rdi, %rsi
    xor     %rax, %rax
getSum.L0:
    movq    0(%rdi), %rcx
    add     %rcx, %rax
    add     $8, %rdi
    cmp     %rsi, %rdi
    jl      getSum.L0
    ret
getSum.L1:
    xor     %rax, %rax
    ret
    .cfi_endproc
