# **জ্যামিতিক সূত্র (Geometric Formulas)**

এই রিপোজিটরিতে কম্পিটিটিভ প্রোগ্রামিংয়ে ব্যবহৃত কিছু মৌলিক জ্যামিতিক সূত্র সংকলন করা হয়েছে।

---

## **1. ত্রিভুজের সূত্র (Triangle Formulas)**

### **1.1. ত্রিভুজের ক্ষেত্রফল (Area of a Triangle)**
```math
\text{Area} = \frac{1}{2} \times \text{base} \times \text{height}
```
- **হেরনের সূত্র (যদি তিনটি বাহুর দৈর্ঘ্য জানা থাকে):**
```math
s = \frac{a + b + c}{2}  \quad (\text{অর্ধ-পরিসীমা})
```
```math
\text{Area} = \sqrt{s(s - a)(s - b)(s - c)}
```
- **স্থানাঙ্ক ব্যবহার করে ক্ষেত্রফল:**
```math
\text{Area} = \frac{1}{2} \left| x_1(y_2 - y_3) + x_2(y_3 - y_1) + x_3(y_1 - y_2) \right|
```

### **1.2. ত্রিভুজের পরিসীমা (Perimeter of a Triangle)**
```math
\text{Perimeter} = a + b + c
```

### **1.3. পিথাগোরাসের উপপাদ্য (Pythagorean Theorem)**
```math
a^2 + b^2 = c^2
```
- যেখানে \(c\) হল সমকোণী ত্রিভুজের অতিভুজ।

---

## **2. বহুভুজের সূত্র (Polygon Formulas)**

### **2.1. বহুভুজের ক্ষেত্রফল (Area of a Polygon)**
```math
\text{Area} = \frac{1}{2} \left| \sum_{i=1}^{n} (x_i y_{i+1} - x_{i+1} y_i) \right|
```
- এখানে \(x_{n+1} = x_1\) এবং \(y_{n+1} = y_1\)।

### **2.2. বহুভুজের পরিসীমা (Perimeter of a Polygon)**
```math
\text{Perimeter} = \sum_{i=1}^{n} \text{side}_i
```

### **2.3. বহুভুজের অন্তঃকোণের সমষ্টি (Sum of Interior Angles)**
```math
\text{Sum of Interior Angles} = (n - 2) \times 180^\circ
```
- যেখানে \(n\) হল বহুভুজের বাহুর সংখ্যা।

---

## **3. বৃত্তের সূত্র (Circle Formulas)**

### **3.1. বৃত্তের পরিধি (Circumference of a Circle)**
```math
C = 2\pi r
```
- যেখানে \(r\) হল ব্যাসার্ধ।

### **3.2. বৃত্তের ক্ষেত্রফল (Area of a Circle)**
```math
A = \pi r^2
```

### **3.3. বৃত্তের চাপের দৈর্ঘ্য (Arc Length)**
```math
L = r \theta
```
- যেখানে \(\theta\) হল রেডিয়ানে কোণ।

### **3.4. বৃত্তের সেক্টরের ক্ষেত্রফল (Area of a Sector)**
```math
A = \frac{1}{2} r^2 \theta
```

### **3.5. বৃত্তের স্পর্শকের সমীকরণ (Equation of Tangent to a Circle)**
- কেন্দ্র \((h, k)\) এবং ব্যাসার্ধ \(r\) বিশিষ্ট বৃত্তের \((x_1, y_1)\) বিন্দুতে স্পর্শকের সমীকরণ:
```math
(x_1 - h)(x - h) + (y_1 - k)(y - k) = r^2
```

### **3.6. দুই বৃত্তের ছেদবিন্দু (Intersection of Two Circles)**
- দুই বৃত্তের সমীকরণ:
```math
(x - h_1)^2 + (y - k_1)^2 = r_1^2
```
```math
(x - h_2)^2 + (y - k_2)^2 = r_2^2
```
- ছেদবিন্দু নির্ণয়ের জন্য সমীকরণ দুটি সমাধান করুন।

---

## **4. বহুভুজের সাথে বৃত্ত (Polygon and Circle)**

### **4.1. বহির্লিখিত বৃত্ত (Circumscribed Circle)**
- **বহুভুজের সব শীর্ষবিন্দুকে স্পর্শ করে**
- **কেন্দ্র:** বহুভুজের **পরিকেন্দ্র (Circumcenter)**
- **ব্যাসার্ধ (R):**
  ```
  R = (abc) / (4 × Area of Triangle)
  ```

### **4.2. অন্তর্লিখিত বৃত্ত (Inscribed Circle)**
- **বহুভুজের সব বাহুকে স্পর্শ করে**
- **কেন্দ্র:** বহুভুজের **অন্তঃকেন্দ্র (Incenter)**
- **ব্যাসার্ধ (r):**
  ```
  r = (Area of Polygon) / (Semi-perimeter)
  ```

---
### **5. গোলকের সূত্র (Sphere Formulas)**

#### **5.1. গোলকের আয়তন (Volume of a Sphere)**
```math
V = \frac{4}{3} \pi r^3
```
- যেখানে \( r \) হল ব্যাসার্ধ।

#### **5.2. গোলকের পৃষ্ঠ ক্ষেত্রফল (Surface Area of a Sphere)**
```math
A = 4\pi r^2
```
- যেখানে \( r \) হল ব্যাসার্ধ।


