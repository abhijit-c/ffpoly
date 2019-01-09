# ffpoly

(Reccomended you use a browser extension like TexTheWorld to render latex in
documents)

An implementation an element under the polynomial ring $Z_n[x]$. 

## Currently Supported Operations

Currently with ffpoly you can (for $f \in Z_n[x]$ with $deg(f) = d$):

- Addition/Subtraction $\theta(d)$.
- Multiplication $\theta(d^2)$ via naive convoluation. 
- Evaluation $\theta(d)$ via Horner's Rule.

## Planned Work

- Improvements to the multiplication algorithm runtime.
	- Karatsuba-esque multiplication algorithm $\theta(d^{\log_2(3)})$
	- Classical FFT method $\theta(d \log(d))$
	- Heuristic to choose between methods depending on $d$.
- Support the division operator.
- Support the ability to factor under $F_n$.
- Class group computations.
- Possible parallelization of compatible methods.
