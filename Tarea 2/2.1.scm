(define (insert n lst)
    (cond 
        [(null? lst) (list n)]
        [(<= n (car lst)) (cons n lst)]
        [else (cons (car lst) (insert n (cdr lst)))]
    )
)