# Toeplitz 矩阵线性方程组快速算法

> tags: #fft; #toeplitz;

## TL; DR

计算 Toeplitz 矩阵与任意向量的乘积 $\mathbf y = \mathbf T \mathbf x$，可以通过如下方式进行计算

1. $\hat c = \mathrm{fft}(\mathbf c)$
2. $\hat x = \mathrm{fft}(\mathbf x)$
3. $\hat y = \hat c \cdot \hat x$
4. $y = \text{ifft}(\hat y)$

## Toeplitz 矩阵

设 $n$ 阶 Toeplitz 矩阵

$$
\mathbf T = (t_{ij})_{n \times n} = \begin{bmatrix}
t_0 & t_1 & \cdots & t_{n-1} \\
t_{-1} & t_0 & \ddots & t_{n-2} \\
\vdots & \ddots & \ddots & t_1 \\
t_{1-n} & \cdots & t_{-1} & t_0
\end{bmatrix}
$$

其中 $t_{ij} = t_{j - i}$
引入记号 $\mathbf I_n$ 与 $\mathbf J_n$

$$
\mathbf I_n = \begin{bmatrix}
1 & 0 & \cdots & 0 \\
0 & 1 & \cdots & 0 \\
\vdots & \vdots & \ddots & 0 \\
0 & 0 & \cdots & 1
\end{bmatrix}_{n \times n},
\mathbf J_n = \begin{bmatrix}
0 & \cdots & 0 & 1 \\
0 & \cdots & 1 & 0 \\
\vdots &  & \vdots & \vdots \\
1 & \cdots & 0 & 0
\end{bmatrix}_{n \times n}, 
$$

Toeplitz 矩阵具有下面的性质

$$
\mathbf J_n \mathbf T \mathbf J_n = \mathbf T^{T}, \mathbf J_n (\mathbf T^{-1})^{T} \mathbf J_n = \mathbf T^{-1}
$$

如果 $\mathbf T$ 为对称 Toeplitz 矩阵，线性方程组 $\mathbf T \mathbf x = \mathbf f$ 的递推算法可以简化成

$$
u_1(1) = \frac{1}{t_0}, x_1(1) = \frac{f(1)}{t_0}
$$

对于 $k = 1, 2, \dots, n-1$

$$
\begin{aligned}
\mu_k &= \sum_{j=1}^{k} t_j u_k(j) \\
\sigma_k &= f(k+1) - \sum_{j=1}^{k} t_{k+1-j} x_k(j) \\
\mathbf u_{k+1} &= \frac{1}{1-\mu_k^2} \left\{ \begin{bmatrix} 0 \\ \mathbf u_k \end{bmatrix} - \mu_k \begin{bmatrix} J_k \mathbf u_k \\ 0 \end{bmatrix} \right\} \\
\mathbf x_{k+1} &= \begin{bmatrix} \mathbf x_k \\ 0 \end{bmatrix} + \sigma_k \mathbf u_{k+1}
\end{aligned}
$$

## Circulant matrix 循环矩阵

设 $n$ 阶 Circulant 矩阵

$$
\mathbf C = (c_{ij})_{n \times n} \begin{bmatrix}
c_0 & c_1 & \cdots & c_{n-1} \\
c_{n-1} & c_0 & \ddots & c_{n-2} \\
\vdots & \ddots & \ddots & c_1 \\
c_{1} & \cdots & c_{n-1} & c_0
\end{bmatrix}
$$

其中 $c_{ij} = c_{(j - i) \mod L}$

循环矩阵的乘法就是循环卷积运算的矩阵表示

## Toeplitz FFT

设 $n$ 阶 Toeplitz 矩阵

$$
\mathbf T_n = (t_{ij})_{n \times n} = \begin{bmatrix}
t_0 & t_1 & \cdots & t_{n-2} & t_{n-1} \\
t_{-1} & t_0 & t_1 & \ddots & t_{n-2} \\
\vdots & t_{-1} & t_0 & \ddots & \vdots \\
t_{2-n} & \ddots & \ddots & t_0 & t_1 \\
t_{1-n} & t_{2-n} & \cdots & t_{-1} & t_0
\end{bmatrix}
$$

构造另一个 $n$ 阶 Toeplitz 矩阵

$$
\mathbf B_n = \begin{bmatrix}
0 & t_{1-n} & \cdots & t_{-2} & t_{-1} \\
t_{n-1} & 0 & t_{1-n} & \ddots & t_{-2} \\
\vdots & t_{n-1} & 0 & \ddots & \vdots \\
t_2 & \ddots & \ddots & 0 & t_{1-n} \\
t_1 & t_2 & \cdots & t_{n-1} & 0
\end{bmatrix}
$$

从而构造 $2n$ 阶的循环矩阵

$$
\mathbf C_{2n} = \begin{bmatrix}
\mathbf T_n & \mathbf B_n \\
\mathbf B_n & \mathbf T_n
\end{bmatrix}
$$

考虑之前的方程组 $\mathbf T \mathbf x = \mathbf f$，我们将其增补为如下形式

$$
\mathbf C_{2n} \begin{bmatrix} \mathbf x \\ \mathbf 0 \end{bmatrix}
= \begin{bmatrix}
\mathbf T_n & \mathbf B_n \\
\mathbf B_n & \mathbf T_n
\end{bmatrix} \begin{bmatrix} \mathbf x \\ \mathbf 0 \end{bmatrix}
= \begin{bmatrix} \mathbf T_n \mathbf x \\ \mathbf B_n \mathbf x \end{bmatrix}
= \begin{bmatrix} \mathbf f \\ \mathbf f_{useless} \end{bmatrix}
$$

所以对于方程 $\mathbf T \mathbf x = \mathbf f$，相当于用循环矩阵 $C_{2n}$ 的第一列 $\mathbf c$ 与增补 $\mathbf x^{\star} = (\mathbf x^T, \mathbf 0)^T$ 做卷积运算

$$
\mathbf c \ast \mathbf x^{\star} = \mathbf f^{\star}
$$

所以就可以应用快速傅里叶变换

$$
\mathrm{fft}(\mathbf c) \cdot \mathrm{fft}(\mathbf x^{\star}) = \mathrm{fft}(\mathbf f^{\star})
$$

其中，算符 $\cdot$ 表示内积。

所以计算 Toeplitz 矩阵与任意向量的乘积 $\mathbf y = \mathbf T \mathbf x$，可以通过如下方式进行计算

1. $\hat c = \mathrm{fft}(\mathbf c)$
2. $\hat x = \mathrm{fft}(\mathbf x)$
3. $\hat y = \hat c \cdot \hat x$
4. $y = \text{ifft}(\hat y)$