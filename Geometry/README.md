### Geometry Laws for Competitive Programming

## Basic Geometry Formulas

### Distance Between Two Points
```math
\text{Distance} = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}
```

### Midpoint Formula
```math
M = \left(\frac{x_1 + x_2}{2}, \frac{y_1 + y_2}{2}\right)
```

### Slope of a Line
```math
m = \frac{y_2 - y_1}{x_2 - x_1}
```
- If two lines have the same slope, they are **parallel**.
- If the product of slopes is `-1`, they are **perpendicular**.

### Collinearity of Three Points
```math
\frac{1}{2} \left| x_1(y_2 - y_3) + x_2(y_3 - y_1) + x_3(y_1 - y_2) \right| = 0
```

## Triangle Formulas

### Area of a Triangle Given Three Points
```math
A = \frac{1}{2} \left| x_1(y_2 - y_3) + x_2(y_3 - y_1) + x_3(y_1 - y_2) \right|
```

### Heron's Formula (Given Three Sides)
```math
s = \frac{a + b + c}{2}
```
```math
A = \sqrt{s(s-a)(s-b)(s-c)}
```

### Circumradius of a Triangle
```math
R = \frac{abc}{4A}
```

### Inradius of a Triangle
```math
r = \frac{A}{s}
```

## Polygon Formulas

### Shoelace Theorem (Polygon Area)
```math
A = \frac{1}{2} \left| \sum_{i=1}^{n} (x_i y_{i+1} - x_{i+1} y_i) \right|
```

### Checking if a Point is Inside a Polygon
- **Ray-Casting Algorithm**
- **Winding Number Algorithm**

## Line Formulas

### Intersection of Two Lines
```math
x = \frac{b_1c_2 - b_2c_1}{a_1b_2 - a_2b_1}, \quad y = \frac{c_1a_2 - c_2a_1}{a_1b_2 - a_2b_1}
```

### Checking If Two Line Segments Intersect
Use **cross product** and **orientation test**.

## Circle Formulas

### Standard Equation of a Circle
```math
(x - h)^2 + (y - k)^2 = r^2
```

### Finding Intersection of a Line and a Circle
Substituting `y = mx + c` in the circle equation and solving.

### Tangents from an External Point
```math
d = \sqrt{(x_0 - h)^2 + (y_0 - k)^2}
```
If `d > r`, then **two tangents** exist.

## Convex Hull Algorithms

### Graham’s Scan (O(n log n))
- Sort points by x-coordinate.
- Use **cross product** to find the convex hull.

### Jarvis March (Gift Wrapping) (O(nh))
- Iteratively find the leftmost point.

## Closest Pair of Points

### Brute Force (O(n²))
### Divide and Conquer (O(n log n))

## Rotations and Vector Operations

### Rotating a Point Around the Origin by θ Degrees
```math
x' = x \cos\theta - y \sin\theta
```
```math
y' = x \sin\theta + y \cos\theta
```

### Dot Product of Two Vectors
```math
A \cdot B = x_1x_2 + y_1y_2
```
- If `A ⋅ B = 0`, the vectors are **perpendicular**.

### Angle Between Two Vectors
```math
\theta = \cos^{-1} \left( \frac{A \cdot B}{|A||B|} \right)
```

## Summary
- **Shoelace Theorem**, **Convex Hull**, and **Point in Polygon** are essential.
- Use **EPS = 10⁻⁹** for floating-point precision.
- **Sweep Line Algorithm** and **Divide and Conquer** are useful in many problems.

🔹 *For explanations or implementations, feel free to ask!* 🚀
