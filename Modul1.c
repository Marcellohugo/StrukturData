// Program ini adalah tugas 2 pada modul 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int id;
    int urgency;
} Patient;

typedef struct
{
    Patient data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

bool is_empty(Queue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

bool is_full(Queue *queue)
{
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(Queue *queue, Patient patient)
{
    if (is_full(queue))
    {
        printf("Antrian penuh.\n");
        return;
    }
    if (is_empty(queue))
        queue->front = queue->rear = 0;
    else
        queue->rear = (queue->rear + 1) % MAX_SIZE;

    queue->data[queue->rear] = patient;
}

Patient dequeue(Queue *queue)
{
    if (is_empty(queue))
    {
        Patient empty_patient = {-1, -1};
        return empty_patient;
    }

    Patient patient = queue->data[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;

    return patient;
}

void simulate_queue()
{
    int num_queries;
    scanf("%d", &num_queries);

    Queue queue;
    initialize(&queue);

    for (int i = 0; i < num_queries; i++)
    {
        char query[10];
        scanf("%s", query);

        if (strcmp(query, "MASUK") == 0)
        {
            Patient patient;
            scanf("%d %d", &patient.id, &patient.urgency);
            enqueue(&queue, patient);
        }
        else if (strcmp(query, "LAYANI") == 0)
        {
            if (is_empty(&queue))
                printf("HORE\n");
            else
            {
                Patient patient = dequeue(&queue);
                printf("%d\n", patient.id);
            }
        }
    }
}

int main()
{
    simulate_queue();
    return 0;
}
