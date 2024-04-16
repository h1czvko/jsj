#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <math.h>


void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double cheng(double a, double b);
double factorial(int n);                                                                            //�׳�
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
    printf("ѡ����: ");
    scanf("%d", &choice);

    switch (choice) {                                                                                           //ѡ��
    case 1:
        printf("������������: ");
        scanf("%lf %lf", &a, &b);
        printf("��: %.2lf\n", add(a, b));
        printf("��: %.2lf\n", subtract(a, b));
        printf("��: %.2lf\n", cheng(a, b));
        break;
    case 2:
        printf("����һ������: ");
        scanf("%d", &n);
        printf("�׳�Ϊ: %.0lf\n", factorial(n));
        break;
    case 3:
        printf("����ϵ�� (a, b, c) �������·��� (ax^2 + bx + c = 0): ");
        scanf("%lf %lf %lf", &a, &b, &c);
        yiYuanFangCheng(a, b, c);
        break;
    case 4:
        printf("����Ȳ����е������������� ");
        scanf("%d %d %d", &shouXiang, &gongCha, &xiangShu);
        printf("�Ȳ����к�Ϊ: %.2lf\n", shulie(shouXiang, gongCha, xiangShu));
        break;
    case 6:
        printf("��������ϵ�� (a, b, c) �������·��� (ax + by = c): ");
        scanf("%lf %lf %lf %lf %lf %lf", &a1, &b1, &c1, &a2, &b2, &c2);
        erYuanFangCheng(a1, b1, c1, a2, b2, c2);
        break;
    case 5:
        printf("�ֱ����������������飺");
        printf("��һ�����������");
        scanf("%d", &n);
        printf("��������");
        int a[1000];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("�ڶ������������");
        scanf("%d", &m);
        printf("��������");
        int b[1000];
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        // �󽻼�
        printf("������");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    printf("%d ", a[i]);
                    break;
                }
            }
        }
        printf("\n");

        // �󲢼�
        printf("������");
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
        printf("��ѽ�����Ǹ�С��Ϳ���أ�ѡ����Ҳû��ϵ��������һ�ΰɡ�XD  \n");
    }

    return 0;
}

void displayMenu() {
    printf("�˵�:\n");
    printf("1. �������� (��, ��, ��)\n");
    printf("2. �׳�\n");
    printf("3. ���η���\n");
    printf("4. �Ȳ����к�\n");
    printf("5. ���Ͻ��벢\n");
    printf("6.һԪ���η�����\n");
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

double factorial(int n) {                                                                                   //�׳�
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
        printf("�޽��������");
    }
    else {
        double x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);                            // ���ݿ���Ĭ�������
        double y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
        printf("X = %.2lf, Y = %.2lf", x, y);
    }
}

void yiYuanFangCheng(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {                                                         //�����ʽ
        double X1 = (-b + sqrt(discriminant)) / (2 * a);
        double X2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots: %.2lf, %.2lf\n", X1, X2);
    }
    else if (discriminant == 0) {
        double X = -b / (2 * a);
        printf("�������: %.2lf\n", X);
    }
    else {
        printf("����\n");
    }
}
