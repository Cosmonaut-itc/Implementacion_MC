(define (bmi w h)
    (define index (/ w (* h h)))
    (cond 
        [(< index  20) 'underweight]
        [(and (>= index 20) (< index 25)) 'normal]
        [(and (>= index 25) (< index 30)) 'obese1]
        [(and (>= index 30) (< index 40)) 'obese2]
        [(>= index 40) 'obese3]
    )
)