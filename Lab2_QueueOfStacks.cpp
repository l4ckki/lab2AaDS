/*
* Кулаков Роман ПС-22
* Visual Studio 22
19. Организовать  в основной  памяти  с помощью указателей
очередь  из  стеков. Обеспечить  операции  ведения  стека  из
начала  очереди, дополнения  и  продвижения  очереди,  выдачи
содержимого очереди
*/

#include <iostream>
#include <Windows.h>
#include <string>


struct Queue
{   
    struct Stack
    {
        int key = 0;
        Stack* next = 0;
        
    };
    std::string stackName;
    Stack* key = 0;
    Queue* next = 0;
    Queue* front = 0;
    Queue* end = 0;
};

int ChangeLocalization();
void PrintQueueMenu();
bool ExitMenu();
int ModeInput();
void WorkWithQueueMenu(Queue*&, bool&);
int PrintStack(Queue::Stack*);
int Push(Queue::Stack*&);

int Enqueue(Queue*& queue)
{   
    bool isPush = true;
    std::string name;
    int mode;
    std::cout << "Введите название стека: " << '\n';
    std::cin >> name;
    if (queue->front == NULL)
    {
        queue->front = new Queue;
        queue->front->stackName = name;
        queue->end = queue->front;
        Queue::Stack* stack = queue->front->key;
        while (isPush)
        {   
            std::cout << "Для ввода данных в стек, введите 1" << "\n";
            std::cout << "Для прекращения ввода данных, введите 2" << "\n";
            std::cin >> mode;
            if (mode == 1)
            {   
                std::cout << "Введите данные для стека: " << "\n";
                Push(stack);
            }
            else if(mode == 2)
            {   
                isPush = false;
                queue->front->key = stack;
                return 0;
            }
            else
            {
                std::cout << "Неверный код операции, повторите попытку" << "\n";
            }
        }
    }
    else
    {
        Queue* newNode = new Queue;
        queue->end->next = newNode;
        newNode->stackName = name;
        queue->end = newNode;
        Queue::Stack* stack = newNode->key;
        while (isPush)
        {
            std::cout << "Для ввода данных в стек, введите 1" << "\n";
            std::cout << "Для прекращения ввода данных, введите 2" << "\n";
            std::cin >> mode;
            if (mode == 1)
            {
                std::cout << "Введите данные для стека: " << "\n";
                Push(stack);
            }
            else if (mode == 2)
            {
                isPush = false;
                newNode->key = stack;
                return 0;
            }
            else
            {
                std::cout << "Неверный код операции, повторите попытку" << "\n";
            }
        }
    }

    return 0;
}

int Dequeue(Queue*& queue)
{   

    Queue* node = queue->front;
    
    if (queue->front == queue->end)
    {
        queue->end = NULL;
    }

    queue->front = queue->front->next;

    delete node;
    
    return 0;
}

int PrintQueue(Queue*& queue)
{
    Queue* temp = queue->front;

    while (temp != NULL)
    {
        std::cout << temp->stackName << ": ";
        PrintStack(temp->key);
        temp = temp->next;
    }

    return 0;
}

int ClearQueue(Queue*& queue)
{   
    while (queue->front != NULL)
    {
        Queue* temp = queue->front;
        queue->front = queue->front->next;

        delete temp;
    }
    
    return 0;
}

int Push(Queue::Stack*& stack)
{   
    int data;
    std::cin >> data;
    Queue::Stack* newNode = new Queue::Stack;
    newNode->key = data;
    newNode->next = stack;
    stack = newNode;

    return 0;
}

int Pop(Queue::Stack*& stack)
{   
    if (stack == NULL)
    {
        std::cout << "Стек пуст" << '\n';

        return -1;
    }

    Queue::Stack* temp = new Queue::Stack;
    
    temp = stack;
    stack = stack->next;
    delete temp;

    return 0;
}

int PrintStack(Queue::Stack* stack)
{   
    if (stack == NULL)
    {
        std::cout << "Стек пуст" << '\n';
        return -1;
    }

    Queue::Stack* temp = stack;

    std::cout << "Содержимое стека:";
    while (temp != NULL)
    {
        std::cout << ' ' << temp->key;
        temp = temp->next;
    }

    std::cout << '\n';

    return 0;
}

int ClearStack(Queue::Stack*& stack)
{   
    while (stack != NULL)
    {
        Queue::Stack* temp = stack;
        stack = stack->next;
        delete temp;
    }

    return 0;
}

int main()
{   
    bool isWork = true;
    Queue* queue = new Queue;
    ChangeLocalization();

    while (isWork)
    {
        PrintQueueMenu();
        WorkWithQueueMenu(queue, isWork);
    }
    
}

void PrintQueueMenu()
{
    std::cout << "1. Добавить элемент в очередь" << '\n';
    std::cout << "2. Удалить элемент из очереди" << '\n';
    std::cout << "3. Очистить очередь" << '\n';
    std::cout << "4. Просмотреть содержимое очереди" << '\n';
    std::cout << "5. Перейти на меню управлению стеком" << '\n';
    std::cout << "6. Выйти из программы" << '\n';
}

void PrintStackMenu()
{
    std::cout << "1. Добавить элемент в стек" << '\n';
    std::cout << "2. Удалить элемент из стека" << '\n';
    std::cout << "3. Очистить стек" << '\n';
    std::cout << "4. Просмотреть содержимое стека" << '\n';
    std::cout << "5. Перейти на меню управления очередью" << '\n';
}

void WorkWithStackMenu(Queue*& queue)
{   
    bool stackWork = true;
    Queue::Stack* stack = queue->front->key;

    while (stackWork)
    {   
        PrintStackMenu();
        int mode = ModeInput();
        std::cout << std::endl;
        switch (mode)
        {
            case 1:
                Push(stack);
                break;
            case 2:
                Pop(stack);
                break;
            case 3:
                ClearStack(stack);
                break;
            case 4:
                PrintStack(stack);
                break;
            case 5:
                stackWork = ExitMenu();
                queue->front->key = stack;
                break;
            default:
                std::cout << "Неверный ввод, введите цифру операции" << std::endl << std::endl;
                break;
        }
    }
}

void WorkWithQueueMenu(Queue*& queue, bool& isWork)
{   
    int mode = ModeInput();
    std::cout << std::endl;
    switch (mode)
    {
        case 1:
            Enqueue(queue);
            break;
        case 2:
            if (queue->front != NULL)
            {
                Dequeue(queue);
            }
            else std::cout << "Очередь пуста" << std::endl << std::endl;
            break;
        case 3:
            if (queue->front != NULL)
            {
                ClearQueue(queue);
            }
            else std::cout << "Очередь пуста" << std::endl << std::endl;
            break;
        case 4:
            if (queue->front != NULL)
            {
                PrintQueue(queue);
            }
            else std::cout << "Очередь пуста" << std::endl << std::endl;
            break;
        case 5:
            if (queue->front != NULL)
            {
                WorkWithStackMenu(queue);
            }
            else std::cout << "Очередь пуста" << std::endl << std::endl;
            break;
        case 6:
            isWork = ExitMenu();
            break;
        default:
            std::cout << "Неверный ввод, введите цифру операции" << std::endl << std::endl;
            break;
    }

}

bool ExitMenu()
{   
    return false;
}

int ModeInput()
{   
    int mode;
    std::cin >> mode;

    return mode;
}

int ChangeLocalization()
{
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    return 0;
}