#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
	map<char,TrieNode*> child;
	int isLast;
    TrieNode()
	{
        for (char i = 'a'; i <= 'z'; i++)
        child[i] = NULL;
		isLast=0;
    }
};

static TrieNode *root = NULL;

void insert(string s,int p)
{
	int len = s.length();
    TrieNode *ptr = root;
	for (int i = 0; i < len; i++)
	{
         TrieNode *nextNode = ptr->child[s[i]];
		if (nextNode == NULL)
		{
            nextNode = new TrieNode();
            ptr->child[s[i]] = nextNode;
		}
		ptr = nextNode;
		if (i == len - 1)
        {
         ptr->isLast=p;
        }
    }
}

void insertIntoTrie(string contacts[],long long int phone_number[],int n)
{
	for (int i = 0; i < n; i++)
		insert(contacts[i],phone_number[i]);
}
void displayContactsUtil(TrieNode *curNode, string prefix,string str)
{
    string temp;
	if (curNode->isLast)
    {
    cout<<"\tcontact : "<<prefix<<"       "<<"\tphone_number : "<<curNode->isLast << endl;
    }
	for (char i = 'a'; i <= 'z'; i++)
	{
		 TrieNode *nextNode = curNode->child[i];
		if (nextNode != NULL)
        {
            temp=prefix + (char)i;
            displayContactsUtil(nextNode, temp,str);

        }
	}
}
void displayContacts(string str)
{
	 TrieNode *prevNode = root;
	 TrieNode *curNode;
    string temp1=str;
	string prefix = "";
	string prefix1 = "";
	int len = str.length();
	int i;
	for (i=0; i<len; i++)
	{
        prefix += (char)str[i];
		char lastChar = prefix[i];
        curNode = prevNode->child[lastChar];
		if (curNode == NULL)
		{
		    cout<<endl;
            i++;
			break;
		}

prevNode = curNode;

	}
	if(curNode!=NULL){
	cout<<endl<< "Suggestions based on " << prefix
			<< " are :"<<endl<<endl;
		displayContactsUtil(curNode,prefix,str);
	}
	for (i=0; i<len; i++)
	{
		prefix += (char)str[i];
		if(prefix==temp1)
		cout << "No Results Found for : " << prefix<<endl<<endl;

   }
}
int main()
{
    int num;
    char ch;
    string contacts[100];
    long long int phone_number[100];
    cout<< "************************************************************************"<<endl;
    cout<<"DEVELOPED BY:"<<endl;
    cout<<"\tPalak Arora"<<endl;
    cout<<"\tAastha Bhat"<<endl;
    cout<<"\tShorya Khanna"<<endl;
    cout<< "************************************************************************"<<endl;
    system("pause");
    system("cls");
    root = new TrieNode();
    entry:
    cout<< "************************************************************************"<<endl;
    cout<<"Enter number of contacts you want to insert in your phonebook:";
    cin>>num;
    cout<<endl;
    cout<< "************************************************************************"<<endl;
    cout<<endl;
    cout<<"Enter contacts:"<<endl<<endl;
    for(int t=0;t<num;t++)
    {
        cout<<"\tcontact name : ";
        cin>>contacts[t];
        cout<<"\tphone number : ";
        cin>>phone_number[t];
        cout<<endl<<endl;
    }
    cout<< "************************************************************************"<<endl;
    int n=num;
    insertIntoTrie(contacts,phone_number,n);
   	string query ;
	cout<<"Enter contact that you want to search in your phonebook : ";
	cin>>query;
    cout<< "************************************************************************"<<endl;
	displayContacts(query);
	cout<< "************************************************************************"<<endl;
	cout<<"You still want to continue(y/n)?"<<endl;
	cout<< "************************************************************************"<<endl;
	cin>>ch;
	switch (ch)
	{
    case 'y':
        goto entry;
        break;
    case 'n':
        system("cls");
        cout<< "************************************************************************"<<endl;
        cout<<"ok bye....!!"<<endl;
        cout<< "************************************************************************"<<endl;
        break;
    default:
        system("cls");
        cout<< "************************************************************************"<<endl;
        cout<<"you entered the wrong option"<<endl;
        cout<<"ok bye....!!"<<endl;
        cout<< "************************************************************************"<<endl;
        break;
	}
	return 0;
}
