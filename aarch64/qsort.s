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
    str     x19, [sp, 0x38]
    str     x20, [sp, 0x30]
    str     x21, [sp, 0x28]
    str     x22, [sp, 0x20]
    str     x23, [sp, 0x18]
    str     x24, [sp, 0x10]
    str     x25, [sp, 0x08]
    str     lr,  [sp, 0x00]
    mov     x24, sp
    sub     sp, sp, #0x30
    mov     x25, sp

//   char * lower_bound = (char *)_nums;
//   char * left=lower_bound;    
    mov     x19, x0     // left = $x19

    mov     x22, x2      // _ele_size = $x22
    mov     x23, x3     // _fn_cmp = $x23

//   char * upper_bound = (char *)_nums + (_count - 1) * _ele_size;
//   char * right = upper_bound;
    sub     x20, x1, #1 
    madd    x20, x20, x22, x19    // right = $x20

    str     x0,  [x25, 0x08]    // push lower_bound
    str     x1,  [x25, 0x10]    // push _count
    str     x20, [x25, 0x18]    // push upper_bound

    sub     x2, x2, #1
    lsr     x2, x2, #4
    add     x2, x2, #1
    lsl     x2, x2, #4
    str     x2, [x25, 0x20]     // push ((_ele_size - 1) / 16) * 16
    sub     sp, sp, x2
    mov     x21, sp     // base = $x21

//   memcpy(base, left, _ele_ssize);
    mov     x0, x21
    mov     x1, x19
    mov     x2, x22
    bl      memcpy

//   while ( left < right ) {
//   while ( left < right && _fn_cmp(right, base) >= 0 ) {
_qsort.L0:
    cmp     x19, x20
    bge     _qsort.L0_end
    mov     x0, x20
    mov     x1, x21
    blr     x23
    cmp     w0, #0
    blt     _qsort.L0_end
//   right -= _ele_size;
    sub     x20, x20, x22
    b      _qsort.L0
//   }
_qsort.L0_end:
//   if(left < right) {
    cmp     x19, x20
    bge     _qsort.L1
//   memcpy(left, right, _ele_size);
    mov     x0, x19
    mov     x1, x20
    mov     x2, x22
    bl     memcpy
//   left += _ele_size;
    add     x19, x19, x22
//   }

//   while (left < right && _fn_cmp(left, base) <= 0) {
_qsort.L1:
    cmp     x19, x20
    bge     _qsort.L1_end
    mov     x0, x19
    mov     x1, x21
    blr     x23
    cmp     w0, #0
    bgt     _qsort.L1_end
//   left += _ele_size;
    add     x19, x19, x22
    b       _qsort.L1
//   }
_qsort.L1_end:
//   if(left < right) {
    cmp     x19, x20
    bge     _qsort.tail
//   memcpy(right, left, _ele_size);
    mov     x0, x20
    mov     x1, x19
    mov     x2, x22
    bl      memcpy
//   right -= _ele_size;
    sub     x20, x20, x22
//   }
    cmp     x19, x20
    blt     _qsort.L0
//   }
_qsort.tail:
//   memcpy(right, base, _ele_size);
    mov     x0, x20
    mov     x1, x21
    mov     x2, x22
    bl      memcpy

//   cqsort(_nums, (left - lower_bound) / _ele_size, _ele_size, _fn_cmp);
    ldr     x0, [x25, 0x08]
    sub     x1, x19, x0
    udiv    x1, x1, x22
    mov     x22, x2
    mov     x23, x3
    bl      _qsort

//   cqsort(right + _ele_size, (upper_bound - right) / _ele_size, _ele_size, _fn_cmp);
    add     x0, x20, x22
    ldr     x1, [x25, 0x18]
    sub     x1, x1, x20
    udiv     x1, x1, x22
    mov     x2, x22
    mov     x3, x23
    bl      _qsort

_qsort.restore_register:
    mov     sp, x24
    ldr     x19, [sp, 0x38]
    ldr     x20, [sp, 0x30]
    ldr     x21, [sp, 0x28]
    ldr     x22, [sp, 0x20]
    ldr     x23, [sp, 0x18]
    ldr     x24, [sp, 0x10]
    ldr     x25, [sp, 0x08]
    ldr     lr,  [sp, 0x00]
    add     sp, sp, #0x40

_qsort.ret_directly:
    ret
    .cfi_endproc
