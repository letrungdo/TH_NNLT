#include<stdio.h>
#include<conio.h>

struct TNode
{
	int Info;
	TNode *Left;
	TNode *Right;
};
struct BTree
{
	TNode* Root;
};
struct StackNode
{
	TNode* Info;
	StackNode* Next;
};
struct Stack
{
	StackNode* Top;
};


StackNode* CreateStackNode(TNode* x)
{
	StackNode*p=new StackNode;
	if(p==NULL)
	{
		return NULL;
	}
	p->Info=x;
	p->Next=NULL;
	return p;
}
void InitStack(Stack &s)
{
	s.Top=NULL;
}
int IsEmpty(Stack s)
{
	if(s.Top==NULL)
		return 1;
	else
		return 0;
}
int Push(Stack &s,TNode* p)
{
	StackNode* q=CreateStackNode(p);
	if(p==NULL)
		return 0;
	if(IsEmpty(s)==1)
		s.Top=q;
	else
	{
		q->Next=s.Top;
		s.Top=q;
	}
	return 1;
}
int Pop(Stack &s,TNode* &x)
{
	if(IsEmpty(s)==1)
		return 0;
	StackNode* p=s.Top;
	s.Top=s.Top->Next;
	x=p->Info;
	delete p;
	return 1;
}


TNode* CreateTNode (int x)
{
	TNode* p= new TNode;
	if(p==NULL)
	{
		return NULL;
	}
	p->Info=x;
	p->Left=NULL;
	p->Right=NULL;
	return p;
}



void InitBTree(BTree &bt)
{
	bt.Root=NULL;
}

int InsertTNode(TNode* &root, TNode* p)
{
	if(p == NULL) return 0;
	if(root == NULL)
	{
		root = p;
		return 1;
	}
	if(root->Info == p->Info) return 0;
	if(p->Info<root->Info)
		InsertTNode(root->Left, p);
	else
		InsertTNode(root->Right, p);
	return 1;
}

void CreateTree(BTree &bt)
{
	InitBTree(bt);
	int n;
	do
	{
		printf("Nhap so phan tu: ");
		scanf("%d",&n);
	}while(n<=0);
	for(int i=0;i<n;i++)
	{
		int x;
		printf("Nhap nut %d: ",i+1);
		scanf("%d",&x);
		InsertTNode(bt.Root,CreateTNode(x));;
	}
}

void NLR(TNode* root)
{
	if(root==NULL) 
		return;
	Stack s;
	InitStack(s);
	printf("%4d",root->Info);
	Push(s,root->Right);
	Push(s,root->Left);
	while(IsEmpty(s)==0)
	{
		TNode* p;
		Pop(s,p);
		if(p!=NULL)
		{
			printf("%4d",p->Info);
			Push(s,p->Right);
			Push(s,p->Left);
		}
	}
}
void main()
{
	BTree bt;
	CreateTree(bt);
	printf("\nNoi dung duoc xuat theo NLR stack: ");
	NLR(bt.Root);
	getch();
}
