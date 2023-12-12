///Щоб запустити програму потрібно прибрати коментарі програми /**/, або ж скопіювати її і вставити в кінець і
///запустити



///task3

/*1, Вам надано заголовки двох відсортованих пов’язаних списків list1 і list2.
Об’єднайте два списки в один відсортований список.
Список має бути створений шляхом з’єднання вузлів перших двох списків.
Повернути заголовок об’єднаного зв’язаного списку.
*/





/*

#include <iostream>

// Структура для представлення вузла в зв'язаному списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для об'єднання двох відсортованих зв'язаних списків
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Створюємо фіктивний вузол для зручності
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    // Поки обидва списки не закінчаться
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Обробляємо залишки у одному зі списків (якщо є)
    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    // Повертаємо результат, пропускаючи фіктивний вузол
    return dummy->next;
}

// Функція для виведення списку на екран
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Створюємо приклади списків
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Об'єднуємо списки
    ListNode* mergedList = mergeTwoLists(list1, list2);

    // Виводимо результат
    std::cout << "Merged List: ";
    printList(mergedList);

    return 0;
}


*/






/*2, Враховуючи head відсортованого пов’язаного списку,
видаліть усі дублікати, щоб кожен елемент з’являвся лише один раз. 
Поверніть зв’язаний список також відсортованим.*/





/*

#include <iostream>

// Структура для представлення вузла в зв'язаному списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для видалення дублікатів з відсортованого зв'язаного списку
ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            // Видаляємо дублікат
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }

    return head;
}

// Функція для виведення списку на екран
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Створюємо приклад списку
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);

    // Видаляємо дублікати
    head = deleteDuplicates(head);

    // Виводимо результат
    std::cout << "Updated List: ";
    printList(head);

    return 0;
}


*/






/*3, Дана head, голова зв’язаного списку, визначає, чи містить зв’язаний список цикл.
У зв’язаному списку існує цикл, якщо в списку є якийсь вузол, до якого можна знову повернутися, 
постійно переходячи за next вказівником. Внутрішньо pos використовується для позначення індексу вузла, 
до якого підключено next покажчик хвоста. Зауважте, що pos не передається як параметр.
Повертає true, якщо у пов’язаному списку є цикл. В іншому випадку поверніть false.*/





/*

#include <iostream>

// Структура для представлення вузла в зв'язаному списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для визначення наявності циклу в зв'язаному списку
bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Знайдено цикл
        }
    }

    return false; // Немає циклу
}

// Функція для створення циклічного зв'язаного списку для тестування
void createCycle(ListNode* head, int pos) {
    if (pos == -1) {
        return; // Цикл відсутній
    }

    ListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    ListNode* cycleNode = head;
    for (int i = 0; i < pos; ++i) {
        cycleNode = cycleNode->next;
    }

    tail->next = cycleNode;
}

int main() {
    // Створюємо приклад зв'язаного списку
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Створюємо цикл для першого прикладу
    createCycle(head, 1);

    // Визначаємо наявність циклу
    bool result = hasCycle(head);

    // Виводимо результат
    std::cout << "Has Cycle: " << (result ? "true" : "false") << std::endl;

    return 0;
}



*/





/*4, Вам надається head однозв’язаного списку. Список можна представити у вигляді:

L0 → L1 → … → Ln - 1 → Ln

Перевпорядкуйте список у такій формі:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

Ви не можете змінювати значення у вузлах списку. Змінювати можна лише самі вузли.
 */




/*

#include <iostream>

// Структура для представлення вузла в зв'язаному списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для виводу зв'язаного списку (для тестування)
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Функція для перевпорядкування однозв'язаного списку
void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return; // Список порожній або має один елемент
    }

    // Знаходимо середину списку
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Реверсуємо другу половину списку
    ListNode* prev = nullptr;
    ListNode* current = slow->next;
    slow->next = nullptr;
    while (current != nullptr) {
        ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // Змішуємо дві половини списку
    ListNode* first = head;
    ListNode* second = prev;
    while (second != nullptr) {
        ListNode* firstNext = first->next;
        ListNode* secondNext = second->next;
        first->next = second;
        second->next = firstNext;
        first = firstNext;
        second = secondNext;
    }
}

int main() {
    // Створюємо приклад зв'язаного списку
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Виводимо початковий список
    std::cout << "Original List: ";
    printList(head);

    // Перевпорядковуємо список
    reorderList(head);

    // Виводимо змінений список
    std::cout << "Reordered List: ";
    printList(head);

    return 0;
}




*/





/*5, Існує head списку з одним зв’язком, і ми хочемо видалити вузол node в ньому.
Вам надається node, який потрібно видалити. Вам не буде надано доступ до першого вузла head.
Усі значення пов’язаного списку є унікальними, і гарантується, що заданий вузол node не є останнім вузлом 
у зв’язаному списку.
*/






/*

#include <iostream>

// Структура для представлення вузла в зв'язаному списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для виводу зв'язаного списку (для тестування)
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Функція для видалення вказаного вузла
void deleteNode(ListNode* node) {
    if (node == nullptr || node->next == nullptr) {
        return; // Неправильний вузол або останній вузол у списку
    }

    // Копіюємо значення наступного вузла до поточного
    node->val = node->next->val;

    // Видаляємо наступний вузол
    ListNode* temp = node->next;
    node->next = node->next->next;
    delete temp;
}

int main() {
    // Створюємо приклад зв'язаного списку
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // Знаходимо вузол, який потрібно видалити (в цьому прикладі - 5)
    ListNode* nodeToDelete = head->next;

    // Виводимо початковий список
    std::cout << "Original List: ";
    printList(head);

    // Видаляємо вказаний вузол
    deleteNode(nodeToDelete);

    // Виводимо змінений список
    std::cout << "List after deletion: ";
    printList(head);

    return 0;
}


*/





/*6, Вам надано head непорожнього зв’язаного списку, що представляє невід’ємне ціле число без нулів на початку.

Повернути head пов’язаного списку після її подвоєння.*/



/*


#include <iostream>

// Структура для представлення вузла в зв'язаному списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для виводу зв'язаного списку (для тестування)
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Функція для подвоєння числа, представленого у вигляді зв'язаного списку
ListNode* doubleList(ListNode* head) {
    int carry = 0;

    // Проходження по зв'язаному списку
    ListNode* current = head;
    while (current != nullptr) {
        int sum = current->val * 2 + carry;
        current->val = sum % 10;
        carry = sum / 10;

        if (current->next == nullptr && carry > 0) {
            // Якщо це останній вузол і є перенос, додаємо новий вузол
            current->next = new ListNode(carry);
            break;
        }

        current = current->next;
    }

    return head;
}

int main() {
    // Створюємо приклад зв'язаного списку
    ListNode* head = new ListNode(1);
    head->next = new ListNode(8);
    head->next->next = new ListNode(9);

    // Виводимо початковий список
    std::cout << "Original List: ";
    printList(head);

    // Подвоюємо число
    head = doubleList(head);

    // Виводимо змінений список
    std::cout << "List after doubling: ";
    printList(head);

    return 0;
}



*/



















