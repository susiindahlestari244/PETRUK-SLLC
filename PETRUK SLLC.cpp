#include <iostream>
#include <stdlib.h>
#include <conio.h> 
using namespace std;
class node {
public:

  int urut;
  node *next; 
}
node *awal_ptr = NULL;
  node *posisi;        
  int option = 0 
void tambah_awal_list()
{
  node *baru;
  baru = new node;
  cout << "Masukkan Data     : ";
  cin >> baru->urut;
  baru->next = NULL;
  if(awal_ptr == NULL)
  {
    awal_ptr=baru;
    awal_ptr->next = NULL;
  }
  else
  {
    baru->next = awal_ptr;
    awal_ptr = baru;
  }
} 

void menambah_node_di_akhir()
  {
  node *temp, *temp2
 
  temp = new node; 
  cout << "Masukkan urut     : ";
  cin >>   temp->urut;
  temp->next = NULL; 
  if (awal_ptr == NULL)
  {
    awal_ptr = temp;
    posisi = awal_ptr;
  }
  else
  {
    temp2 = awal_ptr;
   
    while (temp2->next != NULL)
    {
      temp2 = temp2->next; 
    
    }
  temp2->next = temp;
  }

