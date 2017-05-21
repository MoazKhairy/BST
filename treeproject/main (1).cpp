#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class patient
{
    string name ;
    int num ;
    int age ;
    string* drugs ;
public :
    patient()
    {
        drugs = new string[10];
    }
    patient(int init_number, string init_name, int init_age, string* init_drugs)
    {
        num = init_number;
        name = init_name;
        age = init_age;
        drugs = init_drugs;
    }
    void setName(string N) {name= N ; }
    void setNum(int n) {num= n ; }
    void setAge(int A) {age= A ; }
    void setDrugs(string* D) {drugs= D ; }
    string getName()  {return name ;}
    int getNum ()     {return num ;}
    int getAge ()     {return age ;}
    string* getDrugs()  {return drugs ;}
};
class node
{
    patient* data ;
    node* right ;
    node* left ;
public :
    node () { }
    void setData(patient* D)  {data = D ;}
    void setRight(node* r)  { right = r ;}
    void setLeft(node* L )  { left = L ;}
    patient* getData()           {return data ;}
    node* getRight()        {return right ;}
    node* getLeft()         {return left ;}
};
class Tree
{
    node* root ;
public :
Tree() {root = NULL;}
void insertion (patient* data)
{
   node* newNode = new node() ;
   newNode -> setData (data) ;
   newNode-> setRight(NULL) ;
   newNode-> setLeft(NULL) ;

   if(root == NULL)
   {root = newNode ;}

   else
{
   node* tmp = root ;
   if (newNode -> getData()-> getNum() <= root -> getData()-> getNum() )
   {
       tmp = root-> getLeft() ;
       if (tmp == NULL)
       {root-> setLeft(newNode) ;}
       else
       {
         int done =1 ;
         while(done)
         {
              if (newNode -> getData()-> getNum() <= tmp -> getData()-> getNum() )
              {
                     if(tmp -> getLeft() == NULL)
                     {
                         tmp -> setLeft(newNode) ;
                         done = 0 ;
                     }
                     else
                     {
                         tmp = tmp -> getLeft() ;
                     }
              }
              else
              {
                     if(tmp -> getRight() == NULL)
                     {
                         tmp -> setRight(newNode) ;
                         done = 0 ;
                     }
                     else
                     {
                         tmp = tmp -> getRight() ;
                     }
              }
         }
       }
   }
   else
   {
       tmp = root-> getRight() ;
       if (tmp == NULL)
       {root-> setRight(newNode) ;}
       else
       {
         int done =1 ;
         while(done)
         {
              if (newNode -> getData()-> getNum() <= tmp -> getData()-> getNum() )
              {
                     if(tmp -> getLeft() == NULL)
                     {
                         tmp -> setLeft(newNode) ;
                         done = 0 ;
                     }
                     else
                     {
                         tmp = tmp -> getLeft() ;
                     }
              }
              else
              {
                     if(tmp -> getRight() == NULL)
                     {
                         tmp -> setRight(newNode) ;
                         done = 0 ;
                     }
                     else
                     {
                         tmp = tmp -> getRight() ;
                     }
              }
         }
       }
       }
   }
}

patient* searchBST (int num)
{
    if ( root==NULL )
    {cout <<"empty Hospital \n" ; return NULL ;}
    else
    {
        node* tmp = root ;
        while (tmp != NULL)
        {
            if(num == tmp->getData()->getNum())
            {return tmp->getData(); }
            else if (num > tmp->getData()->getNum())
            {tmp = tmp->getRight(); }
            else
            {tmp= tmp-> getLeft(); }
        }
        cout << "Not Found \n " ;
        return NULL ;
    }
}

void inOrder ()
{
    inOrder2(root);
}
void inOrder2 (node* tmp)
{
     if (tmp == NULL)
        {  return;}
    inOrder2(tmp->getLeft());
    int num = tmp ->getData()->getNum();
    string name = tmp->getData()->getName();
    int age = tmp->getData()->getAge();
    string* drugs = tmp->getData()->getDrugs();
         cout <<"number :"<< num << "\n" <<"name: "<< name << "\n" << "age : "<<  age << "\n";
         cout << "Drugs: ";
         for (int i = 0; i < 3; ++i)
         {
             cout << drugs[i] << " \t ";
         }
         cout << endl;
    inOrder2(tmp->getRight());
}
void preOrder (ofstream& output)      //
    {

        return preOrder2(root ,  output) ; //3shan ana b7tag root 3shan search ashof ana wa2f fan...w output 3shan yst5dmo mkan al cOUT..
    }                                    // 3shan al user mlosh 3laka b al root .
 void preOrder2(node* tmp , ofstream& output)
{
     if (tmp == NULL)
        { return;}
    int num = tmp ->getData()->getNum();
    string name = tmp->getData()->getName();
    int age = tmp->getData()->getAge();
    string* drugs = tmp->getData()->getDrugs();
         output << num << " " << name << " " << age << " ";
         for (int i = 0; i < 3; ++i)
         {
             output << drugs[i] << "  ";
         }
         output << endl;
    preOrder2(tmp->getLeft() , output);
    preOrder2(tmp->getRight() , output);
}
bool delete_Leaf(node* child , node* parent)
{
    if(parent == NULL)        //parent of root == NULL case
    {
        root = NULL ;
    }
    else
    {
        if(parent-> getLeft() == child)
        {
           parent-> setLeft(NULL) ;
        }
        else
        {
            parent->setRight(NULL);
        }
      delete child ;
    }
    return true ;
}
bool delete_Middle_one_child(node* child , node* parent)
{
    if(parent == NULL)        //parent of root == NULL case
    {
        if(child-> getLeft() != NULL)
        {
            root = child->getLeft() ;
        }
        else
        {
            root = child->getRight() ;
        }
    }
    else
    {
        if (parent -> getLeft() == child)
        {
            if(child->getLeft() != NULL)
            {
                parent->setLeft(child->getLeft()) ;
            }
            else
            {
                parent->setLeft(child->getRight()) ;
            }
        }

        else
        {
            if(child->getLeft() != NULL)
            {
                parent->setRight(child->getLeft()) ;
            }
            else
            {
                parent->setRight(child->getRight()) ;
            }
        }
    delete child ;
    }
    return true ;
}
node* MaxNode (node* root)
{
    node* tmp =root ;
    while (tmp->getLeft() != NULL)
    {
        tmp = tmp ->getRight() ;
    }
    return tmp ;
}


bool deleteNode(int num)
{
    return deleteNode2(num , root , NULL) ;
}
bool deleteNode2(int num , node* Begin ,node* parent_Begin )
{
    if(Begin == NULL )
    {
        return false ;
    }
    node* tmp = Begin ;
    node* parent = parent_Begin ;
    while(tmp != NULL)
    {
        if (num == tmp->getData()->getNum())
        {
            if (tmp->getLeft()== NULL && tmp->getRight()== NULL)
            {
                return delete_Leaf(tmp , parent);
            }
            else if (tmp->getLeft()== NULL || tmp->getRight()== NULL )
            {
                return delete_Middle_one_child(tmp , parent);
            }
            else
            {
                node* Max = MaxNode(tmp->getLeft()) ;
                tmp -> setData(Max -> getData());
                return deleteNode2(tmp->getData()->getNum() , tmp->getLeft() , tmp);      //recursion if we have another left child not right because if we have right we got it as a Max as previous
                return true ;
            }
        }
            else if (num < tmp->getData()->getNum())
            {
                parent = tmp ;
                tmp = tmp->getLeft();
            }
            else
            {
                parent = tmp ;
                tmp = tmp->getRight() ;
            }
        }

    return false ;
}
};

