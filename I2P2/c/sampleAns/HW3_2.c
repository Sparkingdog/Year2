
typedef struct _Node
{
    int id;
    struct _Node *next;
} Node;

Node *createList(int n)
{
    Node *head = malloc(sizeof(Node)), *cur = head;
    head->number = 1;
    head->next = head;
    for (int i = 2; i <= n; i++)
    {
        Node *newN = malloc(sizeof(Node));
        newN->number = i;
        newN->next = head;
        cur->next = newN;
        cur = newN;
    }
    return head;
}

void freeList(Node *head)
{
    while (head->next != head)
    {
        Node *tmp = head->next;
        head->next = head->next->next;
        free(tmp);
    }
    free(head);
}

int solveJosephus(Node **head, int step)
{
    int length = 1;
    Node *count = (*head)->next;
    while (count != *head)
        count = count->next, length++;
    while (*head != (*head)->next)
    {
        int k = (step % length - 2 + length) % length;
        for (int i = 0; i < k; i++)
            *head = (*head)->next;
        Node *tmp = (*head)->next;
        (*head)->next = (*head)->next->next;
        free(tmp);
        *head = (*head)->next;
        length--;
    }
    return (*head)->number;
}

int main()
{
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        Node *head = createList(n);
        printf("%d\n", solveJoseph(&head, k));
        freeList(head);
    }
}