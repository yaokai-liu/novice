# x64-64 assembly script

.globl      _qsort
.type       _qsort, @function
.section    .text
# @return:
# @params: _nums=$rdi, _count=$rsi, _ele_size=$rdx, _fn_cmp=$rcx
_qsort:
#   _qsort(void *, size_t, size_t, int (*)(const void *, const void *)) {
    .cfi_startproc

#   if (!_nums || _count < 1 || _ele_size < 1 || !_fn_cmp) { return ; }
    cmp     $0,     %rdi
    je      _qsort.ret_directly
    cmp     $1,     %rsi
    jle     _qsort.ret_directly
    cmp     $1,     %rdx
    jl      _qsort.ret_directly
    cmp     $0,     %rcx
    je      _qsort.ret_directly

    pushq   %r12
    pushq   %r13
    pushq   %r14
    pushq   %r15

    pushq   %rbp
    movq    %rsp,   %rbp
    subq    $0x40,  %rsp

#   char * lower_bound = (char *)_nums;
#   char * left=lower_bound;
    movq    %rdi,   %r12    # left = %r12

#   char * upper_bound = (char *)_nums + (_count - 1) * _ele_size;
#   char * right = upper_bound;
    movq    %rsi,   %r13
    subq    $1,     %r13
    movq    %rdx,   %r15    #   _ele_size = %r15
    movq    %rdx,   %rax
    xorq    %rdx,   %rdx
    mul     %r13
    add     %rdi,   %rax
    movq    %rax,   %r13    #   right = %r13

    movq    %rdi,   0x00(%rsp)     # push lower_bound
    movq    %rax,   0x08(%rsp)     # push upper_bound
    movq    %rcx,   0x10(%rsp)     # push _fn_cmp

#   char * base = (char *)alloca(_ele_size);
    movq    %r15,   %rax
    subq    $1,     %rax
    shrq    $4,     %rax
    addq    $1,     %rax
    shlq    $4,     %rax
    movq    %rsp,   %r14           # store sp
    sub     %rax,   %rsp           # base = %rsp

#   memcpy(base, left, _ele_ssize);
    movq    %rsp,   %rdi
    movq    %r12,   %rsi
    movq    %r15,   %rdx
    call    memcpy

#   while ( left < right ) {
#   while ( left < right && _fn_cmp(right, base) >= 0 ) {
_qsort.L0:
    cmp     %r13,   %r12
    jge     _qsort.L0_end
    movq    %r13,   %rdi
    movq    %rsp,   %rsi
    movq    0x10(%r14),    %rcx
    call    *%rcx
    test    %eax, %eax
    jl      _qsort.L0_end
#   right -= _ele_size;
    subq    %r15,   %r13
    jmp     _qsort.L0
#   }
_qsort.L0_end:
#   if(left < right) {
    cmp     %r13,   %r12
    jge     _qsort.L1
#   memcpy(left, right, _ele_size);
    movq    %r12,    %rdi
    movq    %r13,    %rsi
    movq    %r15,    %rdx
    call    memcpy
#   left += _ele_size;
    addq    %r15,    %r12
#   }

#   while (left < right && _fn_cmp(left, base) <= 0) {
_qsort.L1:
    cmp     %r13,   %r12
    jge     _qsort.L1_end
    movq    %r12,   %rdi
    movq    %rsp,   %rsi
    movq    0x10(%r14),    %rcx
    call    *%rcx
    test    %eax, %eax
    jg      _qsort.L1_end
#   left += _ele_size;
    addq    %r15,   %r12
    jmp     _qsort.L1
#   }
_qsort.L1_end:
#   if(left < right) {
    cmp     %r13,   %r12
    jge     _qsort.tail
#   memcpy(right, left, _ele_size);
    movq    %r13,   %rdi
    movq    %r12,   %rsi
    movq    %r15,   %rdx
    call    memcpy
#   right -= _ele_size;
    subq    %r15,   %r13
#   }
    cmp     %r13,   %r12
    jl      _qsort.L0
#   }

_qsort.tail:
#   memcpy(right, base, _ele_size);
    movq    %r13,   %rdi
    movq    %rsp,   %rsi
    movq    %r15,   %rdx
    call    memcpy

#   cqsort(_nums, (left - lower_bound) / _ele_size, _ele_size, _fn_cmp);
    movq    0x00(%r14),    %rdi
    movq    %r12,   %rax
    subq    %rdi,   %rax
    xorq    %rdx,   %rdx
    divq    %r15
    movq    %rax,   %rsi
    movq    %r15,   %rdx
    movq    0x10(%r14),    %rcx
    call    _qsort

#   cqsort(right + _ele_size, (upper_bound - right) / _ele_size, _ele_size, _fn_cmp);
    movq    %r13,   %rdi
    addq    %r15,   %rdi
    movq    0x08(%r14),    %rax
    subq    %r13,   %rax
    xorq    %rdx,   %rdx
    divq    %r15
    movq    %rax,   %rsi
    movq    %r15,   %rdx
    movq    0x10(%r14),   %rcx
    call    _qsort

    movq    %r14,   %rsp
    addq    $0x40,  %rsp
    movq    %rbp,   %rsp
    popq    %rbp
    popq    %r15
    popq    %r14
    popq    %r13
    popq    %r12
_qsort.ret_directly:
    ret
#   }
    .cfi_endproc
