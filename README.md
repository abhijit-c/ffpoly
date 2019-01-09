# ffpoly

(Reccomended you use a browser extension like TexTheWorld to render latex in
documents)

An implementation an element under the polynomial ring $Z_n[x]$. Currently
supports the operations (for $f \in Z_n[x]$ with $deg(f) = d$):

- Addition/Subtraction $\theta(d)$.
- Multiplication $\theta(d^2)$ via naive convoluation. Later the addition of the
  Karatsuba-esque multiplication algorithm ($\theta(d^{\log(3)})$) and the
  classical FFT method ($\theta(n \log(n))$) will be added, along with
  heuristics to choose the optimal method to apply.
- Evaluation $\theta(d)$.
