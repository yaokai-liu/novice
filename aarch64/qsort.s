// armv8-a assembly script

.arch       armv8-a
.globl      _qsort
.type       _qsort, %function
.text
// @return:    
// @params: _nums=$x0, _count=$x1, _ele_size=$x2, _fn_cmp=$x3
_qsort:
    .cfi_startproc
    cbz     x0, _qsort.ret_directly
    cmp     x1, #1
    ble     _qsort.ret_directly
    cbz     x2, _qsort.ret_directly
    cbz     x3, _qsort.ret_directly

    sub     sp, sp, #0x40
    str     x22,[sp, 0x28]
    str     x21,[sp, 0x20]
    str     x20,[sp, 0x18]
    str     x19,[sp, 0x10]
    str     fp, [sp, 0x08]
    str     lr, [sp, 0x00]

    mov     fp, sp
    mov     x19,x0              // left
    sub     x1, x1, 1
    madd    x20,x2, x1, x19     // right

    str     x19,[sp, 0x30]      // lower_bound
    str     x20,[sp, 0x38]      // upper_bound

    mov     x21,x2              // _ele_size
    mov     x22,x3              // _fn_cmp

_qsort.L0:
    cmp     x19, x20
    bhs     _qsort.tail
    mov     x0, x20
    mov     x1, x19
    blr     x22
    cmp     w0, 0
    blt     _qsort.L0_end
    sub     x20, x20, x21
    b       _qsort.L0
_qsort.L0_end:
    mov     x0, x19
    mov     x1, x20
    mov     x2, x21
    bl      cswap
    add     x19, x19, x21
_qsort.L1:
    cmp     x19, x20
    bhs     _qsort.tail
    mov     x0, x20
    mov     x1, x19
    blr     x22
    cmp     w0, 0
    blt     _qsort.L1_end
    add     x19, x19, x21
    b       _qsort.L1
_qsort.L1_end:
    mov     x0, x19
    mov     x1, x20
    mov     x2, x21
    bl      cswap
    sub     x20, x20, x21

    b       _qsort.L0

_qsort.tail:
    ldr     x0, [sp, 0x30]
    sub     x1, x19, x0
    udiv    x1, x1, x21
    mov     x2, x21
    mov     x3, x22
    bl      _qsort

    add     x0, x20, x21
    ldr     x1, [sp, 0x38]
    sub     x1, x1, x20
    udiv    x1, x1, x21
    mov     x2, x21
    mov     x3, x22
    bl      _qsort

    ldr     x22,[sp, 0x28]
    ldr     x21,[sp, 0x20]
    ldr     x20,[sp, 0x18]
    ldr     x19,[sp, 0x10]
    ldr     fp, [sp, 0x08]
    ldr     lr, [sp, 0x00]
    add     sp, sp, #0x40
_qsort.ret_directly:
    ret
    .cfi_endproc