int main()
{
    Tree* tree = new Tree() ;
    int wanting ;
    int done =1 ;
    while (done)
    {
        cout<<"which opertion you want ?? " <<endl ;
        cout<<" [1] insert new patient? \n " ;
        cout<<"[2] delete a patient ?  \n " ;
        cout<<"[3] search by patient number \n " ;
        cout<<"[4] print all data of patient \n " ;
        cout<<"[5] Store the Tree in the text File \n " ;
        cout<<"[6] Reconstruct the same Tree from the text file \n ";
        cin >> wanting ;
       switch (wanting)
      {
        case 1 :
        {
            int num ;
            string name ;
            int age ;
            string* drugs = new string[10] ;
             for(int i=0 ; i<4 ;i++)
            {
                drugs[i] = "null";
            }
            cout << "Enter the patient information : \n \n" ;
            cout << "Number is : " ;
            cin >> num ;
            cout << "Name is : " ;
            cin >> name ;
            cout << "Age is : " ;
            cin >> age ;
            for(int i=0 ; i<4 ;i++)
            {
            cout<<"drug[ " << i+1 << " ] : " ;
            cin>>drugs[i] ;
            char another_drug ;
            cout<<"want enter another drugs? enter 'y' or 'n' " ;
            cin>>another_drug ;
            if(another_drug == 'n')
            {break;}
            }
            patient* Patient = new patient(num , name , age , drugs);

            tree -> insertion(Patient) ;
            break ;
        }
       case 2 :
        {
         int num ;
         cout << "plz Enter Number of patient : " ;
         cin >> num ;
         bool deleted = tree->deleteNode(num) ;
         if(deleted)
         {
             cout << "delete is done" ;
         }
         else
         {
             cout << "ERROR NUMBER " ;
         }
         break ;
        }
       case 3 :
        {
            int num ;
            cout << "enter number of patient : " ;
            cin >> num ;
            patient* Patient = tree -> searchBST(num) ;
             num = Patient -> getNum() ;
            string name = Patient -> getName() ;
            int age = Patient -> getAge() ;
            cout << "Number : " << num <<"\t" << "Name : " << name <<"\t"<< "Age : " << age <<"\t" << " drugs is : " ;
            string* drugs = Patient->getDrugs();
            for (int i =0 ; i<4 ; i++)
            {cout <<  drugs[i] << "\t" ;}
            cout<<"\n \n" ;
            break ;
        }
       case 4 :
        {
            tree->inOrder() ;
            break ;
        }
       case 5 :
        {
            ofstream output ("Tree.txt");
            tree -> preOrder(output);
            break;
        }
       case 6 :
        {
            ifstream  input("Tree.txt");

                string line;


                while (getline(input, line))     //ast5dmt input 3shan ageb al line
                {
                    istringstream content(line);       //hna ana bfok klemat al line da ale hya mgmo3a mn al strings

                    int num;
                    string name;
                    int age;
                    string* drugs = new string[4];

                    content >> num;

                    content >> name;

                    content >> age;

                    for (int i = 0; i < 4 ; ++i)
                    {
                        content >> drugs[i];
                    }

                    patient* Patient = new patient(num, name, age, drugs);     // because we insert new patient

                    tree->insertion(Patient);
                }

                break;
        }
       default :
        cout << "error operation" ;
    }
char another_operation ;
cout<<"want to do another operation ? enter 'y' or 'n' " ;
cin>> another_operation ;
if (another_operation == 'n' )
{done = 0 ;}
}
    return 0 ;
}
