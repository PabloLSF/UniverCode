program f_call_c
IMPLICIT none
integer :: i = 1, ierr
double precision :: pi = 3.14159
print *, "______________________________"
print *, "Fortran chamando C, passando"
print *, "i = ", i, "pi = ", pi
ierr = cfun_c(i, pi)
print *, "______________________________"
end program f_call_c
