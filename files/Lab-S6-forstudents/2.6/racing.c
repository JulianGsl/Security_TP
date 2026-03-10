    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
     
    #define BUFLEN 32
     
    struct Car {
        char name[12];
        char title[4];
        void (*getYourPrize)();
        void (*SellYourCar)(struct Car*);
    };
     
    struct Circuit{
        char name[16];
        char difficulty[8];
    };
     
    int cleanLine(char* line){
        for(;*line != '\n'; line++);
        *line = 0;
        return 0;
    }
     
    void SellYourCar(struct Car* car){
        printf("You sell your car, bye %s ! One day, you will win this race but not with %s ...\n", car->name, car->name);
        free(car);
    }
    
    void getYourPrize(){
        printf("Congratulations, it was an incredible race. So fast that I didn't see anything !\n");
        printf("You win the Special Cup!\n");
    }
     

     
    struct Car* newCar(char* name){
        printf("You buy a new car : %s\n", name);
        struct Car* car = malloc(sizeof(struct Car));
        strncpy(car->name, name, 12);
        car->getYourPrize = getYourPrize;
        car->SellYourCar = SellYourCar;
        return car;
    }
     
    void trainingCircuit(struct Circuit* circuit, struct Car* car){
        printf("You train with your car %s on the circuit %s \n", car->name, circuit->name);
        printf("Difficulty of the circuit was %s but the rainbow road is EXTREMELY hard !\n",circuit->difficulty);
    }
     
    void removeTrainingCircuit(struct Circuit* circuit){
        if(circuit){
            puts("You remove the training circuit.\n");
            free(circuit);
        }
        else
            puts("You do not have a training circuit.\n");
    }
     
    struct Circuit* newCircuit(){
        char line[BUFLEN] = {0};
       
        struct Circuit* circuit = malloc(sizeof(struct Circuit));
       
        puts("What will be the difficulty of this circuit?");
        fgets(line, BUFLEN, stdin);
        cleanLine(line);
        strncpy(circuit->difficulty, line, 8);
       
        puts("How do you name it?");
        fgets(line, BUFLEN, stdin);
        cleanLine(line);
        strncpy(circuit->name, line, 16);
       
        puts("You build a new circuit !");
       
        return circuit;
    }
     
    int main(){
        int end = 0;
        char order = -1;
        char nl = -1;
        char line[BUFLEN] = {0};
        struct Car* car = NULL;
        struct Circuit* circuit = NULL;
        while(!end){
            puts("1: Buy a new car\n2: Get your prize\n3: Sell your car\n4: Build a training circuit\n5: Go into your training circuit\n6: Remove the training circuit\n7: Participate to the competition\n0: Quit");
            order = getc(stdin);
            nl = getc(stdin);
            if(nl != '\n'){
                exit(0);
            }
            fseek(stdin,0,SEEK_END);
            switch(order){
            case '1':
                puts("Give it a name for the competition :\n");
                fgets(line, BUFLEN, stdin);
                cleanLine(line);
                car = newCar(line);
                break;
            case '2':
                if(!car){
                    puts("You do not have a car.\n");
                    break;
                }
                if (strcmp(car->title,"WIN")==0)
                {
                   car->getYourPrize(); 
                }
                else
                {
                   printf("The prize could only be claimed if you win the race on the rainbow road !\n");   
                
                }
                break;
            case '3':
                if(!car){
                    puts("You do not have a car.\n");
                    break;
                }
                car->SellYourCar(car);
		car=NULL;
                break;
            case '4':
                circuit = newCircuit();
                break;
            case '5':
                if(!car){
                    puts("You do not have a car.\n");
                    break;
                }
                if(!circuit){
                    puts("You do not have a circuit.\n");
                    break;
                }
                trainingCircuit(circuit, car);
                break;
            case '6':
                if(!circuit){
                    puts("You do not have a training circuit.\n");
                    break;
                }
                removeTrainingCircuit(circuit);
                circuit = NULL;
	       	break;
            case '7':
                if(!car){
                    puts("You do not have a car, so it is not possible to participate !\n");
                }
                else
                {
                    puts("You decide to participate to the competition ! Let's go !\n");
                    sleep(1);
                    puts("You are currently first in the competition, let's go for the final race : the rainbow road !\n");
                    sleep(3);
                    puts("Unfortunately, you loose this race...\n");
                    
                    char * fail = "NOP";
                    strcpy(car->title,fail);
                }
                break;
            case '0':
            default:
                end = 1;
            }
        }
        return 0;
    }

