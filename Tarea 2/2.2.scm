
(define (insert key lst)
    (cond
        [(null? lst) (list key)]
        [(<= key (car lst)) (cons key lst)]
        [else (cons (car lst) (insert key (cdr lst)))]
    )
)

(define (insertion-sort lst)
    (cond
        [(null? lst) '()]
        [else (insert (car lst) (insertion-sort (cdr lst)))]
    )
)    

