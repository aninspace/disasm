.name	fmelda
.comment	school21
sti r1, %33, %1
and r1, %0, r1
sti r2, %123, %1
lld  11, r15
sti r4, %4242, r15
live %66
ldi %-5, r3, r1
sti r1, %1234, r3
ldi %-17, r3, r1
sti r1, %2345, r3
sti r1, %3456, r3
sti r1, %4242, r3
add r3, r4, r3
xor r5, r3, r6
zjmp %13
ld %0, r7
zjmp %-61
xor r3, r3, r3
fork %-69
zjmp %-72
