    .arch armv8-a
    .text
    .globl _main

// helper: digit root (sum digits until < 10)
digit_root:
    // x0 = number
    mov     x1, 0              // sum = 0
    mov     x3, 10
1:  cbz     x0, 2f             // if number == 0 -> done sum loop
    udiv    x2, x0, x3         // x2 = x0 / x3   (x3 = 10)
    msub    x1, x2, x3, x0     // x1 = x0 - (x2 * x3)  => digit
    add     x1, x1, x3         // sum += digit (x3 stores old sum)
    mov     x3, x1             // keep running sum
    mov     x0, x2             // x0 = number / 10
    b       1b
2:  cmp     x3, 9
    mov     x0, x3
    ble     3f
    bl      digit_root         // recurse if >9
3:  ret

// main program
_main:
    stp     x29, x30, [sp, -16]!
    mov     x29, sp

    // call cydynamicin() → gets string
    bl      _cydynamicin
    mov     x19, x0
    cbz     x19, quit          // if null -> exit

    // read multiplier with scanf("%d")
    sub     sp, sp, #16
    mov     x0, l_fmt_in
    add     x1, sp, #8
    bl      _scanf
    ldr     w20, [sp, #8]      // multiplier
    add     sp, sp, #16

    // sum digits in string
    mov     x21, x19           // ptr
    mov     w22, 0             // sum_digits = 0
sum_loop:
    ldrb    w0, [x21], #1
    cbz     w0, after_sum
    sub     w0, w0, '0'
    add     w22, w22, w0
    b       sum_loop

after_sum:
    mul     w0, w22, w20       // result = sum_digits * multiplier
    bl      digit_root

    // printf("%d\n", result)
    mov     x1, x0
    mov     x0, l_fmt_out
    bl      _printf

    mov     x0, x19
    bl      _free

quit:
    ldp     x29, x30, [sp], 16
    mov     w0, 0
    ret

    .section __TEXT,__cstring
l_fmt_in:
    .asciz "%d"
l_fmt_out:
    .asciz "%d\n"