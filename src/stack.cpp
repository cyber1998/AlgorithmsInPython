#include <iostream>

static int top = -1;

int stack_size() {
    return top + 1;
}

bool isFull(int n)   {
    if (top == n-1)
        return true;
    return false;
}

bool isEmpty() {
    if (top == -1)
        return true;
    return false;
}


void pop(int st[])   {
    if (isEmpty()) {
        std::cout << "Stack underflow\n";
        return;
    }
    std::cout << st[top--] << "\n";
}
void push(int st[], int n, int x) {
    if (isFull(x)) {
        std::cout << "Stack overflow\n";
        return;
    }
    st[++top] = n;
}


void traverse_stack(int st[])   {

    for(int i=stack_size()-1; i>=0; i--)
        std::cout << st[i] << " ";
    std::cout << "\n";
    return;
}

int main()  {
    int n;
    std::cout << "\nEnter the size of the stack: ";
    std::cin >> n;
    int st[n];

    std::cout << "\nChoose \'p\' to push, \'o\' to pop and \'t\' to traverse. You can choose \'q\' to exit.\n";
    char c;
    std::cin >> c;
    while(c) {

        switch(c)   {
            case 'p':
                int num;
                std::cout << "\nEnter number to push: ";
                std::cin >> num;
                push(st, num, n);
                break;
            case 'o':
                pop(st);
                break;

            case 't':
                traverse_stack(st);
                break;
            case 'q': return 0;
        }
        std::cout << "\nChoose \'p\' to push, \'o\' to pop and \'t\' to traverse. You can choose \'q\' to exit.\n";
        std::cin >> c;
    }
}

