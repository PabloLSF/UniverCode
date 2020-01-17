                                        PROGRAM MATR

                                        INTEGER n
                                        INTEGER, DIMENSION (:,:), ALLOCATABLE :: mat
                                        PRINT *, 'Digite o tamanho da matriz'
                                        READ *, n
                                        IF ( n < 2 ) then
                                           PRINT *, 'Invalido'
                                        END IF
                                        ALLOCATE (mat(n,n))
                                        DO j=1, n
                                           DO i=1, n
                                              mat(j,i) = randNum()
                                           END DO
                                        END DO

                                        END PROGRAM

