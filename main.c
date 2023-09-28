#include <stdio.h>
#include <stdlib.h>

#define actor_lead_m1 "Chillian Murphy"
#define actor_lead_m2 "Leonardo DiCaprio"
#define actor_lead_m3 "Tom Cruise"
#define actor_lead_m4 "Johnny Depp"

#define actor_lead_f1 "Emma Watson"
#define actor_lead_f2 "Ana De Armas"
#define actor_lead_f3 "Emma Stone"
#define actor_lead_f4 "Jennifer Connelly"

#define actor_support_m1 "Jennifer Lawrence"
#define actor_support_m2 "Penelope Cruz"
#define actor_support_m3 "Alexandra Daddario"
#define actor_support_m4 "Emila Carkile"

#define actor_support_f1 "Rami Malik"
#define actor_support_f2 "Bruce Wayne"
#define actor_support_f3 "Robert John"
#define actor_support_f4 "Cris Brown"

int lead_role_male1_votes = 0, lead_role_male2_votes = 0, lead_role_male3_votes = 0, lead_role_male4_votes = 0;
int lead_role_female1_votes = 0, lead_role_female2_votes = 0, lead_role_female3_votes = 0, lead_role_female4_votes = 0;
int supporting_role_male1_votes = 0, supporting_role_male2_votes = 0, supporting_role_male3_votes = 0, supporting_role_male4_votes = 0;
int supporting_role_female1_votes = 0, supporting_role_female2_votes = 0, supporting_role_female3_votes = 0, supporting_role_female4_votes = 0;

