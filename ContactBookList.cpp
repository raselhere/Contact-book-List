#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

struct Contact
{
    string name="";
    string phnNo="";
    Contact *left=NULL;
    Contact *right=NULL;
};

class ContactBook
{
private:
    Contact* root;

    void insertNode(Contact *&tree, string name, string phnNo, int &x)
    {

        if(tree == NULL)
        {
            tree = new Contact;
            tree->name = name;
            tree->phnNo=phnNo;
            tree->left = NULL;
            tree->right = NULL;
        }
        else if(compare(tree->phnNo,phnNo))
        {
            cout << "\n\nContact already exists" << endl << endl;
            x=1;
        }
        else if(name < tree->name)
        {
            insertNode(tree->left,name,phnNo,x);
        }
        else
        {
            insertNode(tree->right,name,phnNo,x);
        }
    }

    void DisplayContacts(Contact *tree)
    {
        if(tree == NULL)
        {
            return;
        }
        DisplayContacts(tree->left);
        cout << tree->name << endl << tree->phnNo << endl << endl;
        DisplayContacts(tree->right);
    }

    string convert(string s)
    {
        for(int i=0; i<s.length(); i++)
        {
            if(!isupper(s[i]))
                s[i]=toupper(s[i]);
        }
        return s;
    }

    bool compare(string s1, string s2)
    {
        if(s1.length()==s2.length())
        {
            for(int i=0; i<s1.length(); i++)
            {
                if(s1[i]!=s2[i])
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    void retrieveNode(Contact *tree, string name)
    {


        if(tree==NULL)
        {

        }
        else
        {
            string fn="",ln="";
            int i=0;
            string a="";
            string fn1,ln1;
            int k=0;
            string a1="";
            string n;

            a=name[i];
            while(a!=" " && i<name.length())
            {
                fn+=name[i];
                i++;
                a=name[i];
            }
            i++;

            for(int j=i; j<name.length(); j++)
            {
                ln+=name[j];
            }



            a1=tree->name[k];
            while(a1!=" " && k<tree->name.length())
            {
                fn1+=tree->name[k];
                k++;
                a1=tree->name[k];
            }
            k++;

            for(int j=k; j<tree->name.length(); j++)
            {
                ln1+=tree->name[j];
            }

            fn=convert(fn);
            ln=convert(ln);
            fn1=convert(fn1);
            ln1=convert(ln1);
            n=convert(name);


            if(compare(fn,fn1)||compare(fn1,ln)||compare(ln1,ln)||compare(ln1,fn)||compare(tree->name,name)||compare(fn1,n)||compare(ln1,n))
            {
                cout << tree->name << endl << tree->phnNo << endl << endl;
                return retrieveNode(tree->right,name);
                return retrieveNode(tree->left,name);
            }
            else if(name < tree->name)
            {
                return retrieveNode(tree->left,name);
            }
            else
            {
                return retrieveNode(tree->right,name);
            }
        }
    }

    void matchFound(Contact *tree, string name, int &counter)
    {

        if(tree == NULL)
        {
            return;
        }
        else
        {
            string fn="",ln="";
            string a="";
            string fn1="",ln1="";
            string a1="";
            string n="";
            int i=0;

            a=name[i];
            while(a!=" " && i<name.length())
            {
                fn+=name[i];
                i++;
                a=name[i];
            }
            i++;
            if(i<name.length())
            {
                for(int j=i; j<name.length(); j++)
                {
                    ln+=name[j];
                }
            }

            int k=0;

            a1=tree->name[k];
            while(a1!=" " && k<(tree->name).length())
            {
                fn1+=tree->name[k];
                k++;
                a1=tree->name[k];
            }
            k++;
            if(k<(tree->name).length())
            {
                for(int j=k; j<(tree->name).length(); j++)
                {
                    ln1+=tree->name[j];
                }
            }

            fn=convert(fn);
            ln=convert(ln);
            fn1=convert(fn1);
            ln1=convert(ln1);
            n=convert(name);

            if(compare(fn,fn1)||compare(fn1,ln)||compare(ln1,ln)||compare(ln1,fn)||compare(tree->name,name)||compare(fn1,n)||compare(ln1,n))
            {
                counter++;
                return matchFound(tree->right,name,counter);
                return matchFound(tree->left,name,counter);
            }
            else if(name < tree->name)
            {
                return matchFound(tree->left,name,counter);
            }
            else
            {
                return matchFound(tree->right,name,counter);
            }
        }

    }

    void deleteNode(Contact *&tree, string name, string phnNo)
    {

        if(tree == NULL)
        {
            return;
        }
        else
        {


            if(compare(tree->name,name)&&compare(tree->phnNo,phnNo))
            {
                if(tree->left == NULL && tree->right == NULL)
                {
                    delete tree;
                    tree = NULL;
                }
                else if(tree->left != NULL)
                {
                    Contact *maxLeftNode = findMaxNode(tree->left);
                    tree = maxLeftNode;
                    deleteNode(tree->left,maxLeftNode->name,maxLeftNode->phnNo);
                }
                else
                {
                    Contact *minRightNode = findMinNode(tree->right);
                    tree = minRightNode;
                    deleteNode(tree->right,minRightNode->name,minRightNode->phnNo);
                }
            }
            else if(tree->name < name)
            {
                deleteNode(tree->right,name,phnNo);
            }
            else
            {
                deleteNode(tree->left,name,phnNo);
            }
        }

    }

    void getNameFromPhnNo(Contact *tree, string &phnNo)
    {

        if(tree->phnNo==phnNo)
        {
            cout << "\n\n1 Match found" << endl;
            phnNo = tree->name;
        }
        else if(tree->left!=NULL)
        {
            getNameFromPhnNo(tree->left,phnNo);
        }
        else if(tree->right!=NULL)
        {
            getNameFromPhnNo(tree->right,phnNo);
        }
        else
        {
            return;
        }
        return;
    }

    Contact *findMinNode(Contact *tree)
    {
        if(tree == NULL)
        {
            return NULL;
        }
        else if(tree->left == NULL)
        {
            return tree;
        }
        else
        {
            return findMinNode(tree->left);
        }
    }

    Contact *findMaxNode(Contact *tree)
    {
        if(tree == NULL)
        {
            return NULL;
        }
        else if(tree->right == NULL)
        {
            return tree;
        }
        else
        {
            return findMaxNode(tree->right);
        }
    }

public:
    ContactBook()
    {
        root = NULL;
    }
    void insertNode(string name, string phnNo)
    {
        int x=0;
        insertNode(root,name,phnNo,x);
        if(x==0)
        {
            cout << "\n\t***Contact added successfully ***" << endl;
        }
    }

    void DisplayContacts()
    {
        if(root==NULL)
        {
            cout << "\n\nThe list is empty" << endl << endl;
        }
        else
        {
            DisplayContacts(root);
        }
    }

    void searchContact(string name)
    {
        if(root!=NULL)
        {
            int counter=0;
            matchFound(root,name,counter);
            //int counter=coun;
            if(counter!=0)
            {
                cout << endl << counter << " match found" << endl << endl;
                retrieveNode(root,name);
            }
            else
            {
                cout << "\n\nNo match found" << endl << endl;
            }
        }
        else
        {
            cout << "\nNo contact is listed" << endl;
        }
    }

    void deleteContact(string phnNo)
    {
        if(root!=NULL)
        {
            string name="";
            name=phnNo;
            getNameFromPhnNo(root,name);
            int counter=0;
            matchFound(root,name,counter);
            //int counter=coun;
            if(counter!=0)
            {

                int p=0;
                while(p==0)
                {
                    cout << "\n\nDelete this contact?\n(Enter y for yes, n for No): ";
                    string ans;
                    cin >> ans;
                    if(ans=="y")
                    {
                        deleteNode(root,name,phnNo);
                        cout << "\n\nContact deleted successfully." << endl << endl;
                        p=1;
                    }
                    else if(ans=="n")
                    {
                        p=1;
                    }
                    else
                    {
                        cout << "\n\nWrong input\n" << endl;
                    }
                }


            }
            else
            {
                cout << "\n\nNo match found" << endl << endl;
            }
        }
        else
        {
            cout << "\nNo contact listed" << endl;
        }

    }

    int findMinNode()
    {
        findMinNode(root);
        return 0;
    }
    int findMaxNode()
    {
        findMaxNode(root);
        return 0;
    }

};


int main()
{
    cout << "### WELCOME TO CONTACT BOOK LIST ###" << endl;
    ContactBook ct;

    int x=0,chose;

    while(x!=1)
    {
        cout << "\n*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "1.Add new contact" << endl;
        cout << "2.Display all contacts" << endl;
        cout << "3.Search for a contact" << endl;
        cout << "4.Delete a contact" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice (1-5):";
        cin >> chose;
        if(chose == 1)
        {
            cout << "\n >> Add new contact" << endl << endl;
            cout << "Enter name: ";
            string name1;
            cin.ignore();
            getline(cin,name1);
            cout << "Enter phone number: ";
            string phnNo1;
            cin >> phnNo1;

            ct.insertNode(name1,phnNo1);

        }
        else if(chose == 2)
        {
            cout << "\n >> Display all contacts" << endl << endl;
            ct.DisplayContacts();
        }
        else if(chose == 3)
        {
            cout << "\n >> Search for a contact" << endl << endl;
            string name2;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin,name2);
            ct.searchContact(name2);

        }
        else if(chose == 4)
        {
            cout << "\n >> Delete a contact" << endl << endl;
            string phnNo="";
            cout << "Enter Phone Number: ";
            cin >> phnNo;
            ct.deleteContact(phnNo);

        }
        else if(chose == 5)
        {
            cout << "\n\t***Program has exited***" << endl << endl;
            cout << "       \t\t\t\t\"/\\_/\\" << endl;
            cout << "(\\__/)" << "\t\t\t\t >^,^<" << endl;
            cout << "(='.'=)" << "\t\t\t\t\"\"/ \\" << endl;
            cout << "C(\")_(\")" << "\t\t\t'(___)_/" << endl;

            x=1;
        }
        else
        {
            cout << "\n\t***Wrong input try again***" << endl << endl;

        }
    }





}
