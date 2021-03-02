(define (rotate-left n lst)
    (cond
        [(null? lst) '()]
        [(> n 0) (rotate-left (- n 1) (append (cdr lst) (cons (car lst) '())))]
        [(< n 0) (rotate-left (* (* n -1) (- (length lst) 1)) lst)]
        [else lst]
    )
)
