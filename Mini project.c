/* Mini Project
Group No:38
Vehicle parking system */

#include<stdio.h>
#include<stdlib.h>
int add(int *NumberOfVehiclesParked,int *space_vehicle,int *m);
int main(){


    //int arr[3][3];
    int i,q,w;
    int choise,x;
    int y,m,count=0;
    int NumberOfVehiclesParked=0,space_vehicle=100;
    //FILE *vehicle;

    printf("\t\t\tVehicle Parking System\n\n");

    for(x=0;x<=100;x++){
        start2:
        printf("\n 1) Update vehicle amount\n 2) View available spaces\n 3) Exit\n:");
        scanf("%d",&choise);


        switch(choise){

        case 1://Update vehicle amount
            printf("\n 1) Vehicle entry number\n 2) Return\n:");
            scanf("%d",&y);

            if(y==1){
                for (i=0; i<5; i++){ // How many times should this loop run? if i=6, loop will run 6 times
                        start:
                        printf("\nHow many vehicle entered? or exit?\nIf exit please enter minus value (Ex: -1 )\nEnter 0 for return\n");
                        scanf("%d",&m);

                            if(m>=1){
                                count = NumberOfVehiclesParked + m;
                                    if(count>=101 || count<=-1){
                                        printf("...sorry... Limited spaces or -value \n");
                                        goto start;
                                    }else{
                                    add(&NumberOfVehiclesParked,&space_vehicle,&m);
                                    }

                            }else if(m<= -1){
                                count = NumberOfVehiclesParked + m;
                                    if(count>=101 || count<=-1){
                                        printf("...sorry... Limited spaces or -value \n");
                                        goto start;
                                    }else{
                                    add(&NumberOfVehiclesParked,&space_vehicle,&m);
                                    }

                            }else if(m==0)
                                goto out;
                }
            }
            else{
                goto start2;
            }
            out:
        break;
        case 2://View available spaces
            printf("\nYou have %d free spaces available",space_vehicle);
            goto start2;
        break;
        case 3://exit
            return 0;
        break;
        default:
            printf("You entered a deferent number. ");
            goto start2;
        }

            FILE * fp;
            fp = fopen("C:\\Users\\Thiwanka Arunalu\\Documents\\codeblox\\test\\Mini project\\Vehicles\\Vehicles.txt","a");
            fprintf(fp,"%s%d","\n\n",count);
            fclose(fp);
    }

return 0;
}
int add(int *NumberOfVehiclesParked,int *space_vehicle,int *m){

    *NumberOfVehiclesParked = *NumberOfVehiclesParked + *m;
    *space_vehicle = *space_vehicle - *m;
     printf("Number of vehicles parked  :%d\n",*NumberOfVehiclesParked);
     printf("Number of spaces available :%d\n",*space_vehicle);
}
