#include <stdio.h>
#include <stdlib.h>
//The creation of nodes for passengers and busses

struct node_pass;
struct node_pass {
    int id;
    int date;
    char time[10];
    char from [20];
    char to [20];
    struct node_pass*  next;
};

struct node_bus;
struct node_bus {
    int id;
    int date;
    char time[10];
    int cap;
    int price;
    char from [20];
    char to [20];
    struct node_pass *passengers;

    struct node_bus* next;
};


//prototypes of functions
struct node_bus* create_node_bus (struct node_bus* );
struct node_pass* create_node_pass (struct node_pass* );
struct node_bus* Findprevbus(int x , struct node_bus* l);
struct node_pass* Findprevpass(int x , struct node_pass* l);
char *trim(char *s);





int main (){

//Create a linked_lists for bus and passenger and waiting list
    struct node_bus* bus = (struct node_bus*)malloc (sizeof(struct node_bus));
    bus->next=NULL;

    struct node_pass* pass =(struct node_pass*)malloc (sizeof(struct node_pass));
    pass->next= NULL;

    struct node_pass* watingl=(struct node_pass*)malloc (sizeof(struct node_pass));
    watingl->next= NULL; ;

    // This array is for reading each line in the file of bus
    char file_bus[100];
    // This array is for reading each line in the file of pass
    char file_pass[100];

    DisplayM(bus,pass,watingl,file_bus,file_pass  );

                 return 0 ;
}



// this function for print the passengers file .
 void printL(struct node_pass* l){
    struct node_pass* p =l;
    printf(" \t  id  \t        DATE  \t \t TIME  \t\t FROM   \t\t TO \n \n");

     do{
      printf(" \t %d \t %d \t %s \t\t %s\t\t %s ", p->id, p->date,p->time, p->from , p->to);
       p=p->next;

     printf("\n");

     }while(p!=NULL);


    }


//// this function for print the buss file contents .

   void printb(struct node_bus* l){
   struct node_bus* p =l;
   printf(" \t ID  \t DATE  \t\t  TIME \t FROM  \t\t TO\t\t PRICE \t CAPACITY \n \n");

   do{

   printf("\t %d \t %d \t %s\t %s \t %s  \t%d \t %d  \n", p->id, p->date,p->time ,p->from , p->to ,p->price,p->cap);
   p=p->next;


   }while((p!=NULL));


  }



//This function is for inserting a new node at last and return this new node to be able to fill the data into it for bus list
   struct node_bus* create_node_bus (struct node_bus* header){

     struct node_bus* position = header;
       while (position->next!= NULL){
            position = position->next;
     }

      struct node_bus* newNode = (struct node_bus*)malloc(sizeof(struct node_bus));
         position->next = newNode;
         newNode->next = NULL;


    return newNode;


         }


//This function is for inserting a new node at last and return this new node to be able to fill the data into it for passengers  list
  struct node_pass* create_node_pass (struct node_pass* header){
       struct node_pass* position = header;
          while (position->next!= NULL){
            position = position->next;
        }
    struct node_pass* newNode = (struct node_pass*)malloc(sizeof(struct node_pass));
       position->next = newNode;
       newNode->next = NULL;
         return newNode;

}

// display choices

void DisplayC(){
    printf("Choose from the menu below:\n");
    printf("1) Load the bus information file\n");
    printf("2) Load the passenger information file.\n");
    printf("3) Assign passengers and print assignment information of all busses \n");
    printf("4)Print a specific bus information along with its passengers information (names and IDs). \n");
    printf("5)Print unmatched passengers. \n");
    printf("6)Add new passenger.\n");
    printf("7)Delete passenger. \n");
    printf("8)Delete bus number.\n");
    printf("9)Exit.\n");
}
 // display menu
