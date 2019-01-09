# ffpoly

(Reccomended you use a browser extension like TexTheWorld to render latex in
documents)

An implementation an element under the polynomial ring $Z_n[x]$. 

## Currently Supported Operations

Currently with ffpoly you can (for $f \in Z_n[x]$ with $deg(f) = d$):

- Addition/Subtraction $\theta(d)$.
- Multiplication $\theta(d^2)$ via naive convoluation. 
- Evaluation $\theta(d)$ via Horner's Rule.

## How to Build and Use

_Note:_ I'm not a professional developer, nor am I particularily aware of best
practices for writing this sort of stuff. If you have suggestions on how to fix
what you consider horrific, please open an issue!

To build you need:
	- Access to a cpp compiler (both g++ and clang tested)
	- The unix tools, _make_ and _ar_.

Following the example in main.cpp, use the commands, call make in the ffpoly
directory to build lib_ffpoly.a. Link this with your program. Make sure to have
the include to ffpoly.h in your program.

## Planned Work

- Improvements to the multiplication algorithm runtime.
	- Karatsuba-esque multiplication algorithm $\theta(d^{\log_2(3)})$
	- Classical FFT method $\theta(d \log(d))$
	- Heuristic to choose between methods depending on $d$.
- Support the division operator.
- Support the ability to factor.
- Support the GCD operation.
- Class group computations.
- Possible parallelization of compatible methods.
