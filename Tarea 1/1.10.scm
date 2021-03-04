(define (positives lst)
  (if (empty? lst)
      '()
      (if (> 0 (car lst))
          (positives (cdr lst))
          (cons (car lst) (positives (cdr lst))))))

