# Cryptography

## 密码学课程设计

## 记录密码学课程设计的代码

## 任务要求

### 课题内容：
（1）原始SPN（教材上）算法的实现。
（2）对上述算法进行线性密码分析及差分密码分析（求出所有32比特密钥）。
（3）增强以上SPN的安全性（如增加分组的长度、密钥的长度、S盒、轮数等）。
（4）对原始及增强的SPN进行随机性检测，对检测结果进行说明。
（5）生成RSA算法的参数（如p、q、N、私钥、公钥等）。
（6）快速实现RSA（对比模重复平方、蒙哥马利算法和中国剩余定理）。
（7）结合RSA和增强后的SPN实现文件（或通信）的加解密。
（8）构造彩虹表破解hash函数。

### 课题任务要求：
（1）	掌握线性、差分分析的基本原理与方法。
（2）	体会位运算、预计算在算法快速实现中的作用。
（3）	可借助OpenSSL、GMP、BIGINT等大数运算库的低层基本函数，实现过程中必须体现模重复平方、中国剩余定理和蒙哥马利算法的过程。
（4）	了解和掌握彩虹表构造的基本原理和方法，能够设计和实现约化函数（reduction  function），针对特定的hash函数构造彩虹表，进行口令破解。
（5）	独立完成课程设计内容，现场演示并讲解。
（6）	课程设计完成后一周内，提交课程设计报告。

### 主要参考文献（由指导教师选定）
（1）	密码学原理与实践（第三版）. DouglasR.Stinson著，冯登国译，电子工业出版社，2009
（2）	应用密码学：协议算法与C源程序（第二版）. Bruce Schneier 著，吴世忠等译，机械工业出版社，2014


