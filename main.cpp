#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "ll.cpp"

#define size 100

using namespace std;

int main()
{
	system("cls");

	LinkedList ll;

	int ppl[size];
	unsigned int alive, skip, pos, no;

	//  initial number of people to seed the game
	printf("Enter the no. of people starting the game: ");
	scanf("%d", &no);

	//  number of people to skip before handing over the dagger
	printf("Enter the no. of people skip after excution: ");
	scanf("%d", &skip);

	//  select from which player, the execution will start
	printf("Enter the position to start the game: ");
	scanf("%d", &pos);

	/*  Example Senario: if number of people is set as 5 skips is set as 2 and position as 3
        Initial Arrangement: 1, 2, 3, 4, 5(circular)
        3 will kill 4, pass the dagger to 2(skipping 5 and 1)
        2 will kill 3, pass the dagger to 2 again(skipping 5 and 1)
        2 will kill 5, pass the dagger to 1(skipping 1 and 2)
        2 will kill 1, as only one is alive now, the game stops...
	*/

	/*  adjusting skips and pos, as per needs   */
	skip++;
	pos--;

	alive=no;   //  no. of people alive initailly is the number of people start the game

	for(int i=0; i<no; i++)
        ll.push(i+1);   //  pushing people to the linked list

    ll.reverse_3p();

    printf("\nSenario before the game starts:\n");
    ll.print();
    printf("\n\n");

    ll.circular();  //  making the linked list circular

    //ll.print();

    Node *temp = ll.head;   //  assigning the head of the linked list to a temp pointer
    for(int i=0; i<pos; i++)
        temp=temp->next;    //  reaching the player who will start the game

	while(alive>1)  //  loop will run till no of people alive is greater than 1
	{
	    /*  printing the list from the killer's psition */
	    for(int i=0; i<ll.llsize; i++)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<<"\b\b  \b\b";

	    //ll.print2();

        printf("\n");

	    Node *next=temp->next->next;    //  setting the next to next element of the list
	    delete temp->next;  //  deleting: hence killing the next person
	    ll.llsize--;    //  the size of the list gets reduced by one
	    temp->next=next;    //  the executed body is detatched from the list

	    /*  skipping the dagger to the next person  */
        for(int i=0; i<skip; i++)
            temp=temp->next;
        alive--;    //  no. of people alive gets reduced by one
	}

	printf("\n#%d is alive", temp->data);   //  oh! Hero never dies ;)

	_getch();
	return 0;
}
