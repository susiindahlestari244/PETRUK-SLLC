#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h> 
using namespace std;

class mahasiswa
{
public:

  int urut;
  mahasiswa *next; 
}; 
  mahasiswa *awal_ptr = NULL;
  mahasiswa *posisi;         
  int option = 0; 

void tambah_data_awal_list()
{
  mahasiswa *baru;
  baru = new mahasiswa;
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

void tambah_data_mahasiswa_di_akhir()
  {
  mahasiswa *temp, *temp2;   
  temp = new mahasiswa; 
  cout << "Masukkan Data     : ";
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
} 

void display_list()
{
  mahasiswa *temp;
  temp = awal_ptr;
  cout << endl;
  cout << "DATA [";  
  if (temp == NULL)
    cout << "Data kosong!" << endl;
  else
  {
    while (temp != NULL)
    {  
     
     cout << "" << temp->urut << ",";
     
     if (temp == posisi)
        cout << "     <<posisi mahasiswa";

     temp = temp->next; 
    }
    cout << "] ";  
    cout << "Akhir list!" << endl;
  }
  
} 

void hapus_awal_mahasiswa()
{
  mahasiswa *temp;
  temp = awal_ptr;
  awal_ptr = awal_ptr->next;
  delete temp;
} 

void hapus_akhir_mahasiswa()
{
  mahasiswa *temp1, *temp2;
  if (awal_ptr == NULL)
    cout << "Data kosong!" << endl;
  else
  {
    temp1 = awal_ptr;
    if (temp1->next == NULL)
    {
      delete temp1;
      awal_ptr = NULL;
    }
    else 
    {
      while (temp1->next != NULL)
      {
        temp2 = temp1;
        temp1 = temp1->next;
      }
      delete temp1;
      temp2->next = NULL;
    }

   }
} 

void pindah_posisi_sebelumnya()
{
  if (posisi->next == NULL)
  cout << "Anda berada pada akhir data." << endl;
  else
  posisi = posisi->next; 
} 

void pindah_posisi_berikutnya()
{
  if (posisi == awal_ptr)
    cout << "Anda berada pada awal data" << endl;
  else
  {
   mahasiswa *previous;     
    previous = awal_ptr; 
    while (previous->next != posisi) 
    { 
      previous = previous->next;
    }
    posisi = previous;
  }
}

void tambah_data_yang_akan_disisipkan_list()
{
  mahasiswa *baru, *bantu;
  int posisi_sisip;
  if(awal_ptr != NULL)
  {
  
   
    cout<<"Akan disisip setelah Data Ke ? : ";
    cin>>posisi_sisip;
    baru =new mahasiswa;
   bantu=awal_ptr;
     
    for(int i=1;i<posisi_sisip-1;i++) {
      if(bantu->next != NULL)
        bantu=bantu->next;
      else
        break; 
    }
  cout << "Masukkan Data     : ";
  cin >> baru->urut;
  baru->next=bantu->next;
  bantu->next=baru;
  }
  else
  {
    cout<<"Maaf data anda belum ada ! silahkan isi data terlebih dulu....";
    getch();
  } 
} 

void Hapus_data_yang_telah_disisipkan_list()
{
  int banyakdata,posisi_hapus,poshapus;
  mahasiswa *hapus, *bantu;
  if(awal_ptr != NULL)
  {
    cout<<" Data yang akan dihapus  : ";
    cin>>posisi_hapus;
    banyakdata=1;
    bantu=awal_ptr;
    while(bantu->next != NULL)
    {
      bantu=bantu->next;
      banyakdata++;
    }
    if((posisi_hapus<1)||(posisi_hapus>banyakdata))
    {
      cout<<"Belum ada data !! masukkan Data dula aja...\n";
    }
    else
    {
      bantu=awal_ptr;
      poshapus=1;
      while(poshapus<(posisi_hapus-1))
      {
        bantu=bantu->next;
        poshapus++;
      }
      hapus=bantu->next;
      bantu->next=hapus->next;
      delete hapus;
    }
 }
 else 
    cout<<"Maaf data anda belum ada !! silahkan isi data terlebih dulu... ";
 getch();
}
 

int init(int nilai){
 mahasiswa *baru;
  baru = new mahasiswa;
  baru->urut=nilai;
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

int main()
{
  cout << "=============================================" << endl;
  cout <<"Nama :\tMayda Brilliani Fauzi  1717051003"<<endl;
  cout <<"\tSusi Indah Lestari     1717051035"<<endl;
  cout <<"\tKhaernun Anisa Ensri   1717051039"<<endl;
  cout <<"============================================="<<endl;
  cout << "\tLINKED LIST" << endl;
  cout << "============================================" << endl;
  awal_ptr = NULL;
  
  init(4);
  init(5);
  init(3);
  init(1);
  init(5);
  init(7);
  init(1);
  do
  {

 
    display_list();
    cout << endl;
    cout << "MENU PILIHAN : " << endl;
    cout << "0. Keluar program." << endl;
    cout << "1. Tambah data awal list." << endl;
    cout << "2. Tambah data akhir list." << endl;
    cout << "3. Tambah data yang akan disisipkan list."<< endl;
    cout << "4. Hapus data awal list." << endl;
    cout << "5. Hapus data akhir list." << endl;
    cout << "6. Hapus data yang telah disisipkan  list." << endl;
    cout << endl << " Pilihan >> ";
    cin >> option; 

switch (option)
  {
  case 1 : tambah_data_awal_list(); 
    break;
  case 2 : tambah_data_mahasiswa_di_akhir();
    break;
  case 3 : tambah_data_yang_akan_disisipkan_list();
    break;
  case 4 : hapus_awal_mahasiswa();
    break;
  case 5 : hapus_akhir_mahasiswa();
    break;
  case 6 : Hapus_data_yang_telah_disisipkan_list();
   
  }
 }  
while (option != 0); 
}