void DisplayM(struct node_bus* bus,struct node_pass* pass,struct node_pass* waitngl,char file_bus[100],char file_pass[100]){
    int choice;
    DisplayC();

    while(1)
    {
        scanf("%d", &choice);
        if(choice == 9)
        {
            printf("Goodbye");
            break;
        }

        switch(choice)
        {
            case 1:
        read_and_print_bus_file(bus,file_bus);

        printf("buss file have : \n\n");

            printb(bus);
            break;


            case 2:
        read_and_print_pass_file(pass,file_pass);


        printf("passengers file have : \n\n");

         printL(pass);


            break;

            case 3:
         registration(bus,pass,waitngl);

                    struct node_bus* cc = bus;
                    printf("------------- pass in each bus -------------\n");
                    while(cc != NULL){
                        printf("--- %d ---\n", cc->id);
                        struct node_pass* ss = cc->passengers->next;
                        while(ss != NULL){
                            printf("%d \n", ss->id);
                            ss = ss->next;
                        }
                        printf("\n");
                        cc = cc->next;
                    }

                break;

            case 4:
                 printf("enter bus id ");

                int bid;
                int co=0;

                scanf("%d" , &bid);
                struct node_bus* b = bus;
                    printf("------------- pass in  bus  %d-------------\n", bid);
                    while(b != NULL){

                            if(b->id == bid){
                                    co++;
                        struct node_pass* p = b->passengers->next;
                        while(p != NULL){
                            printf("%d \n", p->id);
                            p = p->next;
                        }

                            }
                        b = b->next;
                    }


                    if(co ==0)
                        printf("there is no bus with tihs  id  %d ", bid);
                break;

            case 5:


                    printf("\n------------- pass in  waiting list -------------\n");
                        struct node_pass* ss = waitngl->next;
                        while(ss != NULL){
                            printf("%d \n", ss->id);
                            ss = ss->next;
                        }
                        printf("\n");



                break;

            case 6:

                 printf("  ")  ;

int id ; int date ;
 char time[10]  ; char from[10] ; char to[10];
 char temp;

printf("enter pass id ");
scanf("%d" , &id);

printf("enter travel date ");
scanf("%d" , &date);
scanf("%c",&temp);

printf(" enter travel time ");
gets(time);
printf("read temporary character just click enter ");
scanf("%c",&temp);


printf(" enter where you from where  ");
gets(from);


printf(" enter where you want to go ");
gets(to);


addpass(id,date,time,from,to,bus,waitngl);


                break;

            case 7:

              printf("enter pass id ");

                int passid;

                scanf("%d" , &passid);


           // deletepass(passid,bus,pass,waitngl);
           dd(passid, bus,pass,waitngl );


                break;

            case 8:
                 printf("enter bus id ");

                int busid;

                scanf("%d" , &busid);
                 Deletebus(busid ,bus,waitngl );



                break;


            default:
                printf("Please number from 1 to 10\n");
        }

        printf("\n\n");
        DisplayC();
    }
}





void read_and_print_pass_file(struct node_pass* pass_header,char file_pass[100]){
    FILE *pass_file;
    pass_file = fopen("passengers.txt","r");//open the file and read from it

    if (pass_file == NULL){
        printf("File does not exist");
        return (-1);
    }

    fgets(file_pass,100,pass_file);
    fillpass(pass_header,file_pass);  //Here i filled in the header of student (linked)list

    // This loop is for reading from the file and saving the data into nodes until the end of the file
    while ((fgets(file_pass,100,pass_file))!=NULL && pass_file !=EOF){

        struct node_pass* newNode= create_node_pass(pass_header);
        fillpass(newNode,file_pass);
    }

    fclose(pass_file);
}
////This function is for dividing the array from file into tokens and fill these tokens into a node for pass list

void fillpass (struct node_pass* node  ,char line[]){
    char *token = strtok(line,"#");
       token=  trim(token);
        node->id = atoi(token);
    token = strtok(NULL,"#");
       token=  trim(token);
    node->date = atoi(token);

        token = strtok(NULL,"#");
           token=  trim(token);

        strcpy(node->time,token);

    token = strtok(NULL,"#");
        token= trim(token);

        strcpy(node->from,token);



   token = strtok(NULL,"#");
       token= trim(token);

        strcpy(node->to,token);
          }



