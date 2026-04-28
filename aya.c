#include <stdio.h>
#include <string.h>

#define SIZE 2  

//  المخزن global 
char data[SIZE][20];
int  head  = 0;
int  tail  = 0;
int  count = 0;

//  التهيئة
void init() {
    head  = 0;
    tail  = 0;
    count = 0;
}

//  الإدخال (الكتابة)
void enqueue(char value[]) {
    if (count == SIZE) {
        printf("  [Overflow]  لا يمكن إضافة '%s' - المخزن ممتلئ!\n", value);
        return;
    }
    strcpy(data[tail], value);
    tail = (tail + 1) % SIZE;
    count++;
    printf("  [+] أُضيف '%s'\n", value);
}

// الإزالة (القراءة)
void dequeue() {
    if (count == 0) {
        printf("  [Underflow] المخزن فارغ!\n");
        return;
    }
    printf("  [-] قُرئ '%s'\n", data[head]);
    head = (head + 1) % SIZE;
    count--;
}

//  عرض المخزن 
void print_buffer() {
    printf("  المخزن: [");
    for (int i = 0; i < SIZE; i++) {
        if (i > 0) printf(" | ");
        int found = 0;
        for (int j = 0; j < count; j++) {
            if ((head + j) % SIZE == i) { found = 1; break; }
        }
        if (found) printf("%-8s", data[i]);
        else       printf("  ____  ");
    }
    printf("]  count=%d\n", count);
}

//  الدالة الرئيسية
int main() {
    char name[] = "aya";
    int  len    = strlen(name);
    char token[20];

    init();

    printf("الاسم: %s  (عدد الحروف: %d)\n", name, len);
    printf("حجم المخزن: %d  ← أصغر من عدد الحروف\n\n", SIZE);

    // --- تخزين كل حرف كـ CE-ESY+رقم ---
    printf("=== خزّن البيانات ===\n");
    for (int i = 0; i < len; i++) {
        sprintf(token, "CE-ESY%d", i + 1);
        enqueue(token);
        print_buffer();
    }

    // --- قراءة البيانات ---
    printf("\n=== اقرأ البيانات ===\n");
    while (count > 0) {
        dequeue();
        print_buffer();
    }

    // --- تأكيد Underflow ---
    printf("\n=== تأكيد Underflow ===\n");
    dequeue();

    printf("\n=== النتيجة النهائية ===\n");
    printf("  الاسم        : %s\n", name);
    printf("  حجم المخزن  : %d\n", SIZE);
    printf("  عدد الحروف  : %d\n", len);

    return 0;
}
