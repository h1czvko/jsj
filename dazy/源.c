#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <math.h>


void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double cheng(double a, double b);
double factorial(int n);                                                                            //阶乘
double shulie(int shouXiang, int gongCha, int xiangShu);
void erYuanFangCheng(double a1, double a2, double b1, double b2, double c1, double c2);
void yiYuanFangCheng(double a, double b, double c);




int main() {
    int choice;
    double a, b, c;
    double a1, b1, c1, a2, b2, c2, x, y;
    int n, shouXiang, gongCha, xiangShu;
    int m;
    int o[1000];
    int p[1000];

    displayMenu();
    printf("选择功能: ");
    scanf("%d", &choice);

    switch (choice) {                                                                                           //选择
    case 1:
        printf("输入两个数字: ");
        scanf("%lf %lf", &a, &b);
        printf("和: %.2lf\n", add(a, b));
        printf("差: %.2lf\n", subtract(a, b));
        printf("积: %.2lf\n", cheng(a, b));
        break;
    case 2:
        printf("输入一个整数: ");
        scanf("%d", &n);
        printf("阶乘为: %.0lf\n", factorial(n));
        break;
    case 3:
        printf("输入系数 (a, b, c) 给予以下方程 (ax^2 + bx + c = 0): ");
        scanf("%lf %lf %lf", &a, &b, &c);
        yiYuanFangCheng(a, b, c);
        break;
    case 4:
        printf("输入等差数列的首项、公差、项数： ");
        scanf("%d %d %d", &shouXiang, &gongCha, &xiangShu);
        printf("等差数列和为: %.2lf\n", shulie(shouXiang, gongCha, xiangShu));
        break;
    case 6:
        printf("输入两组系数 (a, b, c) 给予以下方程 (ax + by = c): ");
        scanf("%lf %lf %lf %lf %lf %lf", &a1, &b1, &c1, &a2, &b2, &c2);
        erYuanFangCheng(a1, b1, c1, a2, b2, c2);
        break;
    case 5:
        printf("分别输入两个整数数组：");
        printf("第一个数组个数：");
        scanf("%d", &n);
        printf("输入数组");
        int a[1000];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("第二个数组个数：");
        scanf("%d", &m);
        printf("输入数组");
        int b[1000];
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        // 求交集
        printf("交集：");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    printf("%d ", a[i]);
                    break;
                }
            }
        }
        printf("\n");

        // 求并集
        printf("并集：");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        for (int i = 0; i < m; i++) {
            int found = 0;
            for (int j = 0; j < n; j++) {
                if (b[i] == a[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("%d ", b[i]);
            }
        }
        printf("\n");
        break;

    default:
        printf("哎呀，真是个小糊涂蛋呢！选错了也没关系，我们输一次吧。XD  \n");
    }

    return 0;
}

void displayMenu() {
    printf("菜单:\n");
    printf("1. 矩阵运算 (加, 减, 乘)\n");
    printf("2. 阶乘\n");
    printf("3. 二次方程\n");
    printf("4. 等差数列和\n");
    printf("5. 集合交与并\n");
    printf("6.一元二次方程组\n");
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double cheng(double a, double b) {
    return a * b;
}

double factorial(int n) {                                                                                   //阶乘
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

double shulie(int shouXiang, int gongCha, int xiangShu) {
    return (xiangShu / 2.0) * (2 * shouXiang + (xiangShu - 1) * gongCha);
}

void erYuanFangCheng(double a1, double b1, double c1, double a2, double b2, double c2) {
    if (a1 * b2 - a2 * b1 == 0) {
        printf("无解或无穷多解");
    }
    else {
        double x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);                            // 根据克拉默法则计算
        double y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
        printf("X = %.2lf, Y = %.2lf", x, y);
    }
}

void yiYuanFangCheng(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {                                                         //求根公式
        double X1 = (-b + sqrt(discriminant)) / (2 * a);
        double X2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots: %.2lf, %.2lf\n", X1, X2);
    }
    else if (discriminant == 0) {
        double X = -b / (2 * a);
        printf("两根相等: %.2lf\n", X);
    }
    else {
        printf("复根\n");
    }
}
