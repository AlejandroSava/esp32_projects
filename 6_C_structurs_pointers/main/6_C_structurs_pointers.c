#include <stdio.h>
#include <string.h>
#include "esp_log.h"

#define TAG "ESP32_IN_C"
//foundamentals of C: Pointers and structures 

struct Person{
    char first_name[20];
    char last_name[20];
    int age;
};


//typedef is a keyword used to create an alias or an alternative name for an existing data type.

typedef struct Person2{
    char first_name[20];
    char last_name[20];
    int age;
} Person2;

void update_person2(Person2 *person2, char *first_name, char *last_name, int age){
    strcpy(person2->first_name, first_name); // -> = (*ptr).member
    strcpy(person2->last_name, last_name);
    person2->age = age;

}

void exclam_it(char *word, char *cat){
    strcat(word, cat);

}

void app_main(void){
    ESP_LOGI(TAG, "THIS IS AN C EXAMPLE");
    printf("Hello wordl! \n");
    struct Person person_1;
    strcpy(person_1.first_name, "Alejandro");
    strcpy(person_1.last_name, "Salinas");
    person_1.age = 27;
    printf("The person: %s %s is %d years old \n", person_1.first_name, person_1.last_name, person_1.age);

    //typedef
    Person2 person_2;
    strcpy(person_2.first_name, "Alejandro");
    strcpy(person_2.last_name, "Salinas");
    person_2.age = 27;
    printf("The person 2: %s %s is %d years old \n", person_2.first_name, person_2.last_name, person_2.age);
    update_person2(&person_2, "Pancho", "Ramirez", 30);
    printf("The person 2: %s %s is %d years old \n", person_2.first_name, person_2.last_name, person_2.age);

    // add a symbol in the last element
    char word[30] = "Hi everyone";
    printf("The wordl before concatenate is: %s \n", word);
    exclam_it(word, "!!!");
    printf("The wordl after concatenate is: %s\n", word);

}
