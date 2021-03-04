#lang racket

(define (duplicate lst)
  (if (empty? lst)
      '()
      (cons (car lst) (cons (car lst)(duplicate (cdr lst))))))
      

