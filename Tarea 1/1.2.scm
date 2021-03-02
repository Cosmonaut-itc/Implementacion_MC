(define (sign n)
    (cond 
        [(> n 0) 1]
        [(< n 0) -1]
        [else 0]
    )
)