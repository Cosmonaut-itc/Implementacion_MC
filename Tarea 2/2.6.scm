(define (deep-reverse lst)
  (if (null? lst)
      '()
      (append (deep-reverse (rest lst)) (list (first lst)))))