int phone()
{
    long long int number;
    long long int another_number;
    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("Enter your Phone Number: ");
    scanf("%lld", &number);

    int found = 0;
    long long int num;
    while (fscanf(file, "%lld", &num) == 1)
    {
        if (num == number)
        {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found)
    {
        printf("Seems Like You Have Already Casted the Vote Try with another Phone Number!\n");

        printf("Enter Different Number: ");
        scanf("%lld", &another_number);
    }
    else
    {
        FILE *file = fopen("numbers.txt", "a+");
        if (file == NULL)
        {
            printf("Please try again!\n");
            return 1;
        }

        fprintf(file, "%lld\n", number);
        fclose(file);

        printf("YOU MAY PROCEED TO VOTE\n\n\n\n");
    }
}

void castvote()
{
    int vote;
    do
    {
        printf("VOTE FOR BEST ACTOR IN THE LEAD ROLE MALE\n");
        printf(" 1. %s\n", actor_lead_m1);
        printf(" 2. %s\n", actor_lead_m2);
        printf(" 3. %s\n", actor_lead_m3);
        printf(" 4. %s\n", actor_lead_m4);
        scanf("%d", &vote);

        switch (vote)
        {
        case 1:
            lead_role_male1_votes++;
            break;
        case 2:
            lead_role_male2_votes++;
            break;
        case 3:
            lead_role_male3_votes++;
            break;
        case 4:
            lead_role_male4_votes++;
            break;
        default:

            printf("Invalid choice. Please choose a valid option (1-4).\n");
        }
    } while (vote < 1 || vote > 4);

    do
    {
        printf("VOTE FOR BEST ACTOR IN THE LEADING ROLE FEMALE\n");
        printf(" 1. %s\n", actor_lead_f1);
        printf(" 2. %s\n", actor_lead_f2);
        printf(" 3. %s\n", actor_lead_f3);
        printf(" 4. %s\n", actor_lead_f4);
        scanf("%d", &vote);

        switch (vote)
        {
        case 1:
            lead_role_female1_votes++;
            break;
        case 2:
            lead_role_female2_votes++;
            break;
        case 3:
            lead_role_female3_votes++;
            break;
        case 4:
            lead_role_female4_votes++;
            break;
        default:
            printf("Invalid choice. Please choose a valid option (1-4).\n");
        }

    } while (vote < 1 || vote > 4);

    do
    {
        printf("VOTE FOR BEST ACTOR IN THE SUPPORTING ROLE MALE\n");
        printf(" 1. %s\n", actor_support_m1);
        printf(" 2. %s\n", actor_support_m2);
        printf(" 3. %s\n", actor_support_m3);
        printf(" 4. %s\n", actor_support_m4);
        scanf("%d", &vote);

        switch (vote)
        {
        case 1:
            supporting_role_male1_votes++;
            break;
        case 2:
            supporting_role_male2_votes++;
            break;
        case 3:
            supporting_role_male3_votes++;
            break;
        case 4:
            supporting_role_male4_votes++;
            break;
        default:
            printf("Invalid choice. Please choose a valid option (1-4).\n");
        }
    } while (vote < 1 || vote > 4);

    do
    {
        printf("VOTE FOR BEST ACTOR IN THE SUPPORTING ROLE FEMALE\n");
        printf(" 1. %s\n", actor_support_f1);
        printf(" 2. %s\n", actor_support_f2);
        printf(" 3. %s\n", actor_support_f3);
        printf(" 4. %s\n", actor_support_f4);
        scanf("%d", &vote);

        switch (vote)
        {
        case 1:
            supporting_role_female1_votes++;
            break;
        case 2:
            supporting_role_female2_votes++;
            break;
        case 3:
            supporting_role_female3_votes++;
            break;
        case 4:
            supporting_role_female4_votes++;
            break;
        default:
            printf("Invalid choice. Please choose a valid option (1-4).\n");
        }
    } while (vote < 1 || vote > 4);
}

void displayResults()
{
    printf("VOTING RESULTS\n");
    printf("---------------\n");

    printf("BEST ACTOR IN THE LEAD ROLE MALE\n");
    printf("%s: %d votes\n", actor_lead_m1, lead_role_male1_votes);
    printf("%s: %d votes\n", actor_lead_m2, lead_role_male2_votes);
    printf("%s: %d votes\n", actor_lead_m3, lead_role_male3_votes);
    printf("%s: %d votes\n", actor_lead_m4, lead_role_male4_votes);
    printf("\n");

    printf("BEST ACTOR IN THE LEADING ROLE FEMALE\n");
    printf("%s: %d votes\n", actor_lead_f1, lead_role_female1_votes);
    printf("%s: %d votes\n", actor_lead_f2, lead_role_female2_votes);
    printf("%s: %d votes\n", actor_lead_f3, lead_role_female3_votes);
    printf("%s: %d votes\n", actor_lead_f4, lead_role_female4_votes);
    printf("\n");

    printf("BEST ACTOR IN THE SUPPORTING ROLE MALE\n");
    printf("%s: %d votes\n", actor_support_m1, supporting_role_male1_votes);
    printf("%s: %d votes\n", actor_support_m2, supporting_role_male2_votes);
    printf("%s: %d votes\n", actor_support_m3, supporting_role_male3_votes);
    printf("%s: %d votes\n", actor_support_m4, supporting_role_male4_votes);
    printf("\n");

    printf("BEST ACTOR IN THE SUPPORTING ROLE FEMALE\n");
    printf("%s: %d votes\n", actor_support_f1, supporting_role_female1_votes);
    printf("%s: %d votes\n", actor_support_f2, supporting_role_female2_votes);
    printf("%s: %d votes\n", actor_support_f3, supporting_role_female3_votes);
    printf("%s: %d votes\n", actor_support_f4, supporting_role_female4_votes);
    printf("\n");
}

void displayMenu()
{
    printf("1. Cast vote\n");
    printf("2. See Result\n");
    printf("3. Exit\n");
}

void displayResultsToFile()
{
    FILE *outfile = fopen("voting_results.txt", "w"); // Open a file for writing

    if (outfile == NULL)
    {
        printf("Error opening the file for writing.\n");
        return;
    }

    fprintf(outfile, "VOTING RESULTS\n");
    fprintf(outfile, "---------------\n");

    fprintf(outfile, "BEST ACTOR IN THE LEAD ROLE MALE\n");
    fprintf(outfile, "%s: %d votes\n", actor_lead_m1, lead_role_male1_votes);
    fprintf(outfile, "%s: %d votes\n", actor_lead_m2, lead_role_male2_votes);
    fprintf(outfile, "%s: %d votes\n", actor_lead_m3, lead_role_male3_votes);
    fprintf(outfile, "%s: %d votes\n", actor_lead_m4, lead_role_male4_votes);
    fprintf(outfile, "\n");

    fprintf(outfile, "BEST ACTOR IN THE LEADING ROLE FEMALE\n");
    fprintf(outfile, "%s: %d votes\n", actor_lead_f1, lead_role_female1_votes);
    fprintf(outfile, "%s: %d votes\n", actor_lead_f2, lead_role_female2_votes);
    fprintf(outfile, "%s: %d votes\n", actor_lead_f3, lead_role_female3_votes);
    fprintf(outfile, "%s: %d votes\n", actor_lead_f4, lead_role_female4_votes);
    fprintf(outfile, "\n");

    fprintf(outfile, "BEST ACTOR IN THE SUPPORTING ROLE MALE\n");
    fprintf(outfile, "%s: %d votes\n", actor_support_m1, supporting_role_male1_votes);
    fprintf(outfile, "%s: %d votes\n", actor_support_m2, supporting_role_male2_votes);
    fprintf(outfile, "%s: %d votes\n", actor_support_m3, supporting_role_male3_votes);
    fprintf(outfile, "%s: %d votes\n", actor_support_m4, supporting_role_male4_votes);
    fprintf(outfile, "\n");

    fprintf(outfile, "BEST ACTOR IN THE SUPPORTING ROLE FEMALE\n");
    fprintf(outfile, "%s: %d votes\n", actor_support_f1, supporting_role_female1_votes);
    fprintf(outfile, "%s: %d votes\n", actor_support_f2, supporting_role_female2_votes);
    fprintf(outfile, "%s: %d votes\n", actor_support_f3, supporting_role_female3_votes);
    fprintf(outfile, "%s: %d votes\n", actor_support_f4, supporting_role_female4_votes);
    fprintf(outfile, "\n");

    fclose(outfile); // Close the file
}

int main()
{
    int choice;
	char username[50] = "admin", password[50] = "password", get_username[50], get_password[50];
	printf("Enter your username: ");
	gets(get_username);
	printf("Enter your password: ");
	gets(get_password);
	if((strcmp(username, get_username) == 0 && strcmp(password, get_password) == 0)){
    while (1)
    {
        int userChoice;

        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice)
        {
        case 1:
            phone();
            castvote();
            displayResultsToFile();
            break;
        case 2:
            displayResults();

            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    }

    return 0;
}
