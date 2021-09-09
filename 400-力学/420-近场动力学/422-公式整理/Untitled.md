# 对偶邻域的另一种公式推导方式

## 基本符号 Notations

### 基本物理量

* 当前物质点坐标 ${\boldsymbol x}$
* 物质点发生位移 ${\boldsymbol u} := {\boldsymbol u}({\boldsymbol x})$
* 变形后物质点坐标 ${\boldsymbol y} := {\boldsymbol y}({\boldsymbol x}) = {\boldsymbol x} + {\boldsymbol u}({\boldsymbol x})$
* 键向量 ${\boldsymbol\xi} := {\boldsymbol\xi}({\boldsymbol x}', {\boldsymbol x}) = {\boldsymbol x}' - {\boldsymbol x}$
* 键位移向量 ${\boldsymbol\eta} := {\boldsymbol\eta}({\boldsymbol\xi}) = {\boldsymbol\eta}({\boldsymbol x}', {\boldsymbol x}) = {\boldsymbol u}({\boldsymbol x}') - {\boldsymbol u}({\boldsymbol x})$
* 变形后键向量 ${\mathbf Y} := {\mathbf Y}({\boldsymbol\xi}) = {\boldsymbol y}({\boldsymbol x}') - {\boldsymbol y}({\boldsymbol x}) = {\boldsymbol\xi} + {\boldsymbol\eta}$

### 算符或一般记号

* 单位方向向量算符 ${\boldsymbol e}_{\bullet} := \bullet / \|\bullet\|$
  * 例如，键向量 ${\boldsymbol\xi}$ 的单位方向向量为 ${\boldsymbol e}_{{\boldsymbol\xi}} := {\boldsymbol\xi} / \|{\boldsymbol\xi}\|$

## 近场作用邻域

* 当前物质点坐标对应的邻域大小 $\delta({\boldsymbol x})$
* 当前物质点坐标对应的邻域 ${\mathcal H_{\boldsymbol x}} := {\mathcal H}({\boldsymbol x}) = \{{\boldsymbol x}': \|{\boldsymbol x}' - {\boldsymbol x}\| < \delta({\boldsymbol x})\}$
* 当前物质点坐标对应的对偶邻域 ${\mathcal H_{\boldsymbol x}'} := {\mathcal H}'({\boldsymbol x}) = \{{\boldsymbol x}': \|{\boldsymbol x}' - {\boldsymbol x}\| < \delta({\boldsymbol x'})\}$

## PD 基本概念定义

* **单向作用 Partial Interaction of a Bond**
    * 方向：从 ${\boldsymbol x}$ 指向 ${\boldsymbol x}'$，$\hat{\boldsymbol f}({\boldsymbol x}', {\boldsymbol x}) \times {\boldsymbol\xi} = {\boldsymbol 0}$
        $$
        \hat{\boldsymbol f}({\boldsymbol x}', {\boldsymbol x}) = \frac12 c_0({\boldsymbol x}, {\boldsymbol\xi})
            \left( {\boldsymbol e}_{\boldsymbol\xi} \otimes {\boldsymbol e}_{\boldsymbol\xi} \right) {\boldsymbol\eta}
        $$
* **对偶键的单向作用 Partial Interaction of a Dual-Bond**
    * 方向：从 ${\boldsymbol x}'$ 指向 ${\boldsymbol x}$，$\hat{\boldsymbol f}({\boldsymbol x}, {\boldsymbol x}') \times (-{\boldsymbol\xi}) = {\boldsymbol 0}$
        $$
        \hat{\boldsymbol f}({\boldsymbol x}, {\boldsymbol x}') = \frac12 c_0({\boldsymbol x}', -{\boldsymbol\xi})
            \left( {\boldsymbol e}_{-\boldsymbol\xi} \otimes {\boldsymbol e}_{-\boldsymbol\xi} \right) (-{\boldsymbol\eta})
        $$
        $$
        \hat{\boldsymbol f}({\boldsymbol x}, {\boldsymbol x}') = -\frac12 c_0({\boldsymbol x}', -{\boldsymbol\xi})
            \left( {\boldsymbol e}_{\boldsymbol\xi} \otimes {\boldsymbol e}_{\boldsymbol\xi} \right) {\boldsymbol\eta}
        $$
* **平衡方程 Equilibrium Equation**
    * 静力平衡
        $$
        0 = \int_{\mathcal H_{\boldsymbol x}} \hat{\boldsymbol f}({\boldsymbol x}', {\boldsymbol x}) {{\mathrm d\!} V_{{\boldsymbol x}'}}
        - \int_{\mathcal H_{\boldsymbol x}'} \hat{\boldsymbol f}({\boldsymbol x}, {\boldsymbol x}') {{\mathrm d\!} V_{{\boldsymbol x}'}}
            + {\boldsymbol b}({\boldsymbol x})
        $$
    * 记平衡方程中的积分项为算子 ${\mathbf L^{\mathrm{DH}}}({\boldsymbol x})$
        $$
        {\mathbf L^{\mathrm{DH}}}({\boldsymbol x}) + {\boldsymbol b}({\boldsymbol x}) = 0
        $$
* **常数邻域尺寸模型 Constant Horizon**
    * 当近场邻域 ${\mathcal H_{\boldsymbol x}}$ 与对偶邻域 ${\mathcal H_{\boldsymbol x}'}$ 相同时，该模型可化简为传统的 PD 模型。
    * 键力简记为
        $${\boldsymbol f}({\boldsymbol x}', {\boldsymbol x}) = \hat{\boldsymbol f}({\boldsymbol x}', {\boldsymbol x}) - \hat{\boldsymbol f}({\boldsymbol x}, {\boldsymbol x}')$$
    * 静力平衡方程为
        $$
        0 = \int_{\mathcal H_{\boldsymbol x}} {\boldsymbol f}({\boldsymbol x}', {\boldsymbol x}) {{\mathrm d\!} V_{{\boldsymbol x}'}} + {\boldsymbol b}({\boldsymbol x})
        $$
    * 记平衡方程中的积分项为算子 ${\mathbf L^{\mathrm{CH}}}({\boldsymbol x})$
        $$
        {\mathbf L^{\mathrm{CH}}}({\boldsymbol x}) + {\boldsymbol b}({\boldsymbol x}) = 0
        $$

## 弹性能密度 Elastic Energy Density in Peridynamics

* 连续介质力学模型
    $$
    W_{\mathrm{CCM}}({\boldsymbol x}) = \frac12 {\boldsymbol\varepsilon}({\boldsymbol x}) : {\mathbf K}({\boldsymbol x}) : {\boldsymbol\varepsilon}({\boldsymbol x})
    $$
* 键的弹性变形能
    * action force bond $\hat{\boldsymbol f}({\boldsymbol x}', {\boldsymbol x})$
        $$
        w_{{\boldsymbol x}\to{\boldsymbol x}'}
            = \frac12 \hat{\boldsymbol f}({\boldsymbol x}', {\boldsymbol x}) \cdot {\boldsymbol\eta}
            = \frac14 c_0({\boldsymbol x}, {\boldsymbol\xi}) \xi^{-2} {\boldsymbol\eta}^{\mathrm T}
                ({\boldsymbol\xi} \otimes {\boldsymbol\xi}) {\boldsymbol\eta}
        $$
    * reaction force bond $\hat{\boldsymbol f}({\boldsymbol x}, {\boldsymbol x}')$
        $$
        w_{{\boldsymbol x}'\to{\boldsymbol x}}
        = \frac12 \hat{\boldsymbol f}({\boldsymbol x}, {\boldsymbol x}') \cdot (-{\boldsymbol\eta})
        = \frac14 c_0({\boldsymbol x}', -{\boldsymbol\xi}) \xi^{-2} {\boldsymbol\eta}^{\mathrm T}
            ({\boldsymbol\xi} \otimes {\boldsymbol\xi}) {\boldsymbol\eta}
        $$
* 对于点 ${\boldsymbol x}$ 而言，共有两种键储存了变形的弹性势能：从点 ${\boldsymbol x}$ 发射出的键 $\hat{\boldsymbol f}({\boldsymbol x}', {\boldsymbol x})$ ，以及从 ${\boldsymbol x}'$ 发射来的键 $\hat{\boldsymbol f}({\boldsymbol x}, {\boldsymbol x}')$。为了方便统计弹性势能，假设每根键的能量均匀的分配给其端点的物质点，即
    $$
    W_{\mathrm{DH}}({\boldsymbol x})
      = \frac12 \int_{\mathcal H_{\boldsymbol x}} w_{{\boldsymbol x}\to{\boldsymbol x}'} {{\mathrm d\!} V_{{\boldsymbol x}'}} +
        \frac12 \int_{\mathcal H_{\boldsymbol x}'} w_{{\boldsymbol x}'\to{\boldsymbol x}} {{\mathrm d\!} V_{{\boldsymbol x}'}}
    $$
* 为方便表示，不妨设
    $$
    \begin{aligned}
    W_{{\boldsymbol x}\to{\boldsymbol x}'}({\boldsymbol x})
    &= \frac12 \int_{\mathcal H_{\boldsymbol x}} w_{{\boldsymbol x}\to{\boldsymbol x}'} {{\mathrm d\!} V_{{\boldsymbol x}'}}
    = \frac12 \int_{\mathcal H_{\boldsymbol x}} \frac12
        \hat{\boldsymbol f}({\boldsymbol x}', {\boldsymbol x}) \cdot {\boldsymbol\eta} {{\mathrm d\!} V_{{\boldsymbol x}'}} \\
    &= \frac14 \int_{\mathcal H_{\boldsymbol x}}
        c_0({\boldsymbol x}, {\boldsymbol\xi}) \xi^{-2} {\boldsymbol\eta}^{\mathrm T}
                ({\boldsymbol\xi} \otimes {\boldsymbol\xi}) {\boldsymbol\eta} {{\mathrm d\!} V_{{\boldsymbol x}'}} \\
    W_{{\boldsymbol x}'\to{\boldsymbol x}}({\boldsymbol x})
    &= \frac12 \int_{\mathcal H_{\boldsymbol x}'} w_{{\boldsymbol x}'\to{\boldsymbol x}} {{\mathrm d\!} V_{{\boldsymbol x}'}}
    = \frac12 \int_{\mathcal H_{\boldsymbol x}'} \frac12
        \hat{\boldsymbol f}({\boldsymbol x}, {\boldsymbol x}') \cdot (-{\boldsymbol\eta}) {{\mathrm d\!} V_{{\boldsymbol x}'}} \\
    &= \frac14 \int_{\mathcal H_{\boldsymbol x}'}
        c_0({\boldsymbol x}', {\boldsymbol\xi}) \xi^{-2} {\boldsymbol\eta}^{\mathrm T}
                ({\boldsymbol\xi} \otimes {\boldsymbol\xi}) {\boldsymbol\eta} {{\mathrm d\!} V_{{\boldsymbol x}'}} \\
    W_{\mathrm{DH}}({\boldsymbol x})
    &= W_{{\boldsymbol x}\to{\boldsymbol x}'}({\boldsymbol x}) + W_{{\boldsymbol x}'\to{\boldsymbol x}}({\boldsymbol x})
    \end{aligned}
    $$

## 微模量关系

* **局部区域的等应变假设（an infinitesimal homogeneous transformation）**
    $$
    {\boldsymbol\varepsilon}({\boldsymbol x}) \simeq {\boldsymbol\varepsilon}({\boldsymbol x}') = \overline{\boldsymbol\varepsilon}
    $$
* 键的路径积分
    $$
    \int_{{\boldsymbol\xi}} {\boldsymbol\varepsilon} {\mathrm d\!} s = \overline{\boldsymbol\varepsilon} {\boldsymbol\xi} = {\boldsymbol\eta}, \forall {\boldsymbol x}' \in {\mathcal H_{\boldsymbol x}}
    $$
* 等价应变能密度
    $$
    W_{\mathrm{DH}}({\boldsymbol x}) = W_{{\boldsymbol x}\to{\boldsymbol x}'}({\boldsymbol x}) + W_{{\boldsymbol x}'\to{\boldsymbol x}}({\boldsymbol x})
    $$
* 带入键的路径积分结论 ${\boldsymbol\eta} = \overline{\boldsymbol\varepsilon} {\boldsymbol\xi}$，得到 $W_{{\boldsymbol x}\to{\boldsymbol x}'}({\boldsymbol x})$ 的等价形式
    $$
    \begin{aligned}
    W_{{\boldsymbol x}\to{\boldsymbol x}'}({\boldsymbol x})
    &= \frac14 \int_{\mathcal H_{\boldsymbol x}}
        c_0({\boldsymbol x}, {\boldsymbol\xi}) \xi^{-2} {\boldsymbol\eta}^{\mathrm T}
                ({\boldsymbol\xi} \otimes {\boldsymbol\xi}) {\boldsymbol\eta} {{\mathrm d\!} V_{{\boldsymbol x}'}} \\
    &= \frac14 \int_{\mathcal H_{\boldsymbol x}}
        c_0({\boldsymbol x}, {\boldsymbol\xi}) \xi^{-2} (\overline{\boldsymbol\varepsilon} {\boldsymbol\xi})^{\mathrm T}
                ({\boldsymbol\xi} \otimes {\boldsymbol\xi}) (\overline{\boldsymbol\varepsilon} {\boldsymbol\xi}) {{\mathrm d\!} V_{{\boldsymbol x}'}} \\
    &= \frac12 \overline{\boldsymbol\varepsilon} : \frac12 \int_{\mathcal H_{\boldsymbol x}} c_0({\boldsymbol x}, {\boldsymbol\xi}) \xi^{-2} {\boldsymbol\xi} \otimes {\boldsymbol\xi} \otimes {\boldsymbol\xi} \otimes {\boldsymbol\xi} {{\mathrm d\!} V_{{\boldsymbol x}'}} : \overline{\boldsymbol\varepsilon} \\
    &= \frac12 \overline{\boldsymbol\varepsilon} : {\mathbf K}_{{\boldsymbol x}\to{\boldsymbol x}'}({\boldsymbol x}): \overline{\boldsymbol\varepsilon} \\
    \end{aligned}
    $$
* 类似地得到 $W_{{\boldsymbol x}'\to{\boldsymbol x}}({\boldsymbol x})$ 的等价形式
    $$
    \begin{aligned}
    W_{{\boldsymbol x}'\to{\boldsymbol x}}({\boldsymbol x})
    &= \frac14 \int_{\mathcal H_{\boldsymbol x}'}
        c_0({\boldsymbol x}', {\boldsymbol\xi}) \xi^{-2} {\boldsymbol\eta}^{\mathrm T}
                ({\boldsymbol\xi} \otimes {\boldsymbol\xi}) {\boldsymbol\eta} {{\mathrm d\!} V_{{\boldsymbol x}'}} \\
    &= \frac14 \int_{\mathcal H_{\boldsymbol x}'}
        c_0({\boldsymbol x}', {\boldsymbol\xi}) \xi^{-2} (\overline{\boldsymbol\varepsilon} {\boldsymbol\xi})^{\mathrm T}
                ({\boldsymbol\xi} \otimes {\boldsymbol\xi}) (\overline{\boldsymbol\varepsilon} {\boldsymbol\xi}) {{\mathrm d\!} V_{{\boldsymbol x}'}} \\
    &= \frac12 \overline{\boldsymbol\varepsilon} : \frac12 \int_{\mathcal H_{\boldsymbol x}'} c_0({\boldsymbol x}', {\boldsymbol\xi}) \xi^{-2} {\boldsymbol\xi} \otimes {\boldsymbol\xi} \otimes {\boldsymbol\xi} \otimes {\boldsymbol\xi} {{\mathrm d\!} V_{{\boldsymbol x}'}} : \overline{\boldsymbol\varepsilon} \\
    &= \frac12 \overline{\boldsymbol\varepsilon} : {\mathbf K}_{{\boldsymbol x}'\to{\boldsymbol x}}({\boldsymbol x}): \overline{\boldsymbol\varepsilon} \\
    \end{aligned}
    $$
* 由于张量是线性可加的，可进一步整理得到对偶邻域 PD 的等价刚度矩阵 ${\mathbf K}_{\mathrm{DH}}({\boldsymbol x})$
    $$
    \begin{aligned}
    {\mathbf K}_{{\boldsymbol x}\to{\boldsymbol x}'}({\boldsymbol x})
        &= \frac12 \int_{\mathcal H_{\boldsymbol x}} c_0({\boldsymbol x}, {\boldsymbol\xi}) \xi^{-2} {\boldsymbol\xi} \otimes {\boldsymbol\xi} \otimes {\boldsymbol\xi} \otimes {\boldsymbol\xi} {{\mathrm d\!} V_{{\boldsymbol x}'}} \\
    {\mathbf K}_{{\boldsymbol x}'\to{\boldsymbol x}}({\boldsymbol x})
        &= \frac12 \int_{\mathcal H_{\boldsymbol x}'} c_0({\boldsymbol x}', {\boldsymbol\xi}) \xi^{-2} {\boldsymbol\xi} \otimes {\boldsymbol\xi} \otimes {\boldsymbol\xi} \otimes {\boldsymbol\xi} {{\mathrm d\!} V_{{\boldsymbol x}'}} \\
    {\mathbf K}_{\mathrm{DH}}({\boldsymbol x})
        &= {\mathbf K}_{{\boldsymbol x}\to{\boldsymbol x}'}({\boldsymbol x}) + {\mathbf K}_{{\boldsymbol x}'\to{\boldsymbol x}}({\boldsymbol x}) \\
    \end{aligned}
    $$
* 注意到可以将 CCM 的应变能密度与对偶邻域 PD 的弹性能密度建立等价关系
    $$
    \begin{aligned}
    W_{\mathrm{CCM}}({\boldsymbol x})
        &= \frac12 {\boldsymbol\varepsilon}({\boldsymbol x}) : {\mathbf K}_0({\boldsymbol x}) : {\boldsymbol\varepsilon}({\boldsymbol x}) \\
    W_{\mathrm{DH}}({\boldsymbol x})
        &= \frac12 \overline{\boldsymbol\varepsilon} : {\mathbf K}_{\mathrm{DH}}({\boldsymbol x}) : \overline{\boldsymbol\varepsilon} \\
    W_{\mathrm{CCM}}({\boldsymbol x}) &= W_{\mathrm{DH}}({\boldsymbol x}) \\
    \implies {\mathbf K}_0({\boldsymbol x})
        &= {\mathbf K}_{\mathrm{DH}}({\boldsymbol x})
        = {\mathbf K}_{{\boldsymbol x}\to{\boldsymbol x}'}({\boldsymbol x}) + {\mathbf K}_{{\boldsymbol x}'\to{\boldsymbol x}}({\boldsymbol x})
    \end{aligned}
    $$

## 一维情形

* **单向作用 Partial Interaction of a Bond**
    * 一维形式下，向量退化为标量，所以单位向量的张量积退化为单位 1；
        $$
        {\boldsymbol e}_{\boldsymbol\xi} \otimes {\boldsymbol e}_{\boldsymbol\xi} = \frac\xi\xi \times \frac\xi\xi = 1
        $$
    * 杆的横截面积记为 $A$，即体积微元可以化简为
        $${{\mathrm d\!} V_{x'}} = A {{\mathrm d\!} {x'}}$$
    * 最终形式
        $$
        \begin{aligned}
        \hat{f}(x', x) &= \frac12 c_0(x, \xi) \eta \\
        \hat{f}(x, x') &= -\frac12 c_0(x, -\xi) \eta \\
        \end{aligned}
        $$
* **平衡方程 Equilibrium Equation**
    * 静力平衡
        $$
        0 = \int_{\mathcal H_{\boldsymbol x}} \hat{f}(x', x) {{\mathrm d\!} V_{x'}} -  \int_{\mathcal H_{\boldsymbol x}'} \hat{f}(x, x') {{\mathrm d\!} V_{x'}} + {b}(x)
        $$
* **本构函数 Consititutive Function**
    * 假设可以对本构函数 $c_0(x, \xi)$ 做变量分离，即 $c_0(x, \xi) = c(x) \rho(\xi)$，其中 $\rho(\xi)$ 的取值方式可以有如下几种。由于具体计算过程中使用的技巧是类似的，所以这里只讨论常数情形，即 $\rho_{\mathrm{const}}(\xi) = 1$
        $$
        \begin{aligned}
        \rho_{\mathrm{const}}(\xi) &= 1 \\
        \rho_{\mathrm{exp}}(\xi) &= \exp(-|\xi|/L) \\
        \rho_{\mathrm{gauss}}(\xi) &= \exp(-|\xi|^2/L^2) \\
        \end{aligned}
        $$
* **等价应变能密度 Elastic Energy Density in Peridynamics**
    * 连续介质力学模型
        $$
        W_{\mathrm{CCM}} = \frac12 E \varepsilon_x^2(x)
        $$
    * action force bond 储存的弹性能密度 $W_{x\to x'}(x)$ 及对应的等效杨氏模量 $E_{x\to x'}(x)$
        $$
        \begin{aligned}
        W_{x\to x'}(x)
        &= \frac14 \int_{\mathcal H_x} c_0(x, \xi) \xi^{-2} \eta
            (\xi^2) \eta {{\mathrm d\!} V_{x'}} \\
        &= \frac14 \int_{\mathcal H_x} c_0(x, \xi) \xi^{-2}
            (\overline{\varepsilon} \xi) (\xi^2) (\overline{\varepsilon} \xi)
            {{\mathrm d\!} V_{x'}} \\
        &= \frac14 \overline{\boldsymbol\varepsilon}^2
            \int_{\mathcal H_x} c_0(x, \xi) \xi^2 {{\mathrm d\!} V_{x'}} \\
        &= \frac14 \overline{\boldsymbol\varepsilon}^2
            \int_{\mathcal H_x} c_0(x, \xi) \xi^2 A {{\mathrm d\!} {x'}} \\
        &= \frac14 \overline{\boldsymbol\varepsilon}^2 A
            \int_{\mathcal H_x} c_0(x, \xi) \xi^2 {{\mathrm d\!} {x'}} \\
        &= (\frac12 \overline{\boldsymbol\varepsilon}^2) E_{x\to x'}(x) \\
        E_{x\to x'}(x) &= \frac{A}{2} \int_{\mathcal H_x} c_0(x, \xi) \xi^2 {{\mathrm d\!} {x'}}
        = \frac{A}{2} \int_{\mathcal H_x - x} c_0(x, \xi) \xi^2 {{\mathrm d\!} {\xi}}
        \end{aligned}
        $$
    * reaction force bond 储存的弹性能密度 $W_{x'\to x}(x)$ 及对应的等效杨氏模量 $E_{x'\to x}(x)$
        $$
        \begin{aligned}
        W_{x'\to x}(x)
        &= \frac14 \int_{\mathcal H_x'} c_0(x', \xi) \xi^{-2} \eta
            (\xi^2) \eta {{\mathrm d\!} V_{x'}} \\
        &= \frac14 \int_{\mathcal H_x'} c_0(x', \xi) \xi^{-2}
            (\overline{\varepsilon} \xi) (\xi^2) (\overline{\varepsilon} \xi)
            {{\mathrm d\!} V_{x'}} \\
        &= \frac14 \overline{\boldsymbol\varepsilon}^2
            \int_{\mathcal H_x'} c_0(x', \xi) \xi^2 {{\mathrm d\!} V_{x'}} \\
        &= \frac14 \overline{\boldsymbol\varepsilon}^2
            \int_{\mathcal H_x'} c_0(x', \xi) \xi^2 A {{\mathrm d\!} {x'}} \\
        &= \frac14 \overline{\boldsymbol\varepsilon}^2 A
            \int_{\mathcal H_x'} c_0(x', \xi) \xi^2 {{\mathrm d\!} {x'}} \\
        &= (\frac12 \overline{\boldsymbol\varepsilon}^2) E_{x'\to x}(x) \\
        E_{x'\to x}(x) &= \frac{A}{2} \int_{\mathcal H_x'} c_0(x', \xi) \xi^2 {{\mathrm d\!} {x'}}
        = \frac{A}{2} \int_{\mathcal H_x' - x} c_0(x', \xi) \xi^2 {{\mathrm d\!} {\xi}}
        \end{aligned}
        $$
    * 应变能密度及杨氏模量的等价关系
        $$
        \begin{aligned}
        W_{\mathrm{CCM}}(x) &= W_{x\to x'}(x) + W_{x'\to x}(x) \\
        E_0 = E(x) &= E_{x\to x'}(x) + E_{x'\to x}(x) \\
        \end{aligned}
        $$
* 考虑这样的几何设置，左右两端的材料的杨氏模量为 $E1$ 和 $E2$，近邻域大小分别为 $\delta_1$ 和 $\delta_2$，$0 \leq \delta_1 \leq \delta_2$，任意点的近邻域大小为
    $$
    E(x) = \begin{cases}
    E1, & x \in (-\infty, 0] \\ E2, & x \in (0, -\infty)
    \end{cases},
    \delta(x) = \begin{cases}
    \delta_1, & x \in (-\infty, -\delta_1] \\
    k(x + \delta_1) + \delta_1, & x \in (-\delta_1, \delta_2] \\
    \delta_2, & x \in (\delta_2, -\infty)
    \end{cases}
    $$
    其中 $k = \dfrac{\delta_2 - \delta_1}{\delta_1 + \delta_2}$ 表示近邻域的变化率，对于当前这种情形，$0 \leq |k| \leq 1$
    1.  当 $x \in (-\infty, -2\delta_1]$ 时，此时 $\mathcal H_x = \mathcal H_x' = [x - \delta_1, x + \delta_1]$，模型退化为普通的常数邻域模型，则此时的等效杨氏模量 $E_{x\to x'}(x) = E_{x'\to x}(x) = E_0 / 2$，进一步计算可以得到
        $$
        \begin{aligned}
        E_{x\to x'}(x)
        &= \frac{A}{2} \int_{\mathcal H_x} c(x) \rho(\xi) \xi^2 {{\mathrm d\!} {x'}} \\
        &= \frac{A}{2} c(x) \int_{x - \delta_1}^{x + \delta_1} \rho(\xi) \xi^2 {{\mathrm d\!} {x'}} \\
        &= \frac{A}{2} c(x) \int_{-\delta_1}^{\delta_1} \rho(\xi) \xi^2 {{\mathrm d\!} {\xi}} \\
        \end{aligned}
        $$
        不妨假设其为常系数本构 $\rho_{\mathrm{const}}(\xi) = 1$，即 $c(x) = c_1$，则此时的本构系数为
        $$
        \begin{aligned}
        \frac{E}{2} = E_{x\to x'}(x)
        &= c_1 \frac{A}{2} \int_{-\delta_1}^{\delta_1} \xi^2 {{\mathrm d\!} {\xi}} \\
        &= c_1 \frac{A}{2} \bigg(\frac13 \xi^3 \bigg) \bigg|_{-\delta_1}^{\delta_1}
        = c_1 \frac{A}{2} \frac{2}{3} \delta_1^3 \\
        \implies c_1 &= \frac{3 E_0}{2 A \delta_1^3}
        \end{aligned}
        $$
    2. 当 $x \in (-2\delta_1, -\delta_1]$ 时，此时 $\mathcal H_x = [x - \delta_1, x + \delta_1]$，$\mathcal H_x' = [x - \delta_1, x+\frac{1+k}{1-k}\delta_1 + \frac{1}{1-k}x]$，其中 $k = \frac{\delta_2 - \delta_1}{\delta_1 + \delta_2}$，则此时的等效杨氏模量 $E_{x\to x'}(x) + E_{x'\to x}(x) = E_0$，且当 $x \in (-\infty, -2\delta_1]$ 时，有 $c(x) = c_1$， 进一步计算可以得到
        $$
        \begin{aligned}
        E_{x\to x'}(x)
        &= \frac{A}{2} \int_{\mathcal H_x} c(x) \rho(\xi) \xi^2 {{\mathrm d\!} {x'}} \\
        &= \frac{A}{2} c(x) \int_{x - \delta_1}^{x + \delta_1} \rho(\xi) \xi^2 {{\mathrm d\!} {x'}} \\
        &= \frac{A}{2} c(x) \int_{-\delta_1}^{\delta_1} \rho(\xi) \xi^2 {{\mathrm d\!} {\xi}} \\
        \end{aligned}
        $$
        $$
        \begin{aligned}
        E_{x'\to x}(x)
        &= \frac{A}{2} \int_{\mathcal H_x'} c(x') \rho(\xi) \xi^2 {{\mathrm d\!} {x'}} \\
        &= \frac{A}{2} \int_{x - \delta_1}^{x + \frac{1+k}{1-k}\delta_1 + \frac{k}{1-k}x} c(x') \rho(\xi) \xi^2 {{\mathrm d\!} {x'}} \\
        &= \frac{A}{2} \int_{-\delta_1}^{\frac{1+k}{1-k}\delta_1 + \frac{k}{1-k}x} c(\xi+x) \rho(\xi) \xi^2 {{\mathrm d\!} {\xi}} \\
        \end{aligned}
        $$
        不妨假设其为常系数本构 $\rho_{\mathrm{const}}(\xi) = 1$，令该区间 $x \in (-2\delta_1, -\delta_1]$ 内的 $c(x) = c_2(x)$，令该区间 $x \in (-\delta_1, 0]$ 内的 $c(x) = c_3(x)$，由于当 $x \in (-\infty, -\delta_1]$ 时，近邻域大小并未发生变化，所以 PD 的本构参数也不应当发生变化，故 $c_2(x) = c_1 = \frac{3 E_0}{2 A \delta_1^3}$，且 $c_3(x)$ 的左端点的取值 $c_3(-\delta_1) = c_1 = \frac{3 E_0}{2 A \delta_1^3}$，则此时进一步化简得到
        $$
        \begin{aligned}
        E_{x\to x'}(x)
        &= \frac{A}{2} c_2(x) \int_{-\delta_1}^{\delta_1} \rho(\xi) \xi^2 {{\mathrm d\!} {\xi}} \\
        &= \frac{A}{2} c_2(x) \bigg(\frac13 \xi^3 \bigg) \bigg|_{-\delta_1}^{\delta_1} \\
        &= c_2(x) \frac{A}{2} \frac{2}{3} \delta_1^3 \\
        &= \frac13 A \delta_1^3 c_2(x) = \frac13 A \delta_1^3 \frac{3 E_0}{2 A \delta_1^3} \\
        &= \frac{E_0}{2}
        \end{aligned}
        $$
        $$
        \begin{aligned}
        E_{x'\to x}(x)
        &= \frac{A}{2} \int_{-\delta_1}^{\frac{1+k}{1-k}\delta_1 + \frac{k}{1-k}x}
            c(\xi+x) \rho(\xi) \xi^2 {{\mathrm d\!} {\xi}}
        = \frac{A}{2} \int_{-\delta_1}^{\frac{1+k}{1-k}\delta_1 + \frac{k}{1-k}x}
            c(\xi+x) \xi^2 {{\mathrm d\!} {\xi}} \\
        &= \frac{A}{2} \int_{-\delta_1}^{-\delta_1 - x}
            c(\xi+x) \xi^2 {{\mathrm d\!} {\xi}} +
            \frac{A}{2} \int_{-\delta_1 - x}^{\frac{1+k}{1-k}\delta_1 + \frac{k}{1-k}x}
                c(\xi+x) \xi^2 {{\mathrm d\!} {\xi}} \\
        &= \frac{A}{2} \int_{-\delta_1}^{-\delta_1 - x}
            c_2 \xi^2 {{\mathrm d\!} {\xi}} +
            \frac{A}{2} \int_{-\delta_1 - x}^{\frac{1+k}{1-k}\delta_1 + \frac{k}{1-k}x}
                c_3(\xi+x) \xi^2 {{\mathrm d\!} {\xi}} \\
        \end{aligned}
        $$
        令
        $$
        \begin{aligned}
        \text{LeftPart} = F(x) &= \frac{A}{2} \int_{-\delta_1}^{-\delta_1 - x}
            c_2 \xi^2 {{\mathrm d\!} {\xi}} \\
        \text{RightPart} = G(x) &= \frac{A}{2} \int_{-\delta_1 - x}^{\frac{1+k}{1-k}\delta_1 + \frac{k}{1-k}x}
                c_3(\xi+x) \xi^2 {{\mathrm d\!} {\xi}} \\
        \Omega_{L} &= [L_1, L_2] = [-\delta_1, -\delta_1 - x] \\
        \Omega_{R} &= [R_1, R_2] = [-\delta_1 - x, \frac{1+k}{1-k}\delta_1 + \frac{k}{1-k}x] \\
        R_2 &= m_0 + m_1 x = \frac{1+k}{1-k}\delta_1 + \frac{k}{1-k}x \\
        \frac{E_0}{2} &= \text{LeftPart} + \text{RightPart} = F(x) + G(x)
        \end{aligned}
        $$
        进一步化简得到
        $$
        \begin{aligned}
        \text{LeftPart} = F(x) &= \frac{A}{2} \int_{-\delta_1}^{-\delta_1 - x}
            c_2 \xi^2 {{\mathrm d\!} {\xi}} \\
        &= \frac{A}{2} \frac{3 E_0}{2 A \delta_1^3} \bigg(\frac13 \xi^3 \bigg) \bigg|_{-\delta_1}^{-\delta_1 - x} \\
        &= \frac{E_0}{4 \delta_1^3} \bigg( (-\delta_1 - x)^3 - (-\delta_1)^3 \bigg) \\
        &= -\frac{E_0}{4 \delta_1^3} \bigg( 3 \delta_1^2 x + 3 \delta_1 x^2 + x^3 \bigg) \\
        \end{aligned}
        $$
        利用级数求和的技巧，构造函数 $c_3(y) = \sum_{t} \alpha_t y^t$，其中 $t \in \mathbb{N}$，记 $G(x) = \sum_t g_t(x)$，其中
        $$
        \begin{aligned}
        g_t(x) &= \frac{A}{2} \int_{-\delta_1 - x}^{m_0 + m_1 x}
                \alpha_t (\xi+x)^t \xi^2 {{\mathrm d\!} {\xi}} \\
            &= \frac{A \alpha_t}{2} \int_{-\delta_1 - x}^{m_0 + m_1 x}
                \sum_{s=0}^{t} \binom{t}{s} \xi^{t-s+2} x^s {{\mathrm d\!} {\xi}} \\
            &= \frac{A \alpha_t}{2} \sum_{s=0}^{t} \binom{t}{s} x^s \int_{-\delta_1 - x}^{m_0 + m_1 x}
                \xi^{t-s+2} {{\mathrm d\!} {\xi}} \\
        \text{Let}\quad g_{t, s}(x)
        &= \frac{A \alpha_t}{2} \binom{t}{s} x^s \int_{-\delta_1 - x}^{m_0 + m_1 x} \xi^{t-s+2} {{\mathrm d\!} {\xi}}
        \end{aligned}
        $$
        令 $\beta = t - s + 2 \geq 2$，则此时积分项可化简为
        $$
        \begin{aligned}
        I_{t, s}(x) &= \int_{-\delta_1 - x}^{m_0 + m_1 x} \xi^{t-s+2} {{\mathrm d\!} {\xi}} = \int_{-\delta_1 - x}^{m_0 + m_1 x} \xi^{\beta} {{\mathrm d\!} {\xi}} \\
        &= \bigg( \frac{1}{\beta + 1} \xi^{\beta + 1} \bigg) \bigg|_{-\delta_1 - x}^{m_0 + m_1 x} \\
        &= \frac{1}{\beta + 1} \bigg[ 
            (m_0 + m_1 x)^{\beta+1} - (-\delta_1 - x)^{\beta+1} \bigg]\\
        (m_0 + m_1 x)^{\beta+1} &= \sum_{r=0}^{\beta+1} \binom{\beta+1}{r} m_0^{\beta+1-r} m_1^{r} x^r \\
        (\delta_1 + x)^{\beta+1} &= \sum_{r=0}^{\beta+1} \binom{\beta+1}{r} \delta_1^{\beta+1-r} x^r \\
        -(-\delta_1 - x)^{\beta+1} &= (-1)^{\beta+2} (\delta_1 + x)^{\beta+1} \\
            &= \sum_{r=0}^{\beta+1} (-1)^{\beta}\binom{\beta+1}{r} \delta_1^{\beta+1-r} x^r \\
        I_{t, s, r}(x) &= \frac{1}{t-s+3} \binom{t-s+3}{r} \bigg(  m_0^{t-s+3-r} m_1^{r} + \delta_1^{t-s+3-r} \bigg) x^r \\
            &= \gamma_{t, s, r} x^r
        \end{aligned}
        $$
        处理完积分项之后，将结果带入二项式的分项当中，记 $g_{t, s}(x) = \sum_{r = 0}^{t-s+3}g_{t, s, r}(x)$，则可以得到
        $$
        \begin{aligned}
        g_{t, s, r}(x)
        &= \left( \frac{A \alpha_t}{2} \binom{t}{s} x^s \right) (\gamma_{t, s, r} x^r) \\
        &= \frac{A}{2} \binom{t}{s} \gamma_{t, s, r} \alpha_t x^{s+r} \\
        &= \frac{A}{2} \zeta_{t, s, r} \alpha_t x^{s+r}
        \end{aligned}
        $$
        注意到 $G(x) + F(x) = E_0 / 2$，所以将上面的结果进一步整理得到
        $$
        \begin{aligned}
        G(x) &= \frac{E_0}{2} +\frac{E_0}{4 \delta_1^3} \bigg( 3 \delta_1^2 x + 3 \delta_1 x^2 + x^3 \bigg) \\
        &= \frac{E_0}{2} + \frac{3 E_0}{4 \delta_1} x + \frac{3 E_0}{4 \delta_1^2} x^2 + \frac{E_0}{4 \delta_1^3} x^3 
        \end{aligned}
        $$
        同时由于 $G(x) = \sum_t g_{t}(x) = \sum_t \sum_s g_{t, s}(x) = \sum_t \sum_s \sum_r g_{t, s, r}(x) = \sum_{t, s, r} \frac{A}{2} \zeta_{t, s, r} \alpha_t x^{s+r}$，所以我们统计出真正使用到的标号 $\{t, s, r\}$，如下表所示

        | Group |   t   |   s   |   r   | $x^{s+r}$ | Group |   t   |   s   |   r   | $x^{s+r}$ |
        | :---: | :---: | :---: | :---: | :-------: | :---: | :---: | :---: | :---: | :-------: |
        |   1   |   0   |   0   |   0   |   $x^0$   |   4   |   3   |   0   |   0   |   $x^0$   |
        |   2   |   1   |   0   |   0   |   $x^0$   |       |   3   |   1   |   0   |   $x^1$   |
        |       |   1   |   1   |   0   |   $x^1$   |       |   3   |   1   |   1   |   $x^2$   |
        |       |   1   |   1   |   1   |   $x^2$   |       |   3   |   2   |   0   |   $x^2$   |
        |   3   |   2   |   0   |   0   |   $x^0$   |       |   3   |   2   |   1   |   $x^3$   |
        |       |   2   |   1   |   0   |   $x^1$   |       |   3   |   2   |   2   |   $x^4$   |
        |       |   2   |   1   |   1   |   $x^2$   |       |   3   |   3   |   0   |   $x^3$   |
        |       |   2   |   2   |   0   |   $x^2$   |       |   3   |   3   |   1   |   $x^4$   |
        |       |   2   |   2   |   1   |   $x^3$   |       |   3   |   3   |   2   |   $x^5$   |
        |       |   2   |   2   |   2   |   $x^4$   |       |   3   |   3   |   3   |   $x^6$   |

        由此表可得
        $$
        \begin{aligned}
        \frac{E_0}{2} &= \sum_{t, s=r=0} \frac{A}{2} \zeta_{t, s, r} \alpha_t x^{s+r}
            = \frac{A}{2} \sum_t \zeta_{t, 0, 0} \alpha_t \\
        \frac{3 E_0}{4 \delta_1} x &= \sum_{t, s=1, r=0} \frac{A}{2} \zeta_{t, s, r} \alpha_t x^{s+r}
            = \frac{A}{2} \sum_t \zeta_{t, 1, 0} \alpha_t x \\
        \frac{3 E_0}{4 \delta_1^2} x^2 &= \sum_{t, s+r=2} \frac{A}{2} \zeta_{t, s, r} \alpha_t x^{s+r}
            = \frac{A}{2} \sum_t (\zeta_{t, 1, 1} + \zeta_{t, 2, 0}) \alpha_t x^2 \\
        \frac{E_0}{4 \delta_1^3} x^3 &= \sum_{t, s+r=3} \frac{A}{2} \zeta_{t, s, r} \alpha_t x^{s+r}
            = \frac{A}{2} \sum_t (\zeta_{t, 2, 1} + \zeta_{t, 3, 0}) \alpha_t x^3 \\
        0 &= \sum_{t, s+r>3} \frac{A}{2} \zeta_{t, s, r} \alpha_t x^{s+r}
            = \frac{A}{2} \sum_{t, s+r>3} \zeta_{t, s, r} \alpha_t x^{s+r} \\
        \end{aligned}
        $$
        根据上表，取 $t \in \{0, 1, 2, 3\}$，得到关于 $\{\alpha_0, \alpha_1, \alpha_2, \alpha_3\}$ 的一组方程，具体推导过程如下
        $$
        \begin{aligned}
        \frac{E_0}{4 \delta_1^3} \frac{2}{A} &= \zeta_{3, 2, 1} \alpha_3 + \zeta_{2, 2, 1} \alpha_2 \\
        \frac{3 E_0}{4 \delta_1^2} \frac{2}{A} &= (\zeta_{3, 2, 0} + \zeta_{3, 1, 1}) \alpha_3 + (\zeta_{2, 2, 0} + \zeta_{2, 1, 1}) \alpha_2 + \zeta_{1, 1, 1} \alpha_1 \\
        \frac{3 E_0}{4 \delta_1} \frac{2}{A} &= \zeta_{3, 1, 0} \alpha_3 + \zeta_{2, 1, 0} \alpha_2 + \zeta_{1, 1, 0} \alpha_1 \\
        \frac{E_0}{2} \frac{2}{A} &= \zeta_{3, 0, 0} \alpha_3 + \zeta_{2, 0, 0} \alpha_2 + \zeta_{1, 0, 0} \alpha_1 + \zeta_{0, 0, 0} \alpha_0
        \end{aligned}
        $$
        解上面的方程组，即得 $c_3(x) = \sum_{t=0}^{3} \alpha_t x^t$
    3. 当 $x \in (-\delta_1, 0]$ 时，此时 $\mathcal H_x = [x - \delta(x), x + \delta(x)] = [(1-k)x - (k+1)\delta_1, (k+1)(x + \delta_1)]$，$\mathcal H_x' = [x - \delta_1, x+\frac{1+k}{1-k}\delta_1 + \frac{k}{1-k}x]$，其中 $k = \frac{\delta_2 - \delta_1}{\delta_1 + \delta_2}$，则此时的等效杨氏模量 $E_{x\to x'}(x) + E_{x'\to x}(x) = E_0$，且当 $x \in (-\infty, -2\delta_1]$ 时，有 $c(x) = c_1$， 进一步计算可以得到
    4. 当 $x \in (0, \delta_2]$ 时，此时 $\mathcal H_x = [x - \delta_1, x + \delta_1]$，$\mathcal H_x' = [x - \delta_1, x+\frac{1+k}{1-k}\delta_1 + \frac{k}{1-k}x]$，其中 $k = \frac{\delta_2 - \delta_1}{\delta_1 + \delta_2}$，则此时的等效杨氏模量 $E_{x\to x'}(x) + E_{x'\to x}(x) = E_0$，且当 $x \in (-\infty, -2\delta_1]$ 时，有 $c(x) = c_1$， 进一步计算可以得到
    5. 当 $x \in (\delta_2, 2\delta_2]$ 时，此时 $\mathcal H_x = [x - \delta_1, x + \delta_1]$，$\mathcal H_x' = [x - \delta_1, x+\frac{1+k}{1-k}\delta_1 + \frac{k}{1-k}x]$，其中 $k = \frac{\delta_2 - \delta_1}{\delta_1 + \delta_2}$，则此时的等效杨氏模量 $E_{x\to x'}(x) + E_{x'\to x}(x) = E_0$，且当 $x \in (2\delta_2, \infty]$ 时，有 $c(x) = c_6 = \frac{3 E_0}{2 A \delta_2^3}$， 进一步计算可以得到
    6. 当 $x \in (2\delta_2, \infty)$ 时，此时 $\mathcal H_x = \mathcal H_x' = [x - \delta_2, x + \delta_2]$，模型退化为普通的常数邻域模型，则此时的等效杨氏模量 $E_{x\to x'}(x) = E_{x'\to x}(x) = E_0 / 2$，进一步计算可以得到
        $$
        \begin{aligned}
        E_{x\to x'}(x)
        &= \frac{A}{2} \int_{\mathcal H_x} c(x) \rho(\xi) \xi^2 {{\mathrm d\!} {x'}} \\
        &= \frac{A}{2} c(x) \int_{x - \delta_2}^{x + \delta_2} \rho(\xi) \xi^2 {{\mathrm d\!} {x'}} \\
        &= \frac{A}{2} c(x) \int_{-\delta_2}^{\delta_2} \rho(\xi) \xi^2 {{\mathrm d\!} {\xi}} \\
        \end{aligned}
        $$
        不妨假设其为常系数本构 $\rho_{\mathrm{const}}(\xi) = 1$，即 $c(x) = c_6$，则此时的本构系数为
        $$
        \begin{aligned}
        \frac{E}{2} = E_{x\to x'}(x)
        &= c_6 \frac{A}{2} \int_{-\delta_2}^{\delta_2} \xi^2 {{\mathrm d\!} {\xi}} \\
        &= c_6 \frac{A}{2} \bigg(\frac13 \xi^3 \bigg) \bigg|_{-\delta_2}^{\delta_2}
        = c_6 \frac{A}{2} \frac{2}{3} \delta_2^3 \\
        \implies c_6 &= \frac{3 E_0}{2 A \delta_2^3}
        \end{aligned}
        $$



