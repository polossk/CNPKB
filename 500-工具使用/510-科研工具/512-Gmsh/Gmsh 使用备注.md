# Gmsh 使用备注

> tags: #mesh-generator; #gmsh;

主要参考文档<a name="rref1"></a>\[[1](#ref1)\]。

## 基本图形绘制

### 椭圆曲线 Ellipse

```cpp
Ellipse ( expression ) = { expression, expression, expression, <, ...> };
```
> Creates an ellipse arc. If four expressions are provided on the right-hand-side they define the start point, the center point, a point anywhere on the major axis and the end point. If the first point is a major axis point, the third expression can be ommitted. With the OpenCASCADE kernel, if between 5 and 7 expressions are provided, the first three define the coordinates of the center, the next two define the major (along the x-axis) and minor radii (along the y-axis), and the next two the start and end angle. Note that OpenCASCADE does not allow creating ellipse arcs with the major radius smaller than the minor radius.

#### 使用说明

```cpp
Ellipse (Arc1) = {start_point_on_major_axis, center_point, end_point};
Ellipse (Arc1) = {start_point, center_point, point_on_major_axis, end_point};
SetFactory("OpenCASCADE");
Ellipse (Arc1) = {center_x, center_y, center_z, x_axis_radius, y_axis_radius, start_angle, end_angle};
```

```cpp

```

## 图形变换操作

### 旋转操作 Rotate

```cpp
Rotate { { expression-list }, { expression-list }, expression } { transform-list }
```
> Rotates all elementary entities in transform-list by an angle of expression radians. The first expression-list should contain three expressions giving the X, Y and Z direction of the rotation axis; the second expression-list should contain three expressions giving the X, Y and Z components of any point on this axis.

#### 使用说明

```cpp
// direction of the rotation axis := {axis_x, axis_y, axis_z}
// piovt point := {piovt_x, piovt_y, piovt_z}
Rotate { {axis_x, axis_y, axis_z}, {piovt_x, piovt_y, piovt_z}, angle}{ ... }
```

#### 样例




## 软件下载

官网网址 <https://gmsh.info/#Download>

## 参考文档

<a name="ref1">\[1\]</a>[^](#rref1) Gmsh 软件文档 <https://gmsh.info/doc/texinfo/gmsh.html>