//This function reads from file, saves the data correctly in a linked list
        void read_and_print_bus_file(struct node_bus* bus_header,char file_bus[100]){
    // Declare a pointer of type file
    FILE *bus_file;
    bus_file = fopen("busses.txt","r");//open the file and read from it

    if (bus_file == NULL){
        printf("File does not exist");
        return (-1);
    }

    fgets(file_bus,100,bus_file);
    fillbus(bus_header,file_bus);  ///Here i filled in the header of course (linked)list

    // This loop is for reading from the file and saving the data into nodes until the end of the file
    while ((fgets(file_bus,100,bus_file))!=NULL && bus_file !=EOF){
        struct node_bus* newNode= create_node_bus(bus_header);
        fillbus(newNode,file_bus);
    }

    fclose(bus_file);
}
////This function is for dividing the array from file into tokens and fill these tokens into a node for bus list
void fillbus ( struct node_bus* node ,char line[]){
    char *token = strtok(line,"#");
        node->id = atoi(token);
     token=trim(token);
    token = strtok(NULL, "#");
       token=  trim(token);
    node->date = atoi(token);

        token = strtok(NULL, "#");
           token=  trim(token);

        strcpy(node->time,token);

    token = strtok(NULL, "#");
        token= trim(token);

        strcpy(node->from,token);

    token= strtok (NULL, "#");
         token=trim(token);

        strcpy(node->to,token);

         token = strtok(NULL, "#");
            token=  trim(token);

    node->price = atoi(token);

        token = strtok(NULL, "#");
           token= trim(token);

    node->cap = atoi(token);



}


//This function is for assign  each pass  or sending them to waiting list
void registration (struct node_bus* bus_header,struct node_pass* pass_header,struct node_pass* waitingl ){

    int index = 0;
    struct node_bus* bus_position = bus_header;
    while(bus_position != NULL){
        bus_position->passengers = (struct node_pass*)malloc (sizeof(struct node_pass));
        bus_position->passengers->next = NULL;
        bus_position = bus_position->next;
        index++;
    }

    struct node_pass* pass_position = pass_header;
    struct node_pass* waitl = waitingl;

    while(pass_position != NULL){
            int done =0;

       bus_position = bus_header;


   while(bus_position != NULL ){

   if(pass_position->date == bus_position->date && strcmp(pass_position->time,bus_position->time)==-1
      && strcmp(pass_position->from,bus_position->from)==0  && strcmp(pass_position->to,bus_position->to)==0  && bus_position->cap > 0 ){

          bus_position->cap -= 1;
                insertEndP(bus_position,pass_position);
done++;


}
        bus_position = bus_position->next;

                    }

   if(done==0){


                           insertEndW(waitingl,pass_position);





}


        printf("\n\n");
        pass_position = pass_position->next;

}


}

// this function for the assign  added  passengers after function 6
void registrations (struct node_bus* bus_header,struct node_pass* pass_header,struct node_pass* waitingl ){

    struct node_bus* bus_position = bus_header;
    struct node_pass* pass_position = pass_header;
    struct node_pass* waitl = waitingl;


    while(pass_position != NULL){
    int done =0;
   bus_position = bus_header;
   while(bus_position != NULL ){

   if(pass_position->date == bus_position->date && strcmp(pass_position->time,bus_position->time)==-1
      && strcmp(pass_position->from,bus_position->from)==0  && strcmp(pass_position->to,bus_position->to)==0  && bus_position->cap > 0 ){

          bus_position->cap -= 1;
          insertEndP(bus_position,pass_position);
   done++;}
          bus_position = bus_position->next;}

    if(done==0){


                insertEndW(waitingl,pass_position);
}
        printf("\n\n");
        pass_position = pass_position->next;

}}





