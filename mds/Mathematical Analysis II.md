---
title: Mathematical Analysis II
date: 2020-07-04 12:33:57
categories: note
mathjax: true
output: pdf_document
description: 本文为数学分析（二）的课堂内容整理，主要包括Riemann积分，度量空间和连续映射，多元函数微分学，多元函数积分学，以及微分形式的积分
---
# Mathematical Analysis II

## Riemann integral

### Def. measure

A measure |·| is a function $R^n\supset \Omega\to |\Omega|\in R$ s.t.

(i) $|A|\geq 0$

(ii) $A\subset B\Rightarrow |A|\leq |B|$

(iii) $A_j,j\in N$ are mutually dispoint implies that $|\cup_{j\in N}A_j|=\sum_{j\in N}|A_j|$

(iv) Let $C=[0,1]^n\subset R^n$ be a n-D cube, then $0<|C|<\infty$

### Axiom of choice

Let $\lbrace A_\lambda\rbrace_{\lambda\in \Lambda}$ be a family of mutually disjoint, non-empty sets, then $\exists f: \lbrace A_\lambda\rbrace_{\lambda\in \Lambda}\to \cup_{\lambda\in \Lambda} A_\lambda$ s.t. $f(A_\lambda)\in A_\lambda$ for each $\lambda\in \Lambda$

若有一族非空不交集合，总能从每个集合中挑出一个代表元

Rmks:

1.A.C. is equivlant to each of the following:

(1) each vector space over a field $F$ must has a basis

(2) Tychonoff thm

2.A.C. is essential in the proof of

(1) Baire category thm

(2) Hahn-Banach thm

(3) open mapping thm

3.Banach-Taski thm 分球定理

### Thm.

there exists a bounded subset $A \in R$ so that $|A|$ does not exist!

Proof. $\forall x\in [0,1),$ define $A_x=\lbrace y\in [0,1)|y-x\in Q\rbrace$

claim 1: $A_{x_1}\neq A_{x_2}\Rightarrow A_{x_1}\cap A_{x_2}=\emptyset$

by A.C., we can choose an element of each $A_x$ to form a set A

as $Q\cap (0,1)$ is countable, write it as $\lbrace r_1,r_2,\dots,r_n, \dots \rbrace$

define $A_i=r_i+A=\lbrace r_i+s|s\in A\rbrace$, clearly, $A_i\in (-1,2)$

claim 2: $A_i\cap A_j=\emptyset$ for $i\neq j$

claim 3: $[0,1)\subset \cup_{j=1}^\infty A_j$

then $[0,1)\subset \cup_{j=1}^\infty A_j\subset (-1,2)$

as $|A_j|=|A|, 1\leq |A|\cdot\infty\leq 3$, which means $|A|$ does not exist

### Def. partition

$\pi:a=x_0<x_1< \dots <x_n=b$ is called a partition of $[a,b]$

$\Delta x_j:=x_{j+1}-x_j,I_j:=[x_j,x_{j+1}],||\pi||:=\max\lbrace \Delta x_j\rbrace$

### Def. Riemann integral

Given $f:[a,b]\to R$ and $A\in R$

if $\forall \epsilon>0,\exists\delta>0$ s.t. if $||\pi||<\delta,|\sum_{j=0}^{n-1}f(\xi_j)\Delta x_j-A|<\epsilon,\forall\xi_j\in I_j$

then we say that $f$ is Riemann integrable on $[a,b]$ and $\int_a^bf(x)dx:=A$

$S_n:=\sum_{j=0}^{n-1}f(\xi_j)\Delta x_j$ is called the Riemann sum

$R[a,b]:=\lbrace f|f$ is Riemann integrable on $[a,b]\rbrace$

### Thm.

f is Riemann integrable $\Rightarrow$ $f$ is bounded

Proof. for $\epsilon=1,\exists\delta>0$ s.t. if $||\pi||<\delta$

$|\sum_{j=0}^{n-1}f(\xi_j)\Delta x_j-\int_a^b f|<\epsilon,\forall \xi_j\in I_j$

suppose $f$ is unbounded on $I_k$, fix $\xi_j=x_j,\forall j\neq k$

then $|f(\xi_k)\Delta x_k+\sum_{j\neq k}f(x_j)\Delta x_j-\int_a^b f|<\epsilon=1,\forall \xi_k\in I_k$

which shows $f(x)$ is bounded on $I_k$, contradicts!

### Def. Darboux sum

Assume $f$ is bounded on $[a,b]$, define $M_j:=\sup_{I_j}f,m_j:=\inf_{I_j}f$

$\omega_j:=M_j-m_j$ is called the oscillation of $f$ on $I_j$

$S(\pi):=\sum_{j=0}^{n-1}M_j\Delta x_j$ is called Darboux upper sum

$s(\pi):=\sum_{j=0}^{n-1}m_j\Delta x_j$ is called Darboux lower sum

### Def. refinement

$\pi'$ is called the refinement of $\pi$ if all the partition points of $\pi$ are partition points of $\pi'$, written as $\pi'<\pi$

### Thm.

Let $\pi'<\pi$, assume $\pi'$ has k more partition points than $\pi$, then $S(\pi)-k||\pi||(\sup f-\inf f)\leq S(\pi')\leq S(\pi)\\ S(\pi)+k||\pi||(\sup f-\inf f)\geq s(\pi')\geq s(\pi)$

Proof. it suffices to consider the situation that $\pi'$ has one more partition point than $\pi$

WLOG, assume $\pi:a=x_0<x_1=b,\pi':a=x_0<x'<x_1=b$

$S(\pi)=(b-a)\sup_{[a,b]}f$

