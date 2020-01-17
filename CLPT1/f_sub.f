subroutine FOR_SUB(i, pi, y, ny)
IMPLICIT NONE
integer :: i, ny
double precision :: pi
double precision :: y(ny)
! pular uma linha para melhor visualizacao no terminal
print *, " "
print *, "____________________________________________"
print *, "Esta eh uma subrotina em Fortran..."
print *, "i = ", i, ", pi = ", pi
print *, "y = ", y(1:ny)
print *, "____________________________________________"
! pular uma linha para melhor visualizacao no terminal
print *, " "
end subroutine FOR_SUB