//This function is for copying the data from a passenger's node into a new node
void copy_pass_node(  struct node_pass* node, struct node_pass* pass_node){
         node->id = pass_node->id;
         node->date = pass_node->date;

        strcpy(node->time,pass_node->time);
        strcpy(node->from,pass_node->from);
        strcpy(node->to,pass_node->to);




}
// this function for insert new node of pass at the end of the specific bus node
void insertEndP(  struct node_bus* bus , struct node_pass* pass){


struct node_pass* newnode;
newnode=(struct node_pass*)malloc (sizeof(struct node_pass));
copy_pass_node(newnode , pass);
 newnode->next=NULL;

struct node_pass* temp= bus->passengers;
while(temp->next != NULL){

    temp=temp->next;
}
temp -> next=newnode;


}
// this function for insert new node of pass at the end of the waiting  list

void insertEndW(struct node_pass* waitingl, struct node_pass* pass){


struct node_pass* newnode;
newnode=(struct node_pass*)malloc (sizeof(struct node_pass));
copy_pass_node(newnode , pass);
newnode->next=NULL;


struct node_pass* temp=waitingl;
while(temp->next != NULL){

    temp=temp->next;
}
temp -> next=newnode;


}

// this function for add new passenger to the list
void addpass(int id ,int date , char time[10] ,char from[10] , char to[10],struct node_bus* l  , struct node_pass* w){


struct node_pass* newnode;
newnode=(struct node_pass*)malloc (sizeof(struct node_pass));
newnode->next=NULL;

newnode->id=id; newnode->date=date; strcpy(newnode->time,time);strcpy(newnode->from,from);strcpy(newnode->to,to);


registrations( l , newnode,w);// to assign the new pass with  match bus


}

// this function for delete specific bus based on its id
void Deletebus(int x ,struct node_bus* l  ,struct node_pass* w){
struct node_bus* p;
struct node_bus* temp;
struct node_bus* temp2= l ;


    if (temp2 != NULL && temp2->id == x) {
        l->next = temp2->next; // Changed head
        free(temp2); // free old head


       registrations( l ,temp2->passengers->next,w);// to assign the passengers from the deleted bus again to another bus or waiting list

    }
else{

p=Findprevbus(x,l);

if( p->next!=NULL){
    temp = p-> next;
p-> next=temp ->next;
free(temp);
registrations( l ,temp->passengers->next,w);
}
}

}

// this function to find previous bus to link it after deleted the bus
struct node_bus* Findprevbus(int x , struct node_bus* l){
struct node_bus* p ;
p=l;
while (p->next !=NULL && p-> next ->id!=x)
    p=p->next;


return p;

}





// this function to trim spaces from the string
char *trim(char *str)
{
    int i;

    while (isspace (*str)) str++;   // skip left side white spaces
    for (i = strlen (str) - 1; (isspace (str[i])); i--) ;   // skip right side white spaces
    str[i + 1] = '\0';
    return str;
}


// this function to delete  specific pass based on its id
void deletepass(int x  ,struct node_pass* pass){


struct node_pass* p;
struct node_pass* temp;

p=Findprevpass(x,pass);

if( p->next!=NULL){
    temp = p-> next;
p-> next=temp ->next;
free(temp);
}
//registration( l ,p,w);

}


// this function to find previous bus to link it after deleted the bus

struct node_pass* Findprevpass(int x , struct node_pass* l){
struct node_pass* p ;
p=l;
while (p->next !=NULL && p-> next ->id!=x)
    p=p->next;

return p;

}



void dd(int x, struct node_bus* bus_header,struct node_pass* pass_header,struct node_pass* waitingl ){

    struct node_bus* bus_position = bus_header;
    struct node_pass* pass_position = pass_header;
    struct node_pass* waitl = waitingl;


    while(pass_position != NULL){
    int done =0;
   bus_position = bus_header;
   while(bus_position != NULL ){

   if( bus_position->passengers->id==x){
          bus_position->cap += 1;


          deletepass(x,bus_position->passengers);

   done++;}
          bus_position = bus_position->next;}

    if(done==0){

            deletepass(x,waitingl);


}
        printf("\n\n");
        pass_position = pass_position->next;

}}


