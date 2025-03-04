#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 5
#define TIME_LIMIT 10

// Structure to hold a question
typedef struct {
    char question[256];
    char option1[128];
    char option2[128];
    char correctOption; // 'A' or 'B'
} Question;

void displayScore(int score) {
    printf("\nYour total score is: %d out of %d\n", score, NUM_QUESTIONS);
}

int main() {
    Question quiz[NUM_QUESTIONS] = {
        {"What is 2 + 2?", "4", "5", 'A'},
        {"What is the capital of France?", "Paris", "London", 'A'},
        {"What color is the sky on a clear day?", "Blue", "Green", 'A'},
        {"What is 5 x 6?", "30", "25", 'A'},
        {"Which planet is known as the Red Planet?", "Mars", "Jupiter", 'A'}
    };

    int score = 0;
    time_t startTime = time(NULL);

    printf("Welcome to the Quiz! You have %d seconds to complete the quiz.\n\n", TIME_LIMIT);

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].question);
        printf("A. %s\n", quiz[i].option1);
        printf("B. %s\n", quiz[i].option2);
        printf("Enter your choice (A/B): ");

        char answer;
        fflush(stdin);
        // Read the user's answer
        scanf(" %c", &answer);
        fflush(stdin);
        time_t currentTime = time(NULL);
        double elapsedTime = difftime(currentTime, startTime);

        if (elapsedTime > TIME_LIMIT) {
            printf("\nTime's up!\n");
            break;
        }
        
        if(answer >= 'a' && answer <= 'z')
            answer -= 32;
        
        // Check if the answer is correct
        if (answer == quiz[i].correctOption) {
            score++;
        }
    }

    displayScore(score);
    return 0;
}
