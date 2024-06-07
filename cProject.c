
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
// max number of questions defined as macro
#define MAX_QUESTIONS 5
 
// Structure to store question details
typedef struct {
    char question[256];
    char options[4][64];
    int correct_option;
} Question;
 
// function to display question to the user
void displayQuestion(Question q)
{
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}
 
// function to check the answer
int checkAnswer(Question q, int user_answer)
{
    return (user_answer == q.correct_option);
}
 
// driver code
int main()
{
 
    // random number generator
    srand(time(NULL));
 
    // Initializing questions, options and the correct
    // answer
    Question original_questions[MAX_QUESTIONS] = {
        { "which type is 2D or multidimentional arry type?",
          { "arr[]", "arr[][]", "arr", "arr[[]]" },
          2 },
        { "which type is string type?",
          { "{'c','o','l','l','e','g','e',}", "{'college'}", "c o ll e g e", "none of these" },
          2 },
        { "Why pointer use in c language ?",
          { "store address", "variable store",
            "multiplication", "nothing" },
          1 },
        { "which type of  'c' languge?",
          { "high level ", "midile level", "low level", "extra high level" },
          2 },
        { "c langauge is object oriented programing language?",
          { "false", "true", "it is procedure oriented  programing ", "none of these" },
          2 }
    };
 
    // Array of struct data-type
    Question questions[MAX_QUESTIONS];
    memcpy(questions, original_questions,
           sizeof(original_questions));
 
    int num_questions = MAX_QUESTIONS;
 
    int score = 0;
 
    printf("Hello! Here's your Quiz Game!\n");
 
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int random_index = rand() % num_questions;
        Question current_question = questions[random_index];
        displayQuestion(current_question);
 
        int user_answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &user_answer);
 
        if (user_answer >= 1 && user_answer <= 4) {
            if (checkAnswer(current_question,
                            user_answer)) {
                printf("Correct!\n");
                score++;
            }
            else {
                printf("Incorrect. The correct answer is "
                       "%d. %s\n",
                       current_question.correct_option,
                       current_question.options
                           [current_question.correct_option
                            - 1]);
            }
        }
        else {
            printf("Invalid choice. Please enter a number "
                   "between 1 and 4.\n");
        }
 
        questions[random_index]
            = questions[num_questions - 1];
        num_questions--;
    }
 
    printf("Well Done Champ !!!! Quiz completed! Your "
           "score: %d/%d\n",
           score, MAX_QUESTIONS);
 
    return 0;
}