$S(\pi')=(x'-a)\sup_{[a,x']}f+(b-x')\sup_{[x',b]}f$

$\leq (x'-a)\sup_{[a,b]}f+(b-x')\sup_{[a,b]}f=S(\pi)$

also, $S(\pi')\geq (x'-a)\inf_{[a,b]}f+(b-x')\inf_{[a,b]}f$

$=S(\pi)-(b-a)(\sup_{[a,b]}f-\inf_{[a,b]}f)\geq S(\pi)-||\pi||(\sup f-\inf f)$

#### Cor.

$\forall\pi,\pi',S(\pi)\geq s(\pi')$

### Thm.

$\inf_\pi S(\pi)=\lim_{||\pi||\to 0}S(\pi),\sup_\pi s(\pi)=\lim_{||\pi||\to 0}s(\pi)$

Proof. $\forall\epsilon>0,\exists \pi'$ s.t. $S(\pi')<\inf_\pi S(\pi)+\epsilon$

assume $\pi'$ has k partition points, choose $\delta=\frac{\epsilon}{k(\sup f-\inf f)}$, then

$\forall \pi$ satisfies $||\pi||<\delta$, consider $\pi'':=\pi\cup \pi'$

on the one hand, $S(\pi'')\leq S(\pi')<\inf_\pi S(\pi)+\epsilon$

on the other hand, $S(\pi'')\geq S(\pi)-k||\pi||(\sup f-\inf f)$

i.e. $S(\pi)\leq S(\pi'')+k||\pi||(\sup f-\inf f)<\inf_\pi S(\pi)+2\epsilon$

i.e. $\lim_{||\pi||\to 0}S(\pi)=\inf_\pi S(\pi)$

### Thm.

assume $f:[a,b]\to R$ is bounded, then $f\in R[a,b]$ iff $\lim_{||\pi||\to 0}\sum_{j=0}^{n-1}\omega_j\Delta x_j=0$

Proof. $\Rightarrow \forall \epsilon>0,\exists\delta>0$ s.t. if $||\pi||<\delta$

$|\sum_{j=0}^{n-1}f(\xi_j)\Delta x_j-\int_a^b f|<\epsilon,\forall \xi_j\in I_j$

$\int_a^bf-\epsilon\leq\sum_{j=0}^{n-1}m_j\Delta x_j\leq\sum_{j=0}^{n-1}f(\xi_j)\Delta x_j\leq\sum_{j=0}^{n-1}M_j\Delta x_j\leq\int_a^b f+\epsilon$

$0\leq \sum_{j=0}^{n-1}\omega_j\Delta x_j\leq 2\epsilon,\lim_{||\pi||\to 0}\sum_{j=0}^{n-1}\omega_j\Delta x_j=0$

$\Leftarrow \forall\epsilon>0,\exists \delta>0,$ s.t. if $||\pi||<\delta$

$S(\pi)-s(\pi)=\sum_{j=0}^{n-1}\omega_j\Delta x_j<\epsilon$

define $S:=\inf_\pi S(\pi),s:=\sup_\pi s(\pi)$, clearly,$s(\pi)\leq s\leq S\leq S(\pi),\forall \pi$

as $s,S$ are constant, $S=s$, define $A:=S=s$

$\sum_{j=0}^{n-1}f(\xi_j)\Delta x_j-A\leq \sum_{j=0}^{n-1}M_j\Delta x_j-A=S(\pi)-S\leq S(\pi)-s(\pi)<\epsilon$

similarly, $\sum_{j=0}^{n-1}f(\xi_j)\Delta x_j-A>-\epsilon$

$|\sum_{j=0}^{n-1}f(\xi_j)\Delta x_j-A|<\epsilon,$ i.e. $f\in R[a,b]$

### Thm.

assume $f:[a,b]\to R$ is bounded, then $f\in R[a,b]$ iff  $\forall \eta,\tau>0,\exists \delta>0$ s.t. if $||\pi||<\delta, \sum_{\omega_j\geq\eta}\Delta x_j<\tau$

Proof. $\Rightarrow \forall \eta,\tau>0$, choose $\epsilon=\eta\tau>0,\exists \delta>0$ s.t. if $||\pi||<\delta,\sum_{j=0}^{n-1}\omega_j\Delta x_j<\epsilon$

then $\sum_{\omega_j\geq\eta}\Delta x_j\leq \frac{1}{\eta}\sum_{\omega_j\geq\eta}\omega_j\Delta x_j\leq \frac{1}{\eta}\sum_{j=0}^{n-1}\omega_j\Delta x_j<\tau$

$\Rightarrow$ write $M=\sup f,m=\inf f$

$\forall\epsilon>0$, choose $\eta=\tau=\frac{\epsilon}{M-m+b-a}>0,\exists \delta>0$ s.t. if $||\pi||<\delta, \sum_{\omega_j\geq\eta}\Delta x_j<\tau$

$\sum_{j=0}^{n-1}\omega_j\Delta x_j=\sum_{\omega_j\geq\eta}\omega_j\Delta x_j+\sum_{\omega_j<\eta}\omega_j\Delta x_j$

$\leq(M-m)\sum_{\omega_j\geq\eta}\Delta x_j+\eta\sum_{\omega_j<\eta}\Delta x_j\leq(M-m)\tau+(b-a)\eta=\epsilon$

i.e. $f \in R[a,b]$

Example. Dirichlet function is not Riemann integrable.

### Def. measure zero set(MZS)

$S\in R$ is said to be a measure zero set if $\forall\epsilon>0$, there exist at most countable open intervals $\lbrace I_j\rbrace$ s.t.

(i) $S\subset \cup_j I_j$

(ii) $\sum_j |I_j|<\epsilon$

Examples.

(1) at most countable sets

(2) subsets of a MZS

(3) countable union of MZSs

### Thm. Lebesgue criterion

Let $f:[a,b]\to R$ be bounded, then $f\in R[a,b]$ iff $D_f$ is a MZS

$(C_f:=\lbrace x\in [a,b]|f$ is continuous at $x\rbrace,D_f:=[a,b]\setminus C_f)$

Proof. $\Rightarrow$ define $D_\eta:=\lbrace x\in[a,b]|\omega_f(x)\geq\eta\rbrace$

note that $D_f=\cup_{n=1}^\infty D_\frac{1}{n}$, it suffices to show $D\eta$ is a MZS, $\forall\eta>0$

$\forall\tau>0,\exists \delta>0$ s.t. if $||\pi||<\delta, \sum_{\omega_j\geq\eta}\Delta x_j<\tau$

note that if $x\in [x_j,x_{j+1}],\omega_f(x)\leq \omega_j$

assume $\pi$ has n partition points, $D_\eta\subset \cup_{\omega_j\geq\eta}[x_j,x_{j+1}]\cup \cup_{j=0}^n[x_j-\frac{\tau}{2n+2},x_j+\frac{\tau}{2n+2}]$

thus, $|D_\eta|\leq\sum_{\omega_j\geq\eta}\Delta x_j+\sum_{j=0}^{n}\frac{\tau}{n+1}=2\tau$

i.e. $D_\eta$ is a MZS

$\Leftarrow \forall\epsilon>0,\exists \lbrace(\alpha_j,\beta_j)\rbrace$ s.t. $D_f\subset\cup_j(\alpha_j,\beta_j),\sum_j(\beta_j-\alpha_j)<\epsilon$

$\forall x\in [a,b]\setminus \lbrace(\alpha_j,\beta_j)\rbrace$, as $f$ is continuous at x, $\exists \delta_x$ s.t. $\forall x'\in (x-\delta_x,x+\delta_x),|f(x')-f(x)|<\epsilon$

$\lbrace(\alpha_j,\beta_j)\rbrace \cup \lbrace (x-\delta_x,x+\delta_x)|x\in [a,b]\setminus \lbrace(\alpha_j,\beta_j)\rbrace\rbrace$ is an open cover of $[a,b]$

by Heine-Borel, exists finite open intervals $\lbrace I_j\rbrace_{j=1}^N$ be a cover of $[a,b]$

the endpoints of $\lbrace I_j\rbrace_{j=1}^N$ make up an partition of $[a,b]$

$\pi_0:a=y_0<y_1< \dots <y_m=b$, choose $\delta=\min_j y_{j+1}-y_j$

$\forall \pi:a=x_0<x_1< \dots <x_n=b,||\pi||<\delta$, each of the intervals $[x_i,x_{i+1}]$ satisfies either

(i) $[x_i,x_{i+1}]\subset (\alpha_j,\beta_j)$ for some j, or

(ii) $[x_i,x_{i+1}]\subset (x-\delta_x,x+\delta_x)$ for some x

$\sum_{i=0}^{n-1}\omega_j\Delta x_j=\sum_{case (i)}\omega_j\Delta x_j+\sum_{case (ii)}\omega_j\Delta x_j$

$<2||f||_\infty\sum_{case (i)}\Delta x_j+2\epsilon\sum_{case (ii)}\Delta x_j<2||f||_\infty\epsilon+2(b-a)\epsilon$

i.e. $f\in R[a,b]$

#### Cors.

(1) $f\in C[a,b]\Rightarrow f\in R[a,b]$

(2) $f$ is bounded and monotone on $[a,b]\Rightarrow f\in R[a,b]$

(3) $f$ has at most countable discontinuities on $[a,b]\Rightarrow f\in R[a,b]$

(4) $f$ is a piecewise constant function on $[a,b]\Rightarrow f\in R[a,b]$

(5) $f,g\in R[a,b]\Rightarrow f+g,fg\in R[a,b]$

(6) $g\in R[a,b],f\in C(g([a.b]))\Rightarrow f\circ g\in R[a,b]$

Example. Riemann function is Riemann integrable and the integral is 0

### Thm.

(1) $f\in R[a,b]\Rightarrow f\in R[\alpha,\beta],\forall[\alpha,\beta]\subset[a,b]$

(2) $f\in R[a,c],f\in R[c,b]\Rightarrow f\in R[a,b]$

Proof. (1) in $[a,b], \forall \epsilon>0,\exists\delta>0$ s.t. if $||\pi||<\delta,\sum_{j=0}^{n-1}\omega_j\Delta x_j<\epsilon$

$\forall \pi':\alpha=y_0< \dots <y_m=\beta,||\pi'||<\delta$, it is easy to add partition points in $[a,b]-[\alpha,\beta]$ to make up a new partition $\pi$ and keep $||\pi||<\delta$

$\sum_{\pi'}\omega_j\Delta x_j\leq\sum_\pi\omega_j\Delta x_j<\epsilon$, i.e. $f\in R[a,b]$

(2) $\forall \pi:a=x_0<x_1< \dots <x_n=b$, define $\pi_1:(\pi\cap[a,c])\cup\lbrace c\rbrace,\pi_2:(\pi\cap[c,b])\cup\lbrace c\rbrace$, where $\pi_1$ is a partition of $[a,c]$ and $\pi_2$ is a partition of $[c,b]$

$\forall\epsilon>0,\exists \delta_i,>0$ s.t. if $||\pi_i||<\delta,\sum_{\pi_i}\omega_j\Delta x_j<\epsilon,i=1,2$

choose $\delta=\min\lbrace\delta_1,\delta_2,\epsilon\rbrace,\forall ||\pi||<\delta$, we have $||\pi_1||<\delta_1,||\pi_2||<\delta_2$

$\sum_\pi\omega_j\Delta x_j\leq\sum_\pi\omega_j\Delta x_j+\sum_\pi\omega_j\Delta x_j+2||f||_\infty||\pi||< 2\epsilon+2||f||_\infty\epsilon$

i.e. $f\in R[a,b]$

### Def. measure of a set

let $\Omega\subset R$ be bounded, say, $\Omega\subset [a,b]$, then $|\Omega|:=\int_a^b\chi_\Omega(x)dx$, provided $\chi_\Omega\in R[a,b]$, where $\chi_\Omega(x):=\begin{cases}1,x\in\Omega\\  0,x\notin \Omega\end{cases}$

### Thm.

assume $f,g\in R[a,b]$, then

(1) $\int_a^b(f+g)=\int_a^bf+\int_a^bg$

(2) if $f\leq g,\int_a^bf\leq\int_a^b g$, in particular, $|\int_a^bf|\leq\int_a^b|f|$

Proof.(1) $D_{f+g}\subset D_f\cup D_g,f+g\in R[a,b]$

$\int_a^b(f+g)=\lim_{||\pi||\to 0}\sum(f+g)(\xi_j)\Delta x_j$

$=\lim_{||\pi||\to 0}\sum f(\xi_j)\Delta x_j+\lim_{||\pi||\to 0}\sum g(\xi_j)\Delta x_j=\int_a^bf+\int_a^bg$

(2) $\int_a^bf=\lim_{||\pi||\to 0}\sum_{j=0}^{n-1}f(\xi_j)\Delta x_j\leq \lim_{||\pi||\to 0}\sum_{j=0}^{n-1}g(\xi_j)\Delta x_j=\int_a^bg$

note that $-|f|\leq f\leq |f|,\int_a^b (-|f|)\leq\int_a^b f\leq\int_a^b|f|$

i.e. $|\int_a^bf|\leq\int_a^b|f|$

### Thm. the first mean value thm

Let $f,g\in R[a,b],g\geq 0,$ then $\exists \mu\in[\inf f,\sup f]$ s.t. $\int_a^b fg=\mu\int_a^bg$

Proof. note that $\inf f\int_a^bg\leq\int_a^bfg\leq \sup f\int_a^bg$

the case $\int_a^bg=0$ is trivial, otherwise

$\inf f\leq\frac{\int_a^bfg}{\int_a^bg}\leq \sup f,\exists \mu=\frac{\int_a^bfg}{\int_a^bg}$ satisfies $\mu\in[\inf f,\sup f],\int_a^b fg=\mu\int_a^bg$

### Thm.

Let $f\in R[a,b]$, define $F(x):=\int_a^x f$

(1) $F$ is Lipchitz on $[a,b]$

(2) if $f$ is continuous at $\xi\in[a,b],F'(\xi)=f(\xi)$

Proof. (1) $\forall x<y\in [a,b],|F(y)-F(x)|=|\int_a^y f-\int_a^x f|=|\int_x^y f|\leq ||f||_\infty|y-x|$

(2) $\forall \epsilon>0,\exists \delta>0$ s.t. if $|x-\xi|<\delta,|f(x)-f(\xi)|<\epsilon$

when $|x-\xi|<\delta,\frac{F(x)-F(\xi)}{x-\xi}-f(\xi)=\frac{1}{x-\xi}\int_\xi^x(f(t)-f(\xi))dt<\frac{1}{x-\xi}\int_\xi^x\epsilon dt=\epsilon$

i.e. $F'(\xi)=\lim_{x\to\xi}\frac{F(x)-F(\xi)}{x-\xi}=f(\xi)$

### Thm. Newton-Leibniz Formula

Let $F'=f\in R[a,b]$, then $\int_a^bf=F(b)-F(a)=F|_a^b$

Proof. $F|_a^b=\sum_{j=0}^{n-1}(F(x_{j+1})-F(x_j))=\sum_{j=0}^{n-1}F'(\xi_j)\Delta x_j,\xi_j\in I_j$

$=\sum_{j=0}^{n-1}f(\xi_j)\Delta x_j\to\int_a^b f$ as $||\pi||\to 0$

i.e. $\int_a^bf=F(b)-F(a)=F|_a^b$

Rmk. if $F\in C[a,b]$ is differentiable everywhere except some finite points, the formula is still correct

assume the indifferentiable points are $x_1, \dots ,x_n$

$\int_a^bf=\int_a^{x_1}f+ \dots +\int_{x_n}^bf=F|_a^{x_1}+ \dots +F|_{x_n}^b=F|_a^b$

#### Cor.

let $f\in C[a,b]$ and u,v be differentiable, then $\frac{d}{dx}\int_{u(x)}^{v(x)}f=f(v(x))v'(x)-f(u(x))u'(x)$

### Thm. change of variable-warm up

assume $f\in C[a,b],\phi\in C^1([\alpha,\beta],[a,b]),a=\phi(\alpha),b=\phi(\beta)$, then

$\int_a^bf=\int_\alpha^\beta f\circ\phi\cdot\phi'$

Proof. let $F(x)=\int_a^x f$, then $F'=f$

note that $\frac{d}{dx}(F\circ\phi)(x)=f\circ\phi\cdot\phi'$

$\int_\alpha^\beta f\circ\phi\cdot\phi'=(F\circ\phi)|_\alpha^\beta=F_a^b=\int_a^bf$

### Thm. change of variable-strong form

assume $\phi$ is monotone and differentiable on $[\alpha,\beta]$, if $\phi'\in R[\alpha,\beta],f\in R(\phi([\alpha,\beta]))$, then

$f\circ\phi\cdot\phi'\in R[\alpha,\beta]$, and $\int_{\phi(\alpha)}^{\phi(\beta)}f=\int_\alpha^\beta f\circ\phi\cdot\phi'$

Proof. assume $\phi\uparrow$, let $\pi:\alpha=t_0<t_1< \dots <t_n=\beta$

write $x_j=\phi(t_j)$, then $\pi':a=x_0\leq x_1\leq  \dots \leq x_n=b$ is a partition of $[a,b]$

note that $\Delta x_j=\phi(t_{j+1})-\phi(t_j)=\phi'(\xi_j)\Delta t_j,||\pi'||\leq ||\phi'||_\infty||\pi||$

consider $S_n:=\sum_{j=0}^{n-1}f(\xi_j)\Delta x_j$ and $T_n:=\sum_{j=0}^{n-1} f(\phi(\eta_j))\phi'(\eta_j)\Delta t_j, \forall\xi_j\in[x_j,x_{j+1}],\eta_j\in [t_j,t_{j+1}]$, clearly, $S_n\to \int_a^bf,T_n\to \int_\alpha^\beta f\circ\phi\cdot\phi'$

$S_n-T_n=\sum_{j=0}^{n-1}f(\xi_j)\Delta x_j-\sum_{j=0}^{n-1} f(\phi(\eta_j))\phi'(\eta_j)\Delta t_j$

$=\sum_{j=0}^{n-1}(f(\xi_j)-f(\phi(\eta_j)))\Delta x_j+\sum_{j=0}^{n-1} f(\phi(\eta_j))(\Delta x_j-\phi'(\eta_j)\Delta t_j)$

$\leq \sum_{j=0}^{n-1}\omega_j(f)\Delta x_j+\sum_{j=0}^{n-1}||f||_\infty(\phi'(\theta_j)-\phi'(\eta_j))\Delta t_j$

$\leq \sum_{j=0}^{n-1}\omega_j(f)\Delta x_j+\sum_{j=0}^{n-1}||f||_\infty\omega_j(\phi')\Delta t_j\to 0$, as $||\pi||$, together with $||\pi'||,\to 0$

$S_n$ and $T_n$ has the same limit, i.e.$\int_{\phi(\alpha)}^{\phi(\beta)}f=\int_\alpha^\beta f\circ\phi\cdot\phi'$

### Thm. integral by parts-warm up

let u,v be differentiable on $[a,b],u',v'\in R[a,b]$, then

$\int_a^b udv=uv|_a^b-\int_a^bvdu$

Proof. $uv|_a^b=\int_a^b(uv)'=\int_a^budv+\int_a^bvdu$

### Thm. integral by parts-strong form

let $f,g\in R[a,b]$, define $F(x)=\int_a^xf,G(x)=\int_a^xg$, then

$\int_a^bFg=FG|_a^b-\int_a^bfG$

Proof. let $f_n,g_n$ be piecewise affine s.t. $\int_a^b|f_n-f|\to 0,\int_a^b |g_n-g|\to 0,$ as $n\to \infty$

(将 $[a,b]$ n等分,用线段连接相邻分点即得$f_n,\int_a^b|f_n-f|=\sum_{j=0}^{n-1}\int_{x_j}^{x_{j+1}}|f_n-f|$

$\leq \sum_{j=0}^{n-1}\int_{x_j}^{x_{j+1}}\omega_j=\sum_{j=0}^{n-1}\omega_j\Delta x_j\to 0$, as $n\to \infty$)

define $F_n(x)=\int_a^xf_n,G_n(x)=\int_a^xg_n$

note that $F_n,G_n$ are differentiable on each $[x_j,x_{j+1}]$

thus, $\int_a^bF_ng_n=\sum_{j=0}^{n-1}\int_{x_j}^{x_{j+1}}F_ng_n$

$=\sum_{j=0}^{n-1}F_nG_n|_{x_j}^{x_{j+1}}-\sum_{j=0}^{n-1}\int_{x_j}^{x_{j+1}}f_nG_n=F_nG_n|_a^b-\int_a^bf_nG_n(\ast)$

$|\int_a^bF_ng_n-\int_a^bFg|\leq|\int_a^bF_n(g_n-g)|+|\int_a^bg|F_n-F|$

$\leq||F||_\infty\int_a^b|g_n-g|+||g||_\infty\int_a^b|F_n-F|$

$\leq (b-a)||f||_\infty\int_a^b|g_n-g|+||g||_\infty\int_a^b\int_a^b|f_n-f|\to 0$, as $n\to\infty$

similarly, $\int_a^bG_nf_n\to\int_a^bGf$, as $n\to\infty$

let $(\ast)$ attain its limit, $\int_a^bFg=FG|_a^b-\int_a^bfG$

### Thm. the second mean value thm

assume $f\in R[a,b]$, then

(1) if g is monotone on $[a,b]$, then $\exists \zeta\in[a,b]$,s.t.

$\int_a^bfg=g(a)\int_a^\zeta f+g(b)\int_\zeta^b f$

(2) if $g \downarrow,g\geq 0$, then $\exists\xi\in[a,b]$ s.t.

$\int_a^bfg=g(a)\int_a^\xi f$

(3) if $g \uparrow,g\geq 0$, then $\exists\eta\in[a,b]$ s.t.

$\int_a^bfg=g(b)\int_\eta^b f$

Proof. it suffices to show (1)(2)

let $f_n,g_n$ be piecewise affine s.t. $\int_a^b|f_n-f|\to 0,\int_a^b |g_n-g|\to 0,$ as $n\to \infty$

define $F_n(x)=\int_a^xf_n,G_n(x)=\int_a^xg_n$

(1) $\int_a^bf_ng_n=F_ng_n|_a^b-\int_a^bF_ng_n'$

by the first mean value thm, $=F_ng_n|_a^b-F_n(\zeta_n)\int_a^bg_n'$

$=F_ng_n|_a^b-F_n(\zeta_n)(g(b)-g(a))$

let $n\to \infty,\int_a^bfg=Fg|_a^b-\lim_{n\to\infty}F_n(\zeta_n)(g(b)-g(a))$

by bolzano-weierstrass,$\exists \zeta_{n_j}\to\xi$, WLOG, assume $\zeta_n\to\zeta$

$|F_n(\zeta_n)-F(\zeta)|\leq |F_n(\zeta_n)-F(\zeta_n)|+|F(\zeta_n)-F(\zeta)|\to 0$, as $n\to\infty$

thus, $\int_a^bfg=Fg|_a^b-F(\zeta)(g(b)-g(a))$

$=(F(b)-F(\zeta))g(b)+(F(\zeta)-F(a))g(a)=g(a)\int_a^\zeta f+g(b)\int_\zeta^b f$

(2) as $\int_a^bfg=Fg|_a^b-F(\zeta)(g(b)-g(a))=F(b)g(b)+(g(a)-g(b))F(\zeta)$

$\int_a^b fg\leq \max F g(b)+(g(a)-g(b))\max F=g(a)\max F$

similarly, $\int_a^b fg\geq g(a)\min F$

$\min F\leq \frac{\int_a^bfg}{g(a)}\leq \max F$

$\exists\xi$ s.t. $F(\xi)=\frac{\int_a^bfg}{g(a)}$, i.e. $\int_a^bfg=g(a)\int_a^\xi f$

## Metric space

### Def. Euclidean space

$R^n$ is defined to be ordered n-tuples of real numbers

$x\in R^n\Leftrightarrow x=(x_1,x_2, \dots ,x_n),x_j\in R$, or, $R^n=R\times  \dots \times R$

it is a vector space over the field $R$

$x+y:=(x_1+y_1, \dots ,x_n+y_n)\in R^n, \forall x,y\in R^n,$
$\lambda x:=(\lambda x_1, \dots ,\lambda x_n)\in R^n,\forall x\in R^n,\lambda \in R$

the above is the algebra structure

moreover, it is also equipped with a topological structure: the distance of any two points x,y is defined by

$d(x,y):=\sqrt{\sum_{i=1}^n|x_j-y_j|^2}$

$d(\cdot,\cdot):R^n\times R^n \to R_{\geq 0}$ satisfies:

(i) symmetry $d(x,y)=d(y,x)$

(ii) positivity $d(x,y)\geq 0$, and $d(x,y)=0$ iff $x=y$

(iii) triangle inequality $d(x,z)\leq d(x,y)+d(y,z)$ (Cauchy schwarz inequality)

the norm of $x=(x_1, \dots ,x_n)$ is defined by

$||x||:=d(x,0)=\sqrt{\sum_{j=1}^n x_j^2}$

### Def. metric space

given a non-empty set X, $d(\cdot,\cdot): X\times X\to R_{\geq 0}$ is called a metric(distance) if for each $x,y,z\in X$, the following holds:

(i) positivity $d(x,y)\geq 0$, and $d(x,y)=0$ iff $x=y$

(ii) symmetry $d(x,y)=d(y,x)$

(iii) triangle inequality $d(x,z)\leq d(x,y)+d(y,z)$

$(X,d)$ is called a metric space

Example: $(R,d)$ is a metric space with $d(x,y)=k|x-y|,\forall k\in R\setminus\lbrace 0\rbrace$

### Def. normed space

given a vector space V over a field F, a norm on V is a function $||\cdot||:V\to R_{\geq 0}$ with the following properties

(i) positivity $||x||\geq 0$ and $||x||=0$ iff $x=0\in V$

(ii) triangle inequality $||x+y||\leq ||x||+||y||$

(iii) homogeneity齐次性 $||\lambda x||=|\lambda|||x||$

$(V,||\cdot||)$ is called a normed space

Rmk. a normed space is a metric space with $d(x,y):=||x-y||$

### Thm. Holder inequality

let $f,g\in R[a,b],\frac{1}{p}+\frac{1}{q}=1,p,q>0$, then $||fg||_1\leq ||f||_p||g||_q$

where for each $\phi\in R[a,b],||\phi||_p:=(\int_a^b|\phi|^p)^\frac{1}{p}$

Proof. WLOG, assume $||f||_p||g||_q>0$, since $y=e^x$ is convex

$\forall a,b>0,ab=e^{\frac{1}{p}lna^p+\frac{1}{q}lnb^q}\leq \frac{1}{p}e^{lna^p}+\frac{1}{q}e^{lnb^q}=\frac{1}{p}a^p+\frac{1}{q}b^q$

$\frac{||fg||_1}{||f||_p||g||_q}=\int_a^b\frac{|f|}{||f||_p}\frac{|g|}{||g||_q}\leq\int_a^b(\frac{1}{p}\frac{|f|^p}{||f||_p^p}+\frac{1}{q}\frac{|g|^p}{||g||_q^q})=\frac{1}{p}+\frac{1}{q}=1$

i.e. $||fg||_1\leq ||f||_p||g||_q$

### Thm. Minkovski inequality

let $f,g\in R[a,b]$, for $\forall 1\leq p\leq +\infty,||f+g||_p\leq ||f||_p+||g||_p$

Proof. if $p=+\infty$, obviously $\sup(f+g)\leq \sup f+\sup g$

for $1\leq p<+\infty,||f+g||_p^p=\int_a^b|f+g|^p\leq \int_a^b(|f|+|g|)|f+g|^{p-1}$

by Holder inequality, $\leq (\int_a^b|f|^p)^\frac{1}{p}(\int_a^b|f+g|^{(p-1)q})^\frac{1}{q}+(\int_a^b|g|^p)^\frac{1}{p}(\int_a^b|f+g|^{(p-1)q})^\frac{1}{q}$

$=(||f||_p+||g||_p)||f+g||_p^{\frac{p}{q}}$

thus, $||f+g||_p=||f+g||_p^{p-\frac{p}{q}}\leq ||f||_p+||g||_p$

Rmk: the discrete form of Minkovski inequality is $||x+y||_p\leq ||x||_p+||y||_p,\forall x,y\in R^n$, where $||x||_p:=(\sum_{j=1}^n|x_j|^p)^\frac{1}{p}$, and the proof is similar



### Def. inner product space

let V be a vector space over a field F=R, if $\langle\cdot,\cdot\rangle:V\times V\to F=R$ s.t. the following holds for $\forall x,y\in V$

(i) positivity $\langle x,x\rangle\geq 0$, and $\langle x,x\rangle=0$ iff $x=0\in V$

(ii) symmetry $\langle x,y\rangle=\langle y,x\rangle$

(iii) linearity $\langle\lambda x,y\rangle=\lambda \langle x,y\rangle,\forall\lambda\in R$

Rmk: $\langle x,\lambda y\rangle=\langle \lambda y,x\rangle=\lambda \langle y,x\rangle=\lambda\langle x,y\rangle$

then $(V,\langle\cdot,\cdot\rangle)$ is called an inner product space

Rmk. if $a,b\in V\setminus\lbrace 0 \rbrace, \theta:=\arccos\frac{\langle a,b\rangle}{||a||||b||}$ is called the angle between a and b

### Thm. Cauchy-Schwarz inequality

if $(V,||\cdot||)$ is a normed product space with an inner product, then $|\langle u,v\rangle|\leq||u||||v||$

Proof. $0\leq ||u+\lambda v||^2=\langle u+\lambda v,u+\lambda v\rangle=||u||^2+2\lambda\langle u,v\rangle+\lambda^2||v||^2$

$\Delta=4\langle u,v\rangle^2-4||u||^2||v||^2\leq 0$, i.e. $|\langle u,v\rangle|\leq||u||||v||$

### Thm.

if $(V,\langle\cdot,\cdot\rangle)$ is an inner product space, then it is a normed space if we define $||x||:=\sqrt{\langle x,x\rangle},\forall x\in V$

Proof. it suffices to show the triangle inequality

$||x+y||^2=\langle x+y,x+y\rangle=||x||^2+2\langle x,y\rangle+||y||^2\leq (||x||+||y||)^2$

i.e. $||x+y||\leq ||x||+||y||$

### Def. ball

let $(X,d)$ be a metric space, for each $r>0,B_r(x):=\lbrace y\in X|d(x,y)<r\rbrace$ is called an open ball with radius r, centered at x

### Def. cube

$\forall l>0,x\in R^n, C_l(x):=\lbrace y\in R^n||x_j-y_j|<\frac{l}{2},j=1,2, \dots ,n\rbrace$ is called a cube of side-length $l$, centered at point x

### Def. diameter

assume $(X,d)$ be a metric space and $\Omega\subset X,diam\Omega:=\sup_{x,y\in\Omega}d(x,y)$

### Def.

let $(X,d)$ be a metric space

(1) $\Omega\subset X$ is called open if $\forall x\in \Omega,\exists\delta_x>0$ s.t. $B_{\delta_x}(x)\in \Omega$

(2) $S\in X$ is called closed if $S^c$ is open

conventionally, $\emptyset$ is open, i.e. $X$ is closed

Rmk. $X$ and $\emptyset$ are both open and closed

(3) given $x\in X, N$ is called a neighborhood of $x$ if $x\in N$ and $N$ is open

### Thm.

(1) finite union of closed sets is closed

(2) the union of open sets is open

Proof.(1) let $A_1,A_2, \dots ,A_N$ be closed

$\forall x\in \cap_{j=1}^NA_j^c,x\in A_j^c,\forall j, \exists \delta_j>0,B_{\delta_j}(x)\subset A_j^c$

choose $\delta:=\min_{j=1}^N\delta_j,B_{\delta_j}(x)\subset\cap_{j=1}^NA_j^c$

thus, $\cap_{j=1}^NA_j^c$ is open, i.e. $\cup_{j=1}^NA_j$ is closed

(2) assume $\lbrace A_\lambda\rbrace,\lambda\in \Lambda$ be open

$\forall x\in \cup_{\lambda\in \Lambda}A_\lambda,\exists\lambda$ s.t. $x\in A_\lambda,\exists\delta_x>0,B_{\delta_x}(x)\subset A_\lambda$

thus, $B_{\delta_x}(x)\subset \cup_{\lambda\in \Lambda}A_\lambda,\cup_{\lambda\in \Lambda}A_\lambda$ is open

### Def. limit of points

let $(X,d)$ be a metric space, $x_n\in X,x\in X$

$\lim_{n\to\infty}x_n=x$ means $\forall\epsilon>0,\exists N=N(\epsilon)$ s.t. if $n>N,d(x_n,x)<\epsilon$

### Def.

let $(X,d)$ be a metric space, $\Omega\subset X$

(1) $x$ is called an interior point of $\Omega$ if $\exists\delta>0$ s.t. $B_\delta(x)\subset \Omega$

(2) $x$ is called an exterior point of $\Omega$ if $\exists\delta>0$ s.t. $B_\delta(x)\cap\Omega=\emptyset$

(3) $x$ is called an boundary point of $\Omega$ if $\forall\epsilon>0,B_\epsilon(x)\cap\Omega\neq\emptyset,B_\epsilon(x)\cap\Omega^c\neq\emptyset$

(4) $int\Omega:=$ all interior points of $\Omega$,$\partial\Omega:=$ all boundary points of $\Omega$
### Def. closure 闭包

let $(X,d)$ be a metric space, $\Omega\subset X$

$\overline{\Omega}:=\Omega\cup\partial\Omega$ is called the closure of $\Omega$

Rmk: $\overline{\Omega}=int\Omega\cup\partial\Omega$

### Def. Cauchy sequence

a sequence $\lbrace x_n\rbrace$ in a metric space $(X,d)$ is called Cauchy if $\forall\epsilon>0,\exists N=N(\epsilon)$ s.t. if $m>n>N,d(x_m,x_n)<\epsilon$

### Def. completeness

a metric space $(X,d)$ is called complete iff each Cauchy sequence in $X$ is convergent(收敛的)

Example. $(Q,d)$ is not complete

### Thm.

$(R^d,||\cdot||)$ is complete

Proof. let $\lbrace x_n\rbrace\in R^d$ be Cauchy, i.e. $\forall\epsilon>0,\exists N=N(\epsilon)$ s.t. if $m>n>N,||x_m-x_n||=\sqrt{\sum_{j=1}^d|x_m^{(j)}-x_n^{(j)}|^2}<\epsilon$

$\forall 1\leq j\leq d,|x_m^{(j)}-x_n^{(j)}|<\epsilon$, i.e. $\lbrace x_n^{(j)}\rbrace$ is Cauchy, $\exists x^{(j)}\in R, x_n^{(j)}\to x^{(j)}$

let $x=(x^{(1)},x^{(2)}, \dots x^{(d)})\in R^d$

$||x_n-x||=\sqrt{\sum_{j=1}^d|x_n^{(j)}-x^{(j)}|^2}\leq \sum_{j=1}^d|x_n^{(j)}-x^{(j)}|\to 0$, as $n\to\infty$

i.e. $x_n\to x\in R^d$, $(R^d,||\cdot||)$ is complete

### Thm.

S is closed iff $\forall x_n\in S, x_n\to x$ implies $x\in S$

Proof. $\Rightarrow$ if not, $x\in S^c$, since $S^c$ is open, $\exists\delta>0,B_\delta(x)\subset S^c$

as $x_n\to x,\exists N=N(\delta)$ s.t. if $n>N,d(x_n,x)<\delta$

i.e. $x_n\in B_\delta(x)\subset S^c$, contradicts!

$\Leftarrow$ if not, $S^c$ is not open, $\exists \xi\in S^c,\xi\notin intS^c$

i.e. $\forall \frac{1}{n}>0,B_{\frac{1}{n}}(\xi)\cap S\neq \emptyset,\exists x_n\in B_{\frac{1}{n}}(\xi)\cap S$

$x_n\in S,x_n\to\xi$, by the assumption, $\xi\in S$, contradicts!

### Thm. cantor nested sets thm 闭集套定理

let $(X,d)$ be a metric space, then $(X,d)$ is complete iff if $\Omega_1\supset\Omega_2\supset \dots$ be a sequence of non-empty closed sets and $\lim_{n\to\infty}diam\Omega_n=0,\exists!\xi\in \cap\Omega_n$

Proof. $\Rightarrow$ choose $\forall x_n\in \Omega_n$, when $m>n,d(x_m,x_n)<diam \Omega_n\to 0$

i.e. $\lbrace x_n\rbrace$ is Cauchy, $\exists\xi$ s.t. $x_n\to \xi$

$\forall n$, if $m>n,x_m\in \Omega_n$, by the thm above, $\xi\in\Omega_n$, thus, $\xi\in \cap\Omega_n$

suppose $\eta\in \cap\Omega_n,d(\xi,\eta)<diam\Omega_n\to 0,\xi=\eta$

$\Leftarrow$ given $\lbrace x_n\rbrace\in (X,d)$ Cauchy

$\forall\epsilon_k=\frac{1}{2^k},\exists n_k(\uparrow)$ s.t. if $m>n\geq n_k,d(x_m,x_n)<\epsilon_k=\frac{1}{2^k}$

consider $\Omega_k:=B_{2\epsilon_k}(x_{n_k})$, if $x\in\Omega_{k+1},d(x,x_{n_k})\leq d(x,x_{n_{k+1}})+d(x_{n_{k+1}},x_{n_k})<\frac{1}{2^k}+\frac{1}{2^k}=2\epsilon_k$

i.e. $x\in \Omega_k$, thus, $\Omega_1\supset\Omega_2\supset \dots$

as $diam\Omega_n=2\epsilon_k\to 0,\exists!\xi\in\cap\Omega_n$

clearly, $x_{n_k}\to\xi$, as $\lbrace x_n\rbrace$ is Cauchy, $x_n\to\xi$, i.e. $(X,d)$ is complete

### Def. dense 稠密

let $(X,d)$ be a complete metric space, $S\subset X$ is called dense if $\overline{S}=X$

Rmk. (1) Q is dense in R

(2) $\lbrace \sin n|n\in N\rbrace$ is dense in $[-1,1]$

### Thm. baire category thm

let $(X,d)$ be a complete metric space, $A_n\neq\emptyset$ closed, $intA_n=\emptyset\Rightarrow int(\cup_{n=1}^\infty A_n)=\emptyset$

Rmk. in other words, the intersection of countable dense open sets is dense

Proof. if not, $\exists x_1\in int(\cup_{n=1}^\infty A_n)$, i.e. $\exists 1>\delta_1>0,\overline{B_{\delta_1}(x_1)}\subset \cup_{n=1}^\infty A_n$

$B_{\delta_1}(x_1)\setminus A_1$ is open, and as $int A_1=\emptyset,B_{\delta_1}(x_1)\setminus A_1\neq\emptyset$

by A.C., $\exists x_2\in B_{\delta_1}(x_1)\setminus A_1,0<\delta_2<\frac{1}{2},\overline{B_{\delta_2}(x_2)}\subset B_{\delta_1}(x_1)\setminus A_1$

similarly, $B_{\delta_2}(x_2)\setminus A_2\neq\emptyset$, and is open

repeat, then we have $\overline{B_{\delta_1}(x_1)}\supset\overline{B_{\delta_2}(x_2)}\supset \dots$

note that $\overline{B_{\delta_n}(x_n)}\cap A_j=\emptyset,j=1,2, \dots ,n-1$ and $\delta_n\to 0$

$\exists!\xi\in \cap \overline{B_{\delta_j}(x_j)}$, thus, $\xi\notin A_n,\forall n\in N$

on the other hand, $\xi\in \overline{B_{\delta_1}(x_1)}\subset \cup_{n=1}^\infty A_n$, contradicts!

### Def. contraction mapping 压缩映射

let $\Omega\subset(X,d)$ and $f:\Omega\to \Omega$ s.t. $d(f(x),f(y))\leq qd(x,y),\forall x,y\in \Omega$ for some $0\leq q<1$, then $f$ is called a contraction mapping

### Thm. Banach fixed point thm 压缩映像原理

let $\Omega\subset(X,d),\Omega$ is closed and $(X,d)$ is complete, $f:\Omega\to\Omega$ is a contraction mapping, then $\exists!\xi\in\Omega,f(\xi)=\xi$

Proof. $\forall x_1\in\Omega$, define $x_{n+1}=f(x_n)$

$\forall m>n,d(x_m,x_n)\leq d(x_m,x_{m-1})+ \dots +d(x_{n+1},x_n)$

$\leq (q^{m-2}+q^{m-3}+ \dots +q^{n-1})d(x_2,x_1)\leq \frac{q^{n-1}}{1-q}d(x_2,x_1)\to 0$, as $n\to\infty$

thus, $\lbrace x_n\rbrace$ is Cauchy, $\exists!\xi\in \Omega,x_n\to\xi$

$d(f(\xi),\xi)\leq d(f(\xi),f(x_n))+d(x_{n+1},\xi)=qd(\xi,x_n)+d(\xi,x_{n+1})\to 0$

thus, $d(f(\xi),\xi)=0,f(\xi)=\xi$

if $f(\eta)=\eta,d(f(\eta),f(\xi))=d(\eta,\xi)=qd(\eta,\xi),d(\eta,\xi)=0,\eta=\xi$

### Def. open cover

let $\Omega\subset (X,d)$, if $\lbrace G_\lambda\rbrace_{\lambda\in\Lambda}$ is a family of open sets s.t. $\Omega\subset \cup_{\lambda\in\Lambda}G_\lambda$, then $\lbrace G_\lambda\rbrace_{\lambda\in\Lambda}$ is called an open cover of $\Omega$

in particular, if $\exists\Lambda^*\subset\Lambda,\#\Lambda^*<\infty$ s.t. $\Omega\subset \cup_{\lambda\in\Lambda^*}G_\lambda$, then $\lbrace G_\lambda\rbrace_{\lambda\in\Lambda^*}$ is called a finite sub-cover

### Def. compact

$\Omega\subset (X,d)$ is called compact if each open cover of $\Omega$ has a finite sub-cover

Example: $\Omega\subset R$, bounded and closed $\Leftrightarrow\Omega$ is compact

### Thm.

$\Omega$ is compact $\Rightarrow \Omega$ is bounded and closed

Proof. $\forall y\in\Omega$, define $\Omega_n:=\lbrace x|d(x,y)<n\rbrace,n\in N$

note that $\Omega\subset\cup_{j=1}^{\infty}\Omega_j=X$, and $\Omega_1\subset\Omega_2\subset \dots$

thus, $\exists t,\Omega\subset\Omega_t$, i.e. $\Omega$ is bounded

$\forall y\in\Omega^c$, define $\Omega_n:=\lbrace x|d(x,y)>\frac{1}{n}\rbrace,n\in N$

note that $\Omega\subset X\setminus\lbrace y\rbrace=\cup_{j=1}^\infty\Omega_n$, and $\Omega_1\subset\Omega_2\subset \dots$

$\exists t, \Omega\subset \Omega_t$, i.e. $B_{\frac{1}{t}}(y)\subset\Omega^c,\Omega^c$ is open, $\Omega$ is closed

### Thm.

let $\Omega\subset R^n$, then the following are equivlant

(1) $\Omega$ is compact

(2) $\Omega$ is sequential compact, i.e. each sequence in $\Omega$ has a convergent sub-sequence, and the limit is in $\Omega$

(3) $\Omega$ is closed and bounded

Proof. (1) $\Rightarrow$ (2) let $\lbrace x_n\rbrace\in\Omega$, if not, $\forall x\in \epsilon,\exists\delta_x>0,B_{\delta_x}(x)$ contains finite points of $\lbrace x_n\rbrace$

as $\lbrace B_{\delta_x}(x)\rbrace_{x\in\Omega}$ is an open cover of $\Omega$, exists finite sub-cover s.t. $\Omega\subset \cup_{j=1}^N B_{\delta_{x_j}}(x_j)$

but there are only finite elements of $\lbrace x_n\rbrace$ in $\cup_{j=1}^N B_{\delta_{x_j}}(x_j)$, contradicts!

(2) $\Rightarrow$ (3) if $\Omega$ is unbounded, $\exists x_n\in\Omega,d(x_n,x_1)\uparrow +\infty$, obviously there are no convergent sub-sequence of $\lbrace x_n\rbrace$, contradicts!

if $\Omega$ is open, $\exists x_n\in\Omega,x_n\to x,x\notin\Omega$, on the other hand, the convergent sub-sequence of $\lbrace x_n\rbrace$, i.e. itself, $\to x\in\Omega$, contradicts!

(3) $\Rightarrow$ (1) assume $A$ bounded and closed, $\lbrace \Omega_n\rbrace$ is an open cover of A, and any $\cup_{j=1}^N\Omega_{n_j}$ cannot cover $A$

choose an closed cube $I_1\supset A$, divide $I_1$ into $2^n$ parts, claim that there exists $I_2\subset I_1$, any $\cup_{j=1}^N\Omega_{n_j}$ cannot cover $I_2\cap A$

repeat, then we have $I_1\supset I_2\supset \dots ,diamI_n\to 0$, any $\cup_{j=1}^N\Omega_{n_j}$ cannot cover $I_n\cap A,\forall n$

$\exists!\xi\in\cap I_n\cap A$, as $\cup\Omega_n\supset A,\exists t,\xi\in \Omega_t$

let $n\to\infty$, as $diamI_n\to 0,I_n\subset \Omega_t$, contradicts!

#### Cor.

let $\lbrace x_n\rbrace\in R^d$,bounded, then $\lbrace x_n\rbrace$ has a convergent sub-sequence

Rmk. the corollary above is not correct in $R^\infty$

### Def. continuity

given $\zeta\in X$ and $f:(X,d)\to (Y,\rho)$, if $\forall\epsilon>0,\exists\delta=\delta(\epsilon)>0$ s.t. if $d(x,\zeta)<\delta,\rho(f(x),f(\zeta))<\epsilon$, then $f$ is continuous at $\zeta$

notation. $f\in C(\Omega,Y),\Omega\subset X$ means $f$ is continuous at each $x\in\Omega$

Rmk. if $y=R$, then $f$ is called a function

### Thm. Heine

let $f:(X,d)\to (Y,\rho)$ and $\zeta\in X$, $f$ is continuous at $\zeta$ iff $x_n\in X,x_n\to\zeta$ implies $f(x_n)\to f(\zeta)$

Proof. $\Rightarrow \forall\epsilon>0,\exists \delta>0$ s.t. if $d(x,\zeta)<\delta,\rho(f(x),f(\zeta))<\epsilon$

for the $\delta$ given above, $\exists N$ s.t. if $n>N,d(x_n,\zeta)<\delta,\rho(f(x_n),f(\zeta))<\epsilon$

i.e. $\lim_{n\to\infty} f(x_n)=f(\zeta)$

$\Leftarrow$ if not, $\exists\epsilon>0,\forall n>0,\exists x_n\in B_{\frac{1}{n}}(\zeta)\cap X, \rho(f(x_n),f(\zeta))>\epsilon$

by the assumption, $x_n\in X,x_n\to\zeta$ implies $f(x_n)\to f(\zeta)$, contradicts!

### Thm.

$f\in C(X,Y)\Leftrightarrow \forall \Omega\subset Y$ open, $f^{-1}(\Omega)$ is open, where $f^{-1}(\Omega):=\lbrace x\in X|f(x)\in\Omega\rbrace$

Proof. $\Rightarrow\forall \zeta\in f^{-1}(\Omega),\exists\epsilon>0,B_\epsilon(f(\zeta))\subset \Omega$

for the $\epsilon$ given above, $\exists\delta>0,f(B_\delta(\zeta))\subset B_\epsilon(f(\zeta))\subset \Omega$

$B_\delta(\zeta)\subset f^{-1}(\Omega),\zeta\in int f^{-1}(\Omega),f^{-1}(\Omega)$ is open

$\Leftarrow\forall \zeta\in X,\forall\epsilon>0,\zeta\in f^{-1}(B_\epsilon(f(\zeta)))$

$\exists\delta>0,B_\delta(\zeta)\subset f^{-1}(B_\epsilon(f(\zeta)))$

i.e. $f(B_\delta(\zeta))\subset B_\epsilon(f(\zeta)), f$ is continuous at $\zeta$

### Thm.

let $f\in C(X,Y)$, then $\Omega\subset X$ is compact $\Rightarrow f(\Omega)\in Y$ is compact

Proof. let $\lbrace G_\lambda\rbrace_{\lambda\in\Lambda}$ be any open cover of $f(\Omega)$

thus, $\lbrace f^{-1}(G_\lambda)\rbrace_{\lambda\in\Lambda}$ is an open cover of $\Omega$

as $\Omega$ is compact, $\Omega\subset \cup_{j=1}^N f^{-1}(G_{\lambda_j})$

i.e. $f(\Omega)\subset \cup_{j=1}^N G_{\lambda_j}, f(\Omega)$ is compact

### Def. uniform continuity 一致连续

$f:(X,d)\to (Y,\rho)$ is called uniformly continuous if $\forall\epsilon>0,\exists\delta=\delta(\epsilon)>0$ s.t. if $d(x,x')<\delta,\rho(f(x),f(x'))<\epsilon$

### Thm.

let $f\in C(X,Y),\Omega\subset X$ be compact, then $f$ is uniformly continuous on $\Omega$

Proof. if not, $\exists \epsilon>0,\forall \frac{1}{n}>0,\exists a_n,b_n\in X,d(a_n,b_n)<\frac{1}{n},\rho(f(a_n),f(b_n))>\epsilon$

as $\Omega$ is compact, $\lbrace a_n\rbrace,\lbrace b_n\rbrace$ has convergent sub-sequence, WLOG, assume $a_n\to a,b_n\to b$

$d(a,b)\leq d(a,a_n)+d(a_n,b_n)+d(b_n,b)\to 0,a=b$

$\epsilon<\rho(f(a_n),f(b_n))\leq\rho(f(a_n),f(a))+\rho(f(b_n),f(b))\to 0$, contradicts!

#### Cor.

let $f\in C(X,R), X$ be compact, then $\exists\xi,\eta\in X,f(\xi)=\max f,f(\eta)=\min f$

### Def. path-connected

let $\Omega\subset (X,d),\Omega$ is called path-connected if $\forall x,y\in \Omega,\exists \sigma\in C([0,1],\Omega)$ s.t. $\sigma(0)=x,\sigma(1)=y$

### Thm.

let $\Omega$ be path-conected and let $f\in C(\Omega,Y)$, then $f(\Omega)\in Y$ is path-connected

Proof. $\forall y_1,y_2\in f(\Omega)$, let $f(x_1)=y_1,f(x_2)=y_2$

$\exists \sigma \in C([0,1],\Omega)$ s.t. $\sigma(0)=x_1,\sigma(1)=x_2$

it is easy to show $f\circ\sigma\in C([0,1],f(\Omega)),f\circ\sigma(0)=y_1,f\circ\sigma(1)=y_2$

i.e. $f(\Omega)$ is path-connected

#### Cor.

let $\Omega$ be path-conected and let $f\in C(\Omega,R)$, if $f(a)f(b)\leq 0$ for $a,b\in\Omega,\exists\xi\in\Omega,f(\xi)=0$

Proof. note that path-connected set in R must be an interval

### Def.

let $f\in(R^2,R)$, given $L\in R$, if $\forall\epsilon>0,\exists\delta=\delta(\epsilon)>0$ s.t. if $0<||(x,y)-(\xi,\eta)||<\delta,|f(x,y)-L|<\epsilon$, then $\lim_{(x,y)\to(\xi,\eta)}f(x,y)=L$

### Def. homeomorphism 同胚

if $f:X\to Y$ s.t.

(i) $f\in C(X,Y)$

(ii) $f$ is a bijection

(iii) $f^{-1}\in C(Y,X)$

then $f$ is called a homeomorphism

two sets $A$ and $B$ are called homeomorphic if $\exists f:A\to B$ is a homeomorphism

### Thm.

let $f:R^2\to R$ be continuous on x,y respectively, and $f$ is monotone on y, then $f\in C(R^2,R)$

Proof. WLOG, assume $y\uparrow$, it suffices to show $f$ is continuous at $(0,0)$

$\forall\epsilon>0,\exists\delta>0$ s.t. if $|y|<\delta,|f(0,y)-f(0,0)|<\epsilon$

$\exists\delta'>0$ s.t. if $|x|<\delta',|f(x,\delta)-f(0,\delta)|<\epsilon,|f(x,-\delta)-f(0,-\delta)|<\epsilon$

$\forall (x,y)\in [-\delta',\delta']\times[-\delta,\delta],f(x,-\delta)\leq f(x,y)\leq f(x,\delta)$

as $|f(x,-\delta)-f(0,0)|<2\epsilon,|f(x,\delta)-f(0,0)|<2\epsilon,|f(x,y)-f(0,0)|<2\epsilon$

i.e. $f$ is continuous at $(0,0)$

### Def. convex set

$\Omega\subset R^n$ is called convex if $\forall x,y\in\Omega,(1-t)x+ty\in\Omega,\forall t\in[0,1]$

### Def. convex function

let $f:R^n\to R, f$ is called convex if $\forall x,y\in\Omega,f((1-t)x+ty)\leq (1-t)f(x)+tf(y),\forall t\in[0,1]$

## differentiation of several variables

### Def. directional derivative

let $f:\Omega\to R,\Omega\subset R^d$ open, the directional derivative of $f$ at $p\in \Omega$ along the unit vector $\nu$ is defined by: $\frac{\partial f}{\partial \nu}(p):=\lim_{t\to 0}\frac{f(p+t\nu)-f(p)}{t}$, provided the limit exists

in particular, if $\nu=e_j=(0, \dots ,0,1,0, \dots ,0)$, where the $j^{th}$ is 1, then we define $\partial_j f(p)=\partial_{x_j}f(p)=\frac{\partial f}{\partial x_j}(p):=\frac{\partial f}{\partial e_j}(p)$

the high order directional derivative are written as $\frac{\partial^2f}{\partial x_i\partial x_j}:=\frac{\partial}{\partial  x_i}(\frac{\partial f}{\partial x_j})$, in particular, $\frac{\partial^2f}{\partial x_j^2}:=\frac{\partial}{\partial  x_j}(\frac{\partial f}{\partial x_j})$, etc.

Rmk. existence of all first order directional derivatives $\nRightarrow$ continuity

### Def. differentiable

let $\emptyset\neq\Omega\subset R^d$ be open and $f:\Omega\to R$, we say that $f$ is differentiable at $p\in\Omega$, if their exists a linear mapping $L=L(p):R^d\to R$ s.t. $f(x)=f(p)+Lh+o(||h||)$, as $h:=x-p\to 0$

moreover, $df(p)h:=Lh,\forall h\in R^d$ is called the differentiation of $f$ at p

Rmk. it is easy to show differentiable $\Rightarrow$ continuity

### Def. gradient

note that $df(p):R^d\to R\in (R^d)^*$, by the representation thm in algebra, $\exists! \xi\in R^d,df(p)h=<\xi,h>,\forall h\in R^d$

$\nabla f(p):=\xi$ is called the gradient of $f$ at p

Rmk. write $\xi=\xi_1e_1+ \dots +\xi_de_d,h=h_1e_1+ \dots +h_de_d$, then $df(p)h=\xi_1h_1+ \dots +\xi_dh_d$

$\forall j$ fixed, choose $h=h_je_j, f(x)-f(p)=Lh+o(||h||)=\xi_jh_j+o(h_j)$

i.e. $\xi_j=\frac{f(p+h_je_j)-f(p)}{h_j}+o(1)$, let $h\to 0,\xi_j=\partial_jf(p)$

thus, $\nabla f(p)=\xi=(\partial_1f(p), \dots ,\partial_df(p))^T\in R^d$

### Thm.

if $f:\Omega\to R$ is differentiable at $p\in\Omega$, then for each $\nu\in R^d,||\nu||=1,\frac{\partial f}{\partial \nu}(p)=\langle\nabla f(p),\nu\rangle\leq ||\nabla f(p)||$, and "=" holds if $\nu=\pm\frac{\nabla f(p)}{||\nabla f(p)||}$

Proof. $f(p+t\nu)-f(p)=\langle\nabla f(p),t\nu\rangle+o(||t\nu||)$

$\langle\nabla f(p),\nu\rangle=\frac{f(p+t\nu)-f(p)}{t}+o(1)$, let $t\to 0,\langle\nabla f(p),\nu\rangle=\frac{\partial f}{\partial \nu}(p)$

the inequality is obvious

Rmk. the inequality shows that the gradient is the direction where the directional derivative attains its maximun

### Thm.

let $f: \Omega\to R$ be differentiable at $p\in\Omega$, if $f$ attains its local maximun at p, then $\nabla f(p)=0$

Proof. let $p=(p_1,p_2, \dots ,p_d)$, define $\phi_j(x):=F(p_1, \dots ,p_{j-1},x,p_{j+1}, \dots ,p_d)$

note that $\forall j,\phi_j(x)$ attains its local maxinun at $x=p_j$, by Fermat's thm, $\phi_j'(p_j)=0$

as $\phi_j'(p_j)=\partial_j f(p),\nabla f(p)=0$

### Thm.

$\partial_j f(p)$ is continuous at $p$ for all $j\Rightarrow f$ is differentiable at $p$

Proof. take d=2 as example, let $p=(a,b),x-a=h,y-b=k$

$f(x,y)-f(a,b)=f(x,y)-f(a,y)+f(a,y)-f(a,b)$

$=\partial_xf(\xi,y)h+\partial_yf(a,\eta)k=(\partial_xf(a,b)+o(1))h+(\partial_yf(a,b)+o(1))k$

$=\langle\nabla f(p),(h,k)\rangle+o(||(h,k)||)$

i.e. $f$ is differentiable at $p$

### Def. differentiation of mapping

let $F=(f_1, \dots ,f_l):\Omega\to R^l,\emptyset\neq\Omega\subset R^d$ open, we say $F$ is differentiable at $p\in\Omega$ if $\exists$ linear mapping $L:R^d\to R^l$ s.t. $F(x)-F(p)=Lh+o(||h||)$, as $h:=x-p\to 0$

moreover, $dF(p)u:=Lu,\forall u\in R^d$ is called the differentiation of $F$ at $p$

Rmk. for each j fixed, $df_j(p)h=\langle\nabla f_j(p),h\rangle=(\nabla f_j(p))^Th$

thus, $dF(p)h=\begin{bmatrix}(\nabla f_1(p))^T\\ (\nabla f_2(p))^T\\  \dots \\ (\nabla f_l(p))^T\\  \end{bmatrix}h=(\frac{\partial f_i}{\partial x_d})_{l\times d}h$

the matrix $(\frac{\partial f_i}{\partial x_d})_{l\times d}$ is also written as $DF$ or $\frac{\partial(f_1, \dots ,f_l)}{\partial(x_1, \dots ,x_d)}$

### Thm. chain rule

if $F:R^d\to R^n$ and $G:R^n\to R^l$ be differentiable, then $G\circ F:R^d\to R^l$ is differentiable and $D(G\circ F(p))=DG(F(p))\cdot DF(p)$

Proof. write $h=x-p,F(x)-F(p)=DF(p)h+o(||h||)$

$G(F(x))-G(F(p))=DG(F(p))(F(x)-F(p))+o(||F(x)-F(p)||)$

$=DG(F(p))(DF(p)h+o(||h||))+o(||DF(p)h+o(||h||)||)$

$=DG(F(p))DF(p)h+o(||h||)$

i.e. $G\circ F$ is differentiable and $D(G\circ F(p))=DG(F(p))\cdot DF(p)$

### Thm. mean value thm

let $\Omega\subset R^d$ be a convex region and let $f:\Omega\to R$ be differentiable, then $\forall a,b\in\Omega,\exists\theta\in(0,1)$ s.t. $f(b)-f(a)=\langle\nabla f(a+\theta h),h\rangle$, where $h:=b-a$

Proof. introduce $\phi(t):=f(a+th)$, by chain rule, $\phi'(t)=\langle\nabla f(a+th),h\rangle$

by Lagrange mean value thm, $\exists \theta\in[0,1],\phi(1)-\phi(0)=\phi'(\theta)(1-0)$

i.e. $f(b)-f(a)=\langle\nabla f(a+\theta h),h\rangle$

### Thm.

let $\Omega\subset R^d$ be a convex region and let $F=(f_1, \dots ,f_m):\Omega\to R^m$ s.t. $F\in C^1(\Omega,R^m)$, then $\forall a,b\in\Omega,F(b)-F(a)=\int_0^1DF(a+th)hdt$, where $h:=b-a$

Proof. $\forall j$ fixed, introduce $\phi_j(t):=f_j(a+th)$

$f_j(b)-f_j(a)=\phi_j(1)-\phi_j(0)=\int_0^1\phi_j'(t)dt=\int_0^1\langle\nabla f_j(a+th),h\rangle dt$

thus, $f(b)-f(a)=\begin{bmatrix}f_1(b)-f_1(a)\\  \dots \\ f_m(b)-f_m(a)\end{bmatrix}=\begin{bmatrix}\int_0^1\langle\nabla f_1(a+th),h\rangle dt\\  \dots \\ \int_0^1\langle\nabla f_m(a+th),h\rangle dt\end{bmatrix}$

$=\begin{bmatrix}\int_0^1(\nabla f_1(a+th))^Thdt\\  \dots \\ \int_0^1(\nabla f_m(a+th))^Thdt\end{bmatrix}=\int_0^1DF(a+th)hdt$

### Thm.

let $f:\Omega\to R,\Omega\subset R^2$, if $\partial_{xy}f$ and $\partial_{yx}f$ are continuous at $p=(a,b)$, then $\partial_{xy}f(p)=\partial_{yx}f(p)$

Proof. WLOG, let $p=(0,0)$,introduce $u(x):=f(x,y)-f(x,0),v(y):=f(x,y)-f(0,y)$

$u(x)-u(0)=u'(\theta)x=(\partial_xf(\theta,y)-\partial_xf(\theta,0))x$

$=\partial_{yx}f(\theta,\phi)yx=(\partial_{yx}f(0,0)+o(1))yx$

similarly, $v(y)-v(0)=(\partial_{xy}f(0,0)+o(1))yx$

note that $u(x)-u(0)=v(x)-v(0),\partial_{xy}f(0,0)=\partial_{yx}f(0,0)$

### Def. multi index

let $\nu=(\nu_1, \dots ,\nu_d)\in Z_{\geq 0}^d,x=(x_1, \dots ,x_d)\in R^d$

define $|\nu|:=\nu_1+ \dots +\nu_d,\nu!:=\nu_1! \dots \nu_d!,x^\nu:=x_1^{\nu_1} \dots x_d^{\nu_d}$

$\begin{pmatrix}|\nu|\\ \nu\\ \end{pmatrix}=\begin{pmatrix}|\nu|\\  \nu_1, \dots ,\nu_d\\  \end{pmatrix}:=\frac{|\nu|!}{\nu_1! \dots \nu_d!}=\frac{|\nu|!}{\nu!}$

### Thm. multinomial thm

$(x_1+ \dots +x_d)^m=\sum_{|\nu|=m}\begin{pmatrix}m\\ \nu\\ \end{pmatrix}x^\nu$

Proof. obviously, it holds for $d=1$, suppose it holds for $d$, then

$(x_1+ \dots +x_{d+1})^m=\sum_{\nu_{d+1}=0}^m\begin{pmatrix}m\\ \nu_{d+1}\\ \end{pmatrix}(x_1+ \dots +x_d)^{m-\nu_{d+1}}x_{d+1}^{\nu_{d+1}}$

$=\sum_{\nu_{d+1}=0}^m\begin{pmatrix}m\\ \nu_{d+1}\\ \end{pmatrix}\sum_{\nu_1+ \dots +\nu_d=m-\nu_{d+1}}\begin{pmatrix}m-\nu_{d+1}\\ \nu_1, \dots ,\nu_d\\ \end{pmatrix}x_1^{\nu_1} \dots x_d^{\nu_d}x_{d+1}^{\nu_{d+1}}$

$=\sum_{\nu_1+ \dots +\nu_{d+1}=m}\begin{pmatrix}m\\ \nu_1, \dots ,\nu_{d+1}\\ \end{pmatrix}x_1^{\nu_1} \dots x_d^{\nu_d}x_{d+1}^{\nu_{d+1}}$

by induction, the statement holds for all $d\in N^*$

### Thm.

let $\Omega\subset R^d$ be convex and $f\in C^n(\Omega,R)$, given $p,p+\zeta\in\Omega,\phi(t):=f(p+t\zeta),t\in[0,1]$, then $\phi^{(n)}(t)=(\zeta\cdot\nabla)^nf(p+t\zeta)$, where $(\zeta\cdot\nabla)^n:=(\zeta_1\partial_{x_1}+ \dots +\zeta_d\partial_{x_d})^n$

Proof. $\forall g\in C^n(\Omega,R),\frac{d}{dt}g(p+t\zeta)=\sum_{j=1}^d\partial_{x_j}g(p+t\zeta)\zeta=(\zeta\cdot\nabla)g(p+t\zeta)$

inductively, $\phi^{(n)}(t)=(\zeta\cdot\nabla)^nf(p+t\zeta)$

### Thm. Taylor's thm

let $\Omega\subset R^d$ be convex and $f\in C^n(\Omega,R)$, given $p,x\in\Omega,\zeta:=x-p$, then $f(x)=f(p)+\sum_{j=0}^{n-1}\frac{1}{j!}(\zeta\cdot\nabla)^jf(p)+\frac{1}{(n-1)!}\int_0^1(1-t)^{n-1}(\zeta\cdot\nabla)^nf(p+t\zeta)dt$

Proof. introduce $\phi(t):=f(p+t\zeta)\in C^n([0,1])$, then

$\phi(1)=\phi(0)+\sum_{j=0}^{n-1}\frac{1}{j!}\phi^{(j)}(0)+\frac{1}{(n-1)!}\int_0^1\phi^{(n)}(t)(1-t)^{n-1}dt$

i.e. $f(x)=f(p)+\sum_{j=0}^{n-1}\frac{1}{j!}(\zeta\cdot\nabla)^jf(p)+\frac{1}{(n-1)!}\int_0^1(1-t)^{n-1}(\zeta\cdot\nabla)^nf(p+t\zeta)dt$

Rmk. by mean value thm, we can rewrite it into lagrange form

$f(x)=f(p)+\sum_{j=0}^{n-1}\frac{1}{j!}(\zeta\cdot\nabla)^jf(p)+\frac{1}{n!}(\zeta\cdot\nabla)^nf(p+\theta\zeta)dt,\theta\in(0,1)$

### Thm.

let $A\in M_d(R)$ be invertible, then $\exists s_1,s_2>0$ s.t. $s_1||x||\leq ||Ax||\leq s_2||x||,\forall x\in R^d$

Proof. the situation $x=0$ is obvious

as $S^{d-1}:=\lbrace x\in R^d|||x||=1\rbrace$ is compact and $||Ax||$ is continuous on $S^{d-1}$, it attains maximun and minimun

let $s_1=\min_{S^{n-1}}||Ax||,s_2=\max_{S^{n-1}}||Ax||$, as $A$ is invertible, $s_1,s_2>0$

$\forall x\neq 0\in R^d,s_1\leq ||A\frac{x}{||x||}||\leq s_2$, i.e. $s_1||x||\leq ||Ax||\leq s_2||x||$

### Thm.

let $F\in C^1(\Omega,R^d),p\in\Omega\subset R^d$, if $DF(p)$ is invertible, then $\exists U$: neighborhood of $p$ and $\sigma>0$ s.t. $||F(x)-F(y)||\geq \sigma||x-y||,\forall x,y\in U$, in particular, $F|_U$ is injective

Proof. $det DF(p)\neq 0\Rightarrow \exists \sigma>0,||DF(p)\eta||\geq 3\sigma||\eta||,\forall \eta\in R^d$

as $DF(x)$ is continuous, $\exists\delta'>0, ||DF(x)\eta||\geq 2\sigma||\eta||,\forall x\in B_{\delta'}(p),\forall \eta\in R^d$

since $F$ is differentiable, $F(y)-F(x)=DF(x)(y-x)+o(||y-x||),\exists 0<\delta<\delta'$ s.t. $\forall x,y\in B_{\delta}(p),o(||y-x||)<\sigma||y-x||$

then, $||F(y)-F(x)||=||DF(x)(y-x)+o(||y-x||)||$

$\geq 2\sigma||y-x||-\sigma||y-x||=\sigma||y-x||,\forall x,y\in U=B_\delta(p)$

### Thm. open mapping thm

let $S\in R^d$ be open, $F\in C^1(S,R^d)$ and DF is invertible, then $F$ is an open mapping, i.e. $\forall \Omega\subset S$ open, $F(\Omega)$ is open

Proof. $\forall x\in\Omega,detDF(x)\neq 0,\exists\lambda>0,||DF(x)v||\geq \lambda||v||,\forall v\in R^d$

$\exists \delta>0$ s.t. if $u\in \overline{B_{\delta(x)}},F(u)-F(x)=DF(x)(u-x)+o(||u-x||)\geq \frac{\lambda}{2}||u-x||$

in particular, choose $z\in \partial B_{\delta(x)},F(z)-F(x)\geq \frac{\lambda\delta}{2}$

thus, $\forall y_0\in B_{\frac{\lambda\delta}{4}}(F(x)),||y_0-F(x)||<\frac{\lambda\delta}{4}<||y_0-F(z)||$

let $\phi(t):=||y_0-F(t)||^2,t\in\overline{B_{\delta(x)}}$, then $\phi(x)<\phi(t),\forall t\in \partial B_{\delta(x)},\phi$ attains its minimun in its interior point $t_0$

thus, $\nabla\phi(t_0)=2(DF(t_0))^T(F(t_0)-y_0)=0,F(t_0)=y_0$

$y_0\in F(\Omega),B_{\frac{\lambda\delta}{4}}(F(x))\in F(\Omega)$, i.e. $F(x)$ is an interior point of $F(\Omega)$, $F(\Omega)$ is open

### Thm. inverse mapping thm

let $F\in C^k(\Omega,R^d)$ and DF be invertible at $p\in\Omega$, then $\exists U$: neighborhood of $p$ and $V$: neighborhood of $F(p)$ s.t. $F:U\to V$ is bijective and $F^{-1}\in C^k(V,U)$

Proof. by the latest two thms, $\exists U$: neighborhood of $p,F|_U$ is injective, let $V:=F(U),V$ is open, i.e. $V$ is a neighborhood of $F(p)$, then $F:U\to V$ is bijective

it suffices to show $F^{-1}\in C^k(V,U)$

$\forall y,y'\in V,\exists x,x'\in U,f(x)=y,f(x')=y'$

by the structure of $U,\exists\sigma>0,||f(x')-f(x)||\geq \sigma||x'-x||$

i.e. $||f^{-1}(y')-f^{-1}(y)||\leq \frac{1}{\sigma}||y'-y||$

$f^{-1}$ is locally Lipchitz, thus continuous

$\forall y,y'\in V,y'-y=F(F^{-1}(y'))-F(F^{-1}(y))$

$=DF(F^{-1}(y))(F^{-1}(y')-F^{-1}(y))+o(||F^{-1}(y')-F^{-1}(y)||)$

$=DF(F^{-1}(y))(F^{-1}(y')-F^{-1}(y))+o(||y'-y||)$

$F^{-1}(y')-F^{-1}(y)=(DF(F^{-1}(y)))^{-1}(y'-y)+o(||y'-y||)$

i.e. $F^{-1}$ is differentiable at $y$ and $D(F^{-1})(y)=(DF(F^{-1}(y)))^{-1}$

note that $DF^{-1}=(DF\circ F^{-1})^{-1}$

thus, $F^{-1}\in C^j(V)\Rightarrow DF^{-1}\in C^j(V)\Rightarrow F^{-1}\in C^{j+1}(V),\forall j=1,2, \dots ,k-1$

by induction, $F^{-1}\in C^k(V,U)$

### Thm. implicit mapping thm

let $W\subset R^{n+m}$ be open, points in $W$ are written as $(x,y)$, where $x=(x_1, \dots ,x_n),y=(y_1, \dots ,y_m)$, let $F=(f_1, \dots ,f_m)\in C^k(W, R^m)$, let $(x_0,y_0)\in W,f(x_0,y_0)=0,det DF_y(x,y):=(\frac{\partial f_i}{\partial y_j}(x,y))_{m\times m}\neq 0$, then $\exists V\in R^n$ be a neighborhood of $x_0$ and $\exists! g\in C^k(V,R^m)$ s.t.

(i) $y_0=g(x_0)$

(ii) $F(x,g(x))=0,\forall x\in V$

(iii) $Dg(x)=-(DF_y(x,g(x)))^{-1}DF_x(x,g(x))$, where $DF_x(x,y):=(\frac{\partial f_i}{\partial x_j}(x,y))_{m\times n}$

Proof. let $H:W\to R^{n+m},H(x,y):=(x,F(x,y))$, then $H\in C^k(W,R^{n+m}),DH=\begin{bmatrix}I_n&0_{n\times m}\\ DF_x(x,y)&DF_y(x,y)\end{bmatrix},detDH(x,y)\neq 0$

by inverse mapping thm, $\exists V'\times V'',V'\subset R^n,V''\subset R^m$ be a neighborhood of $(x,y),U$ be a neighborhood of $(x,F(x,y))$, and $H^{-1}:=((H^{-1})_1, \dots ,(H^{-1})_{n+m})\in C^k(U,V'\times V'')$,$H^{-1}(x,F(x,y))=(x,y)$

define $V:=\lbrace x\in R^n|(x,0)\in U\rbrace$ and $g:V\to R^m,g(x):=((H^{-1})_{n+1}(x,0), \dots ,(H^{-1})_{n+m}(x,0))$, clearly, $g\in C^k(V,R^m)$

(i) note that $H(x_0,y_0)=(x_0,0)$, thus $H^{-1}(x_0,0)=(x_0,y_0)$, i.e. $g(x_0)=y_0$

(ii) $\forall x\in V,(x,0)\in U,H^{-1}(x,0)=(x,g(x)),H(x,g(x))=(x,0)$, i.e. $F(x,g(x))=0$

(iii) as $F(x,g(x))=0,0=DF(x,g(x))=DF_x(x,g(x))+DF_y(x,g(x))Dg(x)$, i.e. $Dg(x)=-(DF_y(x,g(x)))^{-1}DF_x(x,g(x))$

uniqueness of $g$: let $g'$ satisfies the conditions, then $H(x,g'(x))=(x,0)=H(x,g(x))$, by inverse mapping thm, $H$ is injective, i.e. $g'=g$

Rmk. $g(x)$ is called the implicit mapping determined by $F(x,y)=0$

### Def. diffeomorphism 微分同胚

if $f:X\to Y$ s.t.

(i) $f$ is a homeomorphism

(ii) $f$ and $f^{-1} \in C^\infty$

then we say $f$ is diffeomorphism, written as $f\in Diff(X,Y)$

two sets $A$ and $B$ are called diffeomorphic if $\exists f:A\to B$ is a diffeomorphism

### Thm.

let $U\in R^d$ be open, $f\in C^2(U,R),\nabla f(x_0)=0$, then

(1) if $x_0$ is local minimun of $f,Hess(f)(x_0)\geq 0$

(2) if $Hess(f)(x_0)>0,x_0$ is strict local minimun of $f$

the situation of maximun is similar

Proof. note that by Taylor, $f(x_0+h)-f(x_0)=\frac{1}{2}h^THess(f)(x_0)h+o(||h||^2)$ as $||h||\to 0$

(1) $\forall \nu\in R^d,||\nu||=1$, choose $h=t\nu,t\in R$

then $0\leq f(x_0+h)-f(x_0)=t^2(\frac{1}{2}\nu^THess(f)(x_0)\nu+o(1))$

let $t\to 0,\frac{1}{2}\nu^THess(f)(x_0)\nu\geq 0$

as $\forall \nu\in R^d,||\nu||=1$ the inequality holds, $Hess(f)(x_0)\geq 0$

(2) $\exists P\in GL_d(R),Hess(f)(x_0)=P^TP,\exists \lambda>0,||Px||\geq \lambda ||x||,\forall x\in R^d$, i.e. $h^THess(f)(x_0)h\geq\lambda^2||x||^2$

thus, let $||h||\to 0,f(x_0+h)-f(x_0)\geq\frac{\lambda^2}{2}||h||^2+o(||h||^2)>0$, i.e. $x_0$ is strict local minimun of $f$

### Def. differentiable curve

if $\sigma:[\alpha,\beta]\to R^d$ is differentiable, then $\sigma$ is called a differentiable curve

write $\sigma(t)=(x_1(t), \dots ,x_d(t))^T ,\sigma'(t)=D\sigma(t)=(x_1'(t), \dots ,x_d'(t))^T$ is called the tangent vector of $\sigma$ at $t$

if $\sigma'(t)\neq 0$, then $l:R\to R^d,l(s):=\sigma(t)+s\sigma'(t)$ is called the tangent line of $\sigma$ at $t$, it can also be written as $\frac{x_1-x_1(t)}{x_1'(t)}= \dots =\frac{x_d-x_d(t)}{x_d'(t)}$

### Def. differentiable parametric surface

let $D\in R^d$ be open and let $r=r(u)=r(u_1, \dots ,u_d):D\to R^n(n>d)$ be differentiable, then $r$ is called a differentiable parametric surface

Rmk. if $d=1$, the surface is a curve

for $1\leq j\leq d$, fix $u_1, \dots ,\widehat{u_j}, \dots ,u_d$, then $\sigma_j(x):=r(u_1, \dots ,u_{j-1},x,u_{j+1}, \dots ,u_d)$ is a curve on the surface and $\sigma_j'(x)=\frac{\partial r}{\partial u_j}$

if the vectors $\frac{\partial r}{\partial u_j},1\leq j\leq d$ are linearly independent at $p\in D$, then $T(p):=span\lbrace \frac{\partial r}{\partial u_1}(p), \dots ,\frac{\partial r}{\partial u_d}(p)\rbrace$ is called the tangent space of $r$ at the point $p$, furthermore, $N(p):=T(p)^\bot$ is called the normal space of $r$ at the point $p$, clearly, $dimT(p)=d,dimN(p)=n-d$

### Def. implicit surface in $R^3$

let $D\in R^3$ be open and let $F\in C^k(D,R)$, given $c\in F(D)$, if $\nabla F(x,y,z)=0$ for all $(x,y,z)\in F^{-1}(c)$, then $\Sigma:=F^{-1}(c)$ is called an implicit surface

WLOG, let $\partial_zF(p)\neq 0,p=(x_0,y_0,z_0)\in \Sigma$, then by implicit mapping thm, $\exists U$: neighborhood of $(x_0,y_0)$ and $z\in C^k(U)$ s.t. $F(x,y,z(x,y))=F(p)=c$

consider two curves: $\sigma_{y_0}(x):=(x,y_0,z(x,y_0)),\sigma_{x_0}(y):=(x_0,y,z(x_0,y))$

$\vec{n}=\sigma_{x_0}'\times \sigma_{y_0}'=(-\partial_zx,-\partial_zy,1)^T$

note that $F(x,y,z(x,y))=0\Rightarrow \partial_xF+\partial_zF\partial_xz=\partial_yF+\partial_zF\partial_yz=0$

thus, the normal vector  $\vec{n}=\frac{1}{\partial_zF}(\partial_xF,\partial_yF,\partial_zF)^T=\frac{1}{\partial_zF}\nabla F(p)$

the tangent plane: $\langle r-p,\nabla F(p)\rangle=0,r=(x,y,z)^T$

### Def. implicit surface

let $\Phi=\Phi(x,y)\in C^k(\Omega,R^n),\Omega\subset R^{d+n}$ open, $x\in R^d,y\in R^n$, assume $\frac{\partial \Phi}{\partial y}=n$, then for each fixed $c\in \Phi(\Omega)\subset R^n,\Phi^{-1}(c)$ is called a d-dimensional surface

by implicit mapping thm, $\exists U\in R^d$ and $y\in C^k(U,R^n)$ s.t. $\Phi(x,y(x))=c,\forall x\in U$

write $\Phi=(\phi_1,\phi_2, \dots ,\phi_n)$, then the normal space $N=span\lbrace \nabla\phi_1, \dots ,\nabla\phi_n\rbrace=Im(D\Phi)^T$

note that $0=D(\Phi(x,y(x)))=D\Phi\begin{bmatrix}I_d\\ D_xy\end{bmatrix}$

thus, the tangent space is $T=Im(\begin{bmatrix}I_d\\ D_xy\end{bmatrix})$

clearly, $dimN=n,dimT=d$

### Thm. lagrangian multipliers-warm up

let $U\subset R^2$ be open and let $F,G\in C^1(U,R),\nabla G\neq 0$, if $a=(a_1,a_2)\in U$ is a local extremal point of $F$ subject to the constraint $G(x)=c=const$, then $\exists \lambda_0\in R$ s.t. $\nabla F(a)=\lambda_0\nabla G(a)$

Proof. WLOG, assume $\partial_yG(a)\neq 0$, by implicit mapping thm, $\exists U$: neighborhood of $a_1$, and $y=y(x)\in C^1(U)$ s.t. $G(x,y(x))=G(a)=c$, and $y'(a_1)=-\frac{\partial_xG(a)}{\partial_yG(a)}$

as $a_1$ is a local extremal point of $F(x,y(x)), \partial_xF(a)+\partial_yF(a)y'(a_1)=0$

i.e. $\partial_xF(a)\partial_yG(a)=\partial_yF(a)\partial_xG(a),\begin{vmatrix}\nabla F(a)\\ \nabla G(a)\\ \end{vmatrix}=0$

i.e. $\nabla F(a),\nabla G(a)$ are linearly dependent, $\exists \lambda_0\in R$ s.t. $\nabla F(a)=\lambda_0\nabla G(a)$

### Thm. lagrangian multipliers-general form

let $U\in R^d$ be open and let $F\in C^1(U,R),G\in C^1(U,R^m),m<d,rankDG=m$, if $a\in U$ is a local extremal point of $F$ subject to the constraint $G(x)=c\in R^m$, then $\exists \lambda_0\in R^m$ s.t. $\nabla F(a)=DG(a)^T\lambda_0$

Proof. write points in $U$ as $(x,y),x\in R^m,y\in R^{d-m},a=(a_x,a_y)$, WLOG, assume $det D_xG(a)\neq 0$

by implicit mapping thm, $\exists V\subset R^{d-m}$: neighborhood of $a_y$ and $x=x(y)\in C^1(V,R^m)$ s.t. $G(x(y),y)=G(a)=c$ and $Dx=-(D_xG)^{-1}D_yG$

on the other hand, as $a_y$ is a local extremal point of $F(x(y),y),D_xFDx+D_yF=0$

i.e. $D_xF(D_xG)^{-1}D_yG=D_yF$, define $\lambda_0:=((D_xG)^{-1})^T(D_xF)^T$, then

$D_yF=\lambda_0^TD_yG,D_xF=\lambda_0^TD_xG$

i.e. $(\nabla F)^T=\lambda_0^TDG$, i.e. $\nabla F(a)=DG(a)^T\lambda_0$

algebra proof.

from $Dx=-(D_xG)^{-1}D_yG$, we know that $DG\begin{bmatrix}Dx\\ I_{d-m}\\ \end{bmatrix}=0$

from $D_xFDx+D_yF=0$, we know that $DF\begin{bmatrix}Dx\\ I_{d-m}\\ \end{bmatrix}=0$

consider the equation $[D_x^T I_{d-m}]\alpha=0$, there are $m$ linearly independent vectors in the basic solution

as the rows of DG are all solutions and $rankDG=m$, all solutions, including $\nabla F$, can be represented by the rows of DG

i.e. $\exists \lambda_0\in R^m,\nabla F=(DG)^T\lambda_0$

Rmk. in order to find the extremal point $a$, we need to solve the equation

$(*)\begin{cases}\nabla F(a)=(DG(a))^T\lambda_0\\ G(a)=c\end{cases}$

formally, solving $(*)$ is equivlant to find the critical point $(a,\lambda_0)$ of the so-called lagrangian: $L(x,\lambda):=F(x)-\langle\lambda,G(x)-c\rangle$, thus, $\lambda$ here is called the lagrangian multiplier

## integral of several variables

### Def. box

let $I_j\subset R,j=1,2, \dots ,n$ be bounded intervals, $I=I_1\times I_2\times \dots \times I_n\subset R^n$ is called a box, and $|I|:=\prod_{j=1}^n|I_j|$ is called the measure of $I$

in particular, if $|I_1|= \dots =|I_n|$, then $I$ is called a cube

in the following parts, we take $n=2$ as example, situation in higher dimension is similar

### Def. partition

let $I=[a,b]\times [c,d]\subset R^2$, for any partitions $\pi_x:a=x_0<x_1< \dots <x_n=b,\pi_y:c=y_0<y_1< \dots <y_m=d$, $\pi:=\pi_x\times\pi_y$ is called a partition of $I$

define $I_{ij}:=[x_i,x_{i+1}]\times [y_j,y_{j+1}],||\pi||:=\max_{i,j}diam(I_{ij})$ is called the norm of $\pi$

### Def.

let $F:I\to R,I\subset R^2$ be a box, if their exists $A\in R$ s.t. $\forall\epsilon>0,\exists\delta>0$ s.t. if $||\pi||<\delta,|\sum_{i,j}F(\xi_i,\eta_j)|I_{ij}|-A|<\epsilon,\forall (\xi_i,\eta_j)\in I_{ij}$, then $F$ is called Riemann integrable on $I$, written as $F\in R(I)$, and $\int_IF=\int_IF(x,y)dxdy:=A$

Rmk. similar to one variable, $f$ is Riemann integrable $\Rightarrow f$ is bounded

### Def.

let $F:I\to R$ be bounded, $\pi$ is a partition of $I$, define $m_{ij}:=\inf_{I_{ij}}F,M_{ij}:=\sup_{I_{ij}}F,\omega_{ij}:=M_{ij}-m_{ij}$ is called the oscillation of $F$, $S(\pi):=\sum_{i,j}M_{ij}|I_{ij}|,s(\pi):=\sum_{i,j}m_{ij}|I_{ij}|$ are called the Darboux upper/lower sum

if $\pi_x',\pi_y'$ are refinements of $\pi_x,\pi_y$, then $\pi':=\pi_x'\times\pi_y'$ is called the refinement of $\pi$, written as $\pi'<\pi$

Rmk. similar to single variable

(1) if $\pi'<\pi,S(\pi')\leq S(\pi),s(\pi')\geq s(\pi)$

(2) $\forall \pi,\pi',S(\pi)\geq s(\pi')$

### Thm.

$\inf_\pi S(\pi)=\lim_{||\pi||\to 0}S(\pi),\sup_\pi s(\pi)=\lim_{||\pi||\to 0}s(\pi)$

Proof. $\forall\epsilon>0,\exists \pi'$ s.t. $S(\pi')<\inf_\pi S(\pi)+\epsilon$

assume the partition rectangles of $\pi'$ are $I'_{ij}=[x_i,x_{i+1}]\times [y_j,y_{j+1}]$, then $\exists \delta>0$ s.t. $\sum_{i,j}(|I'_{ij}|-|I''_{ij}|)<\epsilon$, where $I''_{ij}:=[x_i+\delta,x_{i+1}-\delta]\times [y_j+\delta,y_{j+1}-\delta]$

$\forall \pi$ satisfies $||\pi||<\delta$, claim that every partition rectangle of $\pi$, such as $I_{ij}$, satisfies either

(i)  $I_{ij}\subset I'_{ij}$

(ii) $I_{ij}\subset \cup I'_{ij}\setminus \cup {I''_{ij}}$

thus, $S(\pi)=S_{(i)}(\pi)+S_{(ii)}(\pi)\leq S(\pi')+(\sup f-\inf f)|\cup I'_{ij}\setminus \cup {I''_{ij}}|$

$<\inf_\pi S(\pi)+(1+\sup f-\inf f)\epsilon$

i.e. $\lim_{||\pi||\to 0}S(\pi)=\inf_\pi S(\pi)$

### Thm.

let $F:I\to R$ be bounded, then the following are equivlant

(1) $F\in R(I)$

(2) $\inf_\pi S(\pi)=\sup_\pi s(\pi)$

(3) $\lim_{||\pi||\to 0}\sum_{i,j}\omega_{ij}|I_{ij}|=0$

(4) $\forall\epsilon>0,\exists \pi$ s.t. $\sum_{i,j}\omega_{ij}|I_{ij}|<\epsilon$

(5) $\forall \eta,\tau>0,\exists \delta>0$ s.t. if $||\pi||<\delta, \sum_{\omega_{ij}\geq\eta}|I_{ij}|<\tau$

Proof. similar to single variable, omitted

### Def. Lebesgue measure zero set($L_0$ set)

$\Omega\subset R^d$ is called a Lebesgue measure zero set if $\forall\epsilon>0$, there exist at most countable open boxes $\lbrace I_j\rbrace$ s.t.

(i) $\Omega\subset \cup_j I_j$

(ii) $\sum_j |I_j|<\epsilon$

Examples.

(1) at most countable sets

(2) subsets of a $L_0$ set

(3) countable union of $L_0$ sets

(4) $\partial I$

### Def. oscillation

if $F$ is bounded on a neighborhood of $x\in R^d, \omega_F(x):=\lim_{\delta\downarrow 0}\sup_{u,v\in B_\delta(x)}|F(u)-F(v)|$ is called the oscillation of $F$ at $x$

Rmk. $F$ is continuous at $x$ iff $\omega_F(x)=0$

Rmk. similar to single variable, we have Lebesgue criterion

let $F:I\to R$ be bounded, then $F\in R(I)\Leftrightarrow D_f$ is a $L_0$ set

### Def. Jordan measurable set (J set)

$\Omega\subset I\subset R^d$ is called a Jordan measurable set if $\chi_\Omega\in R(I)$, moreover, $|\Omega|:=\int_I\chi_\Omega$ is called the measure of $\Omega$, where $\chi_\Omega(x):=\begin{cases}1,x\in\Omega\\  0,x\in I\setminus\Omega\end{cases}$

Rmk. $|\Omega|$ is well defined since $\int_I\chi_\Omega$ is independent of $I$

### Thm.

let $\Omega\subset R^d$ be bounded, then $\Omega$ is a J set $\Rightarrow \overline{\Omega}$ is a J set

Proof. note that $D_{\chi_\Omega}=\partial\Omega\supset D_{\chi_{\overline{\Omega}}}$

thus, $\Omega$ is a J set $\Rightarrow \chi_\Omega\in R(I)\Rightarrow D_{\chi_\Omega}$ is a $L_0$ set $\Rightarrow D_{\chi_{\overline{\Omega}}}$ is a $L_0$ set

$\Rightarrow \chi_{\overline{\Omega}}\in R(I)\Rightarrow \overline{\Omega}$ is a J set

### Def. Jordan measure zero set ($J_0$ set)

$\Omega\subset R^d$ is called a Jordan measure zero set if $\Omega$ is a J set and $|\Omega|=0$

### Thm.

$\Omega\subset R^d$ is a $J_0$ set iff $\forall\epsilon>0,\exists$ finite open boxes $\lbrace I_j\rbrace_{j=1}^N$ s.t.

(i) $\Omega\subset \cup_{j=1}^N I_j$

(ii) $\sum_{j=1}^N |I_j|<\epsilon$

Proof. $\Rightarrow \Omega$ is a J set $\Rightarrow \partial\Omega$ is a $L_0$ set

$\forall \epsilon>0,\exists \lbrace I_j\rbrace_{j=1}^\infty$ s.t. $\partial\Omega\subset \cup_{j=1}^\infty I_j,\sum_{j=1}^\infty |I_j|<\epsilon$

as $\partial\Omega$ is compact, by Heine-Borel, $\exists N,\partial\Omega\subset \cup_{j=1}^N I_j$

note that as $\Omega$ is a $J_0$ set, $int\Omega=\emptyset,\Omega\subset\partial\Omega$

thus, $\Omega\subset \cup_{j=1}^N I_j,\sum_{j=1}^N |I_j|<\epsilon$

$\Leftarrow$ as $\partial I$ is a $L_0$ set, we can choose $I_j$ all closed

then, $\forall\epsilon>0,\exists \lbrace I_j\rbrace_{j=1}^N,\partial\Omega\subset\overline{\Omega}\subset \cup_{j=1}^N I_j,\sum_{j=1}^N |I_j|<\epsilon$

i.e. $D_{\chi_\Omega}=\partial\Omega$ is a $L_0$ set, $\chi_\Omega\in R(I),\Omega$ is a J set

furthermore, choose the partition containing all the boundaries of $I_j$, then $\chi(x,y)=0,\forall (x,y)\notin \cup_{j=1}^N I_j$

thus, $\sum_{i,k}\chi(x_i,y_k)|I_{ik}|\leq 1\cdot \sum_{i=1}^N|I_j|<\epsilon$

i.e. $\int_I\chi_\Omega=0,\Omega$ is a $J_0$ set

#### Cor.

a $J_0$ set is a $L_0$ set

### Thm.

let $\Omega\subset R^d$ be bounded, then $\Omega$ is a J set iff $\partial\Omega$ is a $J_0$ set

Proof. note that a compact set is a $L_0$ set iff it is a $J_0$ set

thus, $\Omega$ is a J set $\Leftrightarrow\partial\Omega$ is a $L_0$ set $\Leftrightarrow\partial\Omega$ is a $J_0$ set

### Thm.

if $\Omega\subset R^d$ is a $L_0$ set, then $\forall \epsilon>0,\exists \lbrace c_j\rbrace_{j=1}^\infty$: open cubes s.t. $\Omega\subset \cup c_j,\sum |c_j|<\epsilon$

Proof. it suffices to show each open box $I\subset R^d$ can be covered by finite cubes $\lbrace c_j\rbrace$ and $\sum|c_j|\leq 2^d|I|$

write $I=(a_1,b_1)\times (a_2,b_2)\times \dots \times (a_d,b_d),l_j:=b_j-a_j,l:=\min_jl_j$

thus, we can write $l_j$ as $l_j=p_j\frac{l}{2}+\delta_j,p_j\in N,0\leq\delta_j<\frac{l}{2}$

consider $\prod_{j=1}^dp_j$ open cubes

$\lbrace (a_1+k_1\frac{l}{2},a_1+(k_1+2)\frac{l}{2})\times \dots \times(a_d+k_d\frac{l}{2},a_d+(k_d+2)\frac{l}{2})\rbrace_{0\leq k_j\leq p_j-1}$

clearly, the open cubes covers $I$ and $\sum|c_j|=\prod_{j=1}^dp_j\cdot l^d=\prod_{j=1}^d(p_jl)\leq \prod_{j=1}^d(2l_j)=2^d|I|$

### Thm.

(1) let $\Omega\subset I$ be a J set, then $I\setminus \Omega$ is a J set

(2) let $\Omega_1,\Omega_2\subset I$ be J sets, then $\Omega_1\cap\Omega_2,\Omega_1\cup\Omega_2$ are J sets

Proof. (1) $\chi_{I\setminus\Omega}=1-\chi_\Omega$

(2) $\chi_{\Omega_1\cap\Omega_2}=\chi_{\Omega_1}\chi_{\Omega_2},\chi_{\Omega_1\cup\Omega_2}=\chi_{\Omega_1}+\chi_{\Omega_2}-\chi_{\Omega_1}\chi_{\Omega_2}$

### Thm.

suppose $\overline{S}\subset\Omega\subset R^d$, $\Omega$ is a bounded region, $T:\Omega\to R^d$

(1) if $T\in C^1$ and S is a $L_0$ set, then $T(S)$ is a $L_0$ set

(2) if $T\in Diff(\Omega)$ and S is a J set, then $T(S)$ is a J set

Proof. (1)$\forall\epsilon>0,\exists$ countable cubes $\lbrace c_j\rbrace,\cup_jc_j\supset S,\sum_j|c_j|<\epsilon$

let $M:=\max_{\Omega}||DT||$, then $\forall x,y\in\Omega$

$||T(y)-T(x)||=||\langle DT(x+\theta(y-x)),y-x\rangle||\leq M||y-x||$

consider each $c_j$, assume it is centered at $x,\forall y\in c_j$

$||T(y)-T(x)||\leq M||y-x||\leq M\frac{\sqrt[d]{d|c_j|}}{2}$

thus, $\exists c_j'$ be a cube, centered at $T(x)$, with the side length $M\sqrt[d]{d|c_j|}$

clearly, $c_j'\supset T(c_j)$, thus, $\cup_jc_j'\supset T(S),\sum_j|c_j'|=M^dd\sum_j|c_j|<M^dd\epsilon$

i.e. $T(S)$ is a $L_0$ set

(2) as $T\in Diff(\Omega)$, by open mapping thm, $\forall x\in int S,T(x)\in int T(S),\forall x\in int T(S),T(x)\in int S$

thus, $T(\partial S)=\partial T(S)$

S is a J set $\Rightarrow \partial S$ is a $L_0$ set $\Rightarrow T(\partial S)=\partial T(S)$ is a $L_0$ set $\Rightarrow T(S)$ is a J set

### Thm.

let $\Omega\subset R^d$ be a J set, $F\in R(\Omega)$, then $G(F):=\lbrace (x,y)\in R^{d+1},x\in \Omega,y=F(x)\rbrace$ is a $J_0$ set

Proof. $\forall\epsilon>0,\exists \pi$: partition of $\Omega$ s.t. $\sum_j\omega_j|I_j|<\epsilon$

i.e. $\sum_{j}|I_{j}\times[m_j,M_j]|<\epsilon$

clearly, $\cup_j(I_{j}\times[m_j,M_j])\supset G(F)$, i.e. $G(F)$ is a $J_0$ set

### Thm. Lebesgue criterion

let $\Omega\subset I$ be a J set and let $F:\Omega\to R$ be bounded, then $F\in R(\Omega)$ iff $D_F$ is a $L_0$ set

Proof. $\Rightarrow$ note that $D_F\subset D_{F\cdot\chi_\Omega}\cup \partial\Omega$

as $\Omega$ is a J set, $F\in R(\Omega),D_{F\cdot\chi_\Omega}$ and $\partial\Omega$ are $L_0$ sets

thus, $D_F$ is a $L_0$ set

$\Leftarrow$ note that $D_{F\cdot\chi_\Omega}\subset D_F\cup \partial\Omega$

thus, $D_{F\cdot\chi_\Omega}$ is a $L_0$ set, $F\in R(\Omega)$

### Thm.

assume $f,g\in R(\Omega)$, then

(1) $\int_\Omega (f+g)=\int_\Omega f+\int_\Omega g$

(2) if $f\leq g,\int_\Omega f\leq\int_\Omega g$, in particular, $|\int_\Omega f|\leq\int_\Omega |f|$

Proof. similar to single variable, omitted

### Thm.

let $f,g\in R(\Omega),g\geq 0$, then $\exists \mu\in [\inf_\Omega f,\sup_\Omega f]$ s.t. $\int_\Omega fg=\mu\int_\Omega g$

Proof. similar to single variable, omitted

### Thm. Fubini

let $F\in R(I),I=[a,b]\times [c,d]\subset R^2$, if $F(x,y)\in R[a,b],\forall y\in [c,d]$ fixed, then $\int_IF=\int_c^d(\int_a^bF(x,y)dx)dy$, also written as $\int_c^ddy\int_a^bF(x,y)dx$

Proof. define $\phi(y):=\int_a^bF(x,y)dx,\forall \pi=\pi_x\times \pi_y$

$\pi_x:a=x_0<x_1< \dots <x_n=b,\pi_y:c=y_0<y_1< \dots <y_m<d$

note that $\sum_{j=0}^{m-1}\phi(\xi_j)\Delta y_j=\sum_{j=0}^{m-1}\sum_{i=0}^{n-1}\int_{x_i}^{x_{i+1}}F(x,\xi_j)dx\Delta y_j$

thus, $\sum_{j=0}^{m-1}\sum_{i=0}^{n-1}m_{ij}|I_{ij}|\leq \sum_{j=0}^{m-1}\phi(\xi_j)\Delta y_j\leq \sum_{j=0}^{m-1}\sum_{i=0}^{n-1}M_{ij}|I_{ij}|$

note that $\sum_{j=0}^{m-1}\sum_{i=0}^{n-1}m_{ij}|I_{ij}|\leq \int_I F\leq \sum_{j=0}^{m-1}\sum_{i=0}^{n-1}M_{ij}|I_{ij}|$

thus, $|\sum_{j=0}^{m-1}\phi(\xi_j)\Delta y_j-\int_IF|\leq \sum_{i=0}^{n-1}\omega_{ij}|I_{ij}|\to 0$

i.e. $\phi(y)\in R[c,d]$, and $\int_c^d\phi(y)dy=\int_IF$

Rmk. if $F\in R(I)$ and $F(x,y)\in R[c,d],\forall x\in[a,b]$ fixed, then $\int_IF=\int_a^bdx\int_c^dF(x,y)dy$

#### Cor.

let $F\in C(\Omega)$, where $\Omega\subset I=[a,b]\times[c,d]\subset R^2$ be a J set, then $\int_\Omega F=\int_I F\cdot\chi_\Omega=\int_a^bdx\int_c^d F(x,y)\chi_\Omega(x,y)dy$

### Def. support 支集

let $\phi:\Omega\subset R^d\to R^n$, then $supp\phi:=\overline{\lbrace x\in\Omega|\phi(x)\neq 0\rbrace}$ is called the support of $\phi$

Example: the support of Dirichlet function is $[0,1]$

### Def. bump function

$\phi:R^d\to R$ is called a bump function if $\phi\in C^\infty$ and is compact supported (i.e. $supp\phi$ is compact)

Rmk. we can construct a function $\phi$ on $B_\delta(0)$ be bump, in particular, given $\delta'<\delta$, the function can satisfy $\phi(x)=1,\forall x\in B_{\delta'}(0)$

firstly, note that $f(x):=e^{-\frac{1}{x}}\chi_{[0,\infty)}\in C^\infty(R)$

define $g(x):=\frac{f(x)}{f(x)+f(\delta-\delta'-x)}=\begin{cases}0,x\leq 0\\ \frac{f(x)}{f(x)+f(\delta-\delta'-x)}\in(0,1),x\in(0,\delta-\delta')\\ 1,x\geq \delta-\delta'\\ \end{cases}$

define $\psi(x):=g(\delta-|x|)=\begin{cases}1,|x|\leq\delta' \\ g(\delta-|x|)\in(0,1),|x|\in(\delta',\delta)\\ 0,|x|\geq\delta\\ \end{cases}$

thus, we find that $\phi(x):=\psi(||x||)$ satisfies the conditions

### Thm. partition of unity

let $\Omega\subset R^d$ be compact and let $\lbrace A_\lambda\rbrace_{\lambda\in\Lambda}$ is an open cover of $\Omega$, then there are bump functions $\phi_1, \dots ,\phi_n$ s.t.

(i) $0\leq\phi_j\leq 1$

(ii) $\forall j,\exists \lambda\in\Lambda,supp\phi_j\subset A_\lambda$

(iii) $\sum_j\phi_j(x)=1,\forall x\in\Omega$

Proof. $\forall x\in\Omega,\exists\lambda_x$ s.t. $x\in A_{\lambda_x},\exists\delta_x>0$ s.t. $\overline{B_{2\delta_x}(x)}\subset A_{\lambda_x}$

note that $\lbrace {B_{\delta_x}(x)}\rbrace_{x\in\Omega}$ is an open cover of $\Omega$, by Heine-Borel, $\exists N,\Omega\subset\cup_{j=1}^N{B_{\delta_{x_j}}(x_j)}$

let $\psi_j\in C^\infty$ be the bump function constructed by the latest rmk, i.e. it satisfies

(i) $\psi_j(x)=1,\forall x\in B_{\delta_{x_j}}(x_j)$

(ii) $\psi_j(x)\in(0,1),\forall x\in B_{2\delta_{x_j}}(x_j)\setminus B_{\delta_{x_j}}(x_j)$

(iii) $\psi_j(x)=0,\forall x\notin B_{2\delta_{x_j}}(x_j)$

then we define $\phi_j:=(1-\psi_1)(1-\psi_2) \dots (1-\psi_{j-1})\psi_j$

obviously, $\phi_j\in[0,1],\forall x\in\Omega$ and $supp\phi_j\subset supp\psi_j=B_{2\delta_{x_j}}\subset A_{\lambda_{x_j}}$

by induction, we can find that $\sum_j\phi_j=1-\prod_j(1-\psi_j)$

thus, $\forall x\in\Omega,\exists j,x\in B_{\delta_{x_j}}(x_j),\psi_j(x)=1,\sum_j\phi_j(x)=1$

also, by the construction of $\phi_1, \dots ,\phi_N$, they are bump functions, thus, they satisfy the conditions

### Def. dilation 伸缩

let $\Omega\subset R^d$ be open, $G:\Omega\to R^d$ is called a dilation if $\exists k$ s.t. $\langle G(x),e_j\rangle=\langle x,e_j\rangle=x_j,\forall j\neq k$

Rmk. in other words, $\exists g:\Omega\to R^d,k$ s.t. $G(x)=x+\langle g(x)-x_k,e_k\rangle$

moreover, $G$ is differentiable iff $g$ is differentiable, and $detDG=\partial_kg$

### Def. permutation 置换

a linear mapping $B:R^d\to R^d$ that interchanges $e_i$ and $e_j$ is called a permutation, i.e. $B(x_1, \dots ,x_i, \dots ,x_j, \dots ,x_d)=(x_1, \dots ,x_j, \dots ,x_i, \dots ,x_d),\forall x\in R^d$

### Def. projection 投影

$P_j:R^d\to R^j(j\leq d),P_j(x_1, \dots ,x_j,x_{j+1}, \dots ,x_d):=(x_1, \dots ,x_j)$ is called a projection, in particular, $P_0(x):=0,\forall x\in R^d$

### Thm. elementary decomposition 基本分解

let $0\in\Omega\subset R^d$ be open, $F\in C^1(\Omega,R^d),F(0)=0,DF(0)$ be invertible, then $\exists U$: neighborhood of 0 s.t. $F(x)=B_1\circ \dots \circ B_{d-1}\circ G_d\circ \dots \circ G_1 (x),\forall x\in U$, where $G_j$ are dilations and $B_j$ are permutations

Proof. write $F_1:=F$, clearly, $P_0\circ F(x)=0=P_0(x)$

suppose $m<d$ satisfies

$H_1:\exists V_m$: neighborhood of 0, $F_m\in C^1(V_m),F_m(0)=0,DF_m(0)$ be invertible

$H_2:P_{m-1}\circ F_m(x)=P_{m-1}(x),\forall x\in V_m$

by $H_2,F_m(x)=(x_1, \dots ,x_{m-1},f_m(x), \dots ,f_d(x))$

as $DF_m(0)$ is invertible, $D_mF_m(0)=(0, ,0,\partial_mf_m(0), \dots ,\partial_mf_d(x))\neq 0$

$\exists k,\partial_mf_k(0)\neq 0$, define $B_m$ be the permutation interchanges $e_k$ and $e_m$

define $G_m(x):=x+\langle f_k(x)-x_m,e_m\rangle$ be a dilation

clearly, $G_m\in C^1,detDG_m(0)=\partial_mf_k(x)\neq 0,DG_m(0)$ is invertible

by inverse mapping thm, $\exists U_m$: neighborhood of 0, $U_m\subset V_m$ s.t. $G_m\in Diff(U_m,V_{m+1})$, where $V_{m+1}:=G_m(U_m)$

define $F_{m+1}(y):=B_m\circ F_m\circ G_m^{-1}(y),\forall y\in V_{m+1}$, claim that $F_{m+1},V_{m+1}$ satisfies $H_1,H_2$

as $B_m\in C^1(R^d),F_m\in C^1(V_m),G_m^{-1}\in C^1(V_{m+1}),F_{m+1}\in C^1(V_{m+1})$

$F_{m+1}(0)=B_m\circ F_m(0)=B_m(0)=0$

$detF_{m+1}(0)=detB_m(0)detF_m(0)detG_m^{-1}(0)\neq 0$

$P_m\circ F_{m+1}\circ G_m(x)=P_m\circ B_m\circ F_m(x)=P_m(x_1, \dots ,x_{m-1},f_k(x), \dots )$

$=(x_1, \dots ,x_{m-1},f_k(x))=P_m\circ G_m(x)$

i.e. $P_m\circ F_{m+1}(y)=P_m(y),\forall y\in V_{m+1}$

thus, the claim that $F_{m+1},V_{m+1}$ satisfies $H_1,H_2$ is proved

as $H_1,H_2$ holds for $m=1$, thus, by induction, $H_1,H_2$ holds for $m=1,2, \dots ,d$

thus, we have $F_1, \dots ,F_d,F_{j+1}=B_j\circ F_j\circ G_j^{-1}$, i.e. $F_j=B_j\circ F_{j+1}\circ G_j$

then, $F=F_1=B_1\circ F_2\circ G_2= \dots =B_1\circ \dots \circ B_{d-1}\circ F_d\circ G_{d-1}\circ \dots \circ G_1$

by $H_2, F_d$ is a dilation

thus, $F(x)=B_1\circ \dots \circ B_{d-1}\circ G_d\circ \dots \circ G_1 (x),\forall x\in U$, where $G_j$ are dilations and $B_j$ are permutations

### Thm. change of variables in multiple integrals

let $\Omega\subset R^d$ be open, $T\in Diff(\Omega)$ and let S be a J set s.t. $\overline{S}\subset \Omega$ if $F\in C^1,suppF\subset T(S)$, then $\int_{T(S)}F(y)dy=\int_S F\circ T(x)|detDT|dx$

Proof. by thm above, $T(S)$ is a J set

Step 1. it holds for dilations

WLOG, assume $T(x_1, \dots ,x_d):=(x_1, \dots ,x_{d-1},t(x))$ be a dilation

WLOG, assume $\partial_dt(x)>0$

then $\int_S F\circ T(x)|detDT(x)|dx=\int dx_1 \dots dx_{d-1}\int F\circ T(x)\partial_dt(x)dx_d$

$=\int dx_1 \dots dx_{d-1}\int F\circ T(x)d(t(x))_d=\int_SF\circ T(x)d(x_1, \dots ,x_{d-1},t(x))$

$=\int_SF\circ T(x)d(T(x))=\int_{T(S)}F(y)dy$

Step 2. it holds for permutations

in fact, if T is a permutation, $|detDT|=1$, it is Fubini thm

Step 3. it keeps after composition

if $P,Q$ satisfies the equality, then

$\int_{P\circ Q(S)}F(z)dz=\int_{Q(S)}F\circ P(y)|detDP(y)|dy$

$=\int_SF\circ P\circ Q(x)|detDP(Q(x))||detDQ(x)|dx$

$=\int_SF\circ(P\circ Q)(x)|detD(P\circ Q)|dx$

Step 4. the equation is true locally

by elementry decomposition, $\forall x_0\in S,\exists U$: neighborhood of $x_0, T(x)=T(x_0)+B_1\circ \dots \circ B_{d-1}\circ G_d\circ  \dots \circ G_1(x-x_0),\forall x\in U$

note that translation(平移) does not change the value of the integral

thus, $\int_{T(U)}F(y)dy=\int_U F\circ T(x)|detDT|dx$

Step 5. the equation is true globally on S

note that $suppF$ is bounded and closed, i.e. is compact

let $\lbrace A_\lambda\rbrace_{\lambda\in\Lambda}$ be an open cover of $suppF$ s.t. the equation is true on every $A_\lambda$

by partition unity, $\exists \phi_1, \dots ,\phi_N$: bump functions s.t. $\sum_j\phi_j=1,\forall x\in suppF$

i.e. $\sum_{j=1}^N\phi_j(x)F(x)=F(x),\forall x\in suppF$

thus, $\int_{T(S)}F(y)dy=\sum_{j=1}^N\int_{T(S)}\phi_j(y)F(y)dy$

$=\sum_{j=1}^N\int_S\phi_j(T(x))F(T(x))|detDT|dx=\int_SF\circ T(x)|detDT|dx$

### Thm. smooth approximation 光滑逼近

let $\Omega\subset R^n$ be compact and let $F\in C(\Omega,R^d)$, then $\forall\epsilon>0,\exists G\in C^\infty(\Omega,R^d)$ s.t. $||F(x)-G(x)||<\epsilon,\forall x\in\Omega$

Proof. $\forall x\in \Omega, \exists U_x$: neighborhood of $x$ s.t. $\sup_{u,v\in U_x}||F(u)-F(v)||<\epsilon$

as $\lbrace U_x\rbrace_{x\in\Omega}$ is an open cover of $\Omega$, by partition of unity, $\exists \phi_1, \dots ,\phi_N\in C^\infty$ s.t.

(i) $\forall j,\exists x_j,supp\phi_j\subset U_{x_j}$

(ii) $0\leq \phi_j(x)\leq 1,\forall j,\forall x\in\Omega$

(iii) $\sum_j\phi_j(x)=1,\forall x\in\Omega$

define $G(x):=\sum_j\phi_j(x)F(x_j)$, clearly, $G\in C^\infty$

$\forall x\in\Omega,||F(x)-G(x)||=||\sum_j\phi_j(x)F(x)-\sum_j\phi_j(x)F(x_j)||$

note that $||\phi_j(x)(F(x)-F(x_j))||\begin{cases}\leq \phi_j(x)||F(x)-F(x_j)||<\phi_j(x)\epsilon, x\in U_{x_j}\\ =0,x\notin U_{x_j}\end{cases}$

thus, $||F(x)-G(x)||=||\sum_j\phi_j(x)(F(x)-F(x_j))||$

$\leq \sum_j||\phi_j(x)(F(x)-F(x_j))||<\sum_j\phi_j(x)\epsilon=\epsilon$

i.e. $G(x)$ satisfies the condition

### Def. length of curve

let $\sigma:[\alpha,\beta]\to R^2$ given by $\sigma(t)=(x(t),y(t)),x,y\in C^1[\alpha,\beta]$

then we can define its length as $L(\sigma):=\int_\alpha^\beta \sqrt{(x'(t))^2+(y'(t))^2}dt$

Rmk. let $\pi:\alpha=t_0<t_1< \dots <t_n=\beta$ be a partition of $[\alpha,\beta]$

then $L_n:=\sum_{j=0}^{n-1}\sqrt{(x(t_{j+1})-x(t_j))^2+(y(t_{j+1})-y(t_j))^2}$

$=\sum_{j=0}^{n-1}\sqrt{(x'(\xi_j))^2+(y'(\eta_j))^2}\Delta t_j$

introduce $S_n:=\sum_{j=0}^{n-1}\sqrt{(x'(\xi_j))^2+(y'(\xi_j))^2}\Delta t_j$ be the Riemann sum of $\int_\alpha^\beta \sqrt{(x'(t))^2+(y'(t))^2}dt$

note that $|\sqrt{a^2+b^2}-\sqrt{a^2+c^2}|\leq |b-c|$

thus, $|L_n-S_n|\leq\sum_{j=0}^{n-1}|y'(\xi_j)-y'(\eta_j)|\Delta t_j\leq \sum_{j=0}^{n-1}\omega_j(y')\Delta t_j\to 0$

i.e. $L(\sigma)=\lim_{n\to\infty}L_n=\int_\alpha^\beta \sqrt{(x'(t))^2+(y'(t))^2}dt$

Rmk. for $\sigma:[\alpha,\beta]\to R^d$, we can define its length similarly as $\int_\alpha^\beta ||\sigma'(t)||dt$

Rmk. also, we can use the tangent vector to measure the length, $L(\sigma)=\int_\sigma dl:=\lim_{||\pi||\to 0}\sum_{j=0}^{n-1}||\sigma'(t_j)||\Delta t_j$, the value is $\int_\alpha^\beta ||\sigma'(t)||dt$ too

### Def. line integral

let $\sigma:[\alpha,\beta]\to R^n$ be smooth ($\sigma\in C^1[\alpha,\beta],\sigma'(t)\neq 0,\forall x\in[\alpha,\beta]$) and let $F\in R(\sigma([\alpha,\beta]),R)$, then $\int_\sigma Fdl:=\int_\alpha^\beta F\circ\sigma(t)||\sigma'(t)||dt$

### Def. parallelopiped

given independent vectors $u_1, \dots ,u_d\in R^n$, we define the d-dimensional parallelopiped to be $P[u_1, \dots ,u_d]:=\lbrace \sum_{j=1}^dc_ju_j|c_j\in[0,1]\rbrace$

Rmk. let $U:=(u_1, \dots ,u_d),I:=[0,1]^n\subset R^n$, then equivlantly, $P[u_1, \dots ,u_d]=U(I)=\lbrace Uc|c\in I\rbrace$

### Thm.

if $d=n,|detU|=|U(I)|=|P[u_1, \dots ,u_d]|$

Proof. $\int_U(I)dy=\int_I|detDU|dx=|detDU|\int_Idx=|detDU|$

Rmk. the thm shows the geometric meaning of determinant

### Thm. measure of parallelopiped

let $P[u_1, \dots ,u_d]\subset R^n(d\leq n),U:=(u_1, \dots ,u_d)$, then the d-dimensional measure $|P[u_1, \dots ,u_d]|=\sqrt{detU^TU}$

Proof. by Gram-Schmidt, $\exists Q\in M_d(R)$: upper triangle, and all the main diagonal elements are 1 s.t. $UQ=(a_1, \dots ,a_d)=:A,\langle a_i,a_j\rangle =0,\forall i\neq j$

by the definition of measure, $|P[a_1, \dots ,a_d]|=||a_1|| \dots ||a_d||$

on the other hand, $detA^TA=||a_1||^2 \dots ||a_d||^2$

note that $\int_{P[a_1, \dots ,a_d]}dy=\int_{QP[u_1, \dots ,u_d]}dy=\int_{P[u_1, \dots ,u_d]}|detDQ|dx=\int_{P[u_1, \dots ,u_d]}dx$

thus, $\int_{P[u_1, \dots ,u_d]}dx=|P[a_1, \dots ,a_d]|=\sqrt{detA^TA}$

$=\sqrt{detQdetQ^TdetU^TU}=\sqrt{detU^TU}$

Rmk. to avoid confusion, we introduce the notation $\mu_d(P[u_1, \dots ,u_d]):=\sqrt{detU^TU}$, and is called the d-dimensional Jordan measure

Rmk. more generally, let $\Omega\subset R^d$ be a J set and $L:\Omega\to R$ be an affine maping, then $\mu_d(L(\Omega))=\sqrt{det(DL)^TDL}|\Omega|$

### Def. k-surface

let $\Phi\in Diff(\Omega,V),\Omega\subset R^k$ be a J set, $V\subset R^n$, then we call $\Phi$ a k-surface, we define the k-dimensional Jordan measure of $\Phi:\mu_k(\Phi(\Omega)):=\int_\Omega\sqrt{det(D\Phi)^TD\Phi}$

Rmk. we define the mapping $\Phi$ as k-surface, rather than $\Phi(\Omega)$

Rmk. if $k=n,\mu_n(\Phi(\Omega))=\int_\Omega\sqrt{det(D\Phi)^TD\Phi}$

$=\int_\Omega|detD\Phi(y)|dy=\int_{\Phi(\Omega)}dx=|\Phi(\Omega)|$

### Thm.

let $F\in C^1(\Omega,R)$, where $\Omega\subset R^n$ be a J set, if we define $\Phi:\Omega\to R^{n+1},\Phi(x)=(x^T,F(x))^T$, then $\mu_n(\Phi(\Omega))=\int_\Omega\sqrt{1+||\nabla F(x)||^2}dx$

Proof. it suffices to show $det(D\Phi)^TD\Phi=1+||\nabla F(x)||^2$

note that $\forall A\in M_{m\times n},B\in M_{n\times m},|I_n+BA|=|I_m+AB|$

thus, $|(D\Phi)^TD\Phi|=|(I_n,\nabla F)(I_n,\nabla F)^T|=|I_n+\nabla F(\nabla F)^T|$

$=|1+(\nabla F)^T\nabla F|=1+||\nabla F(x)||^2$

### Def. surface integral

let $\Phi\in Diff(\Omega,V),\Omega\subset R^k$ be a J set, $V\subset R^n$, let $F\in C(\Phi(\Omega),R)$, we define surface integral of $F$ over $\Phi(\Omega)$ by $\int_{\Phi(\Omega)}F:=\int_\Omega F\circ\Phi \sqrt{det(D\Phi)^TD\Phi}$

### Thm. reparameterization invariance 参数不变性

let $\Psi\in Diff(D,\Omega),\Phi\in Diff(\Omega,V),D\subset R^k$ be a J set, $\Omega\subset R^k,V\subset R^n$, let $F\in C(\Phi(\Omega),R)$, then $\int_{\Phi(\Omega)}F=\int_{\Phi\circ \Psi(D)}F$

Proof. $\int_{\Phi\circ \Psi(D)}F=\int_DF(z)\sqrt{det(D\Psi(x))^TD(\Phi\circ\Psi(x))^TD(\Phi\circ\Psi(x))D\Psi(x)}dx$

$=\int_DF(z)\sqrt{detD(\Phi\circ\Psi(x))^TD(\Phi\circ\Psi(x))}|detD\Psi(x)|dx$

$=\int_{\Psi(D)}F(z)\sqrt{det(D\Phi(y))^TD\Phi(y)}dy$

$=\int_\Omega F\circ \Phi(y)\sqrt{det(D\Phi(y))^TD\Phi(y)}dy=\int_{\Phi(\Omega)}F$

## integration of differential forms

### Def. simplex

$\lbrace (u_1, \dots ,u_d)\in R^d|u_j\geq 0,\sum_ju_j\leq 1\rbrace$ is called a d-simplex

### Def. multi index

let $I=(i_1, \dots ,i_k),i_1, \dots ,i_k\in\lbrace 1,2, \dots ,n\rbrace,\forall x=(x_1, \dots ,x_n)\in R^n$, we define $x_I:=(x_{i_1}, \dots ,x_{i_k}),dx_I:=dx_{i_1}\wedge \dots \wedge dx_{i_k}$

Rmk. here $\wedge$ is just a meaningless symbol

### Def. differential form

let $E\subset R^n$ be open, let $\omega=\sum_Ia_I(x)dx_I$, where $a_I(x)\in C^1(E,R),\#I=k,\forall I$, then we define the function $\omega:\Phi\in C^1(D,E)\to R:\Phi\to \int_D\sum_I(a_I\circ\Phi)(u)det\frac{\partial x_I}{\partial u}du$, then $\omega$ is called a k-form in E

Rmk. here $\Phi$ is a k-surface, furthermore, in order to use integral and Fubini, we set the limit that $D$ must be a simplex or a box

Rmk. it is also written as $\int_\Phi\omega:=\omega(\Phi)=\int_D\sum_I(a_I\circ\Phi)(u)det\frac{\partial x_I}{\partial u}du$

Rmk. a 0-form in E is defined to be a continuous function on E

Rmk. a k-form is said to be $C^r$ if $a_I\in C^r(E,R),\forall I$

### Def.

let $\omega,\omega_1,\omega_2$ be k-forms in E

(1) $\omega_1=\omega_2$ means $\omega_1(\Phi)=\omega_2(\Phi),\forall$ k-surface $\Phi$

(2) $\omega_1+\omega_2$ is defined by $(\omega_1+\omega_2)(\Phi):=\omega_1(\Phi)+\omega_2(\Phi),\forall$ k-surface $\Phi$

(3) $\forall c\in R,c\omega$ is defined by $(c\omega)(\Phi):=c\omega(\Phi),\forall$ k-surface $\Phi$, in particular, $(-\omega)(\Phi):=-\omega(\Phi),\forall$ k-surface $\Phi$

### Def. permutation

let $\omega=a(x)dx_{i_1}\wedge \dots \wedge dx_{i_s}\wedge \dots \wedge dx_{i_t}\wedge \dots \wedge dx_{i_k}$ be a k-form, let $\overline{\omega}:= a(x)dx_{i_1}\wedge \dots \wedge dx_{i_t}\wedge \dots \wedge dx_{i_s}\wedge \dots \wedge dx_{i_k}$, then $\overline{\omega}$ is called a permutation of $\omega$

### Thm.

let $\overline{\omega}$ be a permutation of $\omega$, then $\overline{\omega}=-\omega$

Proof. by the definition of differential form and properties of determinants

$\forall$ k-surface $\Phi,\int_\phi\omega=\int_D(a\circ\Phi)(u)det\frac{\partial(x_{i_1}, \dots ,x_{i_s}, \dots ,x_{i_t}, \dots ,x_{i_k})}{\partial u}du$

$=-\int_D(a\circ\Phi)(u)det\frac{\partial(x_{i_1}, \dots ,x_{i_t}, \dots ,x_{i_s}, \dots ,x_{i_k})}{\partial u}du=-\int_\Phi\overline{\omega}$

i.e. $\overline{\omega}=-\omega$

Rmk. in particular, $dx_i\wedge dx_j=-dx_j\wedge dx_i,dx_i\wedge dx_i=0,\forall i,j$

Rmk. more generally, $\omega=0$ unless $i_1, \dots ,i_k$ are distinct

Rmk. clearly, if $\omega$ is a k-form in $E\subset R^n,n<k$, then $\omega=0$

### Def. basic k-form

if $I=(i_1, \dots ,i_k)$ s.t. $1\leq i_1\leq i_2\leq  \dots \leq i_k\leq n$, then $dx_I$ is called a basic k-form in $R^n$

Rmk. the number of basic k-forms in $R^n$ is $\binom{n}{k}$

### Def. permutation number

given $I=(i_1, \dots ,i_k),s(i_1, \dots ,i_k):=\prod_{p>q}sgn(i_p-i_q)$ is called then permutation number of $I$

Rmk. clearly, each k-form $dx_J$ can be written in terms of a basic k-form $dx_I$, namely, $dx_J=s(j_1, \dots ,j_k)dx_I$, where I is a permutation of J, arranging in an increasing order

### Def. standard presentation

let $dx_I$ be a basic k-form, $\forall I$, then $\omega=\sum_Ia_I(x)dx_I$ is called a standard presentation

### Thm.

let $\omega=\sum_Ia_I(x)dx_I$ be a standard presentation of a k-form in $E\subset R^n$, then $\omega=0$ implies $a_I=0,\forall I$

Proof. if not, $\exists a_J\neq 0,J=(j_1, \dots ,j_k)$, WLOG, $\exists x\in E,a_J(x)>0$

by the continuity of $a_J,\exists\delta>0$ s.t. the box $G:=\lbrace y|||y-x||_\infty\leq\delta\rbrace$ satisfies $a_I(y)>0,\forall y\in G$

define $D:=\lbrace x\in R^k|||x||_\infty\leq\delta\rbrace$ and $\Phi(u):=x+\sum_{r=1}^k u_re_{j_r}$

note that if $I\neq J,det\frac{\partial x_I}{\partial u}=0$, and $det\frac{\partial x_J}{\partial u}=1$

thus, $\int_\Phi\omega=\int_D\sum_I(a_I\circ \Phi)(u)det\frac{\partial x_I}{\partial u}du$

$=\int_D (a_J\circ\Phi)(u)du>0$, contradicts!

### Def. product

let $I=(i_1, \dots ,i_p),J=(j_1, \dots ,j_q),dx_I,dx_J$ be basic p-form and q-form respectively, then the product of $dx_I$ and $dx_J$ is a $(p+q)$ form given by $dx_I\wedge dx_J:=dx_{i_1}\wedge \dots \wedge dx_{i_p}\wedge dx_{j_1}\wedge \dots \wedge dx_{j_q}$

Rmk. if I and J have an element in common, $dx_I\wedge dx_J=0$

otherwise, we can write $i_1, \dots ,i_p,j_1, \dots ,j_q$ in an increasing order as $[I,J]$, then $dx_I\wedge dx_J=s(i_1, \dots ,i_p,j_1, \dots ,j_q)dx_{[I,J]}$

Rmk. as $s(I,J,K)=s(I,J)s([I,J],K)=s(J,K)s(I,[J,K])$

$(dx_I\wedge dx_J)\wedge dx_K=dx_I\wedge (dx_J\wedge dx_K)$

### Def. multiplication of forms

let $\omega,\eta$ be p-form and q-form in E respectively, and with standard presentations $\omega=\sum_Ia_I(x)dx_I,\eta=\sum_Jb_J(x)dx_J$, then $\omega\wedge\eta:=\sum_I\sum_J a_I(x)b_J(x)dx_I\wedge dx_J$ is a $(p+q)$ form in E

Rmk. if $\omega$ is a 0-form, say, $\omega=f(x)$, then $\omega\wedge\eta=\sum_J f(x)b_J(x)dx_J$

also written as $\eta f=f\eta:=\omega\wedge \eta=\eta\wedge\omega=\sum_J f(x)b_J(x)dx_J$

### Thm.

let $\omega,\omega_1,\omega_2,\eta,\eta_1,\eta_2,\zeta$ be any forms

(1) $(\omega_1+\omega_2)\wedge\eta=\omega_1\wedge\eta+\omega_2\wedge\eta$, if $deg\omega_1=deg\omega_2$

(2) $\omega\wedge(\eta_1+\eta_2)=\omega\wedge\eta_1+\omega\wedge\eta_2$, if $deg\eta_1=deg\eta_2$

(3) $\omega\wedge(\eta\wedge\zeta)=(\omega\wedge\eta)\wedge\zeta$

Proof. (1) let $\omega_1=\sum_Ia_I(x)dx_I,\omega_2=\sum_Jb_J(x)dx_J$ be standard presentations, by the latest thm, the standard presentation of $\omega_1+\omega_2$ must be $\sum_K(a_K(x)+b_K(x))dx_K$, where $K\in\lbrace I,J\rbrace, a_K:=0$ if $K\notin \lbrace I\rbrace, b_K:=0$ if $K\notin \lbrace J\rbrace$

thus, the statement is correct

(2) similar

(3) trivial

### Def. differentiation

(1) let $E\subset R^n$ be open and let $f\in C^1(E,R)$ be a 0-form, define $df(x):=\sum_{j=1}^n\partial_jf dx_j=\langle \nabla f,dx\rangle$

(2) let $\omega=\sum_Ia_I(x)dx_I$ be the standard presentation of $C^1$ k-form, define $d\omega:=\sum_I da_I(x)\wedge dx_I$

### Thm.

(1) let $\omega$ and $\eta$ be $C^1$ forms in $E\subset R^n$, then $d(\omega\wedge\eta)=d\omega\wedge\eta+(-1)^{deg\omega}\omega\wedge d\eta$

(2) if $\omega$ is a $C^2$ form in $E\subset R^n$, then $d^2\omega=0$

Proof. (1) by linerity, it suffices to consider $\omega=Fdx_I，\eta=Gdx_J$

then, $d(\omega\wedge\eta)=d(FGdx_I\wedge dx_J)=d(FGs(I,J)dx_{[I,J]})$

$=d(FG)\wedge s(I,J)dx_{[I,J]}=FdG\wedge dx_I\wedge dx_J+GdF\wedge dx_I\wedge dx_J$

$=(-1)^{deg\omega}Fdx_I\wedge dG\wedge dx_J+GdF\wedge dx_I\wedge dx_J$

$=d\omega\wedge\eta+(-1)^{deg\omega}\omega\wedge d\eta$

(2) firstly, for 0-form $\omega=f,f\in C^2(R^n,R)$

$d^2\omega=d(\sum_{j=1}^n\partial_jf dx_j)=\sum_{i=1}^n\sum_{j=1}^n\partial_{ij}dx_i\wedge dx_j$

$=\sum_{i<j}(\partial_{ij}dx_i\wedge dx_j+\partial_{ji}dx_j\wedge dx_i)=0$

note that $d(dx_I)=0,\forall I$

thus, $\forall \omega=\sum_Ia_I(x)dx_I,d^2\omega=d(\sum_Ida_I(x)\wedge dx_I)$

$=\sum_I(d^2a_I(x)\wedge dx_I+(-1)^{dega_I}a_I(x)\wedge d(dx_I))=0$

### Def. pull back 拉回映射

let $E\subset R^n$ be open and $V \subset R^m$ be open, let $T=(t_1, \dots ,t_m)\in C^1(E,V)$ and let $\omega$ be a k-form in V whose standard presentation is $\omega=\sum_Ia_I(y)dy_I$, then we consider $y=T(x),dy_i=dt_i(x)=\sum_{j=1}^n \partial_j t_i(x)dx_i$, then it is a 1-form in E, we define $\omega_T:=\sum_I(a_I\circ T)(x)dt_I$ be a k-form in E be the pull back of $\omega$

### Thm.

let $E\subset R^n$ be open and $V subset R^m$ be open, let $T=(t_1, \dots ,t_m)\in C^1(E,V),\omega,\eta$ are two forms in V

(1) $(\omega+\eta)_T=\omega_T+\eta_T$, if $deg\omega=deg\eta$

(2) $(\omega\wedge\eta)_T=\omega_T\wedge\eta_T$

(3) if $\omega\in C^1,T\in C^2$, then $d\omega_T=(d\omega)_T$

Proof. (1) trivial

(2) by (1), we just need to consider $\omega=F(y)dy_I,\eta=G(y)dy_J$ be standard presentations

$(\omega\wedge\eta)_T=(s([I,J])F(y)G(y)dy_{[I,J]})_T$

$=s([I,J])(F\circ T)(x)(G\circ T)(x)dt_{[I,J]}$

$=(F\circ T)(x)(G\circ T)(x)dt_I\wedge dt_J=\omega_T\wedge \eta_T$

(3) firstly, we consider $\omega=f(y)$ be a 0-form

$d\omega_T=d(f\circ T(x))=DF(T(x))DT(x)dx$

$(d\omega)_T=(DF(y)dy)_T=DF(T(x))DT(x)dx$

thus, $d\omega_T=(d\omega)_T$

then, let $\omega=F(y)dy_I$ be any k-form

$d\omega_T=d((F\circ T)(x)dt_I)=d(F\circ T)(x)\wedge dt_I+(F\circ T)(x)d(dt_I)$

$=d(F_T)\wedge (dy_I)_T=(dF)_T\wedge (dy_I)_T=(dF\wedge dy_I)_T=(d\omega)_T$

### Thm.

let $E\subset R^n, V\subset R^m, W\subset R^p$ be open, let $T\in C^1(E,V),S\in C^1(V,W)$, let $\omega$ be a k-form in W, then $\omega_{S\circ T}=(\omega_S)_T$

Proof. firstly, note that the statement is trivial for 0-forms

consider $\omega=dz_i$ be an 1-form

$(\omega_S)_T=(D_iS(y)dy)_T=D_iS(T(x))DT(x)dx$

$(\omega_{S\circ T})=D(S_i\circ T)(x)dx=D_iS(T(x))DT(x)dx$

thus, $(\omega_S)_T=(\omega_{S\circ T})$

note that every k-form $\sum_Ia_I(x)dx_I$ can be written as $\sum_I a_I(x)\wedge dx_{i_1}\wedge \dots \wedge dx_{i_k}$, and by the latest thm, if the statement holds for $\omega,\eta$, it holds for $\omega+\eta,\omega\wedge\eta$, thus, it holds for all $\omega$

### Thm. change of variables I

let $\omega$ be a k-form in $E\subset R^n$, let $\Phi\in C^1(D,E)$ be a k-surface, $D\subset R^k$, then $\int_\Phi\omega=\int_D\omega_\Phi$, here we regard $D$ itself as a k-surface

Proof. assume $\omega=a_I(x)dx_I,x=\Phi(u)$, then $\omega_\Phi=(a_I\circ \Phi)(u)d\Phi_I$

note that $d\Phi_I=d\Phi_{i_1}\wedge \dots \wedge d\Phi_{i_k},d\Phi_{i_j}=\sum_{l=1}^k\partial_l \Phi_{i_j}(u)du_l$

thus, $d\Phi_I=\sum_{l_p\neq l_q if p\neq q}\partial_{l_1}\Phi_{i_1} \dots \partial_{l_k}\Phi_{i_k}du_{l_1}\wedge \dots \wedge du_{l_k}$

$=\sum_{l_p\neq l_q if p\neq q}s(l_1, \dots ,l_k)\partial_{l_1}\Phi_{i_1} \dots \partial_{l_k}\Phi_{i_k}du_1\wedge \dots \wedge du_k$

$=det\frac{\partial (\Phi_{i_1}, \dots ,\Phi_{i_k})}{\partial(u_1, \dots ,u_k)}du=det\frac{\partial x_I}{\partial u}du$

thus, $\int_D\omega_\Phi=\int_D(a_I\circ\Phi)(u)det\frac{\partial x_I}{\partial u}du=\int_\Phi\omega$

### Thm. change of variables II

let $E\subset R^n,V\subset R^m$ be open, let $T\in C^1(E,V)$ and let $\Phi$ be a k-surface in E and $\omega$ be a k-form in V, then $\int_{T\circ \Phi}\omega=\int_\Phi\omega_T$

Proof. $\int_{T\circ\Phi}\omega=\int_D\omega_{T\circ\Phi}=\int_D(\omega_T)_\Phi=\int_\Phi\omega_T$

### Def. affine mapping

let $X,Y$ be vector spaces, $F:X\to Y$ is called affine if $F-F(0)$ is linear

Rmk. in other words, $F(x)=F(0)+Ax,A\in L(X,Y)$

### Def. oriented affine k-simplex

let $p_0, \dots ,p_k$ are points in $R^n$, then the oriented affine k-simplex $\sigma=[p_0,p_1, \dots ,p_k]$ is defined to be a k-surface on the standard simplex $Q^k=\lbrace x\in R^k|x_j\geq 0,\sum_{j=1}^k x_j\leq 1\rbrace,\sigma(x):=p_0+\sum_{j=1}^k(p_j-p_0)$, also written as $\sigma(x)=p_0+Ax,A=(p_1-p_0, \dots ,p_j-p_0)\in M_{n\times k}(R)$

if $i_0, \dots ,i_k$ be a permutation of $0, \dots ,k$, then we adopt the notation $[p_{i_0}, \dots ,p_{i_k}]=s(i_0, \dots ,i_k)[p_0, \dots ,p_k]$, if $s(i_0, \dots ,i_k)=1$, we say they have the same orientation, otherwise they have the opposite orientation

in particular, if $k=n$, we say $\sigma$ is positively oriented if $det(p_1-p_0, \dots ,p_k-p_0)>0$, we say $\sigma$ is negatively oriented if $det(p_1-p_0, \dots ,p_k-p_0)<0$

if $k=0$, the oriented 0-simplex is defined to be a point with sign attached, written as $\sigma=+p_0$ or $\sigma=-p_0$, for any 0-form $\omega=f(x)$, we define $\int_{\epsilon p_0}\omega=\epsilon f(p_0)$, where $\epsilon=\pm 1$

### Thm.

let $\sigma$ be an oriented affine k-simplex in $E\subset R^n$, let $\overline{\sigma}$ be a permutation of $\sigma$, i.e. $\overline{\sigma}=\epsilon\sigma,\epsilon=s(i_0, \dots ,i_k)=\pm 1$, then $\int_{\overline{\sigma}}\omega=\epsilon\int_\sigma\omega$

Proof. by the definition, the statement holds for $k=0$

if $k\geq 1$, firstly, consider the permutation interchangeing $p_0$ and $p_j$, i.e. let $T:Q^k\to Q^k,T(x_1, \dots ,x_k):=(x_1, \dots ,x_{j-1},1-\sum_{i=1}^k x_i,x_{j+1}, \dots ,x_k)$, then $\overline{\sigma}=\sigma\circ T,\epsilon=-1$

let $\omega=a_I(x)dx_I,\int_{\overline{\sigma}}\omega=\int_{Q^k}(a_I\circ\sigma\circ T)(u)det\frac{\partial \overline{x_I}}{\partial u}du$

$=\int_{Q^k}(a_I\circ\sigma)(v)|detDT|det\frac{\partial \overline{x_I}}{\partial u}dv$

note that $\frac{\partial \overline{x_I}}{\partial u}$ is a sub matrix of $(p_1-p_j, \dots ,p_{j-1}-p_j,p_0-p_j,p_{j+1}-p_j, \dots ,p_k-p_j)$

on the other hand, $\frac{\partial x_I}{\partial v}$ is a sub matrix of $(p_1-p_0, \dots ,p_k-p_0)$

by the property of determinant, $\forall I, det\frac{\partial \overline{x_I}}{\partial u}=-det\frac{\partial x_I}{\partial v}$

thus, $\int_{\overline{\sigma}}\omega=\int_{Q^k}(a_I\circ\sigma)(v)|detDT|(-det\frac{\partial x_I}{\partial v})dv=-\int_\sigma\omega$

note that all the permutations can be combined by interchanging $p_j$ and $p_0$, and the times of changing is exactly $s(i_0, \dots ,i_k)$, thus, the statement is proved

### Def. affine k-chain

an affine k-chain $\Gamma$ in an open set $E\subset R^n$ is a collection of oriented affine k-simplexes $\sigma_1, \dots ,\sigma_r$ in E, we define $\int_\Gamma\omega=\sum_{j=1}^r\int_{\sigma_j}\omega,\forall \omega$ be a k-form in E

Rmk. the equation suggests us to write $\Gamma=\sigma_1+ \dots +\sigma_r$, however, note that it dose not mean $\Gamma(u)=\sigma_1(u)+ \dots +\sigma_r(u)$

### Def. boundary

the boundary of an oriented affine k-simplex($k\geq 1$) $\sigma=[p_0, \dots ,p_k]$ is defined to be an affine (k-1) chain $\partial\sigma:=\sum_{j=0}^k (-1)^j[p_0, \dots ,\widehat{p_j}, \dots ,p_k]$

### Def.

let $E\subset R^n,V \subset R^m$ be open, $T\in C^2(E,V)$, let $\sigma$ be an oriented affine k-simplex in E, then $\Phi:=T\circ\sigma$ is called an oriented $C^2$ k-simplex

furthermore, if $\Phi_1, \dots ,\Phi_r$ are oriented $C^2$ k-simplexes, then the oriented $C^2$ k-chain $\Psi=\sum_{j=1}^r\Phi_j$ is defined by $\int_\Psi\omega=\sum_{j=1}^r\int_{\Phi_j}\omega$

similarly, we can define the oriented $C^2$ k-chain by operating T on k-chains, i.e. $T(\sum\sigma_j):=\sum T\circ\sigma_j$

also, operating T on boundaries are defined as $\partial \Phi:=T\circ\partial\sigma,\partial\Psi:=\sum \partial\Phi_j$

### Def.

we define the boundary of $Q^k$ to be positively oriented

if $T\in Diff^2(Q^n,E),E\subset Q^n,detDT>0$, then we define the positively oriented boundary of E to be a $(n-1)$-chain, $\partial E=\partial T:=T\circ\partial Q^n$

furthermore, let $\Omega=\cup_{j=1}^r E_j,T_j\in Diff^2(Q^n,E_j),E_j\subset Q^n.detDT_j>0,\\ intE_i\cap intE_j=\emptyset,\forall i\neq j$, then $\partial\Omega:=\sum_{j=1}^r \partial E_j$ is called the positively oriented boundary of $\Omega$

Rmk. $\partial E$ is well defined because by Stokes' thm later, if $T_1,T_2\in Diff^2(Q^n,E)$ be different mappings satisfying the condition, we have $\int_{\partial T_1}\omega=\int_{T_1}d\omega=\int_{T_2}d\omega=\int_{T_2}\omega,\forall \omega$ be a $C^1$ (n-1)-form, by approach, it may hold for all (n-1)-form(not sure), i.e. $\partial T_1=\partial T_2$, so we can write $\partial T_1=\partial T_2=\partial E$

### Stokes' thm

let $V\subset R^n$ be open and let $\Psi$ be a $C^2$ oriented k-chain in V, if $\omega$ is a $C^1$ (k-1)-form in V, then $\int_\Psi d\omega=\int_{\partial\Psi}\omega$

Proof. it suffices to consider $\Psi$ be a $C^2$ oriented k-simplex, i.e. $\exists Q^k\subset E\subset R^k,E$ be open, $\exists T\in C^2(E,V)$ s.t. $\Psi=T\circ\sigma$, where $\sigma$ is the identidy mapping on $Q^k$

then $\int_\Psi d\omega=\int_{T\circ\sigma}d\omega=\int_\sigma (d\omega)_T=\int_\sigma d(\omega_T)$

and $\int_{\partial\Psi}\omega=\int_{T(\partial\sigma)}\omega=\int_{\partial\sigma}\omega_T$

thus, it suffices to prove $\int_\sigma d\eta=\int_{\partial\sigma}\eta,\forall \eta$ be a (k-1)-form in E

if $k=1$, the equation is $\int_0^1 f'(x)=f(1)-f(0)$, which is just Newton-Leibniz formula

let $k>1$, it suffices to consider $\eta=f(x)dx_1\wedge \dots \wedge\widehat{dx_r}\wedge \dots \wedge dx_k$

as $\partial\sigma=[e_1, \dots ,e_k]+\sum_{j=1}^k (-1)^j[0,e_1, \dots ,\widehat{e_j}, \dots ,e_k]$

define $\tau_0:=[e_r,e_1, \dots ,\widehat{e_r}, \dots ,e_k],\tau_j:=[0,e_1, \dots ,\widehat{e_j}, \dots ,e_k]$

then $\partial\sigma=(-1)^{r-1}\tau_0+\sum_{j=1}^k(-1)^j\tau_j$

consider $u\in Q^{k-1}$, we find that $\tau_0(u)=(u_1, \dots ,u_{r-1},1-\sum_{j=0}^{k-1}u_j,u_r, \dots ,u_{k-1})$, and $\tau_i(u)=(u_1, \dots ,u_{r-1},0,u_r, \dots ,u_{k-1})$

it shows that if $i=0,r,det\frac{\partial \tau_i}{\partial u}=1$, otherwise, $det\frac{\partial \tau_i}{\partial u}=0$

thus, $\int_{\partial\sigma}\eta=(-1)^{r-1}\int_{\tau_0}\eta+(-1)^r\int_{\tau_r}\eta$

$=(-1)^{r-1}\int_{Q^{k-1}}(f(\tau_0(u))-f(\tau_r(u)))du$

on the other hand, $\int_\sigma d\eta=\int_\sigma (-1)^{r-1}\partial_r f(x)dx_1\wedge  \dots \wedge dx_r$

view it as an integral of function rather than differential form

$=(-1)^{r-1}\int dx_1\wedge \dots \wedge\widehat{dx_r}\wedge \dots \wedge dx_k\int_0^{1-\sum_{j=1,j\neq r}^k x_j}\partial_r f(x)dx_r$

$=(-1)^{r-1}\int_{Q^{k-1}}(f(\tau_0(u))-f(\tau_r(u)))du$

thus, the thm is proved

Rmk. we only use Stokes' thm on orientable surfaces (Mobius band is a counterexample)

#### Cor.

let $\Phi$ be an oriented $C^2$ k-chain, then $\partial^2\Phi=0$

### Def. closed forms and exact forms

let $E\subset R^n$ be open and $\omega$ be a k-form in E, then

(1) if $d\omega=0,\omega$ is called closed

(2) if $\exists \eta$ be a (k-1)-form in E s.t. $\omega=d\eta$, $\omega$ is called exact

Rmk. clearly, every $C^1$ exact k-form is closed

### Thm.

let $\omega$ be an exact k-form in E, if $\Phi_1,\Phi_2$ are two oriented $C^2$ k-chains in E and $\partial\Phi_1=\partial\Phi_2$, then $\int_{\Phi_1}\omega=\int_{\Phi_2}\omega$, in particular, if $\partial\Phi=0,\int_{\Phi}\omega=0$

Proof. let $\omega=d\eta,\int_{\Phi_1}\omega=\int_{\Phi_1}d\eta=\int_{\partial \Phi_1}\eta=\int_{\partial\Phi_2}\eta=\int_{\Phi_2}d\eta=\int_{\Phi_2}\omega$

### Def. star-shaped 星形集

a set $S\subset R^n$ is called star-shaped if $\exists x\in S$ s.t. $\forall y\in S,\lbrace x+t(y-x)|t\in[0,1]\rbrace\subset S$

### Thm. Poincare lemma

let $E\subset R^n$ be star-shaped, then each closed k-form $\omega$ in E must be exact

Proof. WLOG, assume $0\in E,\forall x\in E,tx\in E,\forall t\in[0,1]$

assume $\omega=\sum_Ia_I(x)dx_I$ be the standard presentation

now we are going to define a linear transform from k-forms to (k-1)-forms s.t.

(i) $L(0)=0$

(ii) $\omega=L(d\omega)+d(L\omega)$

we define $L\omega:=\sum_I\sum_{j=1}^k(-1)^{j-1}(\int_0^1 t^{k-1}a_I(tx)dt) x_{i_j}dx_{i_1}\wedge \dots \wedge \widehat{dx_{i_j}}\wedge \dots \wedge dx_{i_k}$

then, $d(L\omega)=k\sum_I(\int_0^1 t^{k-1}a_I(tx)dt)dx_I$

$+\sum_I\sum_{j=1}^k\sum_{m=1}^n(-1)^{j-1}(\int_0^1 t^k\partial_m a_I(tx)dt)x_{i_j}dx_m\wedge dx_{i_1}\wedge \dots \wedge \widehat{dx_{i_j}}\wedge \dots \wedge dx_{i_k}$

$d\omega=\sum_I\sum_{m=1}^n\partial_ma_I(x)dx_m\wedge dx_I$

$L(d\omega)=\sum_I\sum_{m=1}^n(\int_0^1t^k\partial_ma_I(tx)dt)x_m dx_I$

$-\sum_I\sum_{j=1}^k\sum_{m=1}^n(-1)^{j-1}(\int_0^1 t^k\partial_m a_I(tx)dt) x_{i_j}dx_m\wedge dx_{i_1}\wedge \dots \wedge \widehat{dx_{i_j}}\wedge \dots \wedge dx_{i_k}$

thus, $d(L\omega)+L(d\omega)$

$=k\sum_I(\int_0^1 t^{k-1}a_I(tx)dt)dx_I+\sum_I\sum_{m=1}^n(\int_0^1t^k\partial_ma_I(tx)dt)x_m dx_I$

$=\sum_I(\int_0^1a_I(tx)dt^k)dx_I+\sum_I(\int_0^1t^kda_I(tx)) dx_I$

$=\sum_I(t^ka_I(tx))|_0^1dx_I=\sum_Ia_I(x)dx_I=\omega$

thus, if $\omega$ is closed, $\omega=d(L\omega)$, i.e. $\omega$ is exact

### Def.

let $E\subset R^3$ be open

(1) let $u\in C^1(E,R)$, then $\nabla u:=(\partial_xu,\partial_yu,\partial_zu)$ is called the gradient of u, also written as $grad u$ 梯度

(2) let $F=(P,Q,R)^T:E\to R^3$, consider the 1-form $\omega_F^{(1)}:=Pdx+Qdy+Rdz$, then $d\omega_F^{(1)}=(\partial_yR-\partial_zQ)dy\wedge dz+(\partial_zP-\partial_xR)dz\wedge dx+(\partial_xQ-\partial_yP)dx\wedge dy$, we define the vector $(\partial_yR-\partial_zQ,\partial_zP-\partial_xR,\partial_xQ-\partial_yP)$ be the curl of F, written as $\nabla\times F,curlF,rotF$ 旋度

(3) similarly, consider the 2-form $\omega_F^{(2)}:=Pdy\wedge dz+Qdz\wedge dx+Rdx\wedge dy$, then $d\omega_F^{(2)}=(\partial_xP+\partial_yQ+\partial_zR)dx\wedge dy\wedge dz$, we define the function $\partial_xP+\partial_yQ+\partial_zR$ be the divergence of F, written as $\nabla\cdot F,divF$ 散度

### Thm.

(1) let $u\in C^2(E,R)$, then $\nabla\times(\nabla u)=0$

(2) let $F\in C^2(E,R^3)$, then $\nabla\cdot(\nabla\times F)=0$

furthermore, if E is star-shaped

(3) if $\nabla\times F=0$, then $\exists u\in C^2(E,R)$ s.t. $F=\nabla u$

(4) if $\nabla\cdot F=0$, then $\exists G\in C^2(E,R^3)$ s.t. $F=\nabla\times G$

Proof. (1) write $F=\nabla u$, then $\omega_F^{(1)}=du,d\omega_F^{(1)}=d^2u=0,\nabla\times F=0$

(2) write $G=\nabla\times F$, then $\omega_G^{(2)}=d\omega_F^{(1)},d\omega_G^{(2)}=d^2\omega_F^{(1)}=0,\nabla\cdot G=0$

(3) $d\omega_F^{(1)}=0$, thus $\omega_F^{(1)}$ is exact, $\exists u\in C^2(E,R)$ s.t. $du=\omega_F^{(1)}$, i.e. $F=\nabla u$

(4) $d\omega_F^{(2)}=0$, thus $\omega_F^{(2)}$ is exact, $\exists \eta=Adx+Bdy+Cdz\in C^2$ be a 1-form s.t. $d\eta=\omega_F^{(2)}$, thus, let $G=(A,B,C)^T\in C^2(E,R^3),F=\nabla\times G$

### Thm. classical Stokes' formula

let $E\subset R^3$ be open and let $F=(P,Q,R)^T\in C^1(E,R)$, if $\Phi$ is an oriented $C^2$ 2-surface in E, then $\int_\Phi\begin{vmatrix} dy\wedge dz&dz\wedge dx&dx\wedge dy\\ \partial_x & \partial_y & \partial_z\\ P&Q&R\\ \end{vmatrix}=\int_{\partial\Phi}Pdx+Qdy+Rdz$, it can also be written as $\int_{\Phi}(\nabla\times F)\cdot \vec{n}d\mu_2=\int_{\partial\Phi}F\cdot\vec{\nu}d\mu_1$, where $\vec{n}$ is the unit normal vector of $\Phi$ and $\vec{\nu}$ is the unit tangent vector of $\partial\Phi$

Proof. the first equation is same as $\int_\Phi d\omega_F^{(1)}=\int_{\partial\Phi}\omega_F^{(1)}$, which is proved by Stokes' thm, so it suffices to focus on the second equation

let $\Phi=(x(u,v),y(u,v),z(u,v))$, note that the normal vector of $\Phi$ is $(\begin{vmatrix}\partial_uy& \partial_uz\\ \partial_vy& \partial_vz\\ \end{vmatrix},\begin{vmatrix}\partial_uy& \partial_uz\\ \partial_vy& \partial_vz\\ \end{vmatrix},\begin{vmatrix}\partial_uy& \partial_uz\\ \partial_vy& \partial_vz\\ \end{vmatrix})^T$, write it as $(A,B,C)^T$, then $\vec{n}=\frac{1}{\sqrt{A^2+B^2+C^2}}(A,B,C)^T$

note that $d\mu_2=\sqrt{det(D\Phi)^TD\Phi}dudv=\sqrt{A^2+B^2+C^2}dudv$

thus, $\vec{n}d\mu_2=(A,B,C)^Tdudv=(dy\wedge dz,dz\wedge dx,dx\wedge dy)^T$

thus, $\int_{\Phi}(\nabla\times F)\cdot \vec{n}d\mu_2=\int_\Phi d\omega_F^{(1)}$

let $\sigma=\partial\Phi=(x(t),y(t),z(t)),t\in[0,1]$, then $\vec{\nu}=\frac{\sigma'(t)}{||\sigma'(t)||}$

note that $d\mu_1=||\sigma'(t)||dt$, thus, $\int_{\partial\Phi}F\cdot\vec{\nu}d\nu_1=\int_0^1 F(\sigma(t))\cdot \sigma'(t)dt$

$=\int_{\partial\Phi}(P,Q,R)^T\cdot(dx,dy,dz)^T=\int_{\partial\Phi}\omega_F^{(1)}$

thus, the second equation and the equivlance between the two equations are proved

### Thm. Green's thm

let $E\subset R^2$ be open and let $F=(P,Q)^T\in C^1(E,R^2)$, if $\Phi$ is an oriented $C^2$ 2-surface in E, then $\int_\Phi(\partial_xQ-\partial_yP)dx\wedge dy=\int_{\partial\Phi}Pdx+Qdy=\int_{\partial\Phi}F\cdot\vec{\nu}d\mu_1$

Proof. let $z=0$ in classical Stokes' formula

### Thm. divergence thm 散度定理

let $\Phi$ be a compact $C^2$ n-chain in $E\subset R^n$ and let $F=(f_1, \dots ,f_n)\in C^1(E,R^n)$, then $\int_{\partial\Phi}F\cdot\vec{n}d\mu_{n-1}=\int_{\Phi}\nabla\cdot Fdx$

Proof. firstly, we are going to find $\vec{N}$, let $\partial\Phi:u\to (x_1(u), \dots ,x_n(u)),u\in Q^{n-1}$

the tangent space $T_{\partial\Phi}=span(\frac{\partial x}{\partial u_1}, \dots ,\frac{\partial x}{\partial u_{n-1}})$

note that $\forall 1\leq j\leq n-1,det\frac{\partial (x_1, \dots ,x_n)}{\partial(u_j,u_1, \dots ,u_{n-1})}=0$

i.e. $\sum_{i=1}^n(-1)^{j-1}\partial_jx_i(u)det\frac{\partial(x_1, \dots ,\widehat{x_j}, \dots ,x_n)}{\partial u}=0$

define $N_j:=(-1)^j det\frac{\partial(x_1, \dots ,\widehat{x_j}, \dots ,x_n)}{\partial u},\vec{N}:=(N_1, \dots ,N_{n-1})^T$

then $\langle \vec{N},\frac{\partial x}{\partial u_j}\rangle=0$, thus, $\vec{N}\bot \frac{\partial x}{\partial u_j},\forall 1\leq j\leq n-1$

i.e. $\vec{N}\bot T_{\partial\Phi}$, thus, $\vec{n}=\frac{\vec{N}}{||\vec{N}||}$

introduce $\omega:=\sum_{j=1}^n(-1)^{j-1}f_j(x)dx_1\wedge  \dots \wedge \widehat{dx_j}\wedge \dots  \wedge dx_n$

on the one hand, $\int_{\partial\Phi}\omega=\int_{\partial\Phi}\sum_{j=1}^n(-1)^{j-1}f_j(x)dx_1\wedge  \dots \wedge \widehat{dx_j}\wedge \dots  \wedge dx_n$

$=\int_{Q^{n-1}}\sum_{j=1}^nf_j\cdot N_jdu=\int_{Q^{n-1}} F\cdot\vec{N}du$

$=\int_{Q^{n-1}}F\cdot\vec{n} ||\vec{N}||du=\int_{\partial\Phi}F\cdot\vec{n}d\mu_{n-1}$

on the other hand, $\int_\Phi d\omega=\int_\Phi\sum_{j=1}^n\partial_jf_j(x)dx=\int_\Phi\nabla\cdot Fdx$

thus, as $\int_\Phi d\omega=\int_{\partial\Phi}\omega,\int_{\partial\Phi}F\cdot\vec{n}d\mu_{n-1}=\int_{\Phi}\nabla\cdot Fdx$

Rmk. for $n=3$, we can write it as $\int_{\partial\Phi}Pdy\wedge dz+Qdz\wedge dx+Rdx\wedge dy=\int_\Phi(\partial_xP+\partial_yQ+\partial_zR)dxdydz$, which is also called Gauss' formula

### Thm. coarea formula 余面积公式

let $F\in C^1(\Omega,R),\Omega\subset R^n$ be compact, $\nabla F\neq 0$, let G be continuous on the compact set $F^{-1}([a,b])$, then $\int_{F^{-1}([a,b])}G||\nabla F||=\int_a^bdt\int_{F^{-1}(t)}Gd\mu_{n-1}$, and $\int_{F^{-1}([a,b])}G=\int_a^bdt\int_{F^{-1}(t)}\frac{G}{||\nabla F||}d\mu_{n-1}$

Proof. it suffices to prove the latter one, otherwise just let $G'=G||\nabla F||$

note that $F^{-1}(t)$ is a smooth level set consisting of finite smooth hypersurfaces that together inclose the bounded set $\lbrace x\in\Omega|F(x)>t\rbrace$

consider $\vec{h}//\nabla F,\Delta t=F(x+\vec{h})-F(x)=\nabla F(x)\cdot \vec{h}+o(||\vec{h}||)$

let $||\vec{h}||\to 0,dt=||\nabla F(x)||||\vec{h}||$

thus, $\int_{F^{-1}([a,b])}GdV=\int_{F^{-1}([a,b])}Gd||\vec{h}||d\mu_{n-1}=\int_a^bdt\int_{F^{-1}(t)}\frac{G}{||\nabla F||}d\mu_{n-1}$
